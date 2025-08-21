#include "utils.h"

long long readNumber(const QString &expr, int &pos) {
    long long num = 0;
    while (pos < expr.length() && expr[pos].isDigit()) {
        num = num * 10 + (expr[pos].unicode() - '0');
        ++pos;
    }
    --pos;
    return num;
}

long long priority(QChar Op) {
    if (Op.unicode() == 0x002B || Op.unicode() == 0x2212) return 1;
    if (Op.unicode() == 0x00D7 || Op.unicode() == 0x00F7) return 2;
    if (Op.unicode() == 0x003C || Op.unicode() == 0x003E) return 3;
    return -1;
}

long long divide(long long a, long long b) {
    if (b == 0) {
        std::cerr << "Division by zero error" << std::endl;
        return 0;  // Handle division by zero
    }
    return a / b;
}

long long factorial(std::stack<long long> &operands) {
    if (operands.empty()) {
        throw std::invalid_argument("Factorial of empty stack error");
    }
    if (operands.top() < 0) {
        throw std::invalid_argument("Factorial of negative number error");
    }

    long long result = 1;
    for (long long i = 1; i <= operands.top(); i++) {
        result *= i;
    }
    return result;
}

long long applyOperator(long long a, long long b, QChar Op) {
    switch (Op.unicode()) {
        case 0x002B: // PLUS
            return a + b;
        case 0x2212: // MINUS SIGN
            return a - b;
        case 0x00D7: // MULTIPLICATION SIGN
            return a * b;
        case 0x00F7: // DIVISION SIGN
            return divide(a, b);
        default:
            throw std::runtime_error("Unknown operator");
    }
}

void processOperator(std::stack<long long> &operands, std::stack<QChar> &operators) {
    if (operands.size() < 2 || operators.empty()) {
        throw std::runtime_error("Invalid expression: not enough operands or operators.");
    }
    long long b = operands.top(); operands.pop();
    long long a = operands.top(); operands.pop();
    QChar op = operators.top(); operators.pop();
    operands.push(applyOperator(a, b, op));
    std::cout << "Processed operator: " << op.toLatin1() << " with operands: " << a << ", " << b << ", Result: " << operands.top() << std::endl;
}

void processParenthesis(std::stack<long long> &operands, std::stack<QChar> &operators) {
    if (operators.empty()) {
        throw std::runtime_error("Invalid expression: unexpected operator ')' or missing opening parenthesis.");
    }
    while (!operators.empty() && operators.top() != '(') {
        if (operands.size() < 2) {
            throw std::runtime_error("Invalid expression: not enough operands for operator.");
        }
        long long secNum = operands.top(); operands.pop();
        long long firstNum = operands.top(); operands.pop();
        QChar op = operators.top(); operators.pop();
        operands.push(applyOperator(firstNum, secNum, op));
    }
    if (operators.empty() || operators.top() != '(') {
        throw std::runtime_error("Invalid expression: Mismatched parentheses.");
    }
    operators.pop();
}

void processFactorial(std::stack<long long> &operands) {
    if (operands.empty()) {
        throw std::runtime_error("Invalid expression: No operands for factorial.");
    }
    long long result = factorial(operands);
    operands.pop();  // Remove the operand for factorial
    operands.push(result);
    std::cout << "Processed factorial, Result: " << result << std::endl;
}

long long calculateExpression(const QString &expr) {
    if (expr.trimmed().isEmpty()) {
        std::cerr << "Error: Empty expression" << std::endl;
        return 0;  // Stop processing if expression is empty
    }

    std::stack<long long> operands;
    std::stack<QChar> operators;

    try {
        for (int i = 0; i < expr.length(); ++i) {
            if (expr[i].isSpace())
                continue;

            if (expr[i].isDigit()) {
                operands.push(readNumber(expr, i));

            } else if (expr[i] == '(') {
                operators.push('(');

            } else if (expr[i] == ')') {
                processParenthesis(operands, operators);

            } else if (expr[i] == '!'){
                processFactorial(operands);

            } else {
                while (!operators.empty() && priority(operators.top()) >= priority(expr[i])) {
                    processOperator(operands, operators);
                }
                operators.push(expr[i]);
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 0; // Return 0 or handle error as needed
    } catch (const std::exception &e) {
        std::cerr << "Error occurred while parsing expression: " << e.what() << std::endl;
        return 0; // Return 0 or handle error as needed
    }

    while (!operators.empty()) {
        if (operands.size() < 2) {
            std::cerr << "Error: Not enough operands for operator." << std::endl;
            return 0; // Handle error
        }
        processOperator(operands, operators);
    }
    return operands.top();
}

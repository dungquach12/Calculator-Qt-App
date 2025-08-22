#include "utils.h"

// Helper functions

// To convert the operators to their ASCII equivalents
QString normalizeExpression(QString expr) {
    expr = expr.trimmed();
    if (expr.isEmpty()) {
        return expr;  // Return empty string if input is empty
    }

    QString result = expr;

    // Replace fancy math symbols with plain ASCII
    result.replace(QChar(0x00D7), "*");   // × → *
    result.replace(QChar(0x00F7), "/");   // ÷ → /
    result.replace(QChar(0x2212), "-");   // − → -
    result.replace(QChar(0x002B), "+");   // plus (just in case, usually already '+')

    return result;
}

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
    if (Op.unicode() == '+' || Op.unicode() == '-') return 1;
    if (Op.unicode() == '*' || Op.unicode() == '/') return 2;
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
        case '+': // PLUS
            return a + b;
        case '-': // MINUS SIGN
            return a - b;
        case '*': // MULTIPLICATION SIGN
            return a * b;
        case '/': // DIVISION SIGN
            return divide(a, b);
        default:
            throw std::runtime_error("Unknown operator");
    }
}

bool isOperator(QChar c) {
    static const QSet<QChar> operators = {
        '+', '-', '*', '/', '<', '>', '|', '!', 
    };
    return operators.contains(c);
}

// Process calculation functions

void processOperator(std::stack<long long> &operands, std::stack<QChar> &operators) {
    if (operands.size() < 2 || operators.empty()) {
        throw std::runtime_error("Invalid expression: not enough operands or operators.");
    }
    long long b = operands.top(); operands.pop();
    long long a = operands.top(); operands.pop();
    QChar op = operators.top(); operators.pop();
    operands.push(applyOperator(a, b, op));
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

void processAbsolute(std::stack<long long> &operands, std::stack<QChar> &operators) {
    if (operands.empty()) {
        throw std::runtime_error("Invalid expression: No operands for absolute value.");
    }

    while (!operators.empty() && operators.top() != '|') {
        if (operands.size() < 2) {
            throw std::runtime_error("Invalid expression: not enough operands for operator.");
        }

        long long secNum = operands.top(); operands.pop();
        long long firstNum = operands.top(); operands.pop();
        QChar op = operators.top(); operators.pop();
        long long res = applyOperator(firstNum, secNum, op);

        operands.push(std::abs(res));
    }
    
    if (operators.empty() || operators.top() != '|') {
        throw std::runtime_error("Invalid expression: Mismatched parentheses.");
    }
    operators.pop();
}

long long calculateExpression(const QString &expr) {
    if (expr.trimmed().isEmpty()) {
        std::cerr << "Error: Empty expression" << std::endl;
        return 0;  // Stop processing if expression is empty
    }

    std::stack<long long> operands;
    std::stack<QChar> operators;
    bool checkOpenedAbs = false;

    QString newExpr = normalizeExpression(expr);

    try {
        for (int i = 0; i < newExpr.length(); ++i) {
            if (newExpr[i].isSpace())
                continue;

            if (newExpr[i].isDigit()) {
                operands.push(readNumber(newExpr, i));

            } else if (newExpr[i] == '(') {
                operators.push('(');

            } else if (newExpr[i] == ')') {
                processParenthesis(operands, operators);

            } else if (newExpr[i] == '!'){
                processFactorial(operands);

            } else if (newExpr[i] == '|') {
                checkOpenedAbs = !checkOpenedAbs;
                if (checkOpenedAbs) {
                    operators.push('|');
                } else {
                    processAbsolute(operands, operators);
                }
            
            } else if (newExpr[i] == '-') {
                if (i == 0 || newExpr[i - 1] == '(' || isOperator(newExpr[i - 1])) {
                    operands.push(-1); // Treat as unary minus
                    operators.push('*');
                }
            } else {
                while (!operators.empty() && priority(operators.top()) >= priority(newExpr[i])) {
                    processOperator(operands, operators);
                }
                operators.push(newExpr[i]);
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
            std::stack<QChar> operatorsCopy = operators;
            std::stack<long long> operandsCopy = operands;
            while (!operatorsCopy.empty()) {
                std::cout << "Remaining operator: " << operatorsCopy.top().unicode() << std::endl;
                operatorsCopy.pop();
            }
            while (!operandsCopy.empty()) {
                std::cout << "Remaining operand: " << operandsCopy.top() << std::endl;
                operandsCopy.pop();
            }
            return 0; // Handle error
        }
        processOperator(operands, operators);
    }
    return operands.top();
}

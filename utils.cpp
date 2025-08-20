#include "utils.h"

int divide(int a, int b) {
    if (b == 0) {
        std::cerr << "Division by zero error" << std::endl;
        return 0;  // Handle division by zero
    }
    return a / b;
}

int priority(QChar Op) {
    if (Op.unicode() == 0x002B || Op.unicode() == 0x2212) return 1;
    if (Op.unicode() == 0x00D7 || Op.unicode() == 0x00F7) return 2;
    if (Op.unicode() == 0x003C || Op.unicode() == 0x003E) return 3;
    return -1;
}

int applyOperator(int a, int b, QChar Op) {
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
            std::cerr << "Unknown operator: " << Op.unicode() << std::endl;
            return 0; // Handle unknown operator
    }
}

int calculateExpression(const QString &expr) {
    std::stack<int> operands;
    std::stack<QChar> operators;

    try {
        for (int i = 0; i < expr.length(); ++i) {

            if (expr[i].isSpace())
                continue;

            if (expr[i].isDigit()) {
                int num = 0;
                while (i < expr.length() && expr[i].isDigit()) {
                    num = num * 10 + (expr[i].unicode() - '0');
                    ++i;
                }
                --i;
                std::cout << "Got num: " << num << std::endl;
                operands.push(num);
            } else if (expr[i] == '(') {
                operators.push('(');
            } else if (expr[i] == ')') {
                if (operators.empty()) {
                    throw std::runtime_error("Invalid expression: unexpected operator ')' or missing opening parenthesis.");
                }
                while (!operators.empty() && operators.top() != '(') {
                    if (operands.size() < 2) {
                        throw std::runtime_error("Invalid expression: not enough operands for operator.");
                    }
                    int secNum = operands.top(); operands.pop();
                    int firstNum = operands.top(); operands.pop();
                    QChar op = operators.top(); operators.pop();
                    std::cout << "parenthesis!" << std::endl;
                    operands.push(applyOperator(firstNum, secNum, op));
                }
                if (operators.empty() || operators.top() != '(') {
                    throw std::runtime_error("Invalid expression: Mismatched parentheses.");
                }
                operators.pop();
            } else {
                while (!operators.empty() && priority(operators.top()) >= priority(expr[i])) {
                    int secNum = operands.top(); operands.pop();
                    int firstNum = operands.top(); operands.pop();
                    QChar op = operators.top(); operators.pop();
                    operands.push(applyOperator(firstNum, secNum, op));

                    std::cout << "Applied operator: " << op.unicode() << " on " << firstNum << " and " << secNum << " results in " << operands.top() << std::endl;
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
        int secNum = operands.top(); operands.pop();
        int firstNum = operands.top(); operands.pop();
        QChar op = operators.top(); operators.pop();
        operands.push(applyOperator(firstNum, secNum, op));

        std::cout << "Applied operator: " << op.unicode() << " on " << firstNum << " and " << secNum << " results in " << operands.top() << std::endl;
    }   
        

    return operands.top();
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// to evaluate postfix expression and return output.
int evaluatePostFix(string exp);

// perform operation and return result.
int performOperation(char operator1, char operand1, char operand2);

// verify whether a character is a operator symbol or not.
bool isOperator(char c);

// verify whether a character is a numeric digit.
bool isNumericDigit(char c);

int main() {
    string expression;
    cout << "Enter postfix expression: " << endl;
    getline(cin, expression);
    cout << "Expression is " << expression << endl;
    int result = evaluatePostFix(expression);
    cout << "Output = " << result << endl;
    return 0;
}

int evaluatePostFix(string exp) {
    stack<int> s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ' || exp[i] == ',') {
            continue;
        } else if (isOperator(exp[i])) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result = performOperation(exp[i], operand1, operand2);
            s.push(result);
        } else if (isNumericDigit(exp[i])) {
            int operand = 0;
            while (i < exp.length() && isNumericDigit(exp[i])) {
                operand = operand * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }
    }
    return s.top();
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}

bool isNumericDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

int performOperation(char operator1, char operand1, char operand2) {
    if (operator1 == '+') {
        return operand1 + operand2;
    } else if (operator1 == '-') {
        return operand1 - operand2;
    } else if (operator1 == '*') {
        return operand1 * operand2;
    } else if (operator1 == '/') {
        return operand1 / operand2;
    } else {
        cout << "Unexpected Error!"<< endl;
        return -1;
    }
}

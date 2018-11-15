#include <iostream>
#include <stack>
#include <string>

using namespace std;

// convert infix expression to postfix.
string infixToPostfix(string exp);

// verify whether an operator has higher precedence over the other.
int hasHigherPrecedence(char operator1, char operator2);

// verify whether a character is operator symbol or not.
bool isOperator(char c);

// verify whether a character is alpha or numeric character or not.
bool isOperand(char c);

int main() {
    string expression;
    cout << "Enter infix expression: " << endl;
    getline(cin, expression);
    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ' || exp[i] == ',') {
            continue;
        } else if (isOperator(exp[i])) {
            while (!s.empty() && s.top() != '(' && hasHigherPrecedence(s.top(), exp[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(exp[i]);
        } else if (isOperand(exp[i])) {
            postfix += exp[i];
        } else if (exp[i] == '(') {
            s.push(exp[i]);
        } else if (exp[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

bool isOperand(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else if (c >= 'a' && c <= 'z') {
        return true;
    } else if (c >= 'A' && c <= 'Z') {
        return true;
    } else {
        return false;
    }
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$') {
        return true;
    } else {
        return false;
    }
}

int getOperatorWeight(char op) {
    int weight = -1;
    switch(op) {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '$':
            weight = 3;
            break;
    }
    return weight;
}

bool isRightAssociative(char op) {
    if (op == '$') {
        return true;
    } else {
        return false;
    }
}

int hasHigherPrecedence(char operator1, char operator2) {
    int operator1Weight = getOperatorWeight(operator1);
    int operator2Weight = getOperatorWeight(operator2);
    if (operator1Weight == operator2Weight) {
        if (isRightAssociative(operator1)) {
            return false;
        } else {
            return true;
        }
    }
    return operator1Weight > operator2Weight? true: false;
}

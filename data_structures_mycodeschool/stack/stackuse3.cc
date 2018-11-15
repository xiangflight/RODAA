#include <iostream>
#include <stack>
#include <string>

using namespace std;

// check whether two characters are of the same type
bool arePair(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    } else if (open == '[' && close == ']') {
        return true;
    } else if (open == '{' && close == '}') {
        return true;
    } else {
        return false;
    }
}

bool areParenthesisBalanced(string expression) {
    stack<char> S;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            S.push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (S.empty() || !arePair(S.top(), expression[i])) {
                return false;
            } else {
                S.pop();
            }
        }
    }
    return S.empty();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    cin >> expression;
    if (areParenthesisBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}

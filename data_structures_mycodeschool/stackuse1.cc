#include <iostream>
#include <stack> // stack from standard template library (STL)
using namespace std;

void reverse(char *C, int n) {
    stack<char> S;
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}

int main() {
    char C[51];
    cout << "Enter a string: ";
    gets(C);
    reverse(C, strlen(C));
    printf("output = %s\n", C);
    return 0;
}

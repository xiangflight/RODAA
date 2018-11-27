#include <stdio.h>

void fa(int a) {
    a++;
    printf("in function fa, a = %d\n", a);
}

void fb(int &a) {
    a++;
    printf("in function fb, a = %d\n", a);
}

int main() {
    int n = 1;
    printf("in function main, n = %d\n", n);
    fa(n);
    printf("after invoke function fa, n = %d\n", n);
    fb(n);
    printf("after invoke function fb, n = %d\n", n);
    return 0;
}

#include "c1.h"

int a(int i) {
    if (i == 1) {
        printf("exit the process");
        exit(1);
    }
    return i;
}

int main() {
    int i;
    printf("please input i: ");
    scanf("%d", &i);
    printf("a(i) = %d\n", a(i));
    return 1;
}

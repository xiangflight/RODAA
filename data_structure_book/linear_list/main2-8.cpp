#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-8.cpp"
#include "bo2-9.cpp"
#include "func2-3.cpp"

int main() {
    LinkList L;
    ElemType e, e0;
    Status i;
    int j, k;
    InitList(L);
    for (j = 1; j <= 5; j++) {
        i = ListInsert(L, 1, j);
        if (!i) {
            exit(ERROR);
        }
    }
    printf("insert 1 ～5 at the head of list: L = ");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("Is L empty: i = %d (1: Yes, 0: No)\n", i);
    ClearList(L);
    printf("After clearing, L = ");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("Is L empty: i = %d (1: Yes, 0: No)\n", i);
    for (j = 1; j <= 10; j++) {
        ListInsert(L, j, j);
    }
    printf("insert 1 ~ 10 at the end of list: L = ");
    ListTraverse(L, print);
    i = GetElem(L, 5, e);
    if (i == OK) {
        printf("value at index 5 is %d\n", e);
    }
    for (j = 0; j <= 1; j++) {
        k = LocateElem(L, j, equal);
        if (k) {
            printf("value at index %d is %d\n", k, j);
        } else {
            printf("no element equals to %d\n", j);
        }
    }
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, e0);
        i = PriorElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("element %d has no prior element\n", e0);
        } else {
            printf("prior element of %d is %d\n", e0, e);
        }
    }
    for (j = ListLength(L) - 1; j <= ListLength(L); j++) {
        GetElem(L, j, e0);
        i = NextElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("element %d has no next element\n", e0);
        } else {
            printf("next element of %d is %d\n", e0, e);
        }
    }
    k = ListLength(L);
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(L, j, e);
        if (i == ERROR) {
            printf("fail to delete element at %d index\n", j);
        } else {
            printf("success to delete element %d at %d index\n", e, j);
        }
    }
    printf("L = ");
    ListTraverse(L, print);
    DestroyList(L);
    printf("After destroying, L = %p\n", L);
    return 0;
}

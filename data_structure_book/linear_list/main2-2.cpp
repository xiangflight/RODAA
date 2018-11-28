#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

int main() {
    LinkList L;
    ElemType e, e0;
    Status i;
    int j, k;
    // init list
    InitList(L);
    // list insert
    for (j = 1; j <= 5; j++) {
        i = ListInsert(L, 1, j);
    }
    printf("insert 1 ~ 5 at the head of list: L = ");
    ListTraverse(L, print);
    // test ListEmpty and ClearList
    i = ListEmpty(L);
    printf("Is list empty: i = %d (1: Yes, 0: No)\n", i);
    ClearList(L);
    printf("After ClearList, L = ");
    ListTraverse(L, print);
    i = ListEmpty(L);
    printf("Is list empty: i = %d (1: Yes, 0: No)\n", i);
    // list insert
    for (j = 1; j <= 10; j++) {
        ListInsert(L, j, j);
    }
    printf("insert 1 ~ 10 at the end of list: L = ");
    ListTraverse(L, print);
    // GetElem
    GetElem(L, 5, e);
    printf("value at 5 index is %d\n", e);
    // LocateElem
    for (j = 0; j <= 1; j++) {
        k = LocateElem(L, j, equal);
        if (k) {
            printf("value at index %d is %d\n", k, j);
        } else {
            printf("no value equals to %d\n", j);
        }
    }
    // test PriorElem functions on pre 2 elements
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, e0);
        i = PriorElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("%d has no prior element\n", e0);
        } else {
            printf("prior element of %d is %d\n", e0, e);
        }
    } 
    // test NextElem functions on last 2 elements
    for (j = ListLength(L) - 1; j <= ListLength(L); j++) {
        GetElem(L, j, e0);
        i = NextElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("%d has no next element\n", e0);
        } else {
            printf("next element of %d is %d\n", e0, e);
        }
    }
    // test ListDelete
    k = ListLength(L);
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(L, j, e);
        if (i == ERROR) {
            printf("fail to delete element at index %d\n", j);
        } else {
            printf("success to delete element at index %d, the value is %d\n", j, e);
        }
    }
    printf("After listDelete, now L = ");
    ListTraverse(L, print);
    // destroy list
    DestroyList(L);
    printf("After destroy L, L = %p\n", L);
    return 0;
}

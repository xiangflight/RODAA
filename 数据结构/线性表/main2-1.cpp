#include "c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.cpp"
#include "func2-3.cpp"

Status sq(ElemType c1, ElemType c2) {
    if (c1 == c2 * c2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void db1(ElemType &c) {
    c *= 2;
}

int main() {
    SqList L;
    ElemType e, e0;
    Status i;
    int j, k;
    // initialization
    InitList(L);
    printf("After initialization, L.elem = %p L, L.len = %d L, L.listsize = %d\n", L.elem, L.len, L.listsize);
    // insert 5 elements
    for (j = 1; j <= 5; j++) {
        i = ListInsert(L, 1, j);
    }
    printf("insert 1 ~ 5 at the head of SqList: *L.elem = ");
    for (j = 1; j <= 5; j++) {
        cout << *(L.elem + j - 1) << " ";
    }
    cout << endl;
    printf("L.elem = %p L, L.len = %d L, L.listsize = %d\n", L.elem, L.len, L.listsize);
    // test ListEmpty and ClearList
    i = ListEmpty(L);
    printf("Is L Empty: i = %d (1: Yes, 0: No)\n", i);
    ClearList(L);
    printf("After clearing list, L.elem = %p L, L.len = %d L, L.listsize = %d\n", L.elem, L.len, L.listsize);
    i = ListEmpty(L);
    printf("Is L Empty: i = %d (1: Yes, 0: No)\n", i);
    // insert 10 elements
    for (j = 1; j <= 10; j++) {
        ListInsert(L, j, j);
    }
    printf("insert 1 ~ 10 at the end of SqList: *L.elem = ");
    for (j = 1; j <= 10; j++) {
        cout << *(L.elem + j - 1) << " ";
    }
    cout << endl;
    // insert 0 at the head, notice list is full
    ListInsert(L, 1, 0);
    printf("insert 0 at the head of SqList: *L.elem = ");
    for (j = 1; j <= ListLength(L); j++) {
        cout << *(L.elem + j - 1) << " ";
    }
    cout << endl;
    printf("L.elem = %p (maybe change) L, L.len = %d L, L.listsize = %d\n", L.elem, L.len, L.listsize);
    // get element
    GetElem(L, 5, e);
    printf("element at position 5 is %d\n", e);
    // test LocateElem
    for (j = 10; j <= 11; j++) {
        k = LocateElem(L, j, equal);
        if (k) {
            printf("element at position %d is %d\n", k, j);
        } else {
            printf("no element equals to %d\n", j);
        }
    }
    for (j = 3; j <= 4; j++) {
        k = LocateElem(L, j, sq);
        if (k) {
            printf("element at position %d is square of element %d\n", k, j);
        } else {
            printf("no element equals to square of %d\n", j);
        }
    }
    // test PriorElem
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, e0);
        i = PriorElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("%d has no prior element\n", e0);
        } else {
            printf("the prior element of %d is %d\n", e0, e);
        }
    }
    // test NextElem
    for (j = ListLength(L) - 1; j <= ListLength(L); j++) {
        GetElem(L, j, e0);
        i = NextElem(L, e0, e);
        if (i == INFEASIBLE) {
            printf("%d has no next element\n", e0);
        } else {
            printf("the next element of %d is %d\n", e0, e);
        }
    }
    // test ListDelete
    k = ListLength(L);
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(L, j, e);
        if (i == ERROR) {
            printf("fail to delete element at %d position\n", j);
        } else {
            printf("delete element at %d position, value is %d\n", j, e);
        }
    }
    // test ListTraverse
    printf("print element of L in sequence: ");
    ListTraverse(L, print1);
    printf("after doubling each element of L: ");
    ListTraverse(L, db1);
    ListTraverse(L, print1);
    // destroy
    DestroyList(L);
    printf("After Destroy, L.elem = %p L, L.len = %d L, L.listsize = %d\n", L.elem, L.len, L.listsize);
    return 0;
}

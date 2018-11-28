#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

void Union(LinkList La, LinkList Lb) {
    ElemType e;
    int La_len, Lb_len;
    int i;
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, e);
        if (!LocateElem(La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

int main() {
    LinkList La, Lb;
    int j;
    InitList(La);
    for (j = 1; j <= 5; j++) {
        ListInsert(La, j, j);
    }
    printf("La = ");
    ListTraverse(La, print);
    InitList(Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert(Lb, j, j * 2);
    }
    printf("Lb = ");
    ListTraverse(Lb, print);
    Union(La, Lb);
    printf("new la = ");
    ListTraverse(La, print);
    return 0;
}

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

void MergeList(LinkList La, LinkList Lb, LinkList &Lc) {
    int i = 1, j = 1, k = 0;
    int La_len, Lb_len;
    ElemType ai, bj;
    InitList(Lc);
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if (ai <= bj) {
            ListInsert(Lc, ++k, ai);
            ++i;
        } else {
            ListInsert(Lc, ++k, bj);
            ++j;
        }
    }
    while (i <= La_len) {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai);
    }
    while(j <= Lb_len) {
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }
}

int main() {
    LinkList La, Lb, Lc;
    int j, a[4] = {3, 5, 8, 11}, b[7] = {2, 6, 8, 9, 11, 15, 20};
    InitList(La);
    for (j = 1; j <= 4; j++) {
        ListInsert(La, j, a[j - 1]);
    }
    printf("La = ");
    ListTraverse(La, print);
    InitList(Lb);
    for (j = 1; j <= 7; j++) {
        ListInsert(Lb, j, b[j - 1]);
    }
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, Lb, Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);
    return 0;
}

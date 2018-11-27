#include "c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.cpp"
#include "func2-3.cpp"

void MergeList(SqList La, SqList Lb, SqList &Lc) {
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = La.len + Lb.len;
    pc = Lc.elem = (ElemType *) malloc(Lc.listsize * sizeof(ElemType));
    if (!pc) {
        exit(OVERFLOW);
    }
    pa_last = La.elem + La.len - 1;
    pb_last = Lb.elem + Lb.len - 1;
    while (pa <= pa_last && pb <= pb_last) {
        switch(comp(*pa, *pb)) {
            case 0:
                pb++;
            case -1:
                *pc++ = *pa++;
                break;
            case 1:
                *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
    Lc.len = pc - Lc.elem;
}

int main() {
    SqList La, Lb, Lc;
    int j;
    InitList(La);
    for (j = 1; j <= 5; j++) {
        ListInsert(La, j, j);
    }
    printf("La = ");
    ListTraverse(La, print1);
    InitList(Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert(Lb, j, 2 * j);
    }
    printf("Lb = ");
    ListTraverse(Lb, print1);
    MergeList(La, Lb, Lc);
    printf("Lc = ");
    ListTraverse(Lc, print1);
    return 0;
}

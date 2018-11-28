#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

void CreateList(LinkList &L, int n) {
    int i;
    LinkList p;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;
    printf("Please input %d numbers\n", n);
    for (i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void CreateList2(LinkList &L, int n) {
    int i;
    LinkList p, q;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;
    q = L;
    printf("Please input %d numbers\n", n);
    for (i = 1; i <= n; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        q->next = p;
        q = q->next;
    }
    p->next = nullptr;
}

void MergeList(LinkList La, LinkList &Lb, LinkList &Lc) {
    LinkList pa = La->next, pb = Lb->next, pc;
    Lc = pc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa? pa: pb;
    free(Lb);
    Lb = nullptr;
}

int main() {
    int n = 5;
    LinkList La, Lb, Lc;
    printf("Order by non-descending: ");
    CreateList2(La, n);
    printf("La = ");
    ListTraverse(La, print);
    printf("Order by non-ascending: ");
    CreateList(Lb, n);
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, Lb, Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);
    return 0;
}

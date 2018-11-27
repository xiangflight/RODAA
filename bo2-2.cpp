void InitList(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));
    if (!L) {
        exit(OVERFLOW);
    }
    L->next = nullptr;
}

void DestroyList(LinkList &L) {
    LinkList q;
    while(L) {
        q = L->next;
        free(L);
        L = q;
    }
}

void ClearList(LinkList L) {
    LinkList p, q;
    p = L->next;
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = nullptr;
}

Status ListEmpty(LinkList L) {
    if (L->next) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L->next;
    while(p) {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e) {
    int j = 1;
    LinkList p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) { // j > i may occur i <= 0
        return ERROR;
    }
    e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    int i = 0;
    LinkList p = L->next;
    while(p) {
        i++;
        if (compare(p->data, e)) {
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LinkList q, p = L->next;
    while (p->next) {
        q = p-next;
        if (q->data == cur_e) {
            pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LinkList p = L->next;
    while (p->next) {
        if (p->data == cur_e) {
            next_e = p->next->data;
            return OK;
        }
    }
    p = p->next;
}



void InsertAscend(LinkList &L, ElemType e, int (*compare)(ElemType, ElemType)) {
    LinkList q = L;
    if (!L || compare(e, L->data) <= 0) {
        ListInsert(L, 1, e);
    } else {
        while (q->next && compare(q->next->data, e) < 0) {
            q = q->next;
        }
        ListInsert(q, 2, e);
    }
}

LinkList Point(LinkList L, ElemType e, Status (*equal)(ElemType, ElemType), LinkList &p) {
    int i, j;
    i = LocateElem(L, e, equal);
    if (i) {
        if (i == 1) {
            p = nullptr;
            return L;
        }
        p = L;
        for (j = 2; j < i; j++) {
            p = p->next;
        }
        return p->next;
    }
    return nullptr;
}

Status DeleteElem(LinkList &L, ElemType &e, Status (*equal)(ElemType, ElemType)) {
    LinkList p, q;
    q = Point(L, e, equal, p);
    if (q) {
        if (p) {
            ListDelete(p, 2, e);
        } else {
            ListDelete(L, 1, e);
        }
        return TRUE;
    }
    return FALSE;
}



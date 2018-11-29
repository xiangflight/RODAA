#define DestroyList ClearList

void InitList(LinkList &L) {
    L = nullptr;
}

void ClearList(LinkList &L) {
    LinkList q;
    while (L) {
        // q = L->next;
        // free(L);
        // L = q;
        q = L;
        L = L->next;
        free(q);
    }
}

Status ListEmpty(LinkList L) {
    return L? FALSE: TRUE;
}

int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L;
    while (p) {
       i++;
       p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e) {
    int j = 1;
    LinkList p = L;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    int i = 1;
    LinkList p = L;
    while (p) {
        if (compare(p->data, e)) {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    int j = 1;
    LinkList p = L, s;
    if (i < 1) {
        return ERROR;
    }
    s = (LinkList) malloc(sizeof(ElemType));
    s->data = e;
    if (i == 1) {
        s->next = L;
        L = s;
    } else {
        while (p && j < i - 1) {
            p = p->next;
            j++;
        }
        if (!p) {
            return ERROR;
        }
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
    int j = 1;
    LinkList p = L, q;
    if (i == 1) {
        L = p->next;
        e = p->data;
        free(p);
    } else {
        while (p->next && j < i - 1) {
            p = p->next;
            j++;
        }
        if (!p->next || j > i - 1) { // guarantee i > 1 and node i exists
            return ERROR;
        }
        q = p->next;
        e = q->data;
        p->next = q->next;
        free(q);
    }
    return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType)) {
    LinkList p = L;
    while(p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

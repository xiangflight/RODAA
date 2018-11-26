void InitList(SqList &L) {
    L.elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        exit(OVERFLOW); // malloc failure
    }
    L.len = 0;
    L.listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList &L) {
    free(L.elem);
    L.elem = nullptr;
    L.len = 0;
    L.listsize = 0;
}

void ClearList(SqList &L) {
    L.len = 0;
}

Status ListEmpty(SqList L) {
    if (L.len == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(SqList L) {
    return L.len;
}

Status GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.len) {
        return ERROR;
    }
    e = *(L.elem + i - 1);
    return OK;
}

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    ElemType *p;
    int i = 1;
    p = L.elem;
    while (i <= L.len && !compare(*p, e)) {
        ++p;
        ++i;
    }
    if (i <= L.len) {
        return i;
    } else {
        return 0;
    }
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.len && *p != cur_e) {
        p++;
        i++;
    }
    if (i > L.len) {
        return INFEASIBLE;
    } else {
        pre_e = *(--p);
        return OK;
    }
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.len && *p != cur_e) {
        p++;
        i++;
    }
    if (i == L.len) {
        return INFEASIBLE;
    } else {
        next_e = *(++p);
        return OK;
    }
}

Status ListInsert(SqList &L, int i, ElemType e) {
    ElemType *newbase, *q, *p;
    if (i < 1 || i > L.len + 1) {
        return ERROR;
    }
    if (L.len >= L.listsize) { // full capacity
        if (!(newbase = (ElemType*) realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType)))) {
            exit(OVERFLOW); // realloc failure
        }
        L.elem = newbase;
        L.listsize += LIST_INCREMENT;
    }
    q = L.elem + i - 1; // insert position
    for (p = L.elem + L.len - 1; p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e; // insert e
    ++L.len;
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
    ElemType *p, *q;
    if (i < 1 || i > L.len) {
        return ERROR;
    }
    p = L.elem + i - 1;
    e = *p;
    q = L.elem + L.len - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    L.len--;
    return OK;
}

void ListTraverse(SqList L, void (*vi)(ElemType&)) {
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.len; i++) {
        vi(*p++);
    }
    printf("\n");
}


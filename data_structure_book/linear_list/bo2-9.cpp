Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LinkList p = L, q;
    while (p->next) {
        q = p->next;
        if (q->data == cur_e) {
            pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LinkList p = L, q;
    while (p->next) {
        q = p->next;
        if (p->data == cur_e) {
            next_e = q->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

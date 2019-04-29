#include "LIST_CHILD.h"

void createListChild(List_child &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_child allocatechild(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(address_child &P) {
    delete P;
    P = NULL;
}

void insertFirst(List_child &L, address_child P){
    if (first(L)==NULL) {
        first(L) = P;
        next(P) = NULL;
    }
    else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_child &L, address_child Prec, address_child P){
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
}

void insertLastChild(List_child &L, address_child P){
    if (first(L)==NULL) {
        first(L) = P;
        last(L) = P;
    }
    else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deleteChild(List_child &L, address_child &P) {
    address_child Q, R;
    if (P == first(L)) {
        if (next(P) == NULL) {
            first(L) = NULL;
        }
        else {
            Q = next(P);
            prev(Q) = NULL;
            first(L) = Q;
            next(P) = NULL;
        }
    } else {
        if (next(P) == NULL) {
            Q = prev(P);
            prev(P) = NULL;
            next(Q) = NULL;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = NULL;
            next(P) = NULL;
            next(Q) = R;
            prev(R) = Q;
        }
    }

}

void deleteFirstChild(List_child &L, address_child &P) {
    P=first(L);
    if (first(L)!=NULL){
        if (next(P)!=NULL){
            first(L)=next(P);
            prev(next(P))=NULL;
            next(P)=NULL;
        }
        else{
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}

void deleteLastChild(List_child &L, address_child &P) {
    P=last(L);
    if (P!=NULL){
            if (prev(P)!=NULL){
                last(L)=prev(P);
                prev(P)=NULL;
                next(P)=NULL;
            }
            else{
                first(L)=NULL;
                last(L)=NULL;
            }
        }
}


void deleteAfterChild(List_child &L, address_child Prec, address_child &P){
    P=next(Prec);
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
}

address_child findElmChild(List_child L, infotype_child x) {
    address_child Q = first(L);
    while ((Q!=NULL)&&info(Q)!=x) {
        Q = next(Q);
    }
    if (info(Q)==x) {
        return Q;
    }
    else {
        cout << "Stasiun Tidak Ditemukan";
    }
    return 0;
}

void printInfoChild(List_child L){
    address_child P = first(L);
    int i = 1;
    if (P!=NULL) {
        cout << "==========================" << endl;
        cout << "List Stasiun : " << endl;
            while (P!=NULL) {
                cout<<i<<". "<<info(P) << endl;
                P=next(P);
                i++;
            }
        cout << "==========================" << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}

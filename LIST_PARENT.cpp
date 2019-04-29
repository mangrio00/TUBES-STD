#include "LIST_PARENT.h"

void createListParent(List_parent &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_parent allocateparent(infotype_parent x)
{
    address_parent P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

//void deallocate(address_parent &P) {
//    delete P;
//    P = NULL;
//}

void insertFirstParent(List_parent &L, address_parent P)
{
    if (first(L)==NULL)
    {
        first(L) = P;
        next(P) = NULL;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void insertLastParent(List_parent &L, address_parent P)
{
    if (first(L)==NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void deleteParent(List_parent &L, address_parent &P)
{
    address_parent Q, R;
    if (P == first(L))
    {
        if (next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {

            Q = next(P);
            prev(Q) = NULL;
            first(L) = Q;
            next(P) = NULL;
        }
    }
    else
    {
        if (next(P) == NULL)
        {
            Q = prev(P);
            prev(P) = NULL;
            next(Q) = NULL;
        }
        else
        {
            Q = prev(P);
            R = next(P);
            prev(P) = NULL;
            next(P) = NULL;
            next(Q) = R;
            prev(R) = Q;
        }
    }

}


void deleteFirstParent(List_parent &L, address_parent &P)
{
    P=first(L);
    if (first(L)!=NULL)
    {
        if (next(P)!=NULL)
        {
            first(L)=next(P);
            prev(next(P))=NULL;
            next(P)=NULL;
        }
        else
        {
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}

void deleteLastParent(List_parent &L, address_parent &P)
{
    P=last(L);
    if (P!=NULL)
    {
        if (prev(P)!=NULL)
        {
            last(L)=prev(P);
            prev(P)=NULL;
            next(P)=NULL;
        }
        else
        {
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P)
{
    P=next(Prec);
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
}

address_parent findElmParent(List_parent L, infotype_parent x)
{
    address_parent P = first(L);
    while (info(P)!=x)
    {
        P = next(P);
    }
    if (info(P)==x)
    {
        return P;
    }
    else
    {
        cout << "Kereta Tidak Ditemukan" << endl;
    }
    return 0;
}

void printInfoParent(List_parent L)
{
    address_parent P = first(L);
    int i = 1;
    if (P != NULL)
    {
        cout << "==========================" << endl;
        cout << "List Kereta Api : " << endl;
        while (P!=NULL)
        {
            cout<<i<<". "<<info(P) << endl;
            P=next(P);
            i++;
        }
        cout << "==========================" << endl;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
}



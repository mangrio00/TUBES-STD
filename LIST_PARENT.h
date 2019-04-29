#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev

typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent
{
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct List_parent
{
    address_parent first;
    address_parent last;
};

void createListParent(List_parent &L);
address_parent allocateparent(infotype_parent x);
address_parent deallocate(address_parent &P);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteParent(List_parent &L, address_parent &P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
address_parent findElmParent(List_parent L, infotype_parent x);
void printInfoParent(List_parent L);

#endif // LIST_PARENT_H_INCLUDED

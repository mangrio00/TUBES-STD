#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef string infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child
{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child
{
    address_child first;
    address_child last;
};

void createListChild(List_child &L);
address_child allocatechild(infotype_child x);
void deallocate(address_child &P);
void insertFirst(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteChild(List_child &L, address_child &P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(address_child Prec, address_child &P);
address_child findElmChild(List_child L, infotype_child x);
void printInfoChild(List_child L);

#endif // LIST_CHILD_H_INCLUDED

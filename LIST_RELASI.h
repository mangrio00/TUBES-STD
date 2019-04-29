#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
    address_relasi last;
};

void createListRelasi(List_relasi &L);
address_relasi allocaterelasi( address_parent P, address_child C);
void deallocate(address_relasi &P);
void insertFirst(List_relasi &L, address_relasi P);
void insertLastRelasi(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirstRelasi(List_relasi &L, address_relasi &P);
void deleteLastRelasi(List_relasi &L, address_relasi &P);
void deleteAfterRelasi(address_relasi Prec, address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfoRelasi(List_relasi L);
void showStasiun (List_relasi L, string kereta);
bool starred(address_child C, address_parent P, List_relasi L);
void duakaliStasiun(List_parent P, List_relasi R, List_child C);
int jumlahKereta(address_child Q, List_relasi L);
void stasiunTerbanyak(List_child L, List_relasi R);
int jumlahStasiun(address_child Q, List_relasi L);
void keretaTerbanyak(List_parent L, List_relasi R);

#endif // LIST_RELASI_H_INCLUDED

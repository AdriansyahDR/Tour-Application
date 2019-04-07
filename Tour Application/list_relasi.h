#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct infotype_relasi {
    int biaya,jumanggota;
    string waktukeb;
};

struct elmlist_relasi{
    infotype_relasi info;
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P);


/** PERLU MODIFIKASI */
address_relasi alokasiR( address_parent P, address_child C);
void dealokasi(address_relasi &P);
void printInfo(List_relasi L);
void inputChild(List_parent L, address_child &Q,address_relasi &R);
void cariTujuan(List_parent L, infotype_relasi &y, infotype_child &x, address_parent &P, string tujuan);
void inputCustomerLama(List_parent L, List_child LC, address_relasi &R);
void searchCustomer(List_relasi L);
void deleteRelasi(List_relasi &L, address_parent P, address_child C);
void deleteR(List_relasi &L, address_relasi R);

#endif // LIST_RELASI_H_INCLUDED

#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include "list_parent.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct elmlist_child *address_child;

struct infotype_child {
    string Nama;
    int budget,ID;
};

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct List_child{
    address_child first;
    address_child last;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);


/** PERLU MODIFIKASI */
address_child alokasiC(infotype_child x);
void dealokasi(address_child &P);
void printInfo(List_child L);
address_child checkName(List_child LC, string nama);
void deleteCostumer(List_child &L, string nama, address_child &P);
void deleteC(List_child &L, address_child &P);

#endif // LIST_CHILD_H_INCLUDED

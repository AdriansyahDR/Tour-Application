#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

typedef struct elmlist_parent *address_parent;

struct infotype_parent {
    string kota;
    string tpariwisata;
    int count,harga,pendapatan;
};

struct elmlist_parent {
    infotype_parent info;
    address_parent next,prev;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);


/** PERLU MODIFIKASI */
address_parent alokasiP(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElmkota(List_parent L, string x);
infotype_parent input(List_parent L);
void printInfoP(List_parent L);
void findKota(List_parent L);
void deleteParent(List_parent &L, string kota, address_parent &P);
void deleteP(List_parent &L, address_parent &P);
address_parent findElmPariwisata(List_parent L, string x);
void terlarisP(List_parent L);

#endif // LIST_PARENT_H_INCLUDED

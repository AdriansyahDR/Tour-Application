#include "list_parent.h"


void createList(List_parent &L) {
    /**
    * FS : first(L) diset NULL
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasiP(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = NULL
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLast(List_parent &L, address_parent P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else if(next(first(L)) == NULL) {
        next(first(L)) = P;
        prev(P) = first(L);
        last(L) = P;
    } else {
        prev(P) = last(L) ;
        next(last(L)) = P;
        last(L) = P;
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P) {
    if(first(L) == NULL) {
        insertFirst(L,P);
    } else if(next(first(L)) == NULL) {
        next(first(L)) = P;
        prev(P) = first(L);
        last(L) = P;
    } else {
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
    }
}
void deleteFirst(List_parent &L, address_parent &P) {
    if(first(L) == NULL) {
        cout<< "kosong";
    } else if(next(first(L)) == NULL) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P) {
    if (first(L) == NULL) {
        cout<< "kosong";
    }else if(next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = last(L);
        last(L) = prev(P);
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P) {
    if(first(L) == NULL) {
        cout<< "kosong";
    } else if(next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = NULL;
        next(P) = NULL;
    }
}
void printInfoP(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P ;
    system("CLS");
    cout<<"============= DATA PARIWISATA ============"<<endl;
    cout<<endl;
    if(first(L)!=NULL) {
        P = first(L);
        cout<<" Kota - Tempat Pariwisata - Harga - Pendapatan - Banyak Pengunjung"<<endl;
        cout<<endl;
        while(P!=NULL) {
            cout<<info(P).kota<<" - ";
            cout<<info(P).tpariwisata<<" - Rp.";
            cout<<info(P).harga<<" - Rp.";
            cout<<info(P).pendapatan<<" - ";
            cout<<info(P).count<<" orang"<<endl;
            P = next(P);
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
    cout<<endl;
    system("PAUSE");
}

address_parent findElmkota(List_parent L, string x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan NULL jika tidak ditemukan
    */
    address_parent P = first(L);
    if(first(L)!=NULL){
        while((P != NULL)&&(info(P).kota != x)) {
            P = next(P);
        }
        if(info(P).kota == x) {
            return P;
        }else{
            return NULL;
        }
    }
}
address_parent findElmPariwisata(List_parent L, string x){
    address_parent P = NULL;
    if(first(L)!=NULL){
        P = first(L);
        while((P != NULL)&&(info(P).tpariwisata != x)) {
            P = next(P);
        }
        return P;
    }else{
        return NULL;
    }
}
infotype_parent input(List_parent L) {
    infotype_parent x;
    address_parent P;
    system("CLS");
    cout<<"============ INPUT PARIWISATA ============"<<endl;
    cin.ignore();
    cout<<"Nama Kota : ";getline(cin,x.kota);
    cout<<"Nama Tempat Pariwisata   : ";getline(cin,x.tpariwisata);
    P = findElmPariwisata(L,x.tpariwisata);
    while(P!=NULL){
        cout<<"Tempat Pariwisata telah ada, silahkan input Tempat Pariwisata lain."<<endl;
        cout<<"Nama Tempat Pariwisata   : ";getline(cin,x.tpariwisata);
        P = findElmPariwisata(L,x.tpariwisata);
    }
    x.pendapatan = 0;
    cout<<"Harga per orang          : ";cin>>x.harga;
    while(x.harga<0){
        cout<<"Harga per orang          : ";cin>>x.harga;
    }
    x.count = 0;
    cout<<endl;
    cout<<"Tempat Pariwisata telah berhasil di input."<<endl;
    system("PAUSE");
    return x;
}
void findKota(List_parent L){
    address_parent P;
    int i = 0;
    string kota;
    system("CLS");
    cout<<"=============== SEARCH KOTA =============="<<endl;
    cout<<endl;
    if (first(L)!=NULL){
        cin.ignore();
        cout<<"Input Kota : ";getline(cin,kota);
        P = first(L);
        while(P!=NULL){
            if(info(P).kota==kota){
                i = i + 1;
                cout<<i<<". "<<info(P).kota<<" - "<<info(P).tpariwisata<<endl;
            }
            P = next(P);
        }
        if(i==0){
            cout<<kota<<" Tidak Ada Dalam List"<<endl;
        }
        system("PAUSE");
    }else{
        cout<<"Data Kota Belum diinputkan."<<endl;
        cout<<endl;
        system("PAUSE");
    }
}
void deleteParent(List_parent &L, string pariwisata, address_parent &P){
    if(first(L)!=NULL){
        P = findElmPariwisata(L,pariwisata);
        if(P!=NULL){
            deleteP(L,P);
            cout<<"Data Telah Dihapus."<<endl;
        }else{
            cout<<"Data Tidak Ditemukan."<<endl;
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
    system("PAUSE");
}
void deleteP(List_parent &L, address_parent &P){
    address_parent Prec;
    if (P==first(L)){
        deleteFirst(L,P);
    }else if(next(P)==NULL){
        deleteLast(L,P);
    }else{
        Prec = prev(P);
        deleteAfter(L,Prec,P);
    }
}
void terlarisP(List_parent L){
    address_parent P,Q;
    if (first(L)!=NULL){
        P = first(L);
        Q = first(L);
        while (P!=NULL){
            if(info(Q).count<info(P).count){
                Q = P;
            }
            P = next(P);
        }
    }
    cout<<"Tempat Pariwisata "<<info(Q).tpariwisata<<" merupakan tempat "<<endl;
    cout<<"pariwisata yang paling sering dikunjungi "<<endl;
    cout<<"dengan harga tiket Rp. "<<info(Q).harga<<endl;
}

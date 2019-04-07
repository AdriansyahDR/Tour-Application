#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasiC(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
        next(P) = P;
    } else {
        next(P) = first(L);
        next(last(L)) = P;
        first(L) = P;
    }
}
void insertLast(List_child &L, address_child P){
    if(first(L)==NULL){
        first(L) = P;
        last(L) = P;
        next(P) = P;
    }else{
        next(last(L)) = P;
        next(P) = first(L);
        last(L) = P;
    }
}
void insertAfter(List_child &L, address_child Prec, address_child P){
    if (first(L)==NULL){
        first(L) = P;
        last(L) = P;
        next(P) = P;
    }else if (next(Prec)== first(L)){
        insertLast(L,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void deleteFirst(List_child &L, address_child &P){
    if(first(L)==NULL){

    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(last(L)) = first(L);
        next(P) = NULL;
    }
}
void deleteLast(List_child &L, address_child &P){
    if (first(L)==NULL){

    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        while (next(P)!=last(L)){
            P = next(P);
        }
        last(L) = P;
        P = next(last(L));
        next(last(L))= first(L);
        next(P) = NULL;
    }
}
void deleteAfter(List_child &L, address_child Prec, address_child &P){
    if (first(L)==NULL){

    }else if((next(first(L))== first(L))||(next(Prec)==first(L))){
        deleteFirst(L,P);
    }else if(next(Prec)==last(L)){
        deleteLast(L,P);
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void printInfo(List_child L) {
    address_child P = first(L);
    system("CLS");
    cout<<"============== DATA CUSTOMER ============="<<endl;
    cout<<endl;
    if (first(L)!=NULL){
        cout<<" Nama - ID - Budget"<<endl;
        cout<<endl;
        while(next(P) != first(L)) {
            cout<<""<<info(P).Nama<<" - ";
            cout<<""<<info(P).ID<<" - Rp.";
            cout<<""<<info(P).budget;
            cout<<endl;
            P = next(P);
        }
        cout<<""<<info(P).Nama<<" - ";
        cout<<""<<info(P).ID<<" - Rp.";
        cout<<""<<info(P).budget;
        cout<<endl;
    }else{
        cout<<"Data Kosong"<<endl;
    }
    cout<<endl;
    system("PAUSE");
}
void insertAfter(address_child &Prec, address_child P) {
    next(P) = next(Prec);
    next(Prec) = P;
}
address_child checkName(List_child LC, string nama){
    address_child D;
    if(first(LC)!=NULL){
        D = first(LC);
        while((next(D)!=first(LC))&&(info(D).Nama != nama)){
            D = next(D);
        }
        if(info(D).Nama == nama){
            return D;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}
void deleteCostumer(List_child &L, string nama, address_child &P){
    if (first(L)!=NULL){
        P = checkName(L,nama);
        if(P!=NULL){
            if(info(P).Nama == nama){
                deleteC(L,P);
                cout<<"Data Telah Terhapus."<<endl;
            }
        }else{
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
    system("PAUSE");
}
void deleteC(List_child &L, address_child &P){
    address_child Prec;
    if (P==first(L)){
        deleteFirst(L,P);
    }else if(next(P)==last(L)){
        deleteLast(L,P);
    }else{
        Prec = first(L);
        while(next(Prec)!=P){
            Prec = next(Prec);
        }
        deleteAfter(L,Prec,P);
    }
}

#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasiR(address_parent P, address_child C, infotype_relasi x) {
    address_relasi Q = new elmlist_relasi;
    info(Q) = x;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertLast(List_relasi &L, address_relasi P) {
    address_relasi Q;
    if(first(L) == NULL) {
        insertFirst(L,P);
    }else {
        Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P) {
    if((first(L) != NULL) && (Prec != NULL)) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void deleteFirst(List_relasi &L, address_relasi &P) {
    if(first(L) != NULL) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }else if(next(first(L))==NULL){
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    }
    parent(P) = NULL;
    child(P) = NULL;
}
void deleteLast(List_relasi &L, address_relasi &P) {
    address_relasi Q;
    if(first(L) != NULL) {
        Q = first(L);
        if(next(Q) == NULL) {
            deleteFirst(L,P);
        } else {
            while (next(next(Q)) != NULL ) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
            next(P) = NULL;
            parent(P) = NULL;
            child(P) = NULL;
        }
    }
}
void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P){
    if(first(L) == NULL) {
        cout<< "kosong";
    } else if(next(first(L)) == NULL) {
        deleteFirst(L,P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
        parent(P) = NULL;
        child(P) = NULL;
    }
}
void printInfo(List_relasi L) {
    address_relasi P = first(L);
    system("CLS");
    cout<<"=============== DATA RELASI =============="<<endl;
    cout<<endl;
    if (first(L)!=NULL){
    cout<<" Nama Customer - Kota - Tempat Pariwisata"<<endl;
    cout<<" Waktu Keberangkatan - Banyak Anggota - Biaya"<<endl;
    cout<<endl;
        while(P !=NULL) {
            cout<<info(child(P)).Nama<<"->"<<info(parent(P)).kota<<"->"<<info(parent(P)).tpariwisata<<endl;
            cout<<info(P).waktukeb<<" - "<<info(P).jumanggota<<" orang - Rp."<<info(P).biaya<<endl;
            cout<<endl;
            P = next(P);
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
    system("PAUSE");
}
void deleteRelasi(List_relasi &L, address_parent P, address_child C){
    address_relasi R,Q;
    int i = 0;
    if((first(L)!=NULL)&&(P!=NULL)&&(C!=NULL)){
        R = first(L);
        while(R!=NULL){
            if((info(parent(R)).tpariwisata==info(P).tpariwisata)&&(info(child(R)).Nama==info(C).Nama)){
                deleteR(L,R);
                i = i+1;
            }
            R = next(R);
        }
        if(i!=0){
            cout<<"Data Telah Dihapus."<<endl;
        }else{
            cout<<"Data Tidak Ditemukan"<<endl;
        }
        cout<<endl;
        system("PAUSE");
    }else if((P!=NULL)&&(C==NULL)){
        R = first(L);
        while(R!=NULL){
            if(info(parent(R)).tpariwisata==info(P).tpariwisata){
                Q = R;
                R = next(R);
                deleteR(L,Q);
            }else{
                R = next(R);
            }
        }
    }else if((P==NULL)&&(C!=NULL)){
        R = first(L);
        while(R!=NULL){
            if(info(child(R)).Nama==info(C).Nama){
                Q = R;
                R= next(R);
                deleteR(L,Q);
            }else{
                R = next(R);
            }
        }
    }else{
        cout<<"Data Tidak Ditemukan"<<endl;
        cout<<endl;
        system("PAUSE");
    }
}
void deleteR(List_relasi &L, address_relasi R){
    address_relasi Prec;
    if(R==first(L)){
        deleteFirst(L,R);
    }else if(next(R)==NULL){
        deleteLast(L,R);
    }else{
        Prec = first(L);
        while(next(Prec)!=R){
            Prec = next(Prec);
        }
        deleteAfter(L,Prec,R);
    }
}
void cariTujuan(List_parent L,infotype_relasi &y, infotype_child &x, address_parent &P, string tujuan){
    bool stat = false;
    while ((stat == false)&&(tujuan != "exit")) {
            P = first(L);
            while ((P!=NULL)&&(info(P).tpariwisata!=tujuan)) {
                P = next(P);
            }
            if (P!=NULL){
                if (info(P).tpariwisata == tujuan) {
                    if (x.budget>=(info(P).harga*y.jumanggota)) {
                        x.budget = x.budget - (info(P).harga*y.jumanggota);
                        info(P).pendapatan = info(P).pendapatan + (info(P).harga*y.jumanggota);
                        info(P).count = info(P).count + y.jumanggota;
                        y.biaya = info(P).harga*y.jumanggota;
                        stat = true;
                    }else{
                        cin.ignore();
                        cout<<"Budget tidak mencukupi, silahkan pilih tempat wisata lain"<<endl;
                        cout<<"(Silahkan ketik 'exit' jika ada kesalahan dan lakukan input ulang)"<<endl;
                        cout<<"Tempat Pariwisata : ";getline(cin,tujuan);
                        P = NULL;
                    }
                }
            }else{
                cout<<endl;
                cout<<"Tempat Pariwisata tidak ditemukan, silahkan pilih tempat wisata kembali"<<endl;
                cout<<"Tempat Pariwisata : ";getline(cin,tujuan);
            }
        }
}

void inputChild(List_parent L, address_child &Q, address_relasi &R) {
    infotype_child x;
    infotype_relasi y;
    address_parent P;
    string tujuan;
    cin.ignore();
    system("CLS");
    Q = NULL;
    R = NULL;
    if (first(L)!=NULL){
        cout<<"================ PEMESANAN ==============="<<endl;
        cout<<"Nama             : ";getline(cin,x.Nama);
        cout<<"ID               : ";cin>>x.ID;
        while(x.ID<0){
            cout<<"ID               : ";cin>>x.ID;
        }
        cout<<"Banyak Anggota   : ";cin>>y.jumanggota;
        while(y.jumanggota<1){
               cout<<"Banyak Anggota   : ";cin>>y.jumanggota;
            }
        cout<<"Budget           : ";cin>>x.budget;
        while(x.budget<0){
                cout<<"Budget           : ";cin>>x.budget;
            }
        cin.ignore();
        cout<<"Tgl/Bln/Tahun    : ";getline(cin,y.waktukeb);
        cout<<endl;
        cout<<"Tempat Pariwisata Tujuan"<<endl;
        cout<<"========================"<<endl;
        P = first(L);
        while (P!=NULL) {
            cout<<info(P).kota<<"-"<<info(P).tpariwisata<<endl;
            P = next(P);
        }
        cout<<endl;
        cout<<"Tempat Pariwisata : ";getline(cin,tujuan);
        cariTujuan(L, y, x, P, tujuan);
        if (P!=NULL) {
            Q = alokasiC(x);
            R = alokasiR(P,Q,y);
            cout<<endl;
            cout<<"Pemesanan Berhasil"<<endl;
            system("PAUSE");
        }
    }else{
        cout<<"Maaf, Data Pariwisata Belum Diinputkan."<<endl;
        system("PAUSE");
    }
}
void inputCustomerLama(List_parent L, List_child LC, address_relasi &R){
    infotype_child x;
    infotype_relasi y;
    address_parent P;
    address_child C;
    string tujuan;
    cin.ignore();
    system("CLS");
    R = NULL;
    if (first(L)!=NULL){
        cout<<"================ PEMESANAN ==============="<<endl;
        cout<<"Nama             : ";getline(cin,x.Nama);
        C = checkName(LC,x.Nama);
        if(C != NULL){
            cout<<"Banyak Anggota   : ";cin>>y.jumanggota;
            while(y.jumanggota<1){
               cout<<"Banyak Anggota   : ";cin>>y.jumanggota;
            }
            cout<<"Budget           : ";cin>>x.budget;
            while(x.budget<0){
                cout<<"Budget           : ";cin>>x.budget;
            }
            x.budget = info(C).budget + x.budget;
            cin.ignore();
            cout<<"Tgl/Bln/Tahun    : ";getline(cin,y.waktukeb);
            cout<<endl;
            cout<<"Tempat Pariwisata Tujuan"<<endl;
            cout<<"========================"<<endl;
            P = first(L);
            while (P!=NULL) {
                cout<<info(P).kota<<"-"<<info(P).tpariwisata<<endl;
                P = next(P);
            }
            cout<<endl;
            cout<<"Tempat Pariwisata : ";getline(cin,tujuan);
            cariTujuan(L, y, x, P, tujuan);
            info(C).budget = x.budget;
            if (P!=NULL) {
                R = alokasiR(P,C,y);
                cout<<endl;
                cout<<"Pemesanan Berhasil"<<endl;
                system("PAUSE");
            }
        }else if (C == NULL){
            cout<<"Nama Tidak Ditemukan"<<endl;
            system("PAUSE");
        }
    }else{
        cout<<"Maaf, Data Pariwisata Belum Diinputkan."<<endl;
        system("PAUSE");
    }
}
void searchCustomer(List_relasi L){
    address_relasi P;
    string nama;
    int i = 0;
    system("CLS");
    cout<<"============ SEARCH CUSTOMER ============="<<endl;
    cout<<endl;
    if (first(L)!=NULL){
        cin.ignore();
        cout<<"Input Nama : ";getline(cin,nama);
        cout<<endl;
        P = first(L);
        while (P!=NULL){
            if (info(child(P)).Nama == nama) {
                i = i + 1;
                cout<<i<<". "<<info(child(P)).Nama<<" -> "<<info(parent(P)).kota<<" -> "<<info(parent(P)).tpariwisata<<endl;
            }
            P = next(P);
        }
    }else{
        cout<<"Data Customer Belum diinputkan."<<endl;
        cout<<endl;
    }
    system("PAUSE");
}

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"


int main()
{

    List_parent LP;
    List_child LC;
    List_relasi LR;
    address_child C;
    address_parent P;
    address_relasi R;
    string cari,i;

    createList(LP);
    createList(LC);
    createList(LR);

    /** MENU */
    while (i!="6") {
        system("CLS");
        cout<<"             APLIKASI PARIWISATA          "<<endl;
        cout<<"=========================================="<<endl;
        if((first(LP)!=NULL)&&(first(LC)!=NULL)){
            terlarisP(LP);
            cout<<"=========================================="<<endl;
        }
        cout<<"=1. Input Kota                           ="<<endl;
        cout<<"=2. Input Pemesanan                      ="<<endl;
        cout<<"=3. Data                                 ="<<endl;
        cout<<"=4. Searching                            ="<<endl;
        cout<<"=5. Delete                               ="<<endl;
        cout<<"=6. Exit                                 ="<<endl;
        cout<<"=========================================="<<endl;
        cout<<"=Pilih : ";cin>>i;
        cout<<endl;
        if (i=="1") {
           P = alokasiP(input(LP));
           if (P!=NULL){
               insertFirst(LP,P);
           }
           cout<<endl;
        }else if (i=="2") {
            i = "0";
            while (i!="3"){
                system("CLS");
                cout<<"= Menu >> Pemesanan                      ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"================ PEMESANAN ==============="<<endl;
                cout<<"=1. Costumer Baru                        ="<<endl;
                cout<<"=2. Costumer Lama                        ="<<endl;
                cout<<"=3. Back                                 ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"=Pilih : ";cin>>i;
                if (i=="1"){
                    inputChild(LP,C,R);
                    if((C!=NULL)&&(R!=NULL)){
                        insertFirst(LC,C);
                        insertFirst(LR,R);
                    }
                }else if(i=="2"){
                    inputCustomerLama(LP,LC,R);
                    if(R!=NULL){
                        insertFirst(LR,R);
                    }
                }
            }
            cout<<endl;
        }else if (i=="3"){
            i = "0";
            while (i!="4"){
                system("CLS");
                cout<<"= Menu >> Data                           ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"================== DATA =================="<<endl;
                cout<<"=1. Data Pariwisata                      ="<<endl;
                cout<<"=2. Data Costumer                        ="<<endl;
                cout<<"=3. Data Relasi                          ="<<endl;
                cout<<"=4. Back                                 ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"=Pilih : ";cin>>i;
                if (i=="1"){
                    printInfoP(LP);
                    cout<<endl;
                }else if(i=="2"){
                    printInfo(LC);
                    cout<<endl;
                }else if(i=="3"){
                    printInfo(LR);
                    cout<<endl;
                }
            }
            cout<<endl;
        }else if (i=="4"){
            i = "0";
            while(i!="3"){
                system("CLS");
                cout<<"= Menu >> Searching                      ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"================ SEARCHING ==============="<<endl;
                cout<<"=1. Search Kota                          ="<<endl;
                cout<<"=2. Search Customer                      ="<<endl;
                cout<<"=3. Back                                 ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"=Pilih : ";cin>>i;
                if(i=="1"){
                    findKota(LP);
                }else if(i=="2"){
                    searchCustomer(LR);
                }
            }
            cout<<endl;
        }else if(i=="5"){
            i = "0";
            while(i!="4"){
                system("CLS");
                cout<<"= Menu >> Delete                         ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"================= DELETE ================="<<endl;
                cout<<"=1. Delete Tempat Pariwisata             ="<<endl;
                cout<<"=2. Delete Customer                      ="<<endl;
                cout<<"=3. Delete Relasi                        ="<<endl;
                cout<<"=4. Back                                 ="<<endl;
                cout<<"=========================================="<<endl;
                cout<<"=Pilih : ";cin>>i;
                if(i=="1"){
                    C = NULL;
                    cout<<endl;
                    cout<<"Tempat Pariwisata yang ingin dihapus : ";cin>>cari;
                    deleteParent(LP,cari,P);
                    if(P!=NULL){
                        deleteRelasi(LR,P,C);
                    }
                }else if(i=="2"){
                    P = NULL;
                    cout<<endl;
                    cout<<"Customer yang ingin dihapus : ";cin>>cari;
                    deleteCostumer(LC,cari,C);
                    if(C!=NULL){
                        deleteRelasi(LR,P,C);
                    }
                }else if(i=="3"){
                    cout<<endl;
                    cout<<"Nama Customer : ";cin>>cari;
                    C = checkName(LC,cari);
                    cout<<"Tujuan Pariwisata : ";cin>>cari;
                    P = findElmPariwisata(LP,cari);
                    if(((P!=NULL)&&(C!=NULL))||((P==NULL)&&(C==NULL))){
                        deleteRelasi(LR,P,C);
                    }
                }
            }
        }
    }
    return 0;
}

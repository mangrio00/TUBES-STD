#include "LIST_RELASI.h"
#include "LIST_CHILD.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_relasi allocaterelasi( address_parent x, address_child y) {
    address_relasi P = new elmlist_relasi;
    parent(P) = x;
    child(P) = y;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(address_relasi &P) {
    delete P;
    P = NULL;
}

void insertFirst(List_relasi &L, address_relasi P){
    if (first(L)==NULL) {
        first(L) = P;
        next(P) = NULL;
    }
    else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P){
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
}

void insertLastRelasi(List_relasi &L, address_relasi P){
    if (first(L)==NULL) {
        first(L) = P;
        last(L) = P;
    }
    else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &P) {
    P=first(L);
    if (first(L)!=NULL){
        if (next(P)!=NULL){
            first(L)=next(P);
            prev(next(P))=NULL;
            next(P)=NULL;
        }
        else{
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}

void deleteRelasi(List_relasi &L, address_relasi &P) {

}
void deleteLastRelasi(List_relasi &L, address_relasi &P) {
    P=last(L);
    if (last(L)!=NULL){
            if (prev(P)!=NULL){
                last(L)=prev(P);
//                prev(P)=NULL;
//                next(P)=NULL;
            }
            else{
                first(L)=NULL;
                last(L)=NULL;
            }
        }
}


void deleteAfterRelasi(List_relasi &L, address_relasi Prec, address_relasi &P){
    P=next(Prec);
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
}

//address_relasi findElmRelasi(List_relasi L, address_parent A, address_child C) {
//    address_relasi P = first(L);
//    while (P!=NULL) {
//        if (next(P)!=NULL) {
//            if ((child(P)==C)&&(parent(P)==A)) {
//                address Q = next(P);
//                next(prev(P))=Q;
//                prev(Q)=prev(P);
//            }
//            P=next(P):
//        }
//        else {
//            P=NULL;
//        }
//    }
//    return P;
//}

void showStasiun(List_relasi L, string kereta) {
    address_relasi P = first(L);
    bool flag = false;
    while (P!=NULL) {
        if (info(parent(P)) == kereta) {
            flag = true;
            cout << "Daftar Stasiun : " << endl;
            cout << info(child(P)) << endl;
        }
        P = next(P);
    }
    if (!flag) {
        cout << "Tidak ada Stasiun yang dituju" << endl;
    }
}


void printInfoRelasi(List_relasi L){
    address_relasi P = first(L);
    int i = 1;
    if (P != NULL) {
        cout << "==========================" << endl;
        cout << "List Relasi : " << endl;
            while (P!=NULL) {
                cout<<i<<". "<<info(child(P)) <<" di Tuju oleh Kereta "<<info(parent(P))<< endl;
                P=next(P);
                i++;
            }
        cout << "==========================" << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}

bool starred(address_child C, address_parent P, List_relasi L){
    address_relasi U = first(L);
    while (U!=NULL) {
        if ((child(U)==C)&&(parent(U)==P)) {
            return true;
        }
        U = next(U);
    }
    return false;
}

void duakaliStasiun(List_parent P, List_relasi R, List_child C){
    address_parent A= first(P);
    address_parent B = next(A);
    address_child D;
    int n = 0;
    while (B!=NULL) {
        D = first(C);
        while ((D!=NULL)&&(n!=2)) {
            if (starred(D,A,R)&&(starred(D,B,R))){
                n++;
            }
            D=next(D);
        }
        if (n==2) {
            cout << info(A)<<" dan "<<info(B)<<" pernah mengunjungi dua stasiun yang sama "<<endl;
            n=0;
        }
        A=next(A);
        B=next(B);
    }
}

int jumlahKereta(address_child Q, List_relasi L){
    // jumlah kereta dari suatu stasiun yang dituju
    address_relasi P = first(L);
    int i = 0;
    while (P!=NULL) {
        if (info(child(P))==info(Q)) {
            i++;
        }
        P = next(P);
    }
    return i;
}

void stasiunTerbanyak(List_child L, List_relasi R){
    address_child Q,P = first(L);
    int maks = 0;
    if (P==NULL) {
        cout << "list kosong" << endl;
    }
    else {
        while (P!=NULL) {
            if (maks<jumlahKereta(P, R)) {
                maks = jumlahKereta(P,R);
                Q = P;
            }
            P = next(P);
        }
        cout <<"Stasiun dengan jumlah Kereta terbanyak yaitu "<<info(Q)<<" dengan jumlah Kereta "<<maks<< endl;
    }
}

int jumlahStasiun(address_parent Q, List_relasi L){
    address_relasi P = first(L);
    int i = 0;
    while (P!=NULL) {
        if (info(parent(P))==info(Q)) {
            i++;
        }
        P = next(P);
    }
    return i;
}

void aktorTerbanyak(List_parent L, List_relasi R){
    address_parent Q,P = first(L);
    int maks = 0;
    if (P == NULL) {
        cout << "list kosong" << endl;
    }
    else {
        while (P!=NULL) {
            if (maks<jumlahStasiun(P, R)) {
                maks = jumlahStasiun(P,R);
                Q = P;
            }
            P = next(P);
        }
        cout <<"Kereta yang paling sering menuju Stasiun tertentu "<<info(Q)<<" dengan jumlah  "<<maks<< endl;
    }
}

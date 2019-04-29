#include "LIST_RELASI.h"
#include "LIST_CHILD.h"
#include "LIST_PARENT.h"
#include <windows.h>
int main()
{
    int n;
    List_child stasiun;
    List_parent kereta;
    List_relasi rel;
    createListParent(kereta);
    createListChild(stasiun);
    createListRelasi(rel);
    insertLastParent(kereta,allocateparent("Argo Parahyangan"));
    insertLastParent(kereta,allocateparent("Argo Wilis"));
    insertLastParent(kereta,allocateparent("Cirebon Ekspress"));
    insertLastParent(kereta,allocateparent("Cimahi Ekspress"));
    insertLastChild(stasiun,allocatechild("Stasiun Bandung"));
    insertLastChild(stasiun,allocatechild("Stasiun Ciroyom"));
    insertLastChild(stasiun,allocatechild("Stasiun Kiaracondong"));
    insertLastChild(stasiun,allocatechild("Stasiun Gedebage"));
    insertLastChild(stasiun,allocatechild("Stasiun Gambir"));
    do
    {

        cout << "========================================== MENU ==========================================" << endl;
        cout << "   ====================================================================================" << endl;
        cout << " || 1. Menambahkan Kereta Api Baru                                                     ||" << endl;
        cout << " || 2. Tampilkan Daftar Kereta Api                                                     ||" << endl;
        cout << " || 3. Menambahkan Stasiun Baru                                                        ||" << endl;
        cout << " || 4. Tampilkan Daftar Stasiun                                                        ||" << endl;
        cout << " || 5. Menambahkan Hubungan Antara Kereta Api dan Stasiun                              ||" << endl;
        cout << " || 6. Menampilkan Hubungan Antara Kereta Api dan Stasiun                              ||" << endl;
        cout << " || 7. Menghapus Hubungan Antara Kereta Api dan Stasiun                                ||" << endl;
        cout << " || 8. Menghapus List Kereta Api                                                       ||" << endl;
        cout << " || 9. Menghapus Stasiun Tertentu                                                      ||" << endl;
        cout << " || 10. Menampilkan Semua Stasius yang Pernah Dituju Kereta Api Tertentu               ||" << endl;
        cout << " || 11. Menampilkan Dua Kereta yang Pernah menuju Dua Stasiun yang Sama                ||" << endl;
        cout << " || 12. Menampilkan Stasiun yang Paling Banyak Dikunjungi                              ||" << endl;
        cout << " || 13. Menampilkan Kereta Api yang Paling Sering Mengunjungi Stasiun Tertentu         ||" << endl;
        cout << " || 0. Keluar                                                                          ||" << endl;
        cout << "   ====================================================================================" << endl;
        cout << endl;
        cout << " Ketik Pilihan Anda : ";
        cin >> n;
        cout << endl;
        switch(n)
        {
        case 1 :
        {
            system("cls");
            char krl[100];
            cout << "Masukan Nama Kereta Api : ";
            cin.ignore();
            cin.getline(krl, 100);
            address_parent P = allocateparent(krl);
            insertLastParent(kereta, P);
            break;
        }
        case 2 :
        {
            system("cls");
            printInfoParent(kereta);
            break;
        }
        case 3 :
        {
            system("cls");
            char stas[100];
            cout << "Masukan Nama Stasiun : ";
            cin.ignore();
            cin.getline(stas, 100);
            address_child P = allocatechild(stas);
            insertLastChild(stasiun, P);
            break;
        }
        case 4 :
        {
            system("cls");
            printInfoChild(stasiun);
            break;
        }
        case 5 :
        {
            system("cls");
            printInfoParent(kereta);
            char krl[100];
            cout << "Ketik Nama Kereta: ";
            cin.ignore();
            cin.getline(krl,100);
            address_parent P = findElmParent(kereta, krl);
            printInfoChild(stasiun);
            char stas[100];
            cout << "Ketik Nama Stasiun: ";
            cin.getline(stas, 100);
            address_child Q = findElmChild(stasiun, stas);
            address_relasi R = allocaterelasi(P, Q);
            insertLastRelasi(rel, R);
            cout << "Relasi Berhasil Dibuat" << endl;
            break;
        }
        case 6 :
        {
            system("cls");
            printInfoRelasi(rel);
            break;
        }
        case 7 :
        {
            string pilih;
            printInfoRelasi(rel);
            cout << "Hapus first / after / last ?" << endl;
            cin >> pilih;
            if (pilih == "first")
            {
                address_relasi P = first(rel);
                deleteFirstRelasi(rel, P);
                cout << "Relasi berhasil dihapus" << endl;
                printInfoRelasi(rel);
            }
            break;
        }

        case 8 :
        {
            system("cls");
            printInfoParent(kereta);
            char krl[100];
            cout << "Masukan Nama Kereta Api : "<<endl;
            cin.ignore();
            cin.getline(krl,100);
            address_parent P = findElmParent(kereta, krl);
            deleteParent(kereta, P);
            break;
        }
        case 9 :
        {
            system("cls");
            printInfoChild(stasiun);
            char stas[100];
            cout << "Masukan Nama Stasiun : "<<endl;
            cin.ignore();
            cin.getline(stas,100);
            address_child P = findElmChild(stasiun, stas);
            deleteChild(stasiun, P);
            break;
        }
        case 10 :
        {
            system("cls");
            printInfoParent(kereta);
            char krl[100];
            cout << "Masukan Nama Kereta Api : "<<endl;
            cin.ignore();
            cin.getline(krl,100);
            showStasiun(rel, krl);
            break;
        }
        case 11 :
        {
            system("cls");
            duakaliStasiun(kereta, rel, stasiun);
            break;
        }
        case 12 :
        {
            system("cls");
            stasiunTerbanyak(stasiun, rel);
            break;
        }
//        case 13 : {
//            system("cls");
//            keretaTerbanyak(kereta, rel);
//            break;
//        }
        case 0 :
            break;
        default :
            cout << "invalid"<< endl;
            break;
        }
    }
    while(n != 0);
    return 0;
}


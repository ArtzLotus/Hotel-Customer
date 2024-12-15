#include "header.h"

using namespace std;

int main()
{
    ListCustomer Lc;
    ListHotel Lh;
    ListRelasi Lr;
    int pilihan, in, n, i, noKamar;
    adrHotel H;
    adrCustomer C;
    adrRelasi R;
    string nama;

    createListCustomer(Lc);
    createListHotel(Lh);
    createListRelasi(Lr);

    cout << "=============== Hotel Asgard ===============" << endl;
    cout << "| 1. Tambah                                |" << endl;
    cout << "| 2. Hapus                                 |" << endl;
    cout << "| 3. Cari                                  |" << endl;
    cout << "| 4. Show                                  |" << endl;
    cout << "| 5. Count                                 |" << endl;
    cout << "| 6. Edit                                  |" << endl;
    cout << "| 0. Exit                                  |" << endl;
    cout << "============================================" << endl;
    cout << "Input: ";
    cin >> pilihan;
    while (pilihan != 0){
        switch(pilihan){
            //PILIHAN MENAMBAHKAN DATA
            case 1:
                menuTambah(Lc, Lh, Lr);
            break;

            //PILIHAN MENGHAPUS DATA
            case 2:
                menuHapus(Lc, Lh, Lr);
            break;

            //PILIHAN MENCARI DATA
            case 3:
                menuCari(Lc, Lh, Lr);
            break;

            //PILIHAN MENAMPILKAN DATA
            case 4:
                menuShow(Lc, Lh, Lr);
            break;

            //PILIHAN MENGHITUNG DATA
            case 5:
                menuCount(Lc, Lh, Lr);
            break;

            //PILIHAN MENGEDIT DATA
            case 6:
                menuEdit(Lc, Lh, Lr);
            break;
        }
        cout << "=============== Hotel Asgard ===============" << endl;
        cout << "| 1. Tambah                                |" << endl;
        cout << "| 2. Hapus                                 |" << endl;
        cout << "| 3. Cari                                  |" << endl;
        cout << "| 4. Show                                  |" << endl;
        cout << "| 5. Count                                 |" << endl;
        cout << "| 6. Edit                                  |" << endl;
        cout << "| 0. Exit                                  |" << endl;
        cout << "============================================" << endl;
        cout << "Input: ";
        cin >> pilihan;
    }
    return 0;
}

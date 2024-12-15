#include "header.h"

//MENU TAMBAH
void menuTambah(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr){
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: menambahkan data kedalam list customer atau list hotel atau list relasi
}*/

    int i, n, in, noKamar, jumPenghuni;
    infoCustomer dataC;
    infoHotel dataH;
    adrCustomer C;
    adrHotel H;
    adrRelasi R;
    string nama;

    cout << "=============== Hotel Asgard ===============" << endl;
    cout << "| 1. Tambah Customer                       |" << endl;
    cout << "| 2. Tambah Hotel                          |" << endl;
    cout << "| 3. Tambah Relasi                         |" << endl;
    cout << "============================================" << endl;
    cout << "Input: ";
    cin >> in;
    switch(in){
        case 1:
            // INPUT CUSTOMER
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| Input banyak Customer: ";
            cin >> n;
            for (i = 1; i <= n; i++){
                cout << "=============== Hotel Asgard ===============" << endl;
                cout << "Data Customer ke-" << i <<endl;
                cout << "Nama: ";
                cin >> dataC.nama;
                cout << "Usia: ";
                cin >> dataC.usia;
                cout << "No. telp: ";
                cin >> dataC.telp;
                cout << "Gender: ";
                cin >> dataC.gender;
                cout << "Status Nikah: ";
                cin >> dataC.nikah;
                cout << "KTP: ";
                cin >> dataC.ktp;
                cout << "Tanggal Check-in: ";
                cin >> dataC.tglCi;
                cout << "Tanggal Check-out: ";
                cin >> dataC.tglCo;

                C = createElemenCustomer(dataC);
                insertSortingCustomer(Lc, C);
            }
        break;

        //INPUT KAMAR HOTEL
        case 2:
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| Input Banyak Kamar Hotel: ";
            cin >> n;
            for (i = 1; i <= n; i++){
                cout << "Data Kamar Hotel ke-" << i << endl;
                cout << "Nomor Kamar: ";
                cin >> dataH.noKamar;
                cout << "Jenis Kamar: ";
                cin >> dataH.jenisKamar;
                dataH.jumPenghuni = 0;

                H = createElemenHotel(dataH);
                insertSortingHotel(Lh, H);
            }
            break;

        //INPUT RELASI
        case 3:
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| Input Banyak Relasi: ";
            cin >> n;
            for (i = 1; i <= n; i++){
                cout << "=============== Hotel Asgard ===============" << endl;
                cout << "| Nama Check-in Customer    : ";
                cin >> nama;
                C = findCustomer(Lc, nama);
                cout << "| Nomor kamar untuk Customer: ";
                cin >> noKamar;
                cout << "| Input Jumlah Penghuni     : ";
                cin >> jumPenghuni;
                H = findHotel(Lh, noKamar);

                insertRelasi(Lr, C, H, jumPenghuni);
            }
    }
};

//MENU HAPUS
void menuHapus(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr){
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: menghapus data dari list customer atau list hotel atau list relasi
}*/

    int in, i, n;
    adrCustomer C, precC;
    adrHotel H, precH;
    adrRelasi R, prec;

    cout << "=============== Hotel Asgard ===============" << endl;
    cout << "| 1. Hapus Customer                        |" << endl;
    cout << "| 2. Hapus Hotel                           |" << endl;
    cout << "| 3. Hapus Relasi                          |" << endl;
    cout << "============================================" << endl;
    cout << "Input: ";
    cin >> in;
    switch (in){
        //HAPUS DATA CUSTOMER
        case 1:
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| 1. Hapus Data pertama                    |" << endl;
            cout << "| 2. Hapus Data terakhir                   |" << endl;
            cout << "| 3. Hapus Data ke-                        |" << endl;
            cout << "============================================" << endl;
            cout << "Input: ";
            cin >> in;
            if (in == 1){
                deleteFirstCustomer(Lc, C);
                cout << "Data berhasil dihapus" << endl;
            }else if (in == 2){
                deleteLastCustomer(Lc, C);
                cout << "Data berhasil dihapus" << endl;
            }else {
                cout << "=============== Hotel Asgard ===============" << endl;
                cout << "| Input data ke-";
                cin >> n;
                precC = firstC(Lc);
                i = 1;
                while (precC != nil && i < n){
                    precC = nextC(precC);
                    i++;
                }
                if (precC == nil){
                    cout << "Data tidak ditemukan" << endl;
                }else {
                    deleteAfterCustomer(Lc, precC, C);
                }
            }

            R = firstR(Lr), prec;
            while (R != nil && parent(R) != C){
                prec = R;
                R = nextR(R);
            }

            if (R == nil){
                cout << endl;
            }else {
                if (nextR(R) == nil){
                    deleteLastRelasi(Lr, R);
                }else if (R == firstR(Lr)){
                    deleteFirstRelasi(Lr, R);
                }else {
                    deleteAfterRelasi(Lr, prec, R);
                }
            }

        break;

        //HAPUS DATA HOTEL
        case 2:
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| 1. Hapus Data pertama                    |" << endl;
            cout << "| 2. Hapus Data terakhir                   |" << endl;
            cout << "| 3. Hapus Setelah Data ke-                |" << endl;
            cout << "============================================" << endl;
            cout << "Input: ";
            cin >> in;
            if (in == 1){
                deleteFirstHotel(Lh, H);
                cout << "Data berhasil dihapus" << endl;
            }else if (in == 2){
                deleteLastHotel(Lh, H);
                cout << "Data berhasil dihapus" << endl;
            }else {
                cout << "=============== Hotel Asgard ===============" << endl;
                cout << "| Input data ke-";
                cin >> n;
                precH = firstH(Lh);
                i = 1;
                while (precH != nil && i < n){
                    precH = nextH(precH);
                    i++;
                }
                if (precH == nil){
                    cout << "Data tidak ditemukan" << endl;
                }else {
                    deleteAfterHotel(Lh, precH, H);
                }
            }

            R = firstR(Lr), prec;
            while (R != nil && child(R) != H){
                prec = R;
                R = nextR(R);
            }

            if (R == nil){
                cout << endl;
            }else {
                if (nextR(R) == nil){
                    deleteLastRelasi(Lr, R);
                }else if (R == firstR(Lr)){
                    deleteFirstRelasi(Lr, R);
                }else {
                    deleteAfterRelasi(Lr, prec, R);
                }
            }
        break;

        //HAPUS RELASI
        case 3:
            string nama;
            int noKamar;
            cout << "Masukkan nama customer     :";
            cin >> nama;
            cout << "Masukkan nomor kamar hotel :";
            cin >> noKamar;

            C = findCustomer(Lc, nama);
            H = findHotel(Lh, noKamar);
            R = findRelasiCustomerDanHotel(Lr, C, H);

            if (R != nil) {
                deleteRelasi(Lr, C, H, R);
                cout << "Relasi antara customer " << nama << " dan kamar " << noKamar << " berhasil dihapus." << endl;
            } else {
                cout << "Tidak ada relasi yang ditemukan untuk customer " << nama << " dengan kamar " << noKamar << "." << endl;
            }
            break;
    }
}

//MENU CARI
void menuCari(ListCustomer Lc, ListHotel Lh, ListRelasi Lr){
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: mencari data dari list customer atau list hotel atau list relasi
}*/

    string nama;
    int noKamar, in;
    adrCustomer C;
    adrHotel H;
    adrRelasi R;

    cout << "=============== Hotel Asgard ===============" << endl;
    cout << "| 1. Cari Customer                         |" << endl;
    cout << "| 2. Cari Hotel                            |" << endl;
    cout << "| 3. Cari Relasi                           |" << endl;
    cout << "============================================" << endl;
    cout << "Input: ";
    cin >> in;
    switch (in){
        case 1:{
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| Input Nama Customer: ";
            cin >> nama;

            adrCustomer C = findCustomer(Lc, nama);

            if (C == nil) {
                cout << "Customer tidak ditemukan atau daftar customer sedang kosong." << endl;
            } else {
                cout << "Detail Customer:" << endl;
                cout << "Nama        : " << infoC(C).nama << endl;
                cout << "Usia        : " << infoC(C).usia << endl;
                cout << "No. Telepon : " << infoC(C).telp << endl;
                cout << "Gender      : " << infoC(C).gender << endl;

                if (infoC(C).nikah) {
                    cout << "Status      : Sudah Menikah" << endl;
                } else {
                    cout << "Status      : Belum Menikah" << endl;
                }

                if (infoC(C).ktp) {
                    cout << "KTP         : Sudah Memiliki KTP" << endl;
                } else {
                    cout << "KTP         : Belum Memiliki KTP" << endl;
                }
                cout << "Tanggal CI  : " << infoC(C).tglCi << endl;
                cout << "Tanggal CO  : " << infoC(C).tglCo << endl;
            }
        break;}

        case 2:
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| Input Nomor Kamar Hotel: ";
            cin >> noKamar;

            H = findHotel(Lh, noKamar);

            if (H == nil) {
                cout << "Hotel tidak ditemukan atau data kamar hotel sedang kosong." << endl;
            } else {
                cout << "Detail Hotel:" << endl;
                cout << "Nomor Kamar: " << infoH(H).noKamar << endl;
                cout << "Jenis Kamar: " << infoH(H).jenisKamar << endl;
                cout << "Jumlah Penghuni: " << infoH(H).jumPenghuni << endl;
            }

        break;

        case 3:
            cout << "Input Nama Customer: ";
            cin >> nama;
            cout << "Input Nomor Kamar Hotel: ";
            cin >> noKamar;

            C = findCustomer(Lc, nama);
            H = findHotel(Lh, noKamar);

            if (C == nil) {
                cout << "Customer tidak ditemukan." << endl;
            } else if (H == nil) {
                cout << "Hotel tidak ditemukan." << endl;
            } else {
                adrRelasi R = findRelasiCustomerDanHotel(Lr, C, H);
                if (R == nil) {
                    cout << "Relasi tidak ditemukan." << endl;
                } else {
                    cout << "Relasi ditemukan, customer sudah memesan kamar hotel." << endl;
                }
            }
        break;
    }
}


//MENU SHOW
void menuShow(ListCustomer Lc, ListHotel Lh, ListRelasi Lr){
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: menampilkan data dari list customer atau list hotel atau list relasi
}*/
    int in;
    string nama;

    cout << "=============== Hotel Asgard ===============" << endl;
    cout << "| 1. Show Customer                         |" << endl;
    cout << "| 2. Show Hotel                            |" << endl;
    cout << "| 3. Show Relasi                           |" << endl;
    cout << "============================================" << endl;
    cout << "Input: ";
    cin >> in;
    switch (in){
        //TAMPILKAN LIST CUSTOMER
        case 1:
            cout << "=============== Hotel Asgard ===============" << endl;
            showDataCustomer(Lc);
        break;

        case 2:
            //TAMPILKAN LIST KAMAR HOTEL
            cout << "=============== Hotel Asgard ===============" << endl;
            showDataHotel(Lh);
        break;

        case 3:
            //TAMPILKAN LIST RELASI
            cout << "=============== Hotel Asgard ===============" << endl;
            cout << "| 1. Show Kamar Hotel dengan Customer      |" << endl;
            cout << "| 2. Show Customer dengan Kamar Hotel      |" << endl;
            cout << "| 3. Show Kamar Hotel dari Customer        |" << endl;
            cout << "============================================" << endl;
            cin >> in;
            switch (in){
                case 1:
                    cout << "=============== Hotel Asgard ===============" << endl;
                    showChildwithParent(Lr, Lh);
                break;

                case 2:
                    cout << "=============== Hotel Asgard ===============" << endl;
                    showParentwithChild(Lr, Lc);
                break;

                case 3:
                    cout << "=============== Hotel Asgard ===============" << endl;
                    cout << "| Input nama Customer: ";
                    cin >> nama;
                    cout << "=============== Hotel Asgard ===============" << endl;
                    showChildrenFromParent(Lc, Lr, nama);
                break;
            }
    }
}

//MENU COUNT
void menuCount(ListCustomer Lc, ListHotel Lh, ListRelasi Lr) {
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: menampilkan jumlah data dari list customer atau list hotel atau list relasi dengan beberapa ketentuan
}*/

    int in,hasil;
    string namaCustomer;
    adrCustomer C;


    cout << "================== Menu Count ==================" << endl;
    cout << "| 1. Hitung Jumlah Kamar oleh Customer         |" << endl;
    cout << "| 2. Hitung Jumlah Customer yang Memesan Kamar |" << endl;
    cout << "| 3. Hitung Jumlah Kamar Tanpa Customer        |" << endl;
    cout << "| 4. Hitung Jumlah Customer Tanpa Kamar        |" << endl;
    cout << "================================================" << endl;
    cout << "Pilih opsi: ";
    cin >> in;

    switch (in) {
        case 1:
            cout << "Masukkan nama customer: ";
            cin >> namaCustomer;
            C = findCustomer(Lc, namaCustomer);
            if (C != nil) {
                cout << "Customer dengan nama" << infoC(C).nama << " memesan jumlah kamar sebanyak :" << countChildOfParent(Lr, C) << endl;
            }else {
                cout << "Customer tidak ditemukan." << endl;
            }
            break;
        case 2:
            cout << "Masukkan nama customer: ";
            cin >> namaCustomer;
            countParentOfChild(Lr, namaCustomer);
            break;
        case 3:
            hasil = countChildWithoutParent(Lh, Lr);
            cout << "Jumlah kamar yang belum ditempati: " << hasil << endl;
            break;
        case 4:
            hasil = countParentWithoutChild(Lc, Lr);
            cout << "Jumlah customer yang belum check-in: " << hasil << endl;
            break;
        }
}

void menuEdit(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr) {
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang kosong atau tidak
   FS: mengubah atau mengedit data dari list customer atau list hotel atau list relasi
}*/
    int pilihan, noKamar;
    string nama;
    adrCustomer C;
    adrHotel H;

    cout << "=============== Menu Edit Relasi ===============" << endl;
    cout << "| 1. Edit Penyewa Kamar Hotel                  |" << endl;
    cout << "| 2. Edit Kamar Hotel Yang Disewa              |" << endl;
    cout << "===============================================" << endl;
    cout << "Input: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Input Nomor Kamar yang Akan Diedit: ";
            cin >> noKamar;
            H = findHotel(Lh, noKamar);

            if (H != nil) {
                editRelasiParentFromChild(Lc, Lh, Lr, H);
            } else {
                cout << "Kamar tidak ditemukan." << endl;
            }
            break;

        case 2:
            cout << "Input Nama Customer yang Akan Diedit: ";
            cin >> nama;
            C = findCustomer(Lc, nama);

            if (C != nil) {
                cout << "Input Nomor Kamar Lama: ";
                cin >> noKamar;
                H = findHotel(Lh, noKamar);

                if (H != nil) {
                    editRelasiChildFromParent(Lc, Lh, Lr, C, H);
                } else {
                    cout << "Kamar lama tidak ditemukan." << endl;
                }
            } else {
                cout << "Customer tidak ditemukan." << endl;
            }
            break;
    }
}

//Buat List Customer, Hotel dan Relasi
void createListCustomer(ListCustomer &Lc){
/*{IS: -
   FS: dihasilkan list double linked list customer
   }*/
    firstC(Lc) = nil;
    lastC(Lc) = nil;
};

void createListHotel(ListHotel &Lh){
/*{IS: -
   FS: dihasilkan list single linked list hotel
}*/
    firstH(Lh) = nil;
};

void createListRelasi(ListRelasi &Lr){
/*{IS: -
   FS: dihasilkan list single linked list relasi
}*/
    firstR(Lr) = nil;
};

//Buat elemen Customer, Hotel dan Relasi
adrCustomer createElemenCustomer(infoCustomer dataCustomer){
/*{IS: terdefinisi data customer
   FS: mengembalikan alamat yang sudah di isi dengan data customer
}*/
    adrCustomer C = new elemCustomer;

    infoC(C) = dataCustomer;
    nextC(C) = nil;
    prevC(C) = nil;

    return C;
};

adrHotel createElemenHotel(infoHotel dataHotel){
/*{IS: terdefinisi data hotel
   FS: mengembalikan alamat yang sudah di isi dengan data hotel
}*/
    adrHotel H = new elemHotel;

    infoH(H) = dataHotel;
    nextH(H) = nil;

    return H;
};

adrRelasi createElemenRelasi(adrCustomer C, adrHotel H){
/*{IS:  terdefinisi alamat dari data customer dan data hotel
   FS:  mengembalikan alamat relasi yang dimana alamat parent di isi dengan
        data customer dan alamat child di isi dengan data hotel
}*/
    adrRelasi R = new elemRelasi;

    parent(R) = C;
    child(R) = H;
    nextR(R) = nil;

    return R;
};

//Insert Bagian Customer
void insertFirstCustomer(ListCustomer &Lc, adrCustomer C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang menyimpan data customer
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen pertama
}*/
    if(firstC(Lc) == nil){
        firstC(Lc) = C;
        lastC(Lc) = C;
    } else {
        nextC(C) = firstC(Lc);
        prevC(firstC(Lc)) = C;
        firstC(Lc) = C;
    }
};

void insertLastCustomer(ListCustomer &Lc, adrCustomer C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang menyimpan data customer
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen terakhir
}*/
     if(firstC(Lc) == nil){
        firstC(Lc) = C;
        lastC(Lc) = C;
    }else {
        nextC(lastC(Lc)) =  C;
        prevC(C) = lastC(Lc);
        lastC(Lc) = C;
    }
};

void insertAfterCustomer(ListCustomer &Lc, adrCustomer prec, adrCustomer C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang menyimpan data customer
       dan alamat yang menunjuk sebelum alamat yang mau ditambahkan
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen setelah elemen prec
}*/
     if(firstC(Lc) == nil){
        firstC(Lc) = C;
        lastC(Lc) = C;
    } else if (prec == lastC(Lc)) {
        insertLastCustomer(Lc, C);
    }else {
        nextC(C) = nextC(prec);
        prevC(nextC(prec)) = C;
        prevC(C) = prec;
        nextC(prec) = C;
    }
};

void insertSortingCustomer(ListCustomer &Lc, adrCustomer C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang menyimpan data customer
   FS: alamat customer sudah dimasukkan kedalam list dan alamat sudah langsung tersortir
}*/
   if (firstC(Lc) == nil){
        insertFirstCustomer(Lc, C);
    }else {
        adrCustomer p = firstC(Lc);

        while (p != nil && infoC(p).tglCi < infoC(C).tglCi){
            p = nextC(p);
        }

        if (p == nil){
            insertLastCustomer(Lc, C);
        }else if (p == firstC(Lc)){
            insertFirstCustomer(Lc, C);
        }else {
            insertAfterCustomer(Lc, prevC(p), C);
        }
    }
};

//Insert bagian Hotel
void insertFirstHotel(ListHotel &Lh, adrHotel H) {
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak dan alamat yang menyimpan data hotel
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen pertama
}*/
    if (firstH(Lh) == nil){
        firstH(Lh) = H;
    }else {
        nextH(H) = firstH(Lh);
        firstH(Lh) = H;
    }

}

void insertLastHotel(ListHotel &Lh, adrHotel H){
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak dan alamat yang menyimpan data hotel
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen terakhir
}*/
    adrHotel Q;

    if (firstH(Lh) == nil) {
        firstH(Lh) = H;
    }else {
        Q = firstH(Lh);
        while (nextH(Q) != nil){
            Q = nextH(Q);
        }
        nextH(Q) = H;
    }
}

void insertAfterHotel(ListHotel &Lh, adrHotel prec,adrHotel H){
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak dan alamat yang menyimpan data hotel
       dan alamat yang menunjuk sebelum alamat yang mau ditambahkan
   FS: alamat customer sudah dimasukkan kedalam list dan menjadi elemen setelah elemen prec
}*/
    if (firstH(Lh) == nil) {
        firstH(Lh) = H;
    }else {
        nextH(H) = nextH(prec);
        nextH(prec) = H;
    }

}

void insertSortingHotel(ListHotel &Lh, adrHotel H){
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak dan alamat yang menyimpan data hotel
   FS: alamat customer sudah dimasukkan kedalam list dan alamat sudah langsung tersortir
}*/
    adrHotel prec = firstH(Lh),p = firstH(Lh);
    if (firstH(Lh) == nil) {
        firstH(Lh) = H;
    }else {
        while (prec != nil && infoH(prec).noKamar < infoH(H).noKamar) {
            prec = nextH(prec);
        }
        if (prec == firstH(Lh)) {
            insertFirstHotel(Lh, H);
        }else if (prec == nil) {
            insertLastHotel(Lh, H);
        }else {
            while (nextH(p) != prec){
                p = nextH(p);
            }
            insertAfterHotel(Lh,p,H);
        }
    }
};

//insert bagian relasi
void insertRelasi(ListRelasi &Lr, adrCustomer C, adrHotel H, int penghuni){
/*{IS: terdefinisi list relasi yang mungkin kosongg atau tidak dan alamat yang menyimpan data customer dan hotel
   FS: alamat relasi sudah ditambahkan kedalam list relasi dan menjadi alamat terakhir
}*/
    infoH(H).jumPenghuni = penghuni;
    adrRelasi p = firstR(Lr), R = createElemenRelasi(C, H);

    if (firstR(Lr) == nil){
        firstR(Lr) = R;
    }else {
        while (nextR(p) != nil){
            p = nextR(p);
        }
        nextR(p) = R;
    }
};

//delete bagian customer
void deleteFirstCustomer(ListCustomer &Lc, adrCustomer &C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data customer
   FS: menghapus alamat pertama pada list customer dan disimpan di pointer C
}*/

    if(firstC(Lc) == nil){
        cout << "List kosong" << endl;
    } else if (firstC(Lc) == lastC(Lc)){
        C = firstC(Lc);
        firstC(Lc) = nil;
        lastC(Lc) = nil;
    } else {
        C = firstC(Lc);
        firstC(Lc) = nextC(C);
        nextC(C) = nil;
        prevC(firstC(Lc)) = nil;
    }

};

void deleteLastCustomer(ListCustomer &Lc, adrCustomer &C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data customer
   FS: menghapus alamat terakhir pada list customer dan disimpan di pointer C
}*/
    C = lastC(Lc);
    if(firstC(Lc) == nil){
        cout << "List kosong" << endl;
    } else if (firstC(Lc) == lastC(Lc)){
        firstC(Lc) = nil;
        lastC(Lc) = nil;
    } else {
        lastC(Lc) = prevC(C);
        nextC(lastC(Lc)) = nil;
        prevC(C) = nil;
    }
};

void deleteAfterCustomer(ListCustomer &Lc, adrCustomer prec, adrCustomer &C){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data customer
   FS: menghapus alamat setelah alamat di pointer prec pada list customer dan disimpan di pointer C
}*/
    if(next(prec) == lastC(Lc)) {
        C = nextC(prec);
        deleteLastCustomer(Lc, C);
    } else if(firstC(Lc) == lastC(Lc)){
        firstC(Lc) = nil;
        lastC(Lc) = nil;
    } else {
        C = nextC(prec);
        nextC(prec) = nextC(C);
        prevC(nextC(C)) = prec;
        nextC(C) = nil;
        prevC(C) = nil;
    }
};

//delete bagian hotel
void deleteFirstHotel(ListHotel &Lh, adrHotel &H){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data hotel
   FS: menghapus alamat pertama pada list hotel dan disimpan di pointer H
}*/
    if (firstH(Lh) == nil){
        cout << "List Kosong" << endl;
    }else if (nextH(firstH(Lh)) == nil) {
        H = firstH(Lh);
        firstH(Lh) = nil;
    }else {
        H = firstH(Lh);
        firstH(Lh) = nextH(H);
        nextH(H) = nil;
    }

}

void deleteLastHotel(ListHotel &Lh, adrHotel &H){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data hotel
   FS: menghapus alamat terakhir pada list hotel dan disimpan di pointer H
}*/
    adrHotel Q = firstH(Lh), R;
    if (firstH(Lh) == nil){
        cout << "List Kosong" << endl;
    }else if (nextH(firstH(Lh)) == nil) {
        H = firstH(Lh);
        firstH(Lh) = nil;
    }else {
       while (nextH(Q) != nil) {
            R = Q;
            Q = nextH(Q);
       }
        H = Q;
        nextH(R) = nil;
    }

}

void deleteAfterHotel(ListHotel &Lh,adrHotel prec,adrHotel &H){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan alamat yang akan menyimpan data hotel
   FS: menghapus alamat setelah alamat di pointer prec pada list customer dan disimpan di pointer H
}*/
    if (firstH(Lh) == nil) {
        cout << "List Kosong" << endl;
    }else if (nextH(firstH(Lh)) == nil ){
        H = firstH(Lh);
        firstH(Lh) = nil;
    }else {
        H = nextH(prec);
        nextH(prec) = nextH(H);
        nextH(H) = nil;
    }
}

//delete relasi
void deleteRelasi(ListRelasi &Lr, adrCustomer C, adrHotel H, adrRelasi &R){
/*{IS: terdefinisi list relasi yang mungkin kosong atau tidak, dan alamat pointer customer, hotel dan relasi
   FS: data yang dihapus disimpan di pointer r
}*/

    adrRelasi q, r;

    if (firstR(Lr) == nil) {
        cout << "Belum ada yang check-in" << endl;
    }else {
        q = firstR(Lr);

        while (q != nil && !(parent(q) == C && child(q) == H)){
            q = nextR(q);
        }

        if (q == firstR(Lr)){
            deleteFirstRelasi(Lr, R);
        }else if (q == nil) {
            cout << "Tidak ada relasi yang sesuai" << endl;
        }else if (nextR(q) == nil){
            deleteLastRelasi(Lr, R);
        }else {
            r = firstR(Lr);

            while (nextR(r) != q){
                r = nextR(r);
            }

            deleteAfterRelasi(Lr, r, R);
        }
    }
};

void deleteFirstRelasi(ListRelasi &Lr, adrRelasi &R){
/*{IS: terdefinisi list relasi yang mungkin kosong atau tidak, dan pointer R yang kosong
   FS: elemen pertama dihapus dan disimpan di pointer R
}*/

    adrRelasi p = firstR(Lr);

    parent(R) = nil;
    child(R) = nil;
    if (firstR(Lr) == nil){
        cout << "tidak ada relasi" << endl;
    }else if (nextR(firstR(Lr)) == nil){
        R = p;
        firstR(Lr) = nil;
    }else {
        R = p;
        firstR(Lr) = nextR(R);
        nextR(R) = nil;
    }
};

void deleteLastRelasi(ListRelasi &Lr, adrRelasi &R) {
/*{IS: terdefinisi list relasi yang mungkin kosong atau tidak, dan pointer R yang kosong
   FS: elemen terakhir dihapus dan disimpan di pointer R
}*/

    adrRelasi p = firstR(Lr), q;

    parent(R) = nil;
    child(R) = nil;
    if (firstR(Lr) == nil){
        cout << "tidak ada relasi" << endl;
    }else if (nextR(firstR(Lr)) == nil){
        R = p;
        firstR(Lr) = nil;
    }else {
        while (nextR(p) != nil){
            q = p;
            p = nextR(p);
        }
        R = p;
        nextR(q) = nil;
    }
};

void deleteAfterRelasi(ListRelasi &Lr, adrRelasi prec, adrRelasi &R) {
/*{IS: terdefinisi list relasi yang mungkin kosong atau tidak, dan pointer R yang kosong
   FS: elemen setelah pointer prec dihapus dan disimpan di pointer R
}*/

    parent(R) = nil;
    child(R) = nil;

    if (firstR(Lr) == nil){
        cout << "tidak ada relasi" << endl;
    }else if ( nextR(firstR(Lr)) == nil){
        R = firstR(Lr);
        firstR(Lr) = nil;
    }else {
        R = nextR(prec);
        nextR(prec) = nextR(R);
        nextR(R) = nil;
    }
}

//find customer
adrCustomer findCustomer(ListCustomer Lc, string nama){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak dan nama customer yang akan dicari
   FS: mengembalikan alamat jika list tidak kosong, mengembalikan NULL dan menampilkan "Daftar Customer sedang kosong" ketika list kosong
}*/

    adrCustomer C = firstC(Lc);
    if (firstC(Lc) == nil){
        cout << "Daftar Customer sedang Kosong" << endl;
        return nil;
    }else {
        while(C != nil && infoC(C).nama != nama){
            C = nextC(C);
        }
        return C;
    }
};

//find hotel
adrHotel findHotel(ListHotel Lh, int noKamar){
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak dan nomor kamar yang akan dicari
   FS: mengembalikan alamat jika list tidak kosong, mengembalikan NULL dan menampilkan "Data kamar hotel sedang kosong" ketika list kosong
}*/

    adrHotel H = firstH(Lh);

    if (firstH(Lh) == nil) {
        cout << "Data kamar hotel sedang kosong" << endl;
        return nil;
    }else {
        while (H != nil && infoH(H).noKamar != noKamar){
            H = nextH(H);
        }
        return H;
    }
}

//find relasi antara parent dan child
adrRelasi findRelasiCustomerDanHotel(ListRelasi Lr, adrCustomer C, adrHotel H){
/*{IS: terdefinisi list relasi dan alamat pointer C dan H yang sudah terisi
   FS: mengembalikan nil jika data tidak ditemukan, dan mengembalikan alamat relasi jika data ditemukan
}*/

    adrRelasi R = firstR(Lr);

    if (firstR(Lr) == nil){
        cout << "Belum ada yang Check-in" << endl;
        return nil;
    }else {
        while (R != nil && !(parent(R) == C && child(R) == H)){
            R = nextR(R);
        }
        return R;
    }
}

//show data customer
void showDataCustomer(ListCustomer Lc){
/*{IS: terdefinisi list customer yang mungkin kosong atau tidak
   FS: menampilkan semua data yang ada di list customer
}*/

    cout << "============== List Customers ==============" << endl;
    if (firstC(Lc) == nil){
        cout << "Tidak ada Customer" << endl;
    }else {
        adrCustomer C = firstC(Lc);
        while(C  != nil){
            cout << "Nama Customer      :" << infoC(C).nama << endl;
            cout << "Usia               :" << infoC(C).usia << endl;
            cout << "Nomor Telepon      :" << infoC(C).telp << endl;
            cout << "Gender             : "<< infoC(C).gender << endl;
            if (infoC(C).nikah){
                cout << "Sudah menikah" << endl;
            } else {
                cout << "Belum menikah" << endl;
            }

            if (infoC(C).ktp) {
                cout << "Sudah memiliki KTP" << endl;
            } else {
                cout << "Belum memiliki KTP" << endl;
            }
            cout << "Tanggal Check-In   :"<< infoC(C).tglCi << endl;
            cout << "Tanggal Check-Out  :"<< infoC(C).tglCo << endl;
            cout << "============================================" <<endl;

            C = nextC(C);
        }
    }
};

//show data hotel
void showDataHotel(ListHotel Lh){
/*{IS: terdefinisi list hotel yang mungkin kosong atau tidak
   FS: menampilkan semua data yang ada di list hotel
}*/

    cout << "============= List Hotel Rooms =============" << endl;
    if (firstH(Lh) == nil){
        cout << "Data kamar hotel belum ada" << endl;
    }else {
        adrHotel H = firstH(Lh);
        while (H != nil) {
            cout << "Nomor Kamar     :" <<infoH(H).noKamar << endl;
            cout << "Jenis Kamar     :" <<infoH(H).jenisKamar << endl;
            cout << "Jumlah Penghuni :"<<infoH(H).jumPenghuni << endl;
            cout << "============================================" <<endl;

            H = nextH(H);
        }
    }
}

//show children from parent
void showChildrenFromParent(ListCustomer Lc, ListRelasi Lr, string namaCustomer) {
/*{IS: terdefinisi list customer, list relasi yang mungkin kosong, dan nama customer
   FS: menampilkan kamar hotel dari nama customer yang diinput
}*/

    adrCustomer C = findCustomer(Lc, namaCustomer);
    if (C == nil) {
        cout << "Customer dengan nama " << namaCustomer << " tidak ditemukan." << endl;
    }

    bool found = false;
    adrRelasi R = firstR(Lr);
    adrHotel H;

    cout << "======== Data Kamar Hotel dari Customer: " << namaCustomer << " ========" << endl;
    while (R != nil) {
        if (parent(R) == C) {
            H = child(R);
            cout << "Nomor Kamar       : " << infoH(H).noKamar << endl;
            cout << "Jenis Kamar       : " << infoH(H).jenisKamar << endl;
            cout << "Jumlah Penghuni   : " << infoH(H).jumPenghuni << endl;
            cout << "=============================================" << endl;
            found = true;
        }
        R = nextR(R);
    }

    if (!found) {
        cout << "Customer " << namaCustomer << " tidak memiliki relasi dengan kamar hotel manapun." << endl;
    }
};

//show parent with child
void showParentwithChild(ListRelasi Lr, ListCustomer Lc){
/*{IS: terdefinisi list relasi dan list customer yang mungkin kosong
   FS: menampilkan seluruh customer dengan kamar hotel
}*/

    adrCustomer C = firstC(Lc);
    cout << "============= List Data Relasi Kamar Hotel & Customer =============" << endl;
    if (firstR(Lr) == nil){
        cout << "Tidak ada data relasi" << endl;
    }else {
        adrRelasi R = firstR(Lr);
        while (C != nil) {
            R = firstR(Lr);
            while (R != nil) {
                if (parent(R) == C) {
                    cout << "Nama Customer :" <<infoC(parent(R)).nama << endl;
                    cout << "Nomor Telepon :" <<infoC(parent(R)).telp << endl;
                    cout << "Gender        :" <<infoC(parent(R)).gender << endl;
                    cout << "=============== Kamar Hotel ===============" << endl;
                    cout << "Nomor Kamar   :" <<infoH(child(R)).noKamar << endl;
                    cout << "Jenis Kamar   :" <<infoH(child(R)).jenisKamar << endl;
                    cout << "===========================================" << endl;
                }
                    R = nextR(R);
            }
            C = nextC(C);
        }
    }
};

//show child with parent
void showChildwithParent(ListRelasi Lr, ListHotel Lh){
/*{IS: terdefinisi list relasi dan list hotel yang mungkin kosong
   FS: menampilkan seluruh kamar hotel (baik yang sudah dipesan atau belum) dengan customer yang memesan kamar tersebut
}*/
    adrHotel H;

    cout << "============= List Data Relasi Customer & Kamar Hotel =============" << endl;
    if (firstR(Lr) == nil){
        cout << "Tidak ada data relasi" << endl;
    }else {
        H = firstH(Lh);
        while (H != nil) {
            adrRelasi R = firstR(Lr);
            while (R != nil) {
                if (child(R) == H) {
                    cout << "=============== Kamar Hotel ===============" << endl;
                    cout << "Nomor Kamar    : " << infoH(H).noKamar << endl;
                    cout << "Suite          : " << infoH(H).jenisKamar << endl;
                    cout << "Jumlah Penghuni: " << infoH(H).jumPenghuni << endl;
                    cout << "================ Customer =================" << endl;
                    cout << "Penyewa: " << infoC(parent(R)).nama << endl;
                    cout << "===========================================" << endl;
                }
                R = nextR(R);
            }
            H = nextH(H);
        }
    }
};

//count parent of child
int countParentOfChild(ListRelasi Lr, string namaCustomer) {
/*{IS: terefinisi list relasi yang mungkin kosong atau tidak dan nama customer
   FS: mengembalikan nilai dan menampilkan kamar tersebut sudah di pesan atau belum
}*/

    if (firstR(Lr) == nil) {
        cout << "Customer dengan nama " << namaCustomer << "belum memesan kamar." << endl;
    }

    bool isBooked = false;
    adrRelasi current = firstR(Lr);

    while (current != nil) {
        if (parent(current) != nil && infoC(parent(current)).nama == namaCustomer) {
            isBooked = true;
        }
        current = nextR(current);
    }

    if (isBooked) {
        cout << "Kamar tersebut telah dipesan." << endl;
        return 1;
    } else {
        cout << "Kamar tersebut belum dipesan." << endl;
        return 0;
    }
}

//count child of parent
int countChildOfParent(ListRelasi Lr, adrCustomer C){
/*{IS: terdefinis list relasi yang mungkin kosong atau tidak dan pointer C
   FS: mengembalikan nilai dari jumlah kamar hotel yang sudah dipesan oleh customer
}*/

    int jumlah = 0;

    adrRelasi R = firstR(Lr);
    while (R != nil){
        if (parent(R) == C){
                jumlah++;
        }
        R = nextR(R);
    }
    return jumlah;
}

//count parent without child
int countParentWithoutChild(ListCustomer Lc, ListRelasi Lr) {
/*{IS: terdefinisi list customer dan list relasi yang mungkin kosong atau tidak
   FS: mengembalikan jumlah dari customer yang belum memesan kamar hotel
}*/

    int count = 0;
    adrCustomer currentCustomer = firstC(Lc);
    adrRelasi currentRelasi;
    bool hasChild;

    if (firstC(Lc) == nil) {
        cout << "Tidak ada data customer." << endl;
    }else {
        while (currentCustomer != nil) {
            hasChild = false;
            currentRelasi = firstR(Lr);
            while (currentRelasi != nil) {
                if (parent(currentRelasi) == currentCustomer) {
                    hasChild = true;
                }
                currentRelasi = nextR(currentRelasi);
            }
            if (!hasChild) {
                count++;
            }
            currentCustomer = nextC(currentCustomer);
        }
    }
    return count;
}

//count child without parent
int countChildWithoutParent(ListHotel Lh, ListRelasi Lr){
/*{IS: terdefinisi lsit hotel dan list relasi yang mungkin kosong atau tidak
   FS: mengembalikan jumlah kamar hotel yang belum dipesan
}*/

    int jumlah = 0;
    bool emptyH;
    adrRelasi CurrentR;
    adrHotel CurrentH = firstH(Lh);

    if (firstH(Lh) == nil) {
        cout << "Tidak ada data Hotel." << endl;
    }else {
        while (CurrentH!= nil) {
            emptyH = false;
            CurrentR = firstR(Lr);
            while (CurrentR != nil) {
                if (child(CurrentR) == CurrentH) {
                    emptyH = true;
                }
                CurrentR = nextR(CurrentR);
            }
            if (!emptyH) {
                jumlah++;
            }
            CurrentH= nextH(CurrentH);
        }
    }
    return jumlah;
}

//edit relasi child dari parent tertentu
void editRelasiChildFromParent(ListCustomer Lc, ListHotel Lh, ListRelasi &Lr, adrCustomer C, adrHotel H) {
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang mungkin kosong atau tidak dan pointer C dan H yang sudah terisi
   FS: mengubah/mengganti kamar hotel dari customer tertentu, dengan syarat kamar tersebut belum dipesan oleh customer lain
}*/

    adrHotel tempH;
    adrRelasi R;
    int noKamar, input, jumKamar;
    bool book = false;

    if (C == nil){
        cout << "| Customer tidak ditemukan" << endl;
    }else {
        adrRelasi R = firstR(Lr);
        if (countChildWithoutParent == 0){
            cout << "| Tidak ada kamar yang tersedia" << endl;
        }else {
            //print kamar yang kosong
            showKamarKosong(Lh, Lr);

            while (!book){
                cout << "| Input no.kamar baru: ";
                cin >> noKamar;

                //pencarian no kamar yang diinginkan sudah ditempati atau belum
                R = firstR(Lr);
                while (R != nil && infoH(child(R)).noKamar != noKamar){
                    R = nextR(R);
                }
                //kondisi bila kamar yang diinginkan belum ditempati atau sudah ditempati
                if (R == nil){
                    cout << "| Kamar mau di Booking?: " << endl;
                    cout << "| 1. Ya" << endl;
                    cout << "| 2. Tidak" << endl;
                    cin >> input;
                    jumKamar = countChildOfParent(Lr, C);
                    if (jumKamar == 1) {
                        if (input == 1){
                            book = true;
                            H = findHotel(Lh, noKamar);
                            R = firstR(Lr);

                            while (R != nil && infoC(parent(R)).nama != infoC(C).nama){
                                R = nextR(R);
                            }
                            child(R) = H;
                        }else {
                            book = false;
                        }
                    }else {
                        if (input == 1){
                            book = true;
                            R = firstR(Lr);
                            while (R != nil){
                                if (parent(R) == C && child(R) == H){
                                    tempH = findHotel(Lh, noKamar);
                                    child(R) = tempH;
                                }
                                R = nextR(R);
                            }
                        }else {
                            book = false;
                        }
                    }

                }else {
                    cout << "| Kamar sudah di pesan" << endl;
                    book = false;
                }
            }
        }
    }
}

//edit relasi parent dari child tertentu
void editRelasiParentFromChild(ListCustomer Lc, ListHotel Lh, ListRelasi &Lr, adrHotel H){
/*{IS: terdefinisi list customer, list hotel, dan list relasi yang mungkin kosong atau tidak, dan pointer H yang sudah terisi data hotel
   FS: mengubah penyewa kamar dari kamar tertentu
}*/

    adrRelasi R = firstR(Lr);
    adrCustomer C;
    string nama;
    int jumPenghuni;

    while (R != nil && child(R) != H){
        R = nextR(R);
    }

    if (R == nil){
        cout << "| Kamar yang dicari tidak punya relasi" << endl;
    }else {
        cout << "| Input Nama Penyewa baru: ";
        cin >> nama;
        C = findCustomer(Lc, nama);
        parent(R) = C;
        cout << "| Input Jumlah Penghuni baru: ";
        cin >> jumPenghuni;
        infoH(child(R)).jumPenghuni = jumPenghuni;
    }
}

//show kamar kosong
void showKamarKosong(ListHotel Lh, ListRelasi Lr){
/*{IS: terdefinisi list hotel dan list relasi yang mungkin kosong
   FS: menampilkan data kamar yang kosong atau yang belum dipesan
}*/

    bool empty;
    adrRelasi R;
    adrHotel H = firstH(Lh);

    cout << "=============== Kamar Hotel ===============" << endl;
    while (H != nil) {
        R = firstR(Lr);
        empty = true;
        while (R != nil) {
            if (child(R) == H){
                empty = false;
            }
            R = nextR(R);
        }
        if (empty) {
            cout << "| No.Kamar   : " << infoH(H).noKamar << endl;
            cout << "| Jenis Kamar: " << infoH(H).jenisKamar << endl;
            cout << "===========================================" << endl;
        }
        H = nextH(H);
    }
}

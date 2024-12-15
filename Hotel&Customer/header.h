#include <iostream>
#define firstC(Lc) Lc.firstC
#define firstH(Lh) Lh.firstH
#define firstR(Lr) Lr.firstR
#define lastC(Lc) Lc.lastC
#define nextC(C) C->nextC
#define nextH(H) H->nextH
#define nextR(R) R->nextR
#define infoC(C) C->infoC
#define infoH(H) H->infoH
#define parent(R) R->parent
#define child(R) R->child
#define prevC(C) C->prevC
#define nil NULL

using namespace std;

//parent
struct customer{
    string nama, telp, gender, tglCi, tglCo;
    int usia;
    bool nikah, ktp;
};

//child
struct hotel{
    int noKamar, jumPenghuni;
    string jenisKamar;
};

typedef struct elemCustomer *adrCustomer;
typedef struct elemHotel *adrHotel;
typedef struct elemRelasi *adrRelasi;

typedef customer infoCustomer;
typedef hotel infoHotel;

struct elemCustomer {
    adrCustomer nextC;
    adrCustomer prevC;
    infoCustomer infoC;
};

struct elemHotel {
    adrHotel nextH;
    infoHotel infoH;
};

struct elemRelasi {
    adrCustomer parent;
    adrHotel child;
    adrRelasi nextR;
};

struct ListCustomer {
    adrCustomer firstC, lastC;
};

struct ListHotel {
    adrHotel firstH;
};

struct ListRelasi {
    adrRelasi firstR;
};

//menu tampilan
void menuTambah(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr);
void menuHapus(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr);
void menuCari(ListCustomer Lc, ListHotel Lh, ListRelasi);
void menuShow(ListCustomer Lc, ListHotel Lh, ListRelasi Lr);
void menuCount(ListCustomer Lc, ListHotel Lh, ListRelasi Lr);
void menuEdit(ListCustomer &Lc, ListHotel &Lh, ListRelasi &Lr);

//buat list
void createListCustomer(ListCustomer &Lc);
void createListHotel(ListHotel &Lh);
void createListRelasi(ListRelasi &Lr);

//buat elemen
adrCustomer createElemenCustomer(infoCustomer dataCustomer);
adrHotel createElemenHotel(infoHotel dataCustomer);
adrRelasi createElemenRelasi(adrCustomer C, adrHotel H);

//insert customer
void insertFirstCustomer(ListCustomer &Lr, adrCustomer C);
void insertLastCustomer(ListCustomer &Lr, adrCustomer C);
void insertAftertCustomer(ListCustomer &Lr, adrCustomer C);
void insertSortingCustomer(ListCustomer&Lc, adrCustomer C);

//insert hotel
void insertFirstHotel(ListHotel &Lh, adrHotel H);
void insertLastHotel(ListHotel &Lh, adrHotel H);
void insertAfterHotel(ListHotel &Lh,adrHotel prec,adrHotel H);
void insertSortingHotel(ListHotel &Lh, adrHotel H);

//insert relasi
void insertRelasi(ListRelasi &Lr, adrCustomer C, adrHotel H, int penghuni);

//delete customer
void deleteFirstCustomer(ListCustomer &Lc, adrCustomer &C);
void deleteLastCustomer(ListCustomer &Lc, adrCustomer &C);
void deleteAfterCustomer(ListCustomer &Lc, adrCustomer prec, adrCustomer &C);

//delete hotel
void deleteFirstHotel(ListHotel &Lh, adrHotel &H);
void deleteLastHotel(ListHotel &Lh, adrHotel &H);
void deleteAfterHotel(ListHotel &Lh,adrHotel prec,adrHotel &H);

//delete relasi
void deleteFirstRelasi(ListRelasi &Lr, adrRelasi &R);
void deleteLastRelasi(ListRelasi &Lr, adrRelasi &R);
void deleteAfterRelasi(ListRelasi &Lr, adrRelasi prec, adrRelasi &R);
void deleteRelasi(ListRelasi &Lr, adrCustomer C, adrHotel H,adrRelasi &R);

//find customer berdasarkan nama
adrCustomer findCustomer(ListCustomer Lc, string nama);

//find hotel berdasarkan no.kamar
adrHotel findHotel(ListHotel Lh, int noKamar);

//find relasi dari child dan parent
adrRelasi findRelasiCustomerDanHotel(ListRelasi Lr, adrCustomer C, adrHotel H);

//show all data customer
void showDataCustomer(ListCustomer Lc);

//show all data hotel
void showDataHotel(ListHotel Lh);

//show child with parent
void showChildwithParent(ListRelasi Lr, ListHotel Lh);

//show parent with child
void showParentwithChild(ListRelasi Lr, ListCustomer Lc);

//show child dari parent
void showChildrenFromParent(ListCustomer Lc, ListRelasi Lr, string namaCustomer);

//show kamar kosong
void showKamarKosong(ListHotel Lh, ListRelasi Lr);

//count parent of child
int countParentOfChild(ListRelasi Lr, string namaCustomer);

//count child of parent
int countChildOfParent(ListRelasi Lr, adrCustomer C);

//count child without parent
int countChildWithoutParent(ListHotel Lh, ListRelasi Lr);

//count parent without child
int countParentWithoutChild(ListCustomer Lc, ListRelasi Lr);

//edit relasi child dari parent atau parent dari child
void editRelasiChildFromParent(ListCustomer Lc, ListHotel Lh, ListRelasi &Lr, adrCustomer C, adrHotel H);

//edit relasi parent dari child tertentu
void editRelasiParentFromChild(ListCustomer Lc, ListHotel Lh, ListRelasi &Lr, adrHotel H);

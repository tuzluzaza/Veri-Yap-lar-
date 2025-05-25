/**       
* @file           BagliListe.cpp
* @description    BagliListe sinifinin fonksiyonlari
* @course         Bilgisayar Mühendisligi Veri Yapilari 1-A
* @assignment     2.Ödev
* @date           21.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include "BagliListe.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

BagliListe::BagliListe() {
    bas = nullptr;
}

BagliListe::~BagliListe() {
    while (bas != nullptr) {
        Dugum* silinecek = bas;
        bas = bas->sonraki;
        delete silinecek;
    }
}

void BagliListe::ekle(const string& agac) {
    Dugum* yeni = new Dugum(agac);
    if (bas == nullptr) {
        bas = yeni;
    } else {
        Dugum* gecici = bas;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

Dugum* BagliListe::getir(int indeks) {
    Dugum* gecici = bas;
    int sayac = 0;
    while (gecici != nullptr && sayac < indeks) {
        gecici = gecici->sonraki;
        sayac++;
    }
    return gecici;
}

void BagliListe::sil(int indeks) {
    if (bas == nullptr) return;

    if (indeks == 0) {
        Dugum* silinecek = bas;
        bas = bas->sonraki;
        delete silinecek;
        return;
    }

    Dugum* onceki = nullptr;
    Dugum* gecici = bas;
    int sayac = 0;
    while (gecici != nullptr && sayac < indeks) {
        onceki = gecici;
        gecici = gecici->sonraki;
        sayac++;
    }

    if (gecici != nullptr) {
        onceki->sonraki = gecici->sonraki;
        delete gecici;
    }
}

int BagliListe::boyut() {
    int sayac = 0;
    Dugum* gecici = bas;
    while (gecici != nullptr) {
        sayac++;
        gecici = gecici->sonraki;
    }
    return sayac;
}



int BagliListe::hesaplaToplamDeger(const string& agac) {
    Agac bst;
    for (char ch : agac) {
        bst.ekle(ch);
    }
    return bst.hesaplaToplamDeger();
}


void BagliListe::satirCiz(int sayfaBoyutu) {
    for (int i = 0; i < sayfaBoyutu; i++) {
        cizgiYaz();
    }
}

void BagliListe::cizgiYaz() {
    for (int i = 0; i < 5; i++)
        cout << " ";
    cout << "............";
}

void BagliListe::degerYaz(const string& deger) {
    for (int i = 0; i < 5; i++)
        cout << " ";
    cout << "." << setw(10) << deger << ".";
}

void BagliListe::isaretYaz(int indeks) {
    for (int i = 0; i < indeks; i++) {
        for (int j = 0; j < 5; j++)
            cout << " ";
        cout << "            ";
    }
    for (int i = 0; i < 5; i++)
        cout << " ";
    cout << "^^^^^^^^^^^^";
    cout << endl;
     for (int i = 0; i < indeks; i++) {
        for (int j = 0; j < 5; j++)
            cout << " ";
        cout << "            ";
    }
    for (int i = 0; i < 5; i++)
        cout << " ";
    cout << "||||||||||||";
    cout << endl;
    cout << endl;
    cout << endl;
}

void BagliListe::menuyaz(int indeks, int sayfaIndeksi, int sayfaBoyutu, bool secilenAgacAynalanmisMi) {
    int boyut = this->boyut();
    int baslangic = sayfaIndeksi * sayfaBoyutu;
    int bitis = min(baslangic + sayfaBoyutu, boyut);
    int mevcutSayfaBoyutu = bitis - baslangic; // dinamik olarak o sayfaka kac agac oldugu

    satirCiz(mevcutSayfaBoyutu);
    cout << endl;

    // Secekteki agacın bellekteki adresi
    for (int i = baslangic; i < bitis; i++) {
        Dugum* current = getir(i); 
        if (current) {
            stringstream ss;
            ss << "0x" << hex << reinterpret_cast<uintptr_t>(current);
            degerYaz(ss.str());
        } else {
            degerYaz("NULL");
        }
    }
    cout << endl;
    satirCiz(mevcutSayfaBoyutu);
    cout << endl;

    // Ascii degerleriyle toplam degerin yazildigi satir
    for (int i = baslangic; i < bitis; i++) {
        Dugum* current = getir(i); 
        if (current) {
            Agac bst;
            for (char ch : current->agac) {
                bst.ekle(ch);
            }
            if (current->aynalanmis) { // Aynalanmıssa aynalanmis agaca gore degeri hesaplar
                bst = bst.aynalamaYap();
            }
            degerYaz(to_string(bst.hesaplaToplamDeger()));
        } else {
            degerYaz("NULL");
        }
    }
    cout << endl;
    satirCiz(mevcutSayfaBoyutu);
    cout << endl;

    // Sonraki adres satırı
    for (int i = baslangic; i < bitis; i++) {
        Dugum* current = getir(i); 
        if (current && current->sonraki) {
            stringstream ss;
            ss << "0x" << hex << reinterpret_cast<uintptr_t>(current->sonraki);
            degerYaz(ss.str());
        } else {
            degerYaz("NULL");
        }
    }
    cout << endl;
    satirCiz(mevcutSayfaBoyutu);
    cout << endl;

    //imlec
    isaretYaz(indeks - baslangic);
    cout << endl;
}



void BagliListe::dosyaOku(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        ekle(satir);
    }
    dosya.close();
}


/**       
* @file           BagliListe.cpp
* @description    Kromozom üzerinde işlem yapan fonksiyonların bulunduğu yer
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     1.Ödev
* @date           23.11.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include <fstream>
#include <sstream>
#include <iostream>
#include "BagliListe.hpp"

using namespace std;

BagliListe::BagliListe() {
    this->ilkGen = nullptr;
    this->sonrakiKromozom = nullptr;
}

BagliListe::~BagliListe() {
    // genlerin serbest bırakılması
    Dugum* mevcutGen = this->ilkGen;
    while (mevcutGen) {
        Dugum* silinecek = mevcutGen;
        mevcutGen = mevcutGen->sonraki;
        delete silinecek; 
    }

    // kromozomların serbest bırakılması
    BagliListe* mevcutKromozom = this->sonrakiKromozom;
    while (mevcutKromozom) {
        BagliListe* silinecek = mevcutKromozom;
        mevcutKromozom = mevcutKromozom->sonrakiKromozom;
        delete silinecek; // 
    }
}


void BagliListe::genEkle(char gen) {
    Dugum* yeni = new Dugum(gen);
    if (!ilkGen) {
        ilkGen = yeni;
    } else {
        Dugum* gecici = ilkGen;
        while (gecici->sonraki) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
        yeni->onceki = gecici;
    }
}

void BagliListe::kromozomEkle(BagliListe* kromozom) {
    if (!this->sonrakiKromozom) {
        this->sonrakiKromozom = kromozom;
    } else {
        BagliListe* gecici = this;
        while (gecici->sonrakiKromozom) {
            gecici = gecici->sonrakiKromozom;
        }
        gecici->sonrakiKromozom = kromozom;
    }
}

void BagliListe::caprazlama(int satir1, int satir2) {
    // İlk kromozomun adresini bul
    BagliListe* kromozom1 = this;
    for (int i = 0; i < satir1; i++) {
        if (!kromozom1->sonrakiKromozom) {
            cout << "Gecersiz satir numarasi: " << satir1 << endl;
            return;
        }
        kromozom1 = kromozom1->sonrakiKromozom;
    }

    // İkinci kromozomun adresini bul
    BagliListe* kromozom2 = this;
    for (int i = 0; i < satir2; i++) {
        if (!kromozom2->sonrakiKromozom) {
            cout << "Gecersiz satir numarasi: " << satir2 << endl;
            return;
        }
        kromozom2 = kromozom2->sonrakiKromozom;
    }

    // Uzunlukları bul
    int uzunluk1 = 0, uzunluk2 = 0;
    Dugum* temp1 = kromozom1->ilkGen;
    Dugum* temp2 = kromozom2->ilkGen;

    while (temp1) {
        uzunluk1++;
        temp1 = temp1->sonraki;
    }

    while (temp2) {
        uzunluk2++;
        temp2 = temp2->sonraki;
    }

    int orta1 = uzunluk1 / 2;
    int orta2 = uzunluk2 / 2;

    // Yeni kromozomlar oluştur
    BagliListe* yeniKromozom1 = new BagliListe();
    BagliListe* yeniKromozom2 = new BagliListe();

    // 1. Yeni Kromozom: Birinci kromozomun sol kısmı + İkinci kromozomun sağ kısmı
    temp1 = kromozom1->ilkGen;
    for (int i = 0; i < orta1; i++) { // Birinci kromozomun sol kısmı
        yeniKromozom1->genEkle(temp1->gen);
        temp1 = temp1->sonraki;
    }

    temp2 = kromozom2->ilkGen;
    for (int i = 0; i < uzunluk2; i++) { // İkinci kromozomun sağ kısmı
        if (i >= orta2 + (uzunluk2 % 2 == 0 ? 0 : 1)) { // Orta geni atlama
            yeniKromozom1->genEkle(temp2->gen);
        }
        temp2 = temp2->sonraki;
    }

    // 2. Yeni Kromozom: Birinci kromozomun sağ kısmı + İkinci kromozomun sol kısmı
    temp1 = kromozom1->ilkGen;
    for (int i = 0; i < uzunluk1; i++) { // Birinci kromozomun sağ kısmı
        if (i >= orta1 + (uzunluk1 % 2 == 0 ? 0 : 1)) { // Orta geni atlama
            yeniKromozom2->genEkle(temp1->gen);
        }
        temp1 = temp1->sonraki;
    }

    temp2 = kromozom2->ilkGen;
    for (int i = 0; i < orta2; i++) { // İkinci kromozomun sol kısmı
        yeniKromozom2->genEkle(temp2->gen);
        temp2 = temp2->sonraki;
    }

    // Yeni kromozomları popülasyona ekleme
    kromozomEkle(yeniKromozom1);
    kromozomEkle(yeniKromozom2);

}



void BagliListe::mutasyon(int kromozomNo, int genNo) {
    // seçilen kromozom numarasına gitme
    BagliListe* mevcutKromozom = this;
    for (int i = 0; i < kromozomNo; i++) {
        if (mevcutKromozom->sonrakiKromozom == nullptr) {
            cout << "Hata: Belirtilen kromozom numarasi gecersiz" << endl;
            return;
        }
        mevcutKromozom = mevcutKromozom->sonrakiKromozom;
    }

    // seçilen gen numarasına gitme
    Dugum* mevcutGen = mevcutKromozom->ilkGen;
    for (int i = 0; i < genNo; i++) {
        if (mevcutGen == nullptr) {
            cout << "Hata: Belirtilen gen numarasi gecersiz" << endl;
            return;
        }
        mevcutGen = mevcutGen->sonraki;
    }

    // seçilen gen var ise mutasyon uygulama
    if (mevcutGen != nullptr) {
        mevcutGen->gen = 'X';  // mutasyon işleminde gen 'X' ile değişir
      
    } else {
        cout << "Hata: Belirtilen gen bulunamadi" << endl;
    }
}


void BagliListe::otomatikIslemler(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    string islem;
    int Kromozom1, Kromozom2, genNumara;

    if (!dosya.is_open()) {
       cout << "islem dosyasi acilamadi" << endl;
        return;
    }

    while (dosya >> islem) {
        if (islem == "C") {
            dosya >> Kromozom1 >> Kromozom2;
            caprazlama(Kromozom1, Kromozom2); // caprazlama
        } else if (islem == "M") {
            dosya >> Kromozom1 >> genNumara;
            mutasyon(Kromozom1, genNumara); // mutasyon
        }
    }

    dosya.close();
}

void BagliListe::ekranaYaz() {

    BagliListe* mevcutKromozom = this;

    while (mevcutKromozom) {
        Dugum* ilkGen = mevcutKromozom->ilkGen;
        if (!ilkGen) {
            mevcutKromozom = mevcutKromozom->sonrakiKromozom;
            continue; // boş kromozom varsa atlar
        }

        Dugum* mevcutGen = ilkGen;
        Dugum* hedefGen = ilkGen; 

        // sağdan sola dolaşma
        while (mevcutGen->sonraki) {
            mevcutGen = mevcutGen->sonraki; 
        }
        //ilk genden küçük bir gen bulana kadar dolaşır sağdan sola doğru
        while (mevcutGen) {
            if (mevcutGen->gen < ilkGen->gen) {
                hedefGen = mevcutGen; 
                break;               
            }
            mevcutGen = mevcutGen->onceki; 
        }

        // bulunan gen yazılır
        cout << hedefGen->gen << " ";
        mevcutKromozom = mevcutKromozom->sonrakiKromozom; // sıradaki kromozoma geçer
    }

    cout << endl; 
}

void BagliListe::dosyadanOkuVeOlustur(const string& dosyaAdi, BagliListe*& dna) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi\n";
        return;
    }

    dna = new BagliListe();
    BagliListe* aktifKromozom = dna;

    string satir;
    while (getline(dosya, satir)) {
        for (char gen : satir) {
            if (gen != ' ') {
                aktifKromozom->genEkle(gen);
            }
        }
        aktifKromozom->sonrakiKromozom = new BagliListe();
        aktifKromozom = aktifKromozom->sonrakiKromozom;
    }

    dosya.close();
}
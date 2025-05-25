/**       
* @file           BagliListe.hpp
* @description    Kromozom üzerinde işlem yapan sınıf
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     1.Ödev
* @date           23.11.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

using namespace std;

#include "Dugum.hpp"

class BagliListe {
public:
    Dugum* ilkGen;
    BagliListe* sonrakiKromozom;

    BagliListe();
    ~BagliListe();  
    
    void genEkle(char gen);
    void kromozomEkle(BagliListe* kromozom);
    void caprazlama(int satir1, int satir2);
    void mutasyon(int kromozomNo, int genNo);
    void otomatikIslemler(const string& dosyaAdi);
    void ekranaYaz();
    void dosyadanOkuVeOlustur(const string& dosyaAdi, BagliListe*& dna);

};

#endif

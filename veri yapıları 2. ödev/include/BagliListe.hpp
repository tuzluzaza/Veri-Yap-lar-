/**       
* @file           BagliListe.hpp
* @description    BagliListe sinifinda kullanilan fonksiyonlarin gösterildigi bölüm
* @course         Bilgisayar Mühendisligi Veri Yapilari 1-A
* @assignment     2.Ödev
* @date           23.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include "Dugum.hpp"
#include "Agac.hpp"
#include <string>

using namespace std;

class BagliListe {
public:
    Dugum* bas;

    BagliListe();
    ~BagliListe();

    void ekle(const string& agac);
    Dugum* getir(int indeks);
    void sil(int indeks);
    int boyut();

    //menu islemleri icin fonksiyonlar
    int hesaplaToplamDeger(const string& agac);
    void menuyaz(int indeks, int sayfaIndeksi, int sayfaBoyutu, bool secilenAgacAynalanmisMi);
    void satirCiz(int sayfaBoyutu);
    void cizgiYaz();
    void degerYaz(const string& deger);
    void isaretYaz(int indeks);
    void dosyaOku(const string& dosyaAdi);
};

#endif
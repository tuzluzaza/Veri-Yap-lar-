/**       
* @file           main.cpp
* @description    Kullanıcının gördüğü arayüz de yapılacak işlemin seçildiği main dosyası
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     2.Ödev
* @date           24.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 


#include <iostream>
#include "BagliListe.hpp"

using namespace std;

int main() {
    BagliListe liste;
    liste.dosyaOku("agaclar.txt");

    int indeks = 0;
    int sayfaIndeksi = 0;
    const int sayfaBoyutu = 10;

    while (true) {
        system("cls");

        Dugum* secili = liste.getir(indeks);

        liste.menuyaz(indeks, sayfaIndeksi, sayfaBoyutu, secili ? secili->aynalanmis : false);

        if (secili) {
            cout << "Secilen Agacin Cizimi:" << endl;

            Agac bst;
            for (char ch : secili->agac) {
                bst.ekle(ch);
            }

            if (secili->aynalanmis) {
                bst = bst.aynalamaYap();
                cout << "Agacin Aynalanmis Hali" << endl;
            }

            bst.ciz();
        } else {
            cout << "Gecerli agac bulunamadi." << endl;
        }
        cout << endl;
        cout << "A (sola git), D (saga git), W (aynalama), S (sil), X (cikis): ";
        char secim;
        cin >> secim;

        if (secim == 'x' || secim == 'X') {
            break;
        } else if (secim == 'a' || secim == 'A') {
            if (indeks > 0)
                indeks--;
            if (indeks < sayfaIndeksi * sayfaBoyutu) {
                sayfaIndeksi--;
            }
        } else if (secim == 'd' || secim == 'D') {
            if (indeks < liste.boyut() - 1)
                indeks++;
            if (indeks >= (sayfaIndeksi + 1) * sayfaBoyutu) {
                sayfaIndeksi++;
            }
        } else if (secim == 'w' || secim == 'W') {
            if (secili) {
                secili->aynalanmis = !secili->aynalanmis;
            }
        } else if (secim == 's' || secim == 'S') {
            liste.sil(indeks);

            if (indeks >= liste.boyut() && indeks > 0) {
                indeks--;
            }

            if (indeks < sayfaIndeksi * sayfaBoyutu && sayfaIndeksi > 0) {
                sayfaIndeksi--;
                indeks = sayfaIndeksi * sayfaBoyutu + (sayfaBoyutu - 1);
                if (indeks >= liste.boyut()) {
                    indeks = liste.boyut() - 1;
                }
            }
        }
    }
    return 0;
}
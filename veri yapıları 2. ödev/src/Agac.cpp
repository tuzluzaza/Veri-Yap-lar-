/**       
* @file           Agac.cpp
* @description    Agac sınıfının fonksiyonları
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     2.Ödev
* @date           19.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include "Agac.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Agac::Agac() {
    for (int i = 0; i < MAX_SIZE; i++) {
        AgacDizisi[i] = ' ';
    }
}

void Agac::ekle(char data) {
    int index = 0;
    while (index < MAX_SIZE && AgacDizisi[index] != ' ') {
        if (data < AgacDizisi[index]) {
            index = 2 * index + 1; //sol cocuk dugum
        } else {
            index = 2 * index + 2;//sag cocuk dugum
        }
    }

    if (index < MAX_SIZE) {
        AgacDizisi[index] = data;
    }
}

Agac Agac::aynalamaYap() {
    Agac aynalanmisAgac;
    aynalamaDugum(0, aynalanmisAgac, 0);
    return aynalanmisAgac;
}

void Agac::aynalamaDugum(int index, Agac& aynalanmisAgac, int yeniIndex) {
    if (index >= MAX_SIZE || AgacDizisi[index] == ' ') {
        return;
    }
    aynalanmisAgac.AgacDizisi[yeniIndex] = AgacDizisi[index];
    aynalamaDugum(2 * index + 1, aynalanmisAgac, 2 * yeniIndex + 2);
    aynalamaDugum(2 * index + 2, aynalanmisAgac, 2 * yeniIndex + 1);
}

void Agac::ciz() {
    // Maksimum seviyeyi bulma
    int seviyeler = 0;
    while ((1 << seviyeler) - 1 < MAX_SIZE) {
        seviyeler++;
    }

    // Her seviyeyi yazdırma
    for (int seviye = 0; seviye < seviyeler; seviye++) {
        int baslangic = (1 << seviye) - 1;  // Seviyenin başlangıç indeksi
        int bitis = (1 << (seviye + 1)) - 2; // Seviyenin bitiş indeksi

        // Boşlukları ayarlama
        int boslukSayisi = pow(2, seviyeler - seviye - 1);
        for (int j = 0; j < boslukSayisi - 1; j++) {
            cout << " ";
        }

        // Seviyedeki düğümleri yazdırma
        for (int i = baslangic; i <= bitis; i++) {
            if (i < MAX_SIZE && AgacDizisi[i] != ' ') {
                cout << AgacDizisi[i];
            } else {
                cout << " ";
            }

            for (int j = 0; j < boslukSayisi * 2 - 1; j++) {
                cout << " ";
            }
        }

        cout << endl;

        // Çocuk bağlantılarının noktalarla dalının çizilmesi
        if (seviye < seviyeler - 1) {
            for (int j = 0; j < (boslukSayisi - 1) / 2; j++) {
                cout << " ";
            }

            for (int i = baslangic; i <= bitis; i++) {
                if (i < MAX_SIZE && AgacDizisi[i] != ' ') {
                    //  sol cocuk noktaları ile baglantı
                    int solCocuk = 2 * i + 1;
                    if (solCocuk < MAX_SIZE && AgacDizisi[solCocuk] != ' ') {
                        for (int k = 0; k < boslukSayisi / 2; k++) {
                            cout << ".";
                        }
                    } else {
                        for (int k = 0; k < boslukSayisi / 2; k++) {
                            cout << " ";
                        }
                    }

                    // sag cocuk noktaları ile baglantı
                    int sagCocuk = 2 * i + 2;
                    if (sagCocuk < MAX_SIZE && AgacDizisi[sagCocuk] != ' ') {
                        for (int k = 0; k < boslukSayisi / 2; k++) {
                            cout << ".";
                        }
                    } else {
                        for (int k = 0; k < boslukSayisi / 2; k++) {
                            cout << " ";
                        }
                    }
                } else {
                    for (int k = 0; k < boslukSayisi; k++) {
                        cout << " ";
                    }
                }

                for (int j = 0; j < (boslukSayisi * 2) / 2; j++) {
                    cout << " ";
                }
            }
            cout << endl;

            
            for (int j = 0; j < (boslukSayisi - 1) / 2; j++) {
                cout << " ";
            }

            for (int i = baslangic; i <= bitis; i++) {
                if (i < MAX_SIZE && AgacDizisi[i] != ' ') {
                    // sol uc alt nokta konulması
                    int solCocuk = 2 * i + 1;
                    if (solCocuk < MAX_SIZE && AgacDizisi[solCocuk] != ' ') {
                        cout << ".";
                    } else {
                        cout << " ";
                    }

                
                    for (int k = 0; k < boslukSayisi - 1; k++) {
                        cout << " ";
                    }

                    // sag uc alt nokta konulması
                    int sagCocuk = 2 * i + 2;
                    if (sagCocuk < MAX_SIZE && AgacDizisi[sagCocuk] != ' ') {
                        cout << ".";
                    } else {
                        cout << " ";
                    }
                } else {
                    
                    for (int k = 0; k < boslukSayisi + 1; k++) {
                        cout << " ";
                    }
                }

                for (int j = 0; j < (boslukSayisi * 2 - 1) / 2; j++) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}

int Agac::hesaplaToplamDeger() {
    int toplamDeger = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (AgacDizisi[i] != ' ') {
            if (i == 0) {
                toplamDeger += AgacDizisi[i];
            } else if (i % 2 == 1) {
                toplamDeger += 2 * AgacDizisi[i];
            } else {
                toplamDeger += AgacDizisi[i];
            }
        }
    }
    return toplamDeger;
}

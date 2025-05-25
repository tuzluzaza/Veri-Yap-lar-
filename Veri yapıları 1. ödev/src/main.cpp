/**       
* @file           main.cpp
* @description    Kullanıcın gördüğü arayüz de yapılacak işlemin seçildiği main dosyası
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     1.Ödev
* @date           23.11.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include <iostream>
#include <fstream>
#include "BagliListe.hpp"
#include <sstream>

using namespace std;

int main() {
        
    BagliListe* dna = nullptr;
    dna->dosyadanOkuVeOlustur("Dna.txt", dna);

    int secim;
    do {
        cout << endl;
        cout << "1- Caprazlama\n2- Mutasyon\n3- Otomatik Islemler\n4- Ekrana Yaz\n5- Cikis\nSecim: ";
        cin >> secim;

        switch (secim) {

        case 1: {
            int satir1, satir2;
            cout << "Caprazlama icin iki kromozomun satir numarasini girin: ";
            cin >> satir1 >> satir2;
            dna->caprazlama(satir1, satir2);
                cout << "Caprazlama Tamamlandi"<< endl;
            break;
}
        case 2:{ int kromozomNo, genNo;
                cout << "Mutasyon icin kromozom numarasini girin: ";
                cin >> kromozomNo;
                cout << "Mutasyon icin gen numarasini girin: ";
                cin >> genNo;

                dna->mutasyon(kromozomNo, genNo);
                cout << "Mutasyon tamamlandi." << endl;

                break;}
   
        case 3: {
                cout << "Otomatik islemler basliyor..." << endl;
                dna->otomatikIslemler("Islemler.txt");
                cout << "Otomatik islemler Tamamlandi" << endl;
                break;
}
        case 4: {
                cout << "Kromozomlarin en kucuk genleri yazdiriliyor" << endl;
                dna->ekranaYaz();

                break;
}
        }
    } while (secim != 5);

    return 0;
}



/**       
* @file           Agac.hpp
* @description    Agac sınıfında kullanılan fonksiyonların gösterildiği bölüm
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     2.Ödev
* @date           15.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#ifndef AGAC_HPP
#define AGAC_HPP

#define MAX_SIZE 127

using namespace std;

class Agac {
public:

    char AgacDizisi[MAX_SIZE];

    Agac();
   
    void ekle(char data);
    Agac aynalamaYap();
    void ciz();
    int hesaplaToplamDeger();

private:

    void aynalamaDugum(int index, Agac& aynalanmisAgac, int yeniIndex);
};

#endif

/**       
* @file           Dugum.hpp
* @description    Dugum sınıfı
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     2.Ödev
* @date           12.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <string>
using namespace std;

class Dugum {
public:

    string agac;      // Agacin verisi 
    bool aynalanmis;  // Aynalanma durumu
    Dugum* sonraki;   // Bagli listedeki sonraki dugum

    Dugum(const string& agac);
    ~Dugum();
};

#endif
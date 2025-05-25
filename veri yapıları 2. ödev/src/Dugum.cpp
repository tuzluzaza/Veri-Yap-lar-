/**       
* @file           Dugum.cpp
* @description    Dugum sınıfı cppsi
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     2.Ödev
* @date           10.12.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include "Dugum.hpp"

//yapici fonksiyon
Dugum::Dugum(const string& agac)
    : agac(agac), aynalanmis(false), sonraki(nullptr) {}

//yikici fonksiyon
Dugum::~Dugum() {}
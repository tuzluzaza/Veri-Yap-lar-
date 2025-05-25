/**       
* @file           Dugum.cpp
* @description    Dugumlerin kurulduğu yer
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     1.Ödev
* @date           23.11.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#include "Dugum.hpp"

Dugum::Dugum(char gen) {
    
    this->gen = gen;
    this->onceki = nullptr;
    this->sonraki = nullptr;
}

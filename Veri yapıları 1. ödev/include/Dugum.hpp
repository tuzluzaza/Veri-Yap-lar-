/**       
* @file           Dugum.hpp
* @description    Gen üzerinde işlem yapan sınıf
* @course         Bilgisayar Mühendisliği Veri Yapıları 1-A
* @assignment     1.Ödev
* @date           23.11.2024
* @author         Abdullah Anıl Çobaner B231210097  abdullah.cobaner@ogr.sakarya.edu.tr
*/ 

#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    char gen;
    Dugum* onceki;
    Dugum* sonraki;
    Dugum(char gen);
};

#endif

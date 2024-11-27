/**
* Dosya adı = Gen.cpp  
* Bu dosya Gen.hpp dosyasindaki classin 
* fonksiyonlarinin govde kismini doldurmak icindir.
* 1. Ogretim C grubu
* 1. Odev
* 04/11/2024 Pazartesi
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/
 
 #include "../include/Gen.hpp"

Gen::Gen(char cDeger) : cDeger(cDeger) , pNext(nullptr) , pPrev(nullptr) {}

char Gen::getDeger() {
    return cDeger;
}

void Gen::setDeger(char cValue){
    cDeger = cValue;
}

void Gen::mutasyon(){
    cDeger = 'X';
}

void Gen::setNext(Gen* gNext){
    pNext = gNext;
}

void Gen::setPrev(Gen* gPrev){
    pPrev = gPrev;
}

Gen* Gen::getNext(){
    return pNext;
}

Gen* Gen::getPrev(){
    return pPrev;
}

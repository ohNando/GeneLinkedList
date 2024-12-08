/**
* @file             Gen.cpp  
* @description      Bu dosya Gen.hpp dosyasindaki classin 
*                   fonksiyonlarinin govde kismini doldurmak icindir.
* @course           1. Ogretim C grubu
* @assignment       1. Odev
* @date             04/11/2024 Pazartesi
* @author           Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/
 
 #include "../include/Gen.hpp"

Gen::Gen(char cDeger) : cDeger(cDeger) , pNext(nullptr) , pPrev(nullptr) {} //Gen kurucu fonksiyonu
Gen::~Gen(){
    pNext = nullptr;
    pPrev = nullptr;
    cDeger = '\0';
}

char Gen::getDeger() {
    return cDeger;  //Deger kismi private oldugu icin dogrudan kullanamiyoruz
}                   //Bu sebeple ulasmak icin bu ve asagidaki fonksiyonlara ihtiyacimiz vardir

void Gen::setDeger(char cValue){
    cDeger = cValue;
}

void Gen::mutasyon(){   //Mutasyon teknik olarak sadece genin degerini X olarak degistirmektir
    cDeger = 'X';       //bu yuzden bu fonksiyon genin degerini X olarak degistiriyor
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

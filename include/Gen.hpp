/**
* Dosya adı = Gen.hpp
* BU dosya gen classinin bulundugu dosyadir . 
* CLass a ait kurucu fonksioyon ve diger alt fonksiyonlar burada bulunur.
* 1. Ogretim C grubu
* 1. Odev
* 04/11/2024 Pazar
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#ifndef GEN_HPP
#define GEN_HPP

class Gen {
public:
    Gen(char cDeger);
    char getDeger();    // Bu kisim degeri atamak ve geri dondurmek icindir
    void setDeger(char cValue); 
    void mutasyon();    // Bu fonksiyon geni mutasyon gecirtmek kisaca degerini degistirmek icindir

    Gen* getNext();
    Gen* getPrev(); //Bu kisim linked list icin gereken sonraki ve onceki elemani
    void setNext(Gen* gNext);   //geri dondurmek ya da degerini atamak icindir
    void setPrev(Gen* gPrev);
private:
    char cDeger;
    Gen* pNext;
    Gen* pPrev;
};

#endif 
/**
* Dosya adı = Kromozom.hpp  
* BU dosya kromozom classinin bulundugu ve kromozom ile yapilacak fonksiyonlarin tanimlandigi kutuphane dosyasidir
* 1. Ogretim C grubu
* 1. Odev
* 03/11/2024 pazar
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"

class Kromozom{
    public:
        Kromozom();
        ~Kromozom();

        void genEkle(char cDeger);
        void caprazla(Kromozom* kromozom,Kromozom* newKromozom1,Kromozom* newKromozom2);
        void genYazdir();

        Kromozom* getNext();
        Kromozom* getPrev();
        Gen* getHead();
        Gen* getTail();
        void setNext(Kromozom* kNext);
        void setPrev(Kromozom* kPrev);
        Gen* ortaBul();

    private:
    Kromozom* pNext;
    Kromozom* pPrev;
    Gen* pHead;
    Gen* pTail;
};

#endif 
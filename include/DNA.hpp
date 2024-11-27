/**
* Dosya adı = DNA.hpp  
* Bu dosya dna class yapisini ve bu class icin gereken fonksiyonlari tanimlamak icin kullanilir.
* 1. Ogretim C grubu
* 1. Odev
* 05/11/2024 sali
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#ifndef DNA_HPP
#define DNA_HPP

#include "Kromozom.hpp"
#include <fstream>

class DNA {
    public:
        DNA();
        ~DNA();

        bool dosyaOku(const char* fileName);

        void caprazla(int iKromozom1Index,int iKromozom2Index);
        void mutasyon(int iKromozomIndex, int iGenIndex);

        void ekranaYaz();
        void ekranaYazNormal();

        void islemler(const char* fileName);

        void kromozomEkle(Kromozom* kromozom);
        Kromozom* getKromozom(int index);
        Kromozom* getHead();
        Kromozom* getTail();
    private:
        Kromozom* pHead;
        Kromozom* pTail;
};

#endif
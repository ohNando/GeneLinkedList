/**
* @file             DNA.hpp  
* @description      Bu dosya dna class yapisini ve bu class icin gereken fonksiyonlari tanimlamak icin kullanilir.
* @course           1. Ogretim C grubu
* @assignemnt       1. Odev
* @date             05/11/2024 sali
* @author           Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#ifndef DNA_HPP
#define DNA_HPP

#include "Kromozom.hpp"
#include <fstream>

class DNA {
    public:
        DNA();  //DNA kurucu fonksiyonu
        ~DNA(); //DNA yikici fonksiyonu

        bool dosyaOku(const char* fileName); //DOsyadan okuma fonksiyonu
        void caprazla(int iKromozom1Index,int iKromozom2Index); //Caprazlama fonksiyonu
        void mutasyon(int iKromozomIndex, int iGenIndex);   //Mutasyon yapmak icin fonksiyon
        void ekranaYaz();   //Kurala gore ekrana yazma fonksiyonu
        void islemler(const char* fileName);    //Otomatik islemler fonksiyonu

        void kromozomEkle(Kromozom* kromozom);  //DNA ya kromozom ekleme fonksiyonu
        Kromozom* getKromozom(int index);   //Kromozomun privatine ulasmak icin gereken fonksiyonlar
        Kromozom* getHead();
        Kromozom* getTail();
    private:
        Kromozom* pHead;
        Kromozom* pTail;
};

#endif
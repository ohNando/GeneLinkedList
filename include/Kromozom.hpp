/**
* @file                 Kromozom.hpp  
* @description          Bu dosya kromozom classinin bulundugu ve kromozom ile yapilacak
                        fonksiyonlarin tanimlandigi kutuphane dosyasidir
* @couurse              1. Ogretim C grubu
* @assignment           1. Odev
* @date                 03/11/2024 pazar
* @author               Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"  //Gen classindan gelen bilgileri de kullanmak icin bu kutuphane kullanilir

class Kromozom{
    public:
        Kromozom(); //Kurucu fonksiyon
        ~Kromozom();//Yikici fonksiyon

        void genEkle(char cDeger);  //Gen ekleme fonksiyonu
        void caprazla(Kromozom* kromozom,Kromozom* newKromozom1,Kromozom* newKromozom2);//Caprazlama fonksiyonu
        void genYazdir();//Genleri yazdirma fonksiyonu

        Kromozom* getNext();//Private kullanamdigimiz icin asagidaki fonksiyonlar 
        Kromozom* getPrev();//ile dogrudan olmasada dolayli yoldan private ulasmak icin kullanilir
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
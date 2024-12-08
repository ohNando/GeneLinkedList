/**
* @file             DNA.cpp
* @description      Bu dosya dna.hpp dosyasinda bulunan fonksiyonlarin govde kisminin oldugu yerdir.
* @course           1. Ogretim C grubu
* @assignment       1. Odev
* @date             07/11/2024 persembe
* @course           Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include "../include/DNA.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>

DNA::DNA() : pHead(nullptr) , pTail(nullptr) {} //DNA kurucu fonksiyon

Kromozom* DNA::getHead(){   //Head kismi private de oldugundan dolayi dogrudan 
    return pHead;           //erisim yok bu yuzden bu fonksiyonu kullaniyoruz
}

Kromozom* DNA::getTail(){   //Tail kismi private de oldugundan dolayi dogrudan 
    return pTail;           //erisim yok bu yuzden bu fonksiyonu kullaniyoruz
}

DNA::~DNA(){    //DNA yikici fonksiyon
    Kromozom* kNew = pHead;
    while(kNew != nullptr){
        Kromozom* kTemp = kNew->getNext();
        delete kNew;
        kNew = kTemp;
    }
}

void DNA::kromozomEkle(Kromozom* kromozom){ //DNA ya yeni kromozom ekleme islemi
    if(!kromozom){  //Eger kromozom bulunamamissa hata
        std::perror("EKlenecek kromozom hatasi!!\n");
        return;
    }

    if(pHead == nullptr){   //hic eleman yok ise head ve tail kendisi olur
        pHead = kromozom;
        pTail = kromozom;
    }else {
        pTail->setNext(kromozom);
        kromozom->setPrev(pTail);
        pTail = kromozom;
    }
}

Kromozom* DNA::getKromozom(int index){  //Indexi verilen kromozomun headini dondurme islemi
    Kromozom* kTemp = pHead;    //Ara bir eleman olusturulup tum kromozomlar arasi dolasarak kromozom bulunur
    for(int i=0;i < index && kTemp; ++i){
        kTemp = kTemp->getNext();
    }
    return kTemp;
}

bool DNA::dosyaOku(const char* fileName){   //Filedaki genleri birlestirip DNA yapisini
    std::ifstream pFile(fileName);       // ic ice 2 liste haline getirme islemi
    if(!pFile.is_open()){
        std::perror("Dosya acilamadi!!");   //Dosya acilamamissa hata
        return false;
    }

    Kromozom* kromozom = new Kromozom(); 
    char karakter;
    while(pFile.get(karakter)){
        switch (karakter)
        {
        case ' ':   
            break;
        case '\n':
            this->kromozomEkle(kromozom);   //Alt satira gecmis ise kromozomlari DNA ya ekleme
            kromozom = new Kromozom();
            break;
        default:
            kromozom->genEkle(karakter);    //Dosyadan genler okunarak kromozomlara 
            break;
        }
    }
    pFile.close();
    return true;
}

void DNA::caprazla(int iKromozom1Index, int iKromozom2Index) {  //indexleri verilen fonksiyonlari caprazlama islemi
    Kromozom* kromozom1 = getKromozom(iKromozom1Index);
    Kromozom* kromozom2 = getKromozom(iKromozom2Index); //Gerekli kromozomlar index yardimiyla bulunur

    if (kromozom1 == nullptr || kromozom2 == nullptr) {
        std::perror("Kromozom bulunamadi!!\n"); //Kromozomlar yok ise hata dondurulur
        return;
    }

    std::cout << "Caprazlamaya giren kromozomlar : " << std::endl;
    std::cout << "1. Kromozom : ";
    kromozom1->genYazdir();     //Caprazlamaya girmeden once kromozomun genleri yazdirilir
    std::cout << "\n2. Kromozom : ";
    kromozom2->genYazdir();
    std::cout << std::endl;

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();   //Yeni olusan genler olusturulur

    kromozom1->caprazla(kromozom2, yeniKromozom1, yeniKromozom2);   //Caprazlama islemi

    if (yeniKromozom1 == nullptr || yeniKromozom2 == nullptr) {
        std::perror("Kromozom olusturulamadi!!\n");
        delete yeniKromozom1;   //Eger caprazlamadan sonra bir sorun olusmussa hata verilip 
        delete yeniKromozom2;   //new ile olusuturaln elemanlar memory leak olmamasi icin silinir
        return;
    }

    kromozomEkle(yeniKromozom1);    //Yeni kromozomlar DNA ya eklenir   
    kromozomEkle(yeniKromozom2);

    std::cout << "Caprazlama sonucu yeni kromozomlar : " << std::endl;
    std::cout << "1. yeni kromozom : "; yeniKromozom1->genYazdir(); //Ve yeni kromozomlarin genleri yazdirilir
    std::cout << std::endl << "2. yeni kromozom : "; yeniKromozom2->genYazdir();
    std::cout << std::endl;
}

void DNA::mutasyon(int iKromozomIndex, int iGenIndex) { //indexi verilen kromozomun ,indexi verilen genini mutasyona ugratan islem
    Kromozom* kromozom = getKromozom(iKromozomIndex);   //Index yardimiyla kromozom bulunur

    if (kromozom == nullptr) {  //Eger kromozom yok ise hata dondurulur
        std::perror("Gecersiz kromozom indexi!!\n");
        return;
    }

    Gen* gen = kromozom->getHead();                 //Genler kromozomun basindan basliyarak 
    for (int i = 0; i < iGenIndex && gen; ++i) {    //Mutasyon gecirecek gen bulunur
        gen = gen->getNext();
    }

    if (gen) {   //Eger gen var ise mutasyon islemi gerceklesir
        gen->mutasyon();
    } else {    //Eger yok ise hata dondurulur
        std::perror("Gecersiz gen indexi!!\n");
        return;
    }
}

void DNA::ekranaYaz() { //Belirtilen kurala gore ekrana yazdirma fonksiyonu
    Kromozom* kromozom = getHead(); 

    while (kromozom != nullptr) {   
        Gen* gen = kromozom->getTail(); //Yazdirilacak kromozomun sonundaki genden basliyarak

        if (gen == nullptr) {   //Eger o kromozom yok ise diger kromozoma gecilir
            kromozom = kromozom->getNext();
            continue;
        }

        char cTempGen = gen->getDeger();    //Gecici bir degisken olusturulur ve son genin degeri atanir
        while (gen != nullptr) {
            if (gen->getDeger() < cTempGen) {   //eger deger bastaki elemandan buyukse bir onceki elemana gecer 
                cTempGen = gen->getDeger();
            }
            gen = gen->getPrev();
        }
        std::cout << cTempGen << " ";   //ve bu sekilde en kucuk gen bulunup yazdirilir
        
        kromozom = kromozom->getNext(); //ve bir sonraki kromozomza gecer taki DNAyi tamamen dolasana kadar
    }
    std::cout << std::endl;
}

void DNA::islemler(const char* fileName) {  //Otomatik islemleri islemler.txt den okuyup
    std::ifstream pFile(fileName);          //islemleri gerceklestiren fonksiyon

    if (!pFile.is_open()) { //Eger dosya acilamazsa hata verir
        std::perror("Dosya acilamadi!!");
        return;
    }

    std::string line;   //Her bir satiri ayristip incelemek icin string olusturulur
    while (std::getline(pFile, line)) { //Dosyadaki satirlar bitene kadar yani dosya tamamen dolasacak
        char islem = '\0'; 
        int index1 = -1, index2 = -1;
        int sayi = 0;
        bool sayiOkundu = false;    //Bosluk karakterini ayirmak icin kullanilir
        int iSayiSayac = 0; //Kac sayi okundugunu anlamak icin kullanilir

        for (size_t i = 0; i <= line.size(); ++i) { 
            char ch = (i < line.size()) ? line[i] : ' '; // Satır sonu gibi davran

            if (ch == 'C' || ch == 'M') {
                islem = ch; 
            } else if (ch >= '0' && ch <= '9') {
                sayi = sayi * 10 + (ch - '0');  //Sayi eger birden fazla basamagi var ise sayiya eklenir
                sayiOkundu = true;
            } else {
                if (sayiOkundu) {
                    if (iSayiSayac == 0) index1 = sayi;
                    else if (iSayiSayac == 1) index2 = sayi;
                    iSayiSayac++;
                    sayi = 0;
                    sayiOkundu = false;
                }
            }
        }
        if (islem == 'C' && index1 >= 0 && index2 >= 0) {   //ve sayi kontrol edilerek uygun isleme sokulur
            std::cout << "Caprazlama Islemi: " << index1 << ", " << index2 << std::endl;
            this->caprazla(index1, index2);
        } else if (islem == 'M' && index1 >= 0 && index2 >= 0) {
            std::cout << "Mutasyon Islemi: " << index1 << ", " << index2 << std::endl;
            this->mutasyon(index1, index2);
        } else {    //eger bunlarin disinda bir islem gelmisse hata doner
            std::perror("Hatali satir veya eksik bilgi !!\n");
        }
    }

    pFile.close();
}
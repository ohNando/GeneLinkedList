/**
* Dosya adı = main.cpp  
* BU dosya dna.hpp dosyasinda bulunan fonksiyonlarin govde kisminin oldugu yerdir.
* 1. Ogretim C grubu
* 1. Odev
* 07/11/2024 persembe
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include "../include/DNA.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>

DNA::DNA() : pHead(nullptr) , pTail(nullptr) {}

Kromozom* DNA::getHead(){
    return pHead;
}

Kromozom* DNA::getTail(){
    return pTail;
}

DNA::~DNA(){
    Kromozom* kNew = pHead;
    while(kNew != nullptr){
        Kromozom* kTemp = kNew->getNext();
        delete kNew;
        kNew = kTemp;
    }
}

void DNA::kromozomEkle(Kromozom* kromozom){
    if(!kromozom){
        std::perror("EKlenecek kromozom hatasi!!\n");
        return;
    }

    if(pHead == nullptr){
        pHead = kromozom;
        pTail = kromozom;
    }else {
        pTail->setNext(kromozom);
        kromozom->setPrev(pTail);
        pTail = kromozom;
    }
}

Kromozom* DNA::getKromozom(int index){
    Kromozom* kTemp = pHead;
    for(int i=0;i < index && kTemp; ++i){
        kTemp = kTemp->getNext();
    }
    return kTemp;
}

bool DNA::dosyaOku(const char* fileName){
    Kromozom* kromozom = new Kromozom();
    std::ifstream pFile(fileName);

    if(!pFile.is_open()){
        std::perror("Dosya acilamadi!!");
        delete kromozom;
        return false;
    }

    char karakter;
    while(pFile.get(karakter)){
        switch (karakter)
        {
        case ' ':
            break;
        case '\n':
            this->kromozomEkle(kromozom);
            kromozom = new Kromozom();
            break;
        default:
            kromozom->genEkle(karakter);
            break;
        }
    }
    pFile.close();
    return true;
}

void DNA::caprazla(int iKromozom1Index, int iKromozom2Index) {
    Kromozom* kromozom1 = getKromozom(iKromozom1Index);
    Kromozom* kromozom2 = getKromozom(iKromozom2Index);

    if (kromozom1 == nullptr || kromozom2 == nullptr) {
        std::perror("Kromozom bulunamadi!!\n");
        return;
    }

    std::cout << "Caprazlamaya giren kromozomlar : " << std::endl;
    std::cout << "1. Kromozom : ";
    kromozom1->genYazdir();
    std::cout << "\n2. Kromozom : ";
    kromozom2->genYazdir();
    std::cout << std::endl;

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    kromozom1->caprazla(kromozom2, yeniKromozom1, yeniKromozom2);

    if (yeniKromozom1 == nullptr || yeniKromozom2 == nullptr) {
        std::perror("Kromozom olusturulamadi!!\n");
        delete yeniKromozom1;
        delete yeniKromozom2;
        return;
    }

    kromozomEkle(yeniKromozom1);
    kromozomEkle(yeniKromozom2);

    std::cout << "Caprazlama sonucu yeni kromozomlar : " << std::endl;
    std::cout << "1. yeni kromozom : "; yeniKromozom1->genYazdir();
    std::cout << std::endl << "2. yeni kromozom : "; yeniKromozom2->genYazdir();
    std::cout << std::endl;
}

void DNA::mutasyon(int iKromozomIndex, int iGenIndex) {
    Kromozom* kromozom = getKromozom(iKromozomIndex);

    if (kromozom == nullptr) {
        std::perror("Gecersiz kromozom indexi!!\n");
        return;
    }

    Gen* gen = kromozom->getHead();
    for (int i = 0; i < iGenIndex && gen; ++i) {
        gen = gen->getNext();
    }

    if (gen != nullptr) {
        gen->mutasyon();
    } else {
        std::perror("Gecersiz gen indexi!!\n");
        return;
    }
}

void DNA::ekranaYaz() {
    Kromozom* kromozom = getHead();

    while (kromozom != nullptr) {
        Gen* gen = kromozom->getTail();

        if (gen == nullptr) {
            kromozom = kromozom->getNext();
            continue;
        }

        char cTempGen = gen->getDeger();
        while (gen != nullptr) {
            if (gen->getDeger() < cTempGen) {
                cTempGen = gen->getDeger();
            }
            gen = gen->getPrev();
        }
        std::cout << cTempGen << " ";
        
        kromozom = kromozom->getNext();
    }
    std::cout << std::endl;
}

void DNA::ekranaYazNormal(){
    Kromozom* kromozom = getHead();
    while(kromozom != nullptr){
        kromozom->genYazdir();
        kromozom = kromozom->getNext();
    }
    
}

void DNA::islemler(const char* fileName) {
    std::ifstream pFile(fileName);

    if (!pFile.is_open()) {
        std::perror("Dosya acilamadi!!");
        return;
    }

    std::cout << "Islem baslatildi" << std::endl;

    std::string line;

    while (std::getline(pFile, line)) {
        char islem = '\0';
        int index1 = -1, index2 = -1;
        int sayi = 0;
        bool sayiOkundu = false;
        int iSayiSayac = 0;

        for (size_t i = 0; i <= line.size(); ++i) { 
            char ch = (i < line.size()) ? line[i] : ' '; // Satır sonu gibi davran

            if (ch == 'C' || ch == 'M') {
                islem = ch; 
            } else if (ch >= '0' && ch <= '9') {
                sayi = sayi * 10 + (ch - '0');
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
        if (islem == 'C' && index1 >= 0 && index2 >= 0) {
            std::cout << "Caprazlama Islemi: " << index1 << ", " << index2 << std::endl;
            this->caprazla(index1, index2);
        } else if (islem == 'M' && index1 >= 0 && index2 >= 0) {
            std::cout << "Mutasyon Islemi: " << index1 << ", " << index2 << std::endl;
            this->mutasyon(index1, index2);
        } else {
            std::perror("Hatali satir veya eksik bilgi !!\n");
        }
    }

    pFile.close();
}
/**
* @file             Kromozom.cpp  
* @description      Bu dosya kromozom.hpp dosyasindaki kromozom classindaki 
*                   fonksiyonlarin govde kisminin yazildigi dosyadir.
* @assignemnt       1. Ogretim C grubu
* @course           1. Odev
* @date             03/11/2024 pazar
* @author           Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include "../include/Kromozom.hpp"
#include <iostream>

Kromozom::Kromozom() : pNext(nullptr) , pPrev(nullptr), pHead(nullptr) , pTail(nullptr) {}  //Kromozom kurucu fonksiyonu

Kromozom::~Kromozom(){  //Kromozom yikici fonksiyonu
    Gen* gNew = pHead;
    Gen* gTemp;
    while(gNew){
        gTemp = gNew->getNext();
        delete gNew;
        gNew = gTemp;
    }
}

Kromozom* Kromozom::getNext(){  //Bu asagidaki fonksiyonlar private bolgeye ulasamadigimiz icin 
    return pNext;               //Degerleri degistirmek ya da ulasmak icin kullanilir
}                   

Kromozom* Kromozom::getPrev(){
    return pPrev;
}

Gen* Kromozom::getHead(){
    return pHead;
}

Gen* Kromozom::getTail(){
    return pTail;
}

void Kromozom::setNext(Kromozom* kNext){
    pNext = kNext;
}

void Kromozom::setPrev(Kromozom* kPrev){
    pPrev = kPrev;
}

void Kromozom::genEkle(char cDeger){    //Bu fonksiyon Kromozoma gen eklemek icin kullanilir
    Gen* gNew = new Gen(cDeger);

    if(pHead == nullptr){   //Eger head bossa yani eleman yoksa yeni eleman hem head hem de tail olur
        pHead = gNew;
        pTail = gNew;
    }else{
        pTail->setNext(gNew);
        gNew->setPrev(pTail);
        pTail = gNew;
    }
}

Gen* Kromozom::ortaBul() {  //Bu fonksiyon verilen kromozomun orta elemanini geri dondurur
    Gen* first = pHead;     //ilk eleman birer ilerlerken ikinci eleman iki kere ilerler
    Gen* last = pHead;

    while(last != nullptr && last->getNext() != nullptr){   //Bu sekilde son eleman listenin sonuna ulastiginda 
        first = first->getNext();                           //ilk eleman listenin ortasina ulasir
        last = last->getNext()->getNext();
    }
    return first;
}

void Kromozom::caprazla(Kromozom* kromozom, Kromozom* newKromozom1, Kromozom* newKromozom2) {   //BU fonksiyon caprazlama islemini gerceklestiri
    Gen* gMiddle1 = this->ortaBul();    //Iki kromozomunda orta noktasi bulunur
    Gen* gMiddle2 = kromozom->ortaBul();    

    if (gMiddle1 == nullptr || gMiddle2 == nullptr) {   //Orta noktalar yoksa uyari verilir
        std::perror("Kromozomlarin orta elemani olusturulamadi!!\n");
        return; 
    }

    Gen* gTemp = this->pHead;   //1. elemanin orta noktasi gecici bir elemana verilir caprazlama islemi gerceklestirir
    while (gTemp != gMiddle1) {
        newKromozom1->genEkle(gTemp->getDeger());
        gTemp = gTemp->getNext();
    }

    gTemp = gMiddle2;
    while (gTemp != nullptr) {
        newKromozom1->genEkle(gTemp->getDeger());
        gTemp = gTemp->getNext();
    }

    gTemp = kromozom->getHead();
    while (gTemp != gMiddle2) {
        newKromozom2->genEkle(gTemp->getDeger());
        gTemp = gTemp->getNext();
    }

    gTemp = gMiddle1;
    while (gTemp != nullptr) {
        newKromozom2->genEkle(gTemp->getDeger());
        gTemp = gTemp->getNext();
    }
}


void Kromozom::genYazdir(){ //Bu fonksiyon kromozomun genlerini yazdirir
    Gen* gNew = getHead();

    while(gNew != nullptr){
        std::cout << gNew->getDeger() << " ";
        gNew = gNew->getNext();
    }
    std::cout << std::endl;
}






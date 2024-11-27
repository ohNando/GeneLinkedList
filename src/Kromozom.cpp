/**
* Dosya adı = Kromozom.cpp  
* Bu dosya kromozom.hpp dosyasinda ki kromozom classindaki 
* 1. Ogretim C grubu
* 1. Odev
* 03/11/2024 pazar
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include "../include/Kromozom.hpp"
#include <iostream>

Kromozom::Kromozom() : pNext(nullptr) , pPrev(nullptr), pHead(nullptr) , pTail(nullptr) {}

Kromozom::~Kromozom(){
    Gen* gNew = pHead;
    Gen* gTemp;
    while(gNew){
        gTemp = gNew->getNext();
        delete gNew;
        gNew = gTemp;
    }
}

Kromozom* Kromozom::getNext(){
    return pNext;
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

void Kromozom::genEkle(char cDeger){
    Gen* gNew = new Gen(cDeger);

    if(pHead == nullptr){
        pHead = gNew;
        pTail = gNew;
    }else{
        pTail->setNext(gNew);
        gNew->setPrev(pTail);
        pTail = gNew;
    }
}

Gen* Kromozom::ortaBul() {
    Gen* first = pHead;
    Gen* last = pHead;

    while(last != nullptr && last->getNext() != nullptr){
        first = first->getNext();
        last = last->getNext()->getNext();
    }
    return first;
}

void Kromozom::caprazla(Kromozom* kromozom, Kromozom* newKromozom1, Kromozom* newKromozom2) {
    Gen* gMiddle1 = this->ortaBul();
    Gen* gMiddle2 = kromozom->ortaBul();

    if (gMiddle1 == nullptr || gMiddle2 == nullptr) {
        std::perror("Kromozomlarin orta elemani olusturulamadi!!\n");
        return;
    }

    Gen* gTemp = this->pHead;
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


void Kromozom::genYazdir(){
    Gen* gNew = getHead();

    while(gNew != nullptr){
        std::cout << gNew->getDeger() << " ";
        gNew = gNew->getNext();
    }
    std::cout << std::endl;
}






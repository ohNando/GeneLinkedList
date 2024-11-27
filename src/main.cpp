/**
* Dosya adı = main.cpp  
* bu dosya programin calistigi ana dosya olarak dusunebiliriz
* 1. Ogretim C grubu
* 1. Odev
* 03/11/2024 pazar
* Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include "../include/DNA.hpp"

using namespace std;
using namespace std::chrono;

const char* dosyaAdi = "/home/ohnando/Projects/Homeworks/dataStructures/B231210051/Dna.txt";
const char* islemlerDosya = "/home/ohnando/Projects/Homeworks/dataStructures/B231210051/Islemler.txt";

void ekraniTemizle() {
#ifdef _WIN32
    system("cls");  
#else
    system("clear");
#endif
}

void menu(){
    cout << "\n|-----DNA ISLEM MENUSU-------|" << endl;
    cout << "|      (1) Caprazlama        |" << endl;
    cout << "|       (2) Mutasyon         |" << endl;
    cout << "|    (3) Otomatik Islemler   |" << endl;
    cout << "|       (4) Ekrana Yaz       |" << endl;
    cout << "|         (5) Cikis          |" << endl;
    cout << "|----------------------------|" << endl;
    cout << "Seciminiz -->";
}

int main(){
    DNA* dna = new DNA();

    auto start = high_resolution_clock::now();
    if(dna->dosyaOku(dosyaAdi)){
        cout << "(+) " << dosyaAdi << " dosyasindan DNA yuklendi!!\n";
    }else{
        std::perror("(-) Dosyadan DNA yuklenemedi!!");
        return 1;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    

    int iSecim;
    int kromozomIndex1 ,kromozomIndex2;

    do{
        ekraniTemizle();
        cout << duration.count() << "ms" << endl;
        menu();
        cin>> iSecim;

        switch (iSecim){
            case 1: {
                cout << "Caprazlamak istediginiz 1. kromozomun indexini giriniz -->";
                cin >> kromozomIndex1;
                cout << "Caprazlamak istediginiz 2. kromozomun indexini giriniz -->";
                cin >> kromozomIndex2;

                dna->caprazla(kromozomIndex1,kromozomIndex2);
                cout << "Caprazlama islemi tamamlandi! Yeni olusan kromozomlar DNA'ya eklendi !" << endl;
                cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << endl;
                sleep(1);
                break;
            }case 2: {
                int genIndex;
                cout << "Mutasyon uygulamak istediginiz kromozom indexini giriniz -->";
                cin >> kromozomIndex1;
                cout << "Mutasyon uygulamak istediginiz gen indexini giriniz -->";
                cin >> genIndex;

                dna->mutasyon(kromozomIndex1,genIndex);
                cout << "Mutasyon islemi tamamlandi! Gen basariyla guncellendi !" << endl;
                cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << endl;
                sleep(1);
                break;
            }case 3: {
                sleep(1);
                cout << "Islemler basliyor ..." << endl;
                start = high_resolution_clock::now();
                dna->islemler(islemlerDosya);
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                cout << duration.count() << "ms" << endl;
                sleep(1);
                cout << "Islemler bitti !!" << endl;
                cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << endl;
                sleep(1);
                break;
            }case 4: {
                cout << "DNA'nin mevcut durumu :" << endl;
                start = high_resolution_clock::now();
                dna->ekranaYazNormal();
                //dna->ekranaYaz();
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                cout << duration.count() << "ms" << endl;
                sleep(1);
                cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << endl;
                sleep(1);
                
                break;
            }case 5:
                cout << "Programdan cikiliyor!!" << endl;
                cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << endl;
                sleep(1);
                break;
            default:
                perror("Yanlis ya da eksik bir secim yaptiniz!!");
                break;
        }

    }while(iSecim != 5);
    
    delete dna;
    return 0;
}
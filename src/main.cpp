/**
* @file             main.cpp  
* @description      bu dosya programin calistigi ana dosya olarak dusunebiliriz
* @course           1. Ogretim C grubu
* @assignment       1. Odev
* @date             03/11/2024 pazar
* @author            Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include "../include/DNA.hpp"

const char* dosyaAdi = "/home/ohnando/Projects/Homeworks/dataStructures/B231210051/Dna.txt";
const char* islemlerDosya = "/home/ohnando/Projects/Homeworks/dataStructures/B231210051/Islemler.txt";
//Dosya yollari bir degiskene verilerek sureklilik onlenmistir , const yapilarak duzenlenmesi engellenir

void ekraniTemizle() {  //Bu fonksiyon linux ve windows farkindan dolayi konmustur
#ifdef _WIN32
    system("cls");  
#else
    system("clear");
#endif
}

int main(){
    DNA* dna = new DNA();   //Islemleri yapmak icin heapden bir dna degiskeni olusturulur

    auto start = std::chrono::high_resolution_clock::now(); //Dosyadan verileri alirken kronometre acilir 
    if(dna->dosyaOku(dosyaAdi)){    //Dosyadan veriler okunur eger okunmussa veya okunamazsa bilgi verilir
        std::cout << "(+) " << dosyaAdi << " dosyasindan DNA yuklendi!!\n";
    }else{
        std::perror("(-) Dosyadan DNA yuklenemedi!!");
        return 1;
    }
    auto stop = std::chrono::high_resolution_clock::now();  //Kronometre durdurulur
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);    //Ve kac ms surdugu hesaplanir
    

    int iSecim;
    int genIndex;
    int kromozomIndex1 ,kromozomIndex2;

    do{
        ekraniTemizle();    //Her seferinde onceki islemden kalan kisimlar gozukmemesi icin ekran temizlenir
        std::cout << duration.count() << "ms";  //Dosyadan okuma isleminin kac ms surdugu yazdirilir

        std::cout << "\n|-----DNA ISLEM MENUSU-------|" << std::endl; //Menu olusturulup yazdirilir
        std::cout << "|      (1) Caprazlama        |" << std::endl;
        std::cout << "|       (2) Mutasyon         |" << std::endl;
        std::cout << "|    (3) Otomatik Islemler   |" << std::endl;
        std::cout << "|       (4) Ekrana Yaz       |" << std::endl;
        std::cout << "|         (5) Cikis          |" << std::endl;
        std::cout << "|----------------------------|" << std::endl;
        std::cout << "Seciminiz -->";
        std::cin>> iSecim;  //Secim bilgisi alinir

        switch (iSecim){    //Secime gore switch case yapisi ile islem yapilir
            case 1: {
                std::cout << "Caprazlamak istediginiz 1. kromozomun indexini giriniz -->";
                std::cin >> kromozomIndex1;
                std::cout << "Caprazlamak istediginiz 2. kromozomun indexini giriniz -->";
                std::cin >> kromozomIndex2;

                dna->caprazla(kromozomIndex1,kromozomIndex2);   //Hangi kromozomlarin caprazlanacagi alinan index bilgisine gore yapilir
                std::cout << "Caprazlama islemi tamamlandi! Yeni olusan kromozomlar DNA'ya eklendi !" << std::endl;
                std::cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << std::endl;
                sleep(1);
                break;
            }case 2: {
                std::cout << "Mutasyon uygulamak istediginiz kromozom indexini giriniz -->";
                std::cin >> kromozomIndex1;
                std::cout << "Mutasyon uygulamak istediginiz gen indexini giriniz -->";
                std::cin >> genIndex;

                dna->mutasyon(kromozomIndex1,genIndex); //Gelen kromozom ve gen indexlerine gore mutasyon islemi yapilir
                std::cout << "Mutasyon islemi tamamlandi! Gen basariyla guncellendi !" << std::endl;
                std::cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << std::endl;
                sleep(1);
                break;
            }case 3: {
                std::cout << "Islemler basliyor ..." << std::endl;
                dna->islemler(islemlerDosya);   //Otomatik islemlerin yapilacagi dosya ismi alinarak otomatik islemler yapilir
                sleep(1);
                std::cout << "Islemler bitti !!" << std::endl;
                std::cout << "1 saniye sonra ana menuye aktariliyorsunuz ..." << std::endl;
                sleep(1);
                break;
            }case 4: {
                std::cout << "DNA'nin mevcut durumu :" << std::endl;
                dna->ekranaYaz();   //Kurala gore DNA nin mevcut genler yazdirilir
                std::cout << "2 saniye sonra ana menuye aktariliyorsunuz ..." << std::endl;
                sleep(2);
                
                break;
            }case 5:    //Programdan cikma istemi gelirse programdan cikilir
                std::cout << "1 saniye sonra programdan cikariliyorsunuz!!";
                sleep(1);
                break;
            default:    //Eger yanlis bir islem yapilirsa programdan cikilir
                perror("Yanlis ya da eksik bir secim yaptiniz!!");
                return 0;
        }

    }while(iSecim != 5);
    
    delete dna;
    return 0;
}
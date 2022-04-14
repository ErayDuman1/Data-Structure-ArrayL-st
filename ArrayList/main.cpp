#include <iostream>
#include <windows.h>

using namespace std;

void veriAl(int,int);
double notHesapla(int,int);    /* FONKSÝYONLAR */
void goster(int,int);
void sil();

struct Ogrenci
{
string *isim,*harfnotu;
int *ogrencino,*testnotlari;    /* Ogrencinin Bilgilerini Iceren Struct*/
double *ortalama;
}ogr;



void veriAl(int ogrnmb,int testnmb)
{
    int sayac=0;

    ogr.testnotlari=new int[ogrnmb*testnmb];
    ogr.isim=new string [ogrnmb];               
    ogr.harfnotu=new string [ogrnmb];         /*Struct da tanimlanan pointerlar ile bellekten dinamik yer alma */
    ogr.ogrencino=new int [ogrnmb];
    ogr.ortalama=new double [ogrnmb];

    for(int i=0;i<ogrnmb;i++)
    {
        cout<<" "<<i+1<<".Ogrencinin Adini Giriniz:";
        cin>>ogr.isim[i];                                   /* for dongusu ile kullanicidan isim ve numara verilerini alma.*/
        cout<<" "<<i+1<<".Ogrencinin Numarasini Giriniz:";
        cin>>ogr.ogrencino[i];

        for(int j=0;j<testnmb;j++)
        {
            cout<<" "<<i+1<<".Ogrencinin "<<j+1<<".Test Notunu Giriniz:";  /*kullanici kac not girmis ise girdigi notlar diziye ataniyor */
            cin>>ogr.testnotlari[j+sayac];
            
        }
        sayac+=testnmb;    /*sayaci "testnmb" kadar artirarak bi daha ki ogrenci ekleme de dizi kaldigi yerden eklemeye devam ediyor.*/
        cout<<endl;
    }

}

double notHesapla(int testnmbr,int ogrnumber)
{
    int toplam,i,sayac1=0;
    for(i=0;i<ogrnumber;i++)
    {
        toplam=0;
        for(int j=0;j<testnmbr;j++)
        {
            toplam+=ogr.testnotlari[j+sayac1];    /*test sayisi kadar dizi de ileri gidip ogrencilerin test verilerini alip toplama ekliyor*/
        }
        
     ogr.ortalama[i]=((double)toplam)/testnmbr;   /* toplam/testsayisi ile ortalama hesaplaniyor. */
     sayac1+=testnmbr;

     if((ogr.ortalama[i]>=85) && (ogr.ortalama[i]<=100)) {
        ogr.harfnotu[i]="A";
     }
     else if((ogr.ortalama[i]>=75) && (ogr.ortalama[i]<85)) {
        ogr.harfnotu[i]="B";                                     /* Ortalamaya gore harf notu belirleniyor. */
     }
     else if((ogr.ortalama[i]>=65) && (ogr.ortalama[i]<75)) {
        ogr.harfnotu[i]="C";
     }
     else if((ogr.ortalama[i]>=50) && (ogr.ortalama[i]<65)) {
        ogr.harfnotu[i]="D";
     }
     else {
        ogr.harfnotu[i]="F";
     }
    }


    return sayac1;
}

void goster(int ogrnmbr,int tstnmbr)
{
    system("cls");    /*Ekrani temizliyor*/
    int sayac=0;
    for(int i=0;i<ogrnmbr;i++)
    {
        cout<<" "<<i+1<<".Ogrencinin Adi:"<<ogr.isim[i]<<endl;              
        cout<<" "<<i+1<<".Ogrencinin Numarasi:"<<ogr.ogrencino[i]<<endl;

        for(int j=0;j<tstnmbr;j++)                                         /*Ogrecilerin sirasiyla bilgilerini, ortalamalarini ve harf notlarýný yazdiriyor*/
        {
            cout<<" "<<i+1<<".Ogrencinin "<<j+1<<".Test Notu:"<<ogr.testnotlari[j+sayac];
            cout<<endl;
        }
        cout<<" Ortalamasi:"<<(double)ogr.ortalama[i]<<"  Harf notu:"<<ogr.harfnotu[i]<<endl;
        sayac+=tstnmbr;
        cout<<endl;
    }
}

void sil()
{
    delete[] ogr.testnotlari;
    delete[] ogr.isim;
    delete[] ogr.ogrencino;   /*Bellekten alinan yeri iade ediyor.*/
    delete[] ogr.harfnotu;
    delete[] ogr.ortalama;
}
int main()
{
    int ogrSayi,testSayi;
    cout<<" Ogrenci sayisini giriniz:";
    cin>>ogrSayi;                           /*Kullanici dan ogrenci sayisini ve test sayisini aliyor*/
    cout<<" Test sayisini giriniz:";
    cin>>testSayi;
    cout<<endl;

    veriAl(ogrSayi,testSayi);
    notHesapla(testSayi,ogrSayi);           /*Fonksiyonlar main de cagiriliyor.*/
    goster(ogrSayi,testSayi);
    sil();
    
    system("pause");                       
    return EXIT_SUCCESS;
}

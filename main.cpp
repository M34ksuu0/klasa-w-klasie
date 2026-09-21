#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
    int nr;

public:
    //metoda do wczytywania z klawiatury
    void wczytaj_z_klawiatury()
    {
        cin >> imie >> nazwisko >> nr;
    }
    //metoda do wczytywania z pliku
    void wczytaj(ifstream &plik)
    {
        plik >> imie >> nazwisko >> nr;
    }
    //metoda do wypisywania
    void wypisz()
    {
        cout << imie << " " << nazwisko << " " << nr << endl;
    }
};

class Klasa
{
private:
    string nazwa;
    string wychowawca;
    Osoba osoba[30];

public:
    //metoda do wczytywania z klawiatury
    void wczytaj_z_klawiatury(const int &ile)
    {
        cin >> nazwa;
        cin >> wychowawca;

        for(int i = 0; i < ile; i++)
        {
            osoba[i].wczytaj_z_klawiatury();
        }
    }
    //metoda do wczytywania z pliku
    void wczytaj(ifstream &plik, const int &ile)
    {
        plik >> nazwa;
        plik >> wychowawca;

        for(int i = 0; i < ile; i++)
        {
            osoba[i].wczytaj(plik);
        }
    }
    //metoda do wypisywania
    void wypisz(const int &ile)
    {
        cout << "Klasa: " << nazwa << endl;
        cout << "Wychowawca: " << wychowawca << endl;

        for(int i = 0; i < ile; i++)
        {
            osoba[i].wypisz();
        }
    }
};


int main()
{
    int ile = 2;
    Klasa klasa1;
    bool zPliku;
    uint8_t wybor;
    cout<<"z pliku czy z klawiatury?(z pliku '1', z klawiatury '2')"<<endl ;
    cin>>wybor;
    if(wybor=='1'){
    //otwarcie pliku a.txt
    ifstream plik("a.txt");
    //wczytanie z pliku
    klasa1.wczytaj(plik, ile);
    //zamkniecie pliku
    plik.close();
    //wypisanie klasy
    klasa1.wypisz(ile);
    }
    else{
    //wczytanie z klawiatury
    klasa1.wczytaj_z_klawiatury(ile);
    //wypisanie klasy
    klasa1.wypisz(ile);
    }
    return 0;
}

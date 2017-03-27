#include "projekt.hh"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

  fstream plikDanych;
  plikDanych.open("data10.txt", fstream::in);

  int iloscZadan;
  int iloscZaleznosci;
  string bufor;
  string metaDane = string();
  string dane = string();
  int i = 0, j = 0, temp;
  int *czasyPrzetwarzania;
  int nrZadania, nrZadaniaPoprzedzajacego;

  // wczytywanie danych z pliku - start
  
  getline(plikDanych, bufor);
  while (bufor[i] != ' ')
    metaDane += bufor[i++];

  iloscZadan = stoi(metaDane);
  metaDane.clear();
  
  while (bufor[i] == ' ') i++;
  while (bufor[i] != ' ' and bufor[i] != '\n')
    metaDane += bufor[i++];

  iloscZaleznosci = stoi(metaDane);
  metaDane.clear();

  getline(plikDanych, bufor);
  czasyPrzetwarzania = new int[iloscZadan];
  
  for (i = 0; i < iloscZadan; i++) {

    while (bufor[j] != ' ')
      dane += bufor[j++];

    czasyPrzetwarzania[i] = stoi(dane);
    dane.clear();

    while (bufor[j] == ' ') j++;
  }

  j = 0;
  getline(plikDanych, bufor);

  // stwórz projekt
  Projekt projekt(iloscZadan, czasyPrzetwarzania);

  for (i = 0; i < iloscZaleznosci; i++) {

    while (bufor[j] != ' ')
      dane += bufor[j++];
    
    nrZadaniaPoprzedzajacego = stoi(dane);
    dane.clear();

    while (bufor[j] == ' ') j++;

    while (bufor[j] != ' ')
      dane += bufor[j++];

    nrZadania = stoi(dane);
    dane.clear();

    // założyłem, że numer zadania poprzedzającego powinien być
    // mniejszy od numeru zadania
    if (nrZadania < nrZadaniaPoprzedzajacego) {

      temp = nrZadania;
      nrZadania = nrZadaniaPoprzedzajacego;
      nrZadaniaPoprzedzajacego = temp;

    }

    projekt.dodajZaleznosc(nrZadaniaPoprzedzajacego, nrZadania);

    while (bufor[j] == ' ') j++;

  }

  plikDanych.close();

  // wczytywanie danych z pliku - koniec

  
  // projekt.obliczParametryZadan();

  // cout << "Czas wykonywania: " << projekt.czasWykonywaniaProjektu << endl;
}

#include "projekt.hh"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

  fstream plikDanych;

  if (argc > 1)
    plikDanych.open(argv[1], fstream::in);

  else {
    
    cerr << "Brak pliku wejsciowego" << endl;
    exit(-1);
  }

  int iloscZadan;
  int iloscZaleznosci;
  string bufor;
  string metaDane = string();
  string dane = string();
  int i = 0, j = 0;
  int *czasyPrzetwarzania;
  int nrZadania, nrZadaniaPoprzedzajacego;
  unsigned int rozmiar;

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

    projekt.dodajZaleznosc(nrZadaniaPoprzedzajacego, nrZadania);

    while (bufor[j] == ' ') j++;

  }

  plikDanych.close();

  // wczytywanie danych z pliku - koniec
  
  projekt.obliczParametryZadan();
  projekt.wyznaczSciezkeKrytyczna();

  cout << "process time:" << endl
       << projekt.czasWykonywaniaProjektu << endl;

  cout << "earlyStart earlyFinish lateStart lateFinish:" << endl;

  for (unsigned int i = 0; i < projekt.zadania.size(); i++)
    cout << projekt.zadania[i]->ES << " " << projekt.zadania[i]->EF << " "
	 << projekt.zadania[i]->LS << " " << projekt.zadania[i]->LF << endl;

  rozmiar = projekt.sciezkaKrytyczna.size();
  cout << "critical path:" << endl;

  for (unsigned int i = 0; i < rozmiar; i++)
    cout << projekt.sciezkaKrytyczna[rozmiar-1-i]->numer << " "
	 << projekt.sciezkaKrytyczna[rozmiar-1-i]->ES << " "
      	 << projekt.sciezkaKrytyczna[rozmiar-1-i]->EF << endl;
  
}

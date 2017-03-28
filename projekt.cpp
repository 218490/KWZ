#include "projekt.hh"
using namespace std;

Projekt::Projekt(int iloscZadan, int *czasyPrzetwarzania) {

  czasWykonywaniaProjektu = -1;
  Projekt::iloscZadan = iloscZadan;
  for (int i = 0; i < iloscZadan; i++)
    zadania.push_back(new Zadanie(i+1, czasyPrzetwarzania[i]));

  delete[] czasyPrzetwarzania;

}

void Projekt::dodajZaleznosc(int nrZadaniaPoprzedzajacego,
			     int nrZadania) {

  zadania[nrZadania-1]->dodajPoprzednika(zadania[nrZadaniaPoprzedzajacego-1]);
  zadania[nrZadaniaPoprzedzajacego-1]->dodajNastepnika(zadania[nrZadania-1]);
  
}

void Projekt::obliczParametryZadan() {

  int EF;
  
  for (unsigned int i = 0; i < zadania.size(); i++) {
    
    EF = zadania[i]->obliczParametryEARLY();
    if (czasWykonywaniaProjektu < EF)
      czasWykonywaniaProjektu = EF;

  }

  for (unsigned int i = 0; i < zadania.size(); i++)
    zadania[i]->obliczParametryLATE(czasWykonywaniaProjektu);
}

void Projekt::wyznaczSciezkeKrytyczna() {

  unsigned int i;
  Zadanie *zadanie = nullptr, *zadaniePoprzedzajace;
  
  for (i = 0; i < zadania.size(); i++)
    if (zadania[i]->ES == zadania[i]->LS
	and zadania[i]->LF == czasWykonywaniaProjektu) {

      zadanie = zadania[i];
      sciezkaKrytyczna.push_back(zadanie);
      break;
    }

  zadaniePoprzedzajace = zadanie;
  
  while (zadaniePoprzedzajace != nullptr) {

    zadaniePoprzedzajace = nullptr;
    
    for (i = 0; i < zadanie->poprzedzajace.size(); i++)
      if (zadanie->poprzedzajace[i]->ES == zadanie->poprzedzajace[i]->LS
	  and zadanie->poprzedzajace[i]->LF == zadanie->LS) {

	zadaniePoprzedzajace = zadanie->poprzedzajace[i];
	zadanie = zadaniePoprzedzajace;
	sciezkaKrytyczna.push_back(zadaniePoprzedzajace);
	break;
      }
	
  }
}

Projekt::~Projekt() {

  for (int i = 0; i < iloscZadan; i++)
    delete zadania[i];

}

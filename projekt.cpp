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

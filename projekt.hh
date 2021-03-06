#ifndef PROJEKT_HH
#define PROJEKT_HH
#include "zadanie.hh"
using namespace std;

class Projekt {

public:

  int iloscZadan;
  int czasWykonywaniaProjektu; // EFmax
  vector<Zadanie*> zadania;
  vector<Zadanie*> sciezkaKrytyczna;
  
  Projekt(int iloscZadan, int *czasyPrzetwarzania);
  
  void dodajZaleznosc(int nrZadaniaPoprzedzajacego,
		      int nrZadania);

  void obliczParametryZadan();

  void wyznaczSciezkeKrytyczna();

  ~Projekt();

};

#endif

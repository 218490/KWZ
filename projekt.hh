#ifndef PROJEKT_HH
#define PROJEKT_HH
#include "zadanie.hh"
using namespace std;

class Projekt {

public:

  int iloscZadan;
  int czasWykonywaniaProjektu; // EFmax
  vector<Zadanie*> zadania;
  
  Projekt(int iloscZadan, int *czasyPrzetwarzania);
  
  void dodajZaleznosc(int nrZadaniaPoprzedzajacego,
		      int nrZadania);

  void obliczParametryZadan();

};

#endif

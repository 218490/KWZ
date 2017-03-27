#include "zadanie.hh"
using namespace std;

Zadanie::Zadanie(int numer, int czasPrzetwarzania) {

  Zadanie::numer = numer;
  PT = czasPrzetwarzania;
  ES = LS = 0;
  EF = LF = czasPrzetwarzania;

}

void Zadanie::dodajPoprzednika(Zadanie *poprzednik) {

  poprzedzajace.push_back(poprzednik);

}

void Zadanie::dodajNastepnika(Zadanie *nastepnik) {

  nastepujace.push_back(nastepnik);

}

int Zadanie::obliczParametryEARLY() {
  
  // oblicz EF i ES

  return EF;
}


void Zadanie::obliczParametryLATE(int czasWykonywaniaProjektu) {
  
  // oblicz LS i LF, czasWykonywaniaProjektu == największe EF
  
}

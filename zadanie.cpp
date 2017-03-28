#include "zadanie.hh"
using namespace std;

Zadanie::Zadanie(int numer, int czasPrzetwarzania) {

  Zadanie::numer = numer;
  PT = czasPrzetwarzania;
  ES = LS = -1;
  EF = LF = -1;

}

void Zadanie::dodajPoprzednika(Zadanie *poprzednik) {

  poprzedzajace.push_back(poprzednik);

}

void Zadanie::dodajNastepnika(Zadanie *nastepnik) {

  nastepujace.push_back(nastepnik);

}

int Zadanie::obliczParametryEARLY() {
  
  // oblicz EF i ES
  ES = 0;
  
  for (unsigned int i = 0; i < poprzedzajace.size(); i++) {
    
    if (poprzedzajace[i]->EF == -1)
      poprzedzajace[i]->obliczParametryEARLY();

    if (poprzedzajace[i]->EF > ES)
      ES = poprzedzajace[i]->EF;

  }

  EF = ES + PT;
    
  return EF;
}


void Zadanie::obliczParametryLATE(int czasWykonywaniaProjektu) {
  
  // oblicz LS i LF, czasWykonywaniaProjektu == największe EF
  LF = czasWykonywaniaProjektu;

  for (unsigned int i = 0; i < nastepujace.size(); i++) {

    if (nastepujace[i]->LS == -1)
      nastepujace[i]->obliczParametryLATE(czasWykonywaniaProjektu);

    if (nastepujace[i]->LS < LF)
      LF = nastepujace[i]->LS;

  }

  LS = LF - PT;
  
}

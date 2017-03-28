#ifndef WIERZCHOLEK_HH
#define WIERZCHOLEK_HH
#include <vector>
#include <iostream>
using namespace std;

class Zadanie {

public:
  
  vector<Zadanie*> poprzedzajace;
  vector<Zadanie*> nastepujace;
  
  int numer; // nr zadania
  int ES; // early start
  int EF; // early finish
  int LS; // late start
  int LF; // late finish
  int PT; // processing time
  
  Zadanie(int numer, int czasPrzetwarzania);

  void dodajPoprzednika(Zadanie *poprzednik);

  void dodajNastepnika(Zadanie *nastepnik);

  int obliczParametryEARLY();

  void obliczParametryLATE(int czasWykonywaniaProjektu);
  
};

#endif

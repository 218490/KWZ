// Wojciech Michałowski
// nr albumu 218705

#ifndef WIERZCHOLEK_HPP
#define WIERZCHOLEK_HPP
#include <string>
#include <vector>
using namespace std;

class wierzcholek {
  
public:

  int ES; //early start
  int EF; //early finish
  int LS; //late start
  int LF; //late finish
  int PT; //processing time
  int indeks;
  vector<wierzcholek*>* klaster;

  wierzcholek(int processingTime) {

    PT = processingTime;
    indeks = -1;
    klaster = new vector<wierzcholek*>;
    klaster->push_back(this);
    
  }
};

#endif

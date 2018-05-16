#ifndef _JOUEURS_H_
#define _JOUEURS_H_
//Les bibliothèque utilisées par la classe
#include "cartes.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
/**********************************************
*    Définition de la class JOUEURS
***********************************************/
class Joueurs
{
  friend class Table;
private:
  int _num;
  Cartes _main[2];
  int _nbCartes;
public:
  // Constructeurs & Destructeurs de la classe
  Joueurs();
  ~Joueurs();
  // Les GETTERS
  int getNum() const;
  // Les SETTERS
  void setNum(const int &val);
  // Surcharges des opérateurs de la class
  friend ostream& operator<<(ostream& os, const Joueurs &j);
};
#endif

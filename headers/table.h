#ifndef _TABLES_H_
#define _TABLES_H_
//Les bibliothèque utilisées par la classe
#include "joueurs.h"
#include "paquet.hpp"
#include "utile.h"
#include <iostream>

using namespace std;
/**********************************************
*    Définition de la class TABLE
***********************************************/
class Table
{
private:
  Cartes _board[5]; // Board d'une table
  Paquet<Cartes> _deck; // Paquet de 52 cartes
  Joueurs *_nbJ; // Pointeurs contenant les joueurs d'une parties
  int _nbrJ; // Nombres des joueurs d'une partie
  int getNbCBoard() const; // retourne le nombre de carte du board
public:
  // Constructeurs & Destructeurs de la classe
  Table();
  ~Table();
  // Le GETTER
  int getNbrJ() const;
  // Les Méthodes
  void afficheBoard();
  void distriBoard(const int &);
  void partie();// Créer une partie de poker
  void combinaison(const Joueurs &j); // Check la main du joueur
  bool estQFlushRoyal(const Cartes *tab,int nb);
  bool estQFlush(const Cartes *tab,int nb);
  bool estCarre(const Cartes *tab,int nb);
  bool estFullHouse(const Cartes *tab,int nb);
  bool estCouleur(const Cartes *tab,int nb);
  bool estQuinte(const Cartes *tab,int nb);
  bool estBrelan(const Cartes *tab,int nb);
  bool estDoublePaire(const Cartes *tab,int nb);
  bool estPaire(const Cartes *tab,int nb);
  void estHauteur(const Cartes *tab,int nb);
};
#endif

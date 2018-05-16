/**********************************************
*    Fichier : paquet.hpp
*    - Définie un paquet de cartes
*    - Les bibliothèque qu'il utilise
*    - Ses attribut privés
*    - Les CONSTRUSTRUTEURS ET DESTRUCTEURS
*    - Les Méthodes, GETTERS & SETTERS
*    - L'implémentation des méthodes
*    - L'implémentation du constructeurs
*    - L'implémentation du destructeurs
***********************************************/
#ifndef _PAQUET_H_
#define _PAQUET_H_
//Les bibliothèque utilisées par la classe
#include "cartes.h"
#include <cstdlib>
#include <iostream>

using namespace std;

const int nCartes = 52; // nombre de carte d'un paquet
/**********************************************
*    Définition de la class templaté Paquet
***********************************************/
template<class T>
class Paquet
{
private:
  Cartes _paquet[nCartes];
  bool _piocher[nCartes];
public:
  // Constructeurs & Destructeurs de la classe
  Paquet();
  ~Paquet();
  // Le GETTER
  bool estPiocher(const int &i);
  // Le SETTER
  void setPiocher(const int &i);
  // Méthode
  Cartes pioche();
  // Surcharge d'OPERATEURS
  template<class U>
  friend ostream& operator<<(ostream &os, const Paquet<U> &p);
};


template<class T>
ostream& operator<<(ostream &os, const Paquet<T> &p)
{
  for(int i=0;i<nCartes;i++)
    os << p._paquet[i];
  return os;
}
/**********************************************
*    Constructeurs de la class
*    Construit jeu de 52 cartes
*    Numérotés de 2 à 14
*    Répartie en 4 familles
*    Coeur Pique Trefle Carreau
***********************************************/
template<class T>
Paquet<T>::Paquet()
{
  int coul = -1;
  int haut = 2;
  for(int i=0;i<nCartes;i++)
  {
    if(i%14 == 0)
      coul++;
    if(haut > 14)
      haut = 2;
    _paquet[i].setCoul(coul);
    _paquet[i].setHauteur(haut);
    haut++;
    _piocher[i] = false;
  }
}
/**********************************************
*    Destructeurs de la class
***********************************************/
template<class T>
Paquet<T>::~Paquet()
{

}
/**********************************************
*    Predicat retournant
*    si une carte est piochée
*    dans _piocher
***********************************************/
template<class T>
bool Paquet<T>::estPiocher(const int &i)
{
  return _piocher[i];
}
/**********************************************
*    Met le booléen de
*    l'indice i à true
***********************************************/
template<class T>
void Paquet<T>::setPiocher(const int &i)
{
  this->_piocher[i]=true;
}
/**********************************************
*    Permet de pioché une carte
*    dans le paquet de carte
***********************************************/
template<class T>
Cartes Paquet<T>::pioche()
{
  int i = 0;
  i = rand()%52;
  if(!this->estPiocher(i))
  {
    this->setPiocher(i);
    return _paquet[i];
  }
  else
  {
    return this->pioche();
  }
}
#endif

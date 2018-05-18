/**********************************************
*    Fichier : cartes.h
*    - Définie une cartes
*    - Les bibliothèque qu'elle utilises
*    - Ses attribut privés
*    - Les CONSTRUSTRUTEURS ET DESTRUCTEURS
*    - Les Méthodes, GETTERS & SETTERS
***********************************************/
#ifndef _CARTES_H_
#define _CARTES_H_

//Les bibliothèque utilisées par la classe
#include <iostream>
/**********************************************
*    Définition de la class CARTES
**********************************************/
class Cartes
{
private:
  // Attribut privé de la classe Cartes
  int _couleur; // 0 trèfle, 1 carreau, 2 coeur, 3 pique
  int _hauteur; // 0 à 10, 11 valet, 12 dame, 13 roi, 14 as
public:
  //Constructeurs & Destructeurs de la classe
  Cartes();
  Cartes(const Cartes &);
  ~Cartes();
  // Les GETTERS
  int getCoul() const;
  int getHauteur() const;
  // Les SETTERS
  void setCoul(const int val);
  void setHauteur(const int val);
  // Surcharge d'OPERATEURS
  bool operator>(const Cartes &c1);
  Cartes& operator[](const int &i);
  Cartes& operator=(const Cartes &c);
  bool operator==(const Cartes &c) const;
};
/**************************************************
* Surcharge de l'opérateur de flux de sortie
*  externe à la classe, afin de pouvoir interagir
*   avec des objets en dehors de la classe
**************************************************/
std::ostream& operator<<(std::ostream &os, const Cartes &c);
#endif

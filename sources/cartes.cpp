#include "../headers/cartes.h"
//Utilisation de l'espace de nomage STD afin de ne pas taper std::
using namespace std;
//Constructeurs par defaut d'une carte
Cartes::Cartes()
{
  this->_couleur = -1;
  this->_hauteur = -1;
}
//Constructeurs surcharger d'une Carte
Cartes::Cartes(int coul,int haut):_couleur(coul),_hauteur(haut){}
//Destructeurs de ma classe cartes
Cartes::~Cartes()
{

}
//Getter qui reccupère la couleur d'une carte (coeur,piques,...)
int Cartes::getCoul() const
{
  return _couleur;
}
//Retourne la couleur de la carte
int Cartes::getHauteur() const
{
  return _hauteur;
}
//Modifie la couleur de la carte
void Cartes::setCoul(const int val)
{
  this->_couleur = val;
}
//Modifie la hauteur d'une carte
void Cartes::setHauteur(const int val)
{
  this->_hauteur = val;
}
//Opérateur permettant de comparer si la carte c1 est plus petite que (*THIS)
bool Cartes::operator>(const Cartes &c1)
{
  return (this->getHauteur() > c1.getHauteur()) ? true : false;
}
//Compare l'égalitée de deux cartes
bool Cartes::operator==(const Cartes &c) const
{
  return this->getHauteur() == c.getHauteur();
}
//Retourne l'élément à l'indice i d'un tableau de carte
Cartes& Cartes::operator[](const int &i)
{
  return (*this)[i];
}
//Surcharge de l'opérateur d'affectation, (a = b)
Cartes& Cartes::operator=(const Cartes &c)
{
  this->_couleur = c.getCoul();
  this->_hauteur = c.getHauteur();
  return (*this);
}
/**********************************************
* Surcharge de l'opérateur de flux de sortie
* Fait une correspondance textuelle entre les
* entier et la valeur affichable d'une carte
***********************************************/
ostream& operator<<(ostream &os , const Cartes &c)
{
  if((c.getHauteur() > 10) || (c.getHauteur() < 0))
  {
    if(c.getHauteur() == 11)
      os <<"Valet";
    if(c.getHauteur() == 12)
      os <<"Dame";
    if(c.getHauteur() == 13)
      os <<"Roi";
    if(c.getHauteur() == 14)
      os <<"As";
    if(c.getHauteur() == -1)
      os <<"DEBUG";

    if(c.getCoul() == 0)
      os <<" de_trefle ";
    if(c.getCoul() == 1)
      os <<" de_carreau ";
    if(c.getCoul() == 2)
      os <<" de_coeur ";
    if(c.getCoul() == 3)
      os <<" de_pique ";
    if(c.getCoul() == -1)
      os <<"DEBUG";
  }
  else
  {
    if(c.getCoul() == -1)
      os <<"DEBUG";
    if(c.getCoul() == 0)
      os <<c.getHauteur()<<" de_trefle ";
    if(c.getCoul() == 1)
      os <<c.getHauteur()<<" de_carreau ";
    if(c.getCoul() == 2)
      os <<c.getHauteur()<<" de_coeur ";
    if(c.getCoul() == 3)
      os <<c.getHauteur()<<" de_pique ";
  }
  return os ;
}

#include "../headers/joueurs.h"

Joueurs::Joueurs()
{
  this->_num = 0;
}

Joueurs::~Joueurs()
{

}

int Joueurs::getNum() const
{
  return _num;
}

void Joueurs::setNum(const int &val)
{
  this->_num = val;
}

ostream& operator<<(ostream& os, const Joueurs &j)
{
  cout<<"\n \033[1;34mJoueurs "<<j.getNum()<<" :\033[0m\n";
  cout<<"\t\033[1;33mcarte(s) : \033[1;32m"<<j._main[0]<<", "<<j._main[1]<<"\033[0m"<<endl;
  return os;
}

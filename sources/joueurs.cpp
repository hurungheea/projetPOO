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
  cout<<"\nJoueurs "<<j.getNum()<<" :\n";
  cout<<"\t2 carte(s) : "<<j._main[0]<<", "<<j._main[1]<<endl;
  return os;
}

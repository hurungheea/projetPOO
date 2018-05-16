#include "../headers/table.h"

Table::Table()
{
  do
  {
    try
    {
      cout<<"Combien de joueurs participes à la partie : ";
      cin>>_nbrJ;
      if(cin.fail())
      {
        cin.clear();
        cin.ignore();
        throw _nbrJ;
      }
      if(_nbrJ < 2 || _nbrJ >10)
          cerr<<"Le nombre de joueurs doit être comprit entre 2 et 10\n";
    }
    catch(int e)
    {
      cerr<<"Entrez un entier\n";
    }
  }while(_nbrJ<2 || _nbrJ>10);
  this->_nbJ = new Joueurs[_nbrJ];
  for(int i=0;i<_nbrJ;i++)
  {
    this->_nbJ[i].setNum(i);
    this->_nbJ[i]._main[0] = _deck.pioche();
    this->_nbJ[i]._main[1] = _deck.pioche();
  }
}

void Table::partie()
{
  bool fin = false;
  int tour = 0;
  while((!fin)&&(tour <=4))
  {
    tour++;
    affiche(tour);
    this->afficheBoard();
    for(int i=0;i<_nbrJ;i++)
      cout<<_nbJ[i];
    this->distriBoard(tour);

  }
}

void Table::distriBoard(const int &tour)
{
  switch(tour)
  {
    case 1:
    for(int i=0;i<3;i++)
    _board[i] = _deck.pioche();
    break;

    case 2:
    _board[3] = _deck.pioche();
    break;

    case 3:
    _board[4] = _deck.pioche();
    break;

    default: break;
  }
}

void Table::afficheBoard()
{
  cout<<"Board :"<<endl;
  int nb = getNbCBoard();
  if(nb == 0)
    cout<<"\taucune carte\n";
  else
    cout<<"\t"<<nb<<" carte(s) : ";
  for(int i = 0;i<nb;i++)
  {
    cout<<_board[i];
  }
}

int Table::getNbCBoard() const
{
  int j;
  for(j = 0;j<5;j++)
  {
    if((_board[j].getHauteur()) == -1)
    {
      break;
    }
  }
  return j;
}

void Table::combinaison(const Joueurs &j)
{
  /*
  tab[0].setCoul(0);
  tab[0].setHauteur(1);
  tab[1].setCoul(1);
  tab[1].setHauteur(1);
  tab[2].setCoul(0);
  tab[2].setHauteur(6);
  tab[3].setCoul(0);
  tab[3].setHauteur(10);
  tab[4].setCoul(1);
  tab[4].setHauteur(7);
  tab[5].setCoul(1);
  tab[5].setHauteur(9);
  tab[6].setCoul(1);
  tab[6].setHauteur(10);
  cout<<this->estDoublePaire(tab,2+nb)<<"\n";
  */
  int nb = this->getNbCBoard();
  Cartes tab[7];
  int i;
  for(i=0;i<2;i++)
    tab[i]=j._main[i];
  for(int i=0;i<nb;i++)
    tab[i+2]=_board[i];
  sort(tab,2+nb);
}

bool Table::estQFlushRoyal(const Cartes *tab,int nb)
{
  if((!this->estQuinte(tab,nb))||(!this->estCouleur(tab,nb)))
    return false;
  if((tab[nb-5].getHauteur() == 10)&&(tab[nb-1].getHauteur() == 14))
    return true;
  else
    return false;
}

bool Table::estQFlush(const Cartes *tab,int nb)
{
  if((!this->estQuinte(tab,nb))||(!this->estCouleur(tab,nb)))
    return false;
  else
    return true;
}

bool Table::estCarre(const Cartes *tab,int nb)
{
  int nbPaire = 0;
  for(int i=0;i<nb;i++)
  {
    if(tab[i] == tab[i+1])
      nbPaire++;
    if(nbPaire == 3)
      return true;
  }
  return false;
}

bool Table::estFullHouse(const Cartes *tab,int nb)
{
  int hautBrelan = 0;
  if(!this->estBrelan(tab,nb))
    return false;
  else
  {
    for(int i=0;i<nb-2;i++)
    {
      if((tab[i] == tab[i+1])&&(tab[i] == tab[i+2]))
      {
        hautBrelan = tab[i].getHauteur();
      }
    }
    for(int i=0;i<nb;i++)
    {
      if((tab[i] == tab[i+1])&&(tab[i].getHauteur() != hautBrelan))
        return true;
    }
    return false;
  }
}

bool Table::estCouleur(const Cartes *tab,int nb)
{
  int c(0),co(0),p(0),t(0);
  for(int i=0;i<nb;i++)
  {
    switch (tab[i].getCoul())
    {
      case 0:
        t++;
        break;
      case 1:
        c++;
        break;
      case 2:
        co++;
        break;
      case 3:
        p++;
        break;
    }
  }
  return((c==5)||(co==5)||(t==5)||(p==5)) ? true : false ;
}

bool Table::estQuinte(const Cartes *tab,int nb)
{
  int k=0;//indice de suite.
  for (int i=0;i<nb;i++)
  {
    if (tab[i].getHauteur()+1==tab[i+1].getHauteur())
    {
      k++;
    }
  }
  if (k>=4)
  {
    return true;//il y a une suite
  }
  else
  {
    return false;//il n'y a pas de suite.
  }
}

bool Table::estBrelan(const Cartes *tab,int nb)
{
  for(int i=0;i<nb-2;i++)
  {
    if((tab[i] == tab[i+1])&&(tab[i] == tab[i+2]))
    {
      return true;
    }
  }
  return false;
}

bool Table::estDoublePaire(const Cartes *tab,int nb)
{
  int nbPaire=0;
  int k=0;
  for(k=0;k<nb;k++)
  {
    if(tab[k] == tab[k+1])
    {
      nbPaire+=1;
      break;
    }
  }
  if(nbPaire==0)
    return false;
  for(int j=k+2;j<nb;j++)
  {
    if(tab[j] == tab[j+1])
    {
      nbPaire+=1;
      break;
    }
  }
  return (nbPaire==2) ? true : false;
}

bool Table::estPaire(const Cartes *tab,int nb)
{
  for(int i=0;i<nb;i++)
  {
    if(tab[i] == tab[i+1])
      return true;
  }
  return false;
}

int Table::estHauteur(const Cartes *tab,int nb)
{
  return tab[nb-1].getHauteur();
}

int Table::getNbrJ() const
{
  return _nbrJ;
}

Table::~Table()
{

}

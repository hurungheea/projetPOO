#include "../headers/utile.h"

using namespace std;

void affiche(const int &tour)
{
  cout<<"";
  switch(tour)
  {
    case 1:
      cout<<"\n=============================\n\tPREFLOP\n=============================\n";
      break;
    case 2:
      cout<<"\n=============================\n\tFLOP\n=============================\n";
      break;
    case 3:
      cout<<"\n=============================\n\tTURN\n=============================\n";
      break;
    case 4:
      cout<<"\n=============================\n\tRIVER\n=============================\n";
      break;
    default: exit(-1);
  }
}

void sort(Cartes *tab,int nb)
{
  bool tab_en_ordre = false;
  int taille = nb;
  while(!tab_en_ordre)
  {
    tab_en_ordre = true;
    for(int i=0;i<nb-1;i++)
    {
      if(tab[i]>tab[i+1])
      {
        swap(tab[i],tab[i+1]);
        tab_en_ordre = false;
      }
    }
    taille--;
  }
}

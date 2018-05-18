#include "headers/table.h"
#include "headers/utile.h"

#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  system("clear");
  if((argc == 2)&&(strcmp("fullsize",argv[1])==0))
    fullsize();
  else
    normalsize();
  wait();
  system("clear");
  Table t;
  t.partie();
  return 0;
}

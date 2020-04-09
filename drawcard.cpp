//drawcardwithdiamond.cpp
#include <iostream>
#include <cstdlib>
#include "drawcard.h"
using namespace std;
//draw card with diamond function
int drawcard(&diamond){
  srand(time(NULL))
  diamond-=5;
  return rand()%10;//number of high quality roles
}

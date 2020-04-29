//drawcardwithdiamond.cpp
#include <iostream>
#include <cstdlib>
#include "drawcardwithdiamond.h"
using namespace std;
//draw card with diamond function
int drawcardwithdiamond(int &diamond){
  srand(time(NULL));
  diamond-=5;
  return rand()%10;//number of high quality roles
}

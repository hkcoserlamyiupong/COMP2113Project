//drawcardwithheart.cpp
#include <iostream>
#include <cstdlib>
#include "drawcardwithheart.h"
using namespace std;
//draw card with diamond function
int drawcardwithheart(int &heart){
  srand(time(NULL));
  heart-=5;
  return rand()%10+10;//number of low quality roles, number of high quality roles
}

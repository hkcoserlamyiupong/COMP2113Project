//play.cpp
#include <iostream>
#include "role.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
void play(info role[], monsterinfo monster[]){
  info team[5];//team is an array of roles drawn to be summoned for the game and the maximum roles that can be drawn is 5//
  int j = 0;
  for (int i = 0; i < 10; i++){
    if (role[i].own==true){
      team[j]=role[i]
      j++;
    }
  }
  bool end;//a boolean variable indicating the end of game//
  int stage=1;//a variable indicating the level of the game//
  cout<<"stage 1, a goblin"<<endl;
  monster[0].present=true;
  monster[0].x=2;
  monster[0].y=9;
  srand(time(NULL));
  int map=rand()%4;//4 random maps, including hell, comp lab, phy lab and chem lab are featured//
  while (end==false){
    if (monster[0].dead=true){
      cout<<"stage 1 cleared"<<endl;
      stage++;
      cout<<"stage 2, a skeleton, which can revive once"<<endl;
    }
    else if ()
  }
}

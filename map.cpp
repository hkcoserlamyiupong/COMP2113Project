//map.cpp
#include <iostream>
#include "role.h"
#include "map.h"
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
void mapmap(info team[], monsterinfo monster[], string m[][10], int map){
  srand(time(NULL));
  for (int j = 0; j <=9; j++){
    for (int i = 0;i <= 4; i++){
      if (team[i].x==i&&team[i].y==j){
        m[i][j]=to_string(i);
      }
      else {
        m[i][j]="";
      }
      if (monster[0].x==i&&monster[0].y==j){
        m[i][j]+="G";//globin
      }
      if (monster[1].x==i&&monster[1].y==j){
        m[i][j]+="O";//orc
      }
      if (monster[2].x==i&&monster[2].y==j){
        m[i][j]+="S";//skeleton
      }
      if (monster[3].x==i&&monster[3].y==j){
        m[i][j]+="P";//tgpopo
      }
      if (monster[4].x==i&&monster[4].y==j){
        m[i][j]+="B";//boss baron
      }
    }
  }
  if (map==1){
    m[2][4]+="U";//uranium
  }
  if (map==2){
    m[rand()%5][rand()%10]+="F";//bunsen burner
    m[4-rand()%5][9-rand()%10]+="H";//heat proof mat
  }
  if (map==3){
    m[2][4]+="C";//computer
  }
  ofstream fout;
  fout.open("map.txt");
  m[rand()%5][rand()%10]+="+";//medkit
  for (int j = 9; j >=0; j--){
    for (int i = 0;i <= 4; i++){
      fout<<m[i][j]<<"  ";
    }
    fout<<endl;
  }
  fout.close();
}

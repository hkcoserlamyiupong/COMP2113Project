//stat.cpp
#include <iostream>
#include "role.h"
#include "stat.h"
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
//displays stats each round
void stat(info team[], monsterinfo monster[], int t){
  ofstream fout;
  fout.open("stat.txt", ios::app);
  for (int i = 0; i < 5; i++){
    fout<<"team member "<<i<<" "<<team[i].name<<endl;
    if (team[i].dead==true){
      fout<<"dead"<<endl;
    }
    else {
      fout<<"skill "<<team[i].skillname;
      if (team[i].cd<=0){
        fout<<" ready";
      }
      fout<<" cd:"<<team[i].cd<<"/"<<team[i].maxcd<<" hp:"<<team[i].hp<<"/"<<team[i].maxhp<<" position:("<<team[i].x<<","<<team[i].y<<")"<<" radiation:"<<team[i].radiation;
      if (team[i].ignited==true){
        fout<<" ignited, effect reamins for"<<t-team[i].ignitedt;
      }
      if (team[i].occupy>0){
        fout<<" occupying computer for"<<team[i].occupy;
      }
      fout<<endl;
    }
  }
  for (int i = 0; i < 5; i++){
    if (monster[i].present==true){
      fout<<"monster "<<i<<" "<<monster[i].name<<endl;
      if (monster[i].dead==true){
        fout<<"dead"<<endl;
      }
      else {
        fout<<"hp: "<<monster[i].hp<<"/"<<monster[i].maxhp<<" radiation:"<<monster[i].radiation;
        if (monster[i].ignited==true){
          fout<<" ignited, effect reamins for"<<t-monster[i].ignitedt;
        }
        if (monster[i].shocked==true){
          fout<<" shocked";
        }
        fout<<endl;
      }
    }
  }
  fout.close();
}

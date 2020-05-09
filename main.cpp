#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include "drawcardwithdiamond.h"
#include "play.h"
#include "role.h"
#include "stat.h"
#include "map.h"
#include "minigame.h"
using namespace std;
int main(){
  int diamond=25;
  info role[20];
  ifstream fin("roleinfo.txt");
  monsterinfo monster[5];
  //to intialize role stats//
  for (int i = 0; i < 20; i++){
    role[i].number=i;
    fin>>role[i].name>>role[i].skillname>>role[i].maxcd>>role[i].maxhp>>role[i].md>>role[i].ed>>role[i].bd>>role[i].maxvelocity;
    role[i].cd=role[i].maxcd;
    role[i].hp=role[i].maxhp;
    role[i].own=false;
    role[i].dead=false;
    role[i].infected=false;
    role[i].ignited=false;
    role[i].radiation=0.0;
    role[i].occupy=0;
  }
  //to initialize mob stats//
  for (int i = 0; i<5;i++){
    monster[i].number=i;
    fin>>monster[i].name>>monster[i].maxhp>>monster[i].md>>monster[i].ed>>monster[i].bd>>monster[i].maxvelocity;
    monster[i].hp=monster[i].maxhp;
    monster[i].present=false;
    monster[i].dead=false;
    monster[i].revive=false;
    monster[i].ignited=false;
    monster[i].shocked=false;
    monster[i].radiation=0.0;
  }
  fin.close();
  string command;
  while (command!="quit"){
    cout<<"please enter a command(drawcardwithdiamond, play ,minigame or quit)"<<endl;
    cin>>command;//user type a command//
      if (command=="drawcardwithdiamond"){
        if (diamond>=5){
          role[drawcardwithdiamond(diamond)].own=true;
        }
        else {
          cout<<"not enough diamonds"<<endl;
        }
      }else if (command=="play"){
        if (diamond==25){
          cout<<"please summon roles by drawcardwithdiamond first"<<endl;
        }
        else {
          info team[5];//team is an array of roles drawn to be summoned for the game and the maximum roles that can be drawn is 5//
          int j = 0;
          for (int i = 0; i < 20; i++){
            if (role[i].own==true){
              team[j]=role[i];
              j++;
            }
          }//team[i]where i belongs to{0,1,2,3,4}can be used to refer to roles for the game
          int stage=1;//a variable indicating the level of the game//
          play(team, monster, stage, role);
        }
      }else if (command=="minigame") {
        minigame();
      }
      else if (command=="quit"){
        break;
      }else{
          cout<<"invalid input"<<endl;
      }
  }
  return 0;
}

//play.cpp
#include <iostream>
#include "role.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
void play(info team[], monsterinfo monster[], int& stage, info role[]){
  srand(time(NULL));
  int t;//indicating the rounds in each match
  string m[5][10];//2d array for the map with row the x-coordinate and column the y-coordinate(the transpose of the matrix is the map)
  string command;
  for (int i = 0; i < 5; i++){
    team[i].ignited=false;
    team[i].radiation=0.0;
    team[i].occupy=0;
  }
  switch (stage){
    case '1':
      cout<<"stage 1, a goblin"<<endl;
      monster[0].present=true;
      monster[0].hp=monster[0].maxhp;
      monster[0].dead=false;
      monster[0].ignited=false;
      monster[0].shocked=false;
      monster[0].radiation=0.0;
      monster[0].x=2;
      monster[0].y=9;
      monster[0].revive=false;
      break;
    case '2':
      cout<<"stage 2, a skeleton, which can revive once and may appear anywhere on the map initially"<<endl;
      monster[2].present=true;
      monster[2].hp=monster[2].maxhp;
      monster[2].dead=false;
      monster[2].ignited=false;
      monster[2].shocked=false;
      monster[2].radiation=0.0;
      monster[2].x=rand()%5;
      monster[2].y=rand()%9;
      monster[2].revive=true;
      break;
    case '3':
      cout<<"stage 3, a goblin, an orc and a skeleton"<<endl;
      for (int i = 0;i <= 2;i++){
        monster[i].present=true;
        monster[i].hp=monster[i].maxhp;
        monster[i].dead=false;
        monster[i].ignited=false;
        monster[i].shocked=false;
        monster[i].radiation=0.0;
        monster[i].x=1+i;
        monster[i].y=7+i;
        monster[i].revive=false;
      }
      monster[2].revive=true;
      break;
    case '4':
      cout<<"stage 4, a teargaspopo with 2 modes of attack"<<endl;
      monster[3].present=true;
      monster[3].hp=monster[3].maxhp;
      monster[3].dead=false;
      monster[3].ignited=false;
      monster[3].shocked=false;
      monster[3].radiation=0.0;
      monster[3].x=2;
      monster[3].y=9;
      monster[3].revive=false;
      break;
    case '5':
      cout<<"stage 5, a tanky baron"<<endl;
      monster[4].present=true;
      monster[4].hp=monster[4].maxhp;
      monster[4].dead=false;
      monster[4].ignited=false;
      monster[4].shocked=false;
      monster[4].radiation=0.0;
      monster[4].x=2;
      monster[4].y=9;
      monster[4].revive=false;
      break;
  }
  bool end=false;//a boolean variable indicating the end of game//
  int map=rand()%4;//4 random maps, including hell, comp lab, phy lab and chem lab are featured//
  switch (map){
    case '0':
      cout<<"hell map"<<endl;
      cout<<"combustion of all roles and mobs in this map"<<endl;
      break;
    case '1':
      cout<<"physics lab"<<endl;
      cout<<"radioactive uranium emitting gamma ray at the centre of this map"<<endl;
      break;
    case '2':
      cout<<"chemistry lab"<<endl;
      cout<<"random items like bunsen burners and heatproof mats are available"<<endl;
      break;
    case '3':
      cout<<"computer lab"<<endl;
      cout<<"any role staying at the computer at (2,4)for 20 consecutive rounds may hack the game and pass the stage directly"<<endl;
      break;
  }
  while (end==false){
    if (team[0].dead==true&&team[1].dead==true&&team[2].dead==true&&team[3].dead==true&&team[4].dead==true){
      cout<<"all your roles are dead"<<endl;
      cout<<"defeat"<<endl;
      end=true;
    }
    else if(stage>5){
      cout<<"you have cleared all stages"<<endl;
      cout<<"victory"<<endl;
      end=true;
    }
    else if(monster[0].dead==true&&monster[1].dead==true&&monster[2].dead==true&&monster[3].dead==true&&monster[4].dead==true&&monster[2].revive=false){
      for (int i = 0; i < 5; i++){
        monster[i].present=false;
      }
      cout<<"you have cleared stage "<<stage<<endl;
      stage++;
      void play(team, monster, stage);
    }
    if (map==0){
      for (int i = 0; i < 5; i++){
        if (team[i].dead==false){
          team[i].ignited=true;
          team[i].ignitedt=t;
        }
        if (monster[i].present==true&&monster[i].dead==false){
          monster[i].ignited=true;
          monster[i].ignitedt=t;
      }
    }
    if (map==1){
      for (int i = 0; i < 5; i++){
        if (team[i].dead==false){
          team[i].radiation=200/((team[i].x-2)*(team[i].x-2)+(team[i].y-4)*(team[i].y-4));
        }
        if (monster[i].present==true&&monster[i].dead==false){
          monster[i].radiation=200/((monster[i].x-2)*(monster[i].x-2)+(monster[i].y-4)*(monster[i].y-4));
      }
    }
    if (map==2){
      for (int i = 0; i < 5; i++){
        if (team[i].dead==false){
          string s=m[team[i].x][team[i].y];
          for (int j = 0; j < s.length(); j++){
            if (s[j]=='F'){
              team[i].ignited=true;
              team[i].ignitedt=t;
            }
            if (s[j]=='H'){
              team[i].ignited=false;
            }
          }
        }
        if (monster[i].present==true&&monster[i].dead==false){
          string s=m[monster[i].x][monster[i].y];
          for (int j = 0; j < s.length(); j++){
            if (s[j]=='F'){
              monster[i].ignited=true;
              monster[i].ignitedt=t;
            }
            if (s[j]=='H'){
              monster[i].ignited=false;
            }
          }
        }
      }
    }
    if (map==3){
      for (int i = 0; i < 5; i++){
        if (team[i].dead==false){
          if (team[i].occupy>=20){
            for (int i = 0; i < 5; i++){
              if (monster[i].present==true){
                monster[i].dead=true;
              }
            }
          }
          else if (team[i].x==2&&team[i].y==4){
            team[i].occupy++;
          }
          else {
            team[i].occupy=0;
          }
        }
      }
    }
    for (int i = 0; i < 5; i++){
      if (team[i].hp<=0){
        team[i].dead=true;
      }
      if (monster[i].hp<=0){
        monster[i].dead=true;
      }
      if (team[i].dead==false){
        if (team[i].ignited==true){
          team[i].hp-=(3-t+team[i].ignitedt)*30;
        }
        team[i].hp-=team[i].radiation-team[i].bd;
        string s=m[team[i].x][team[i].y];
        for (int j = 0; j < s.length(); j++){
          if (s[j]=='+'){
            if (team[i].hp>=team[i].maxhp-100){
              team[i].hp=team[i].maxhp;
            }
            else {
              team[i].hp+=100;
            }
          }
        }
      }
      if (monster[i].dead==false){
        if (monster[i].ignited==true){
          monster[i].hp-=(3-t+monster[i].ignitedt)*30;
        }
        monster[i].hp-+monster[i].radiation-monster[i].bd;
      }
    }
    cout<<"Please enter command("skill" or "move"?)"<<endl;
    cin>>command;
    if (command=="skill"){
      cout<<"Please enter your alive team member role(from 0 to 4) to use skill"<<endl;
      int k;
      bool valid=false;
      while (valid==false){
        cin>>k;
        if (k>=0&&k<=4){
          if (team[k].dead=false){
            team[k].skill(role, monster);
            valid=true;
          }
          else {
            cout<<"team member dead, please enter again"<<endl;
          }
        }
        else {
          cout<<"invalid input, please enter again"<<endl;
        }
      }
    }
    else if (command=="move"){
      cout<<"Please enter your alive team member role(from 0 to 4) to move"<<endl;
      int k;
      bool valid=false;
      while (valid==false){
        cin>>k;
        if (k>=0&&k<=4){
          if (team[k].dead=false){
            team[k].move();
            valid=true;
          }
          else {
            cout<<"team member dead, please enter again"<<endl;
          }
        }
        else {
          cout<<"invalid input, please enter again"<<endl;
        }
      }
    }
    map(team, monster, m, map);
    t++;//time increment of 1s each round
  }
}

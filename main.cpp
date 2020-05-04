#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include "drawcardwithdiamond.h"
#include "play.h"
#include "role.h"
using namespace std;
int main(){
  int diamond=25;
  struct info role[20];
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
  role[].skill(role, monster);
  while (command!="quit"){
    cin>>command;//user type a command//
      if (command=="drawcardwithdiamond"){
        if (diamond>=5){
          role[drawcardwithdiamond(diamond)].own=true;
          break;
        }
        else {
          cout<<"not enough diamonds"<<endl;
        }
      }else if (command=="play"){
        void(role, monster);
      }else if (command=="quit"){
        break;
      }else{
          cout<<"invalid input"<<endl;
      }
  }
  return 0;
}

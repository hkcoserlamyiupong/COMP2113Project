#include <iostream>
#include <cstdlib>
#include "drawcardwithdiamond.h"
#include "drawcardwithheart.h"
#include "role.h"
using namespace std;
int main(){
  int diamond=25;
  int heart=50;
  string command;

  info role[20];
  for (int i = 0; i < 20; i++){
    role[i].number=i;
  }
  role[].skill(role);
  while (command!='quit'){
    cin>>command;//user type a command//
    switch (command){
      case 'drawcardwithdiamond':
        role[drawcardwithdiamond(diamond)].own=true;
        break;
      case 'quit':
        break;
      default:
        cout<<"invalid input";
    }
  }
  return 0;
}

//skill.cpp
#include <iostream>
#include "role.h"
#include <cmath>
#include <string>
using namespace std;
void info::skill(info role[]){
  cout<<skillname<<endl;
  cd=maxcd;
  switch(number){
    case '0':
      cout<<"travel within a distance of 5 and attack enemies physically on the path";
      cout<<"please enter coordinates of destination"<<endl;
      int x1 = x;
      int y1 = y;
      int * x1 = new int;
      *x1 = x1;
      int * y1 = new int;
      *y1 = y1;
      double distance;
      cin>>x;
      cin>>y;
      distance=sqrt((*x1-x)*(*x1-x)+(*y1-y)*(*y1-y));//distance the role travels//
      while (distance>5.0){
        cout<<"too far"<<endl;
        cin>>x;
        cin>>y;
        distance=sqrt((*x1-x)*(*x1-x)+(*y1-y)*(*y1-y));
      }
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          distance=abs((y-(*y1)*monster[i].x+(*x1-x)*monster[i].y-(*x1)*y+x*(*y1))/sqrt((y-(*y1))*(y-(*y1))+(*x1-x)*(*x1-x));
          //a monster is considered to be passed through if the perpendicular distance from the monster to the straight line the role travels is less than 1//
          if (distance<1){
            int *dhdt = new int (400-monster[i].md);
            cout<<"mechanical damage dealt "<<*dhdt<<endl;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
          }
        }
      }
      *x1=new int;
      *y1=new int;
      delete x1;
      delete y1;
      break;
    case '1':
      cout<<"attack a single enemy 16 hits with dual blades"<<endl;
      string target;
      bool *valid=new bool(false);
      cout<<"please enter a target"<<endl;
      cin>>target;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true&&monster[i].name==target){
          int *dhdt = new int ((100-monster[i].md)*16);//the value of mob's mechanical defence will be deducted to give the damage for each hit//
          cout<<"mechanical damage dealt "<<*dhdt<<endl;
          monster[i].hp-=*dhdt;
          delete dhdt;
          dhdt=0;
          *valid=true;
        }
      }
      while (*valid==false){
        cout<<"invalid targetr input"<<endl;
        for (int i = 0; i < 5; i++){
          if (monster[i].present==true&&monster[i].name==target){
            int *dhdt = new int ((100-monster[i].md)*16);
            cout<<"mechanical damage dealt "<<*dhdt<<endl;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
            *valid=true;
          }
        }
      }
      delete valid;
      valid=0;
      break;
    case '2':
      cout<<"slash every enemy within a distance of 3 at the stage with the katana"<<endl;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          double *distance = new double;
          *distance=sqrt((x-monster[i].x)*(x-monster[i].x)+(y-monster[i].y)*(y-monster[i].y));
          if (*distance <=3.0){
            int *dhdt = new int (300-monster[i].md);
            cout<<"mechanical damage dealt "<<*dhdt<<endl;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
          }
          delete distance;
          distance=0;
        }
      }
      break;
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
  }
}

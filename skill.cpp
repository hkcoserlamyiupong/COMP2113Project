//skill.cpp
#include <iostream>
#include "role.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
void info::skill(info role[], monsterinfo monster[]){
  cout<<skillname<<endl;
  cd=maxcd;
  switch(number){
    case 0:
      cout<<"travel within a displacement of 5 and attack enemies physically on the path"<<endl;
      cout<<"please enter coordinates of destination"<<endl;
      int x1 = x;
      int y1 = y;
      int * x1 = new int;
      *x1 = x1;
      int * y1 = new int;
      *y1 = y1;
      double distance;
      bool valid=false;
      while (valid==false){
        cin>>x;
        cin>>y;
        if (x>=0&&x<=4&&y>=0&&y<=9){
          double distance;
          distance=sqrt((*x1-x)*(*x1-x)+(*y1-y)*(*y1-y));//distance the role travels//
          if (distance<=5.0){
            valid=true;
          }
          else {
            cout<<"too far, please enter again"<<endl;
          }
        }
        else {
          cout<<"out of range, please enter again"<<endl;
        }
      }
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          distance=abs((y-(*y1))*monster[i].x+(*x1-x)*monster[i].y-(*x1)*y+x*(*y1))/sqrt((y-(*y1))*(y-(*y1))+(*x1-x)*(*x1-x));
          //a monster is considered to be passed through if the perpendicular distance from the monster to the straight line the role travels is less than 1//
          if (distance<1){
            int *dhdt = new int (400-monster[i].md);
            cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
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
      x1=0;
      y1=0;
      break;
    case 1:
      cout<<"attack a single enemy 16 hits with dual blades"<<endl;
      string target;
      bool *valid=new bool(false);
      cout<<"please enter a target(the name of mob you want to hit with dual blades)"<<endl;
      cin>>target;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true&&monster[i].name==target){
          int *dhdt = new int ((100-monster[i].md)*16);//the value of mob's mechanical defence will be deducted to give the damage for each hit//
          cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
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
            cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
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
    case 2:
      cout<<"heal all your team members(roles) by up to 400 hp"<<endl;
      for (int i = 0; i < 10; i++){
        if (role[i].own==true){
          if (role[i].hp>=role[i].maxhp-400){
            role[i].hp=role[i].maxhp;
          }
          else {
            role[i].hp+=400;
          }
        }
      }
    case 3:
      cout<<"slash every enemy within a distance of 3 at the stage with the katana and appear at the position of the enemy you slash"<<endl;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          double *distance = new double;
          *distance=sqrt((x-monster[i].x)*(x-monster[i].x)+(y-monster[i].y)*(y-monster[i].y));
          if (*distance <=3.0){
            int *dhdt = new int (300-monster[i].md);
            cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
            x=monster[i].x;
            y=monster[i].y;
          }
          delete distance;
          distance=0;
        }
      }
      break;
    case 4:
      cout<<"launch an atomic bomb with massive damage to both sides"<<endl;
      cout<<"please enter coordinates of detonation of nuclear fission"<<endl;
      int * x0 = new int;
      cin>>*x0;
      int * y0 = new int;
      cin>>*y0;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          double *distance = new double;
          *distance=sqrt((*x0-monster[i].x)*(*x0-monster[i].x)+(*y0-monster[i].y)*(*y0-monster[i].y));
          monster[i].hp-=1000/((*distance)*(*distance))+monster[i].md;
          monster[i].radiation+=200/((*distance)*(*distance));
          delete distance;
          distance=0;
        }
      }
      for (int i = 0; i < 10; i++){
        if (role[i].own==true){
          double *distance = new double;
          *distance=sqrt((*x0-role[i].x)*(*x0-role[i].x)+(*y0-role[i].y)*(*y0-role[i].y));
          role[i].hp-=1000/((*distance)*(*distance))+role[i].md;
          role[i].radiation+=200/((*distance)*(*distance));
          delete distance;
          distance=0;
        }
      }
      delete x0;
      delete y0;
      x0=0;
      y0=0;
      break;
    case 5:
      cout<<"hack to achieve an instant victory by changing the boolean death status of all enemies to true(this overrides the ability to revive of skeletons)"<<endl;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          monster[i].hp=0;
          monster[i].dead=true;
          monster[i].revive=false;
        }
      }
      break;
    case 6:
      cout<<"shoot an enemy with your sniper"<<endl;
      string target;
      bool *valid=new bool(false);
      cout<<"please enter a target(the name of mob you want to shoot)"<<endl;
      cin>>target;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true&&monster[i].name==target){
          int *dhdt = new int (800-monster[i].md);
          cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
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
            int *dhdt = new int (800-monster[i].md);
            cout<<"mechanical damage dealt to"<<monster[i].name<<*dhdt<<endl;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
            *valid=true;
          }
        }
      }
      break;
    case 7:
      cout<<"set an exertal potential difference of 100kV across an enemy and skip the enemy 1 round"<<endl;
      string target;
      bool *valid=new bool(false);
      cout<<"please enter a target(the name of mob to conduct electricity)"<<endl;
      cin>>target;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true&&monster[i].name==target){
          int *dhdt = new int (10000/monster[i].ed);
          cout<<"electrical damage dealt to"<<monster[i].name<<*dhdt<<endl;
          monster[i].shocked=true;
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
            int *dhdt = new int (10000/monster[i].ed);
            cout<<"electrical damage dealt to"<<monster[i].name<<*dhdt<<endl;
            monster[i].shocked=true;
            monster[i].hp-=*dhdt;
            delete dhdt;
            dhdt=0;
            *valid=true;
          }
        }
      }
      break;
    case 8:
      cout<<"spread toxic chlorine gas(Haber wears a mask himself so he will not get poisoned)"<<endl;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          double *distance = new double;
          *distance=sqrt((x-monster[i].x)*(x-monster[i].x)+(y-monster[i].y)*(y-monster[i].y));
          monster[i].hp-=400/((*distance)*(*distance))+monster[i].bd;
          delete distance;
          distance=0;
        }
      }
      for (int i = 0; i < 10; i++){
        if (role[i].own==true){
          double *distance = new double;
          *distance=sqrt((x-role[i].x)*(x-role[i].x)+(y-role[i].y)*(y-role[i].y));
          role[i].hp-=400/((*distance)*(*distance))+role[i].bd;
          delete distance;
          distance=0;
        }
      }
      break;
    case 9:
      cout<<"fire the shotgun in a direction and damage enemies within pi/6 from normal"<<endl;
      cout<<"please enter coordinates where you aim your shotgun"<<endl;
      int * x0 = new int;
      cin>>*x0;
      int * y0 = new int;
      cin>>*y0;
      for (int i = 0; i < 5; i++){
        if (monster[i].present==true){
          double *distance = new double;
          double *distancefromnormal = new double;
          *distance=sqrt((x-monster[i].x)*(x-monster[i].x)+(y-monster[i].y)*(y-monster[i].y));//
          distancefromnormal=abs((y-(*y0))*monster[i].x+(*x0-x)*monster[i].y-(*x0)*y+x*(*y0))/sqrt((y-(*y0))*(y-(*y0))+(*x0-x)*(*x0-x));
          if ((*distancefromnormal)/(*distance)<=0.5){
            monster[i].hp-=500/((*distance)*(*distance))+monster[i].md;
          }
          delete distance;
          distance=0;
          delete distancefromnormal;
          distancefromnormal=0;
        }
      }
      break;
  }
}

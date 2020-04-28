//skill.cpp
#include <iostream>
#include "role.h"
#include <cmath>
using namespace std;
void info::skill(info role[]){
  cout<<skillname<<endl;
  cd=maxcd;
  switch(number){
    case '0':
      cout<<"travel within a distance of 5 and attack enemies on the path";
      cout<<"please enter coordinates of destination"<<endl;
      int * i = new int;
      *i = x;
      int * j = new int;
      *j = y;
      double distance;
      cin>>x;
      cin>>y;
      distance=sqrt((*i-x)*(*i-x)+(*j-y)*(*j-y));
      while (distance>5.0){
        cout<<"too far";

      }
      break;
    case '1':
      cout<<"attack a single enemy 16 hits with dual blades"<<endl;
      int target;
      cout<<"please enter a target"<<endl;
      cin>>target;
      break;
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
  }
}

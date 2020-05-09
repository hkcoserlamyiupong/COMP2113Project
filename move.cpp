//move.cpp
#include <iostream>
#include "role.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
void info::move(){
  cout<<"please enter coordinates of destination"<<endl;
  int xx = x;
  int yy = y;
  int * x1 = new int;
  *x1 = xx;
  int * y1 = new int;
  *y1 = yy;
  bool valid=false;
  while (valid==false){
    cin>>x;
    cin>>y;
    if (x>=0&&x<=4&&y>=0&&y<=9){
      double distance;
      distance=sqrt((*x1-x)*(*x1-x)+(*y1-y)*(*y1-y));//distance the role travels//
      if (distance<=maxvelocity){
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
  x1=new int;
  y1=new int;
  delete x1;
  delete y1;
  x1=0;
  y1=0;
}

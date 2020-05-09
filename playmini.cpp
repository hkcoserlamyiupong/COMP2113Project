
#include <iostream>
#include "playmini.h"
#include "champ.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void playmini(champ hero,champ monster,int maxhp, string command[],int level,int k,int Ncommand){
    srand( time(NULL) );
    cout<<endl<<"hero attack damage: "<<hero.att<<endl;
    string need,input;
    int t,t2,sp;
    monster.att+=1;
    monster.hp=maxhp*1.2;
    while (monster.hp>0&&hero.hp>0){
        cout<<"hero has "<<hero.hp<<"hp"<<endl;
        cout<<"monster has "<<monster.hp<<"hp"<<endl;
        t=time(NULL);
        for (int i=0;i<k;i++){
            cout<<"You need "<<k-i<<" spells more to attack"<<endl;
            need=command[rand()%Ncommand];
            cout<<need<<endl;
            cin>>input;
            while (input!=need){
                cout<<"Wrong! Input again:"<<endl<<need<<endl;
                cin>>input;
            }
        }
        t2=time(NULL);
        hero.hp-=monster.att*(t2-t);
        monster.hp-=hero.att;
        //cout<<monster.hp<<endl;
        cout<<endl;
        if (hero.hp<=0){
            cout<<"Gave Over"<<endl;
            cout<<"You have reach level "<<level<<endl;
        }else if (monster.hp<=0){
            cout<<"Lv "<<level<<" clear"<<endl;
            level++;
            if (level%3==0){
                k+=3; //increase the command needed every 3 levels
            }
            cout<<"You have "<<level*15<<" skill point"<<endl;
            cout<<"You rise attack by (The remaining will heal th HP):";
            while (true){
                cin>>sp;
                if (sp<=level*15&&sp>=0){
                    hero.att+=sp;
                    hero.hp+=level*10-sp;
                    break;
                }
                cout<<"Invalid Input"<<endl;
            }
            cout<<"1: Continue"<<endl<<"2: Save and Quit"<<endl;
            cin>>input;
            while (true) {
                if (input=="2"){
                    cout<<endl;
                    return;
                }else if(input!="1"){
                    cout<<"Invalid Input!"<<endl<<endl;
                    cin>>input;
                }else{
                    break;
                }
            }
    }
        
    }
    cout<<endl;
}

#include <iostream>
#include "champ.h"
#include <cstdlib>
#include <ctime>
#include "playmini.h"
#include "NewGame.h"
#include "minigame.h"
#include <fstream>

using namespace std;
void minigame() {
    //string command[]={"abc","def","hijk"};    string need;
    //cout<<"Loading..."<<endl<<endl;
    int input,k,Ncommand,level;
    champ hero;
    champ monster;
    cout<<"Monsters are distroying the world"<<endl<<"Fight with it by magic"<<endl<<"Type the suitable magic spells to attack it"<<endl<<"The Longer you spend, the larger damage it deals to You"<<endl<<"The monsters you face will be stronger by the time"<<endl<<"Survive as long as you can! Good luck"<<endl<<endl;
    while (true){
        ifstream fin1("ministat.txt");
        fin1>>hero.att>>hero.hp>>monster.att>>monster.hp>>level>>k>>Ncommand;
        //cout<<monster.hp<<endl;
        //cout<<hero.att<<" "<<hero.hp<<" "<<monster.att<<" "<<hero.hp<<endl<<endl;
        fin1.close();
        ifstream fin2("command.txt");
        string *command=new string [Ncommand];
        for (int i=0;i<Ncommand;i++){
            fin2>>command[i];
        }
        int maxhp=monster.hp;
        fin2.close();
        cout<<"1: Continue Playing"<<endl;
        cout<<"2: Start New Game"<<endl;
        cout<<"3: Add New Spells"<<endl;
        cout<<"4: Show All Spells"<<endl;
        cout<<"5: Quit"<<endl;
        while (!(cin>>input)){
            cout<<"Invalid Input!"<<endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
        switch (input) {
            case 1:
                playmini(hero,monster,maxhp,command,level,k,Ncommand);
                break;
            case 2:
                NewGame(hero,monster,level,k);
                playmini(hero,monster,maxhp,command,level,k,Ncommand);
                break;

            case 3:
            {
                ofstream add("command.txt",std::fstream::in | std::fstream::out | std::fstream::app);
                string spell;
                cout<<"Input the spell: ";
                cin>>spell;
                add<<spell<<"\n";
                Ncommand++;
                ofstream fout2("ministat.txt");
                fout2<<hero.att<<" "<<hero.hp<<"\n"<<monster.att<<" "<<monster.hp<<"\n"<<level<<" "<<k<<"\n"<<Ncommand;
                fout2.close();
                cout<<spell<<" has been added to spells"<<endl<<endl;
                break;
            }
            case 4:
            {
                for (int i=0;i<Ncommand;i++){
                    cout<<command[i]<<endl;
                }
                cout<<endl;
                break;
            }
            case 5:
            {
                ofstream save("ministat.txt");
                save<<hero.att<<" "<<hero.hp<<"\n"<<monster.att<<" "<<monster.hp<<"\n"<<level<<" "<<k<<"\n"<<Ncommand;
                delete [] command;
                return;
                break;
            }

            default:
                cout<<"Invalid Input!"<<endl<<endl;
                break;
        }

    }
}

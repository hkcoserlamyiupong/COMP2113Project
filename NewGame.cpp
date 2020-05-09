//
//  NewGame.cpp
//  New PJ
//
//  Created by Fu Wing Ho on 9/5/2020.
//  Copyright © 2020 Fu Wing Ho. All rights reserved.
//

#include "NewGame.h"
#include <fstream>
#include "champ.h"
using namespace std;
void NewGame(champ &hero, champ &monster, int &level, int &k){
    int temp;
    hero.att=30;
    hero.hp=250;
    monster.att=2;
    monster.hp=70;
    level=1;
    k=3;
    ifstream fin("/Users/hubertfu/Desktop/1340/New PJ/New PJ/ministat.txt");
    fin>>temp>>temp>>temp>>temp>>temp>>temp>>temp;
    fin.close();
    ofstream fout("/Users/hubertfu/Desktop/1340/New PJ/New PJ/ministat.txt");
    fout<<"30 200\n"<<"2 70\n"<<"1 3\n"<<temp;
    fout.close();
}

//role.h
#include <string>
#ifndef ROLE
#define ROLE
using namespace std;
struct monsterinfo {
  int number;//index of mobs//
  string name;//name of mobs//
  int hp;//current health point//
  int maxhp;//health point//
  int md;//mechanical defence//
  int ed;//electrical defence//
  int bd;//biological defence//
  int x;
  int y;
  double maxvelocity;//maximum displacement of mobs in a round//
  bool present;//indicate the mob is present in that stage
  bool dead;
  bool revive;
  bool ignited;
  bool shocked;
  double radiation;
  int ignitedt;//initial time of combustion
};
struct info {
  int number;//index of role//
  string name;//name of role//
  string skillname;//name of skill//
  int cd;//current cool down time//
  int maxcd;//cool down time//
  void skill(info [], monsterinfo []);
  void move();
  int hp;//current health point//
  int maxhp;//health point//
  int md;//mechanical defence//
  int ed;//electrical defence//
  int bd;//biological defence//
  double maxvelocity;//maximum displacement in a round//
  int x;
  int y;
  bool own;//indicate the player owns the role
  bool dead;
  bool infected;
  bool ignited;
  double radiation;
  int occupy;//indicate the time of occupying the computer in computer lab
  int ignitedt;//initial time of combustion
};
#endif

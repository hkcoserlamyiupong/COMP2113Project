//role.h
#ifndef skill
#define skill
struct info {
  int number;//index of role//
  string name;//name of role//
  string skillname;//name of skill//
  int cd;//current cool down time//
  int maxcd;//cool down time//
  void skill(info []);
  void move();
  int hp;//current health point//
  int maxhp;//health point//
  int md;//mechanical defence//
  int ed;//electrical defence//
  int bd;//biological defence//
  double maxvelocity;//maximum displacement in a round//
  int x;
  int y;
  bool own;
  bool dead;
  bool revive;
  bool infected;
};
struct monsterinfo {
  int number;//index of mobs//
  string name;//name of mobs//
  int hp;//current health point//
  int maxhp;//health point//
  int md;//mechanical defence//
  int ed;//electrical defence//
  int bd;//biological defence//
  double maxvelocity;//maximum displacement of mobs in a round//
};
#endif

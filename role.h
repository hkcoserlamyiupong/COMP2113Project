//role.h
#ifndef skill
#define skill
struct info {
  string name;
  string skillname;
  int cd;
  int maxcd;
  void skill(info &role[i]);
  int hp;
  int maxhp;
  double maxvelocity;
  double visibility;
  int x;
  int y;
  bool dead;
  bool revive;
};
#endif

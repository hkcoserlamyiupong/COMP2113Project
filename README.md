# COMP2113Project
text based game
A brief identification of the team members:
I am Lam Yiu Pong. My uid is 3035691248.
My teammate is Fu Wing Ho.

A game description with basic game rules:
  This game will be a 1vs1 battle game among roles (to avoid ambiguity, the 角色s in the game will be named 'roles' instead of 'characters' which is a well defined data type). At first, the player draws some roles and choose them into the team. Then during the battle, the chosen roles in the team will be generated on a map with rectangular coordinates. Each map will have two zones for roles of both sides to be generated and a neutral zone betwen them. Both sides take turns to give one command. For each turn, one may displace one of his or her roles and use skills or normal attacks. One will lose when all of the roles die.
  This game will adopt different game and anime characters from League of Legends, Fate Grand Order, Kimetsu no Yaiba, etc. while the rules may have reference to champion stats from League of Legends.

A list of features / functions that you plan to implement, vis-a-vis each of the items 1 to 5 listed under coding requirements above:
Code Requirement. Your implementation should encompass the following coding elements:
  Generation of random game sets or events:
    As we all know that luck makes game more interesting, this game will feature generation of random roles, random maps, random elements on the maps and some random variation on damage dealt.
    For roles, the player will be given 25 diamonds and 50 hearts to summon the roles by random. There will be 1 to 2 functions for the 抽卡系統. Drawing a high quality role costs 5 diamonds each while drawing a low quality role costs 10 hearts each.
    For maps, the player may choose one of the maps or a random map. There may be several maps available: hell map where all roles suffer from continuous thermal damage, physics laboratory lab where there will be a radioactive uranium in the middle of the map and all roles receive damage which is inversely proportional to the distance between the role and the source, etc.
    
  Data structures for storing game status:
    Each role has its own unique status stored in a struct. We will have an array of structs to store status of different roles so each role can be identified by an index in the array.
    For each struct, there will be a string storing the role's name and race or occupation, bool to store death or debuff status, int or double to store hp(health point), mp(stamina), postion, maxvelocity(the maximum displacement in each round), visibility, basic attack range, basic attack rate, mechanical attack, mechanical defence, thermal attack, thermal defence, biological attack, biological defence, hit probability, crit probability, etc. The position will be in int for discrete grid in the map, but maxvelocity, range and visibility will be in double so as to calculate the distance more accurately. There will also be an uniques function for each role's skill, with its discription and cd(cooldown time).
    
  Dynamic memory management:
  We may use dynamic array and variables for storing status of map and characters instantaneously.
  
  File input/output (e.g., for loading/saving game status):
  There will be text files to store descriptions of each character, each character's skill.
  There will be files to display the map grid simultaneously and each character's instant status for each turn.
  
  Program codes in multiple files:
  There will be header files to declare various functions separately. These header files will be #include<>d in the main .cpp program.
  e.g. drawcard.h, displaymap.h, etc.

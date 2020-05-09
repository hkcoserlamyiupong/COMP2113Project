# COMP2113Project
text based game
A brief identification of the team members:
I am Lam Yiu Pong. My uid is 3035691248.
My teammate is Fu Wing Ho. UID: 3035692890

A game description with basic game rules:
  This game will be a mvp battle game where the player use roles (to avoid ambiguity, the champions in the game will be named 'roles' instead of 'characters' which is a well defined data type) to fight against monster or mobs and there will be five waves of mobs to fight against. At first, the player draws some roles randomly and assign them into the team. Then during the battle, the chosen roles in the team will be generated on a map with rectangular coordinates. Both sides take turns to give one command. For each turn, one may displace one of his or her roles or use skills(when available). The player will lose when all of his/her roles die. If all the mobs in a stage is dead, the player may proceed to the next stage. A player will achieve the final victory only when all five waves of mobs are dead. To start the game, make main in the command line of linux and run the main.cpp program.
  During the game, there is decrement of cooldowntime cd and increment of time t each round. When cd of a role drops to 0, it may use a skill.
  This game will adopt different game and anime characters from League of Legends, Sword Art Online, Kimetsu no Yaiba, etc.

A list of features / functions that you plan to implement, vis-a-vis each of the items 1 to 5 listed under coding requirements above:
Code Requirement. Your implementation should encompass the following coding elements:
  Generation of random game sets or events:
    As we all know that luck makes game more interesting, this game will feature generation of random roles, random maps, random elements on the maps and some random variation on damage dealt.
    For roles, the player will be given 25 diamonds to summon the roles by random. There will be a function for the drawing system. Drawing a role costs 5 diamonds each so player may draw up to 5 roles from the set of roles.
    For maps, a random map out of 4 will be generated. There may be several maps available: hell map where all roles suffer from continuous thermal damage, physics laboratory lab where there will be a radioactive uranium in the middle of the map and all roles receive damage which is inversely proportional to the distance between the role and the source, chemistry laboratory where there will be random bunsen burner and heat proof mat, and a computer laboratory with a computer in the centre of the map where roles may occupy it and stay for 20 rounds to directly win for that stage. There may also be random medkit for recovery appearing on the map.
    The mode of mobs may also involve some random elements. Skeletons, orcs and goblins perform Brownian motion while tear gas popo launches tear gas to a random coordinate in the map as one of its 2 attack modes.
    There is a 50% chance for the role shinon and teargas popo to have a head shot which doubles the maximum damage.
  Data structures for storing game status:
    Each role has its own unique status stored in a struct. We will have an array of structs to store status of different roles so each role can be identified by an index in the array. We will have another array of structs to store the status of mobs.
    For each struct, there will be a string storing the role's name, bool to store death or debuff status, int or double to store hp(health point), cd(cooldown time), position, maxvelocity(the maximum displacement in each round), mechanical defence, electrical defence, biological defence, etc. The position will be in int for discrete grid in the map, but maxvelocity will be in double so as to calculate the distance more accurately. There will also be functions for each role's unique skill and displacement.
    
  Dynamic memory management:
  We may use dynamic array and variables for storing status of map and characters instantaneously. For example, in the skill function of a role, we will use new ints to store the initial position of the role so as to get the distance travelled and the formula of the straight line where the role travels, thus the perpendicular distance between the mob and this line. There may also be dynamic variable to store the damage dealt for a skill. These dynamic variables are to be deleted after the displacement or skill.
  
  File input/output (e.g., for loading/saving game status):
  There will be text files to store descriptions of each character, each character's skill.
  The roleinfo.txt storing stats of roles and mobs will be a file input.
  There will be files to display the map grid simultaneously and each character's instant status for each turn, namely map.txt and stat.txt.
  
  Program codes in multiple files:
  There will be header files to declare various functions separately. These header files will be #include<>d in the main .cpp program.
  e.g. drawcardwithdiamond.h, displaymap.h, role.h, etc.

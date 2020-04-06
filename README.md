# COMP2113Project
text based game
A brief identification of the team members:

A game description with basic game rules:
  This game will be a 1vs1 battle game among roles (to avoid ambiguity, the 角色s in the game will be named 'roles' instead of 'characters' which is a well defined data type). 

A list of features / functions that you plan to implement, vis-a-vis each of the items 1 to 5 listed under coding requirements above:
Code Requirement. Your implementation should encompass the following coding elements:
  Generation of random game sets or events:
    As we all know that luck makes game more interesting, this game will feature generation of random roles, random maps, random elements on the maps and some random variation on damage dealt.
    For roles, the player will be given 25 diamonds and 50 hearts to summon the roles by random. There will be 1 to 2 functions for the 抽卡系統. Drawing a high quality role costs 5 diamonds each while drawing a low quality role costs 10 hearts each.
    For maps, there may be several maps available: hell map where all roles suffer from continuous thermal damage, 
    
  Data structures for storing game status:
    Each role has its own unique status stored in a struct. We will have an array of structs to store status of different roles so each role can be identified by an index in the array.
    For each struct, there will be a string storing the role's name, int or double to store hp(health point), mp(stamina), mechanical attack, mechanical defence, thermal attack, thermal defence, biological attack, biological defence
    
  Dynamic memory management:
  
  File input/output (e.g., for loading/saving game status):
  
  Program codes in multiple files:

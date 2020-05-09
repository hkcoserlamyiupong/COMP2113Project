#makefile
FLAGS = -pedantic-errors -std=c++11
drawcardwithdiamond.o: drawcardwithdiamond.cpp drawcardwithdiamond.h
	g++ $(FLAGS) -c $<
move.o: move.cpp role.h
	g++ $(FLAGS) -c $<
skill.o: skill.cpp role.h
	g++ $(FLAGS) -c $<
map.o: map.cpp map.h role.h
	g++ $(FLAGS) -c $<
stat.o: stat.cpp stat.h role.h
	g++ $(FLAGS) -c $<
play.o: play.cpp play.h map.h stat.h role.h
	g++ $(FLAGS) -c $<
NewGame.o: NewGame.cpp NewGame.h champ.h
	g++ $(FLAGS) -c $<
playmini.o: playmini.cpp playmini.h champ.h
	g++ $(FLAGS) -c $<
minigame.o: minigame.cpp minigame.h playmini.h NewGame.h champ.h
	g++ $(FLAGS) -c $<
main.o: main.cpp drawcardwithdiamond.h play.h role.h map.h stat.h minigame.h playmini.h NewGame.h champ.h
	g++ $(FLAGS) -c $<
main: drawcardwithdiamond.o move.o skill.o map.o stat.o play.o NewGame.o playmini.o minigame.o main.o
	g++ $(FLAGS) $^ -o $@

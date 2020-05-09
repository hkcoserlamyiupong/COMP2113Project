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
main.o: main.cpp drawcardwithdiamond.h play.h role.h map.h stat.h
	g++ $(FLAGS) -c $<
main: drawcardwithdiamond.o move.o skill.o map.o stat.o play.o main.o
	g++ $(FLAGS) $^ -o $@

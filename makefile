#makefile
drawcardwithdiamond.o: drawcardwithdiamond.cpp drawcardwithdiamond.h
	g++ -pedantic-errors -std=c++11 drawcardwithdiamond.cpp
move.o: move.cpp role.h
	g++ -pedantic-errors -std=c++11 move.cpp
skill.o: skill.cpp role.h
	g++ -pedantic-errors -std=c++11 skill.cpp
map.o: map.cpp map.h role.h
	g++ -pedantic-errors -std=c++11 map.cpp
stat.o: stat.cpp stat.h role.h
	g++ -pedantic-errors -std=c++11 stat.cpp
play.o: play.cpp play.h map.h stat.h role.h
	g++ -pedantic-errors -std=c++11 play.cpp
main.o: main.cpp drawcardwithdiamond.h play.h role.h map.h stat.h
	g++ -pedantic-errors -std=c++11 $<
main: drawcardwithdiamond.o move.o skill.o map.o stat.o play.o main.o
	g++ $^ -o $@

Game: ./main.cpp ./cGame/cGame.cpp ./cGame/cGame.h ./cMap/cMap.cpp ./cMap/cMap.h ./cPlayer/cPlayer.cpp ./cPlayer/cPlayer.h ./cPosition/cPosition.cpp ./cPosition/cPosition.h ./cEnemy/cEnemy.cpp ./cEnemy/cEnemy.h ./cLevel/cLevel.cpp ./cLevel/cLevel.h ./cOneRow/cOneRow.cpp ./cOneRow/cOneRow.h ./cRows/cRows.cpp ./cRows/cRows.o
	g++ -std=c++11 -Wall -o ./cPosition/cPosition.cpp cPosition.o
	g++ -std=c++11 -Wall -o ./cEnemy/cEnemy.cpp cEnemy.o
	g++ -std=c++11 -Wall -o ./cLevel/cLevel.cpp cLevel.o
	g++ -std=c++11 -Wall -o ./cOneRow/cOneRow.cpp cOneRow.o
	g++ -std=c++11 -Wall -o ./cRows/cRows.cpp cRows.o
	g++ -std=c++11 -Wall -o ./cPlayer/cPlayer.cpp cPlayer.o
	g++ -std=c++11 -Wall -o ./cMap/cMap.cpp cMap.o
	g++ -std=c++11 -Wall -o ./cGame/cGame.cpp cGame.o
	g++ -std=c++11 -Wall ./main.cpp -o main *.o

clean: 
	rm -f core *.o
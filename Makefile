main:
	g++ -std=c++14 -Wall -I/usr/include src/example.cpp -o output -lsfml-graphics -lsfml-window -lsfml-system 
	./output
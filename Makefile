lab1:
	g++ ./Lab-1/file_in.cpp -o ./Lab-1/file_in.o -std=c++98
	cd Lab-1 && ./file_in.o
	cd Lab-1 && rm file_in.o
lab2:
	g++ ./Lab-2/calculator.cpp -o ./Lab-2/calc && ./Lab-2/calc
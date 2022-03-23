lab1:
	g++ ./Lab-1/file_in.cpp -o ./Lab-1/file_in.o -std=c++98
	cd Lab-1 && ./file_in.o
	cd Lab-1 && rm file_in.o
lab2:
	cd Lab-2 && g++ calculator.cpp -c -std=c++14
	cd Lab-2 && g++ main.cpp calculator.o -o main -std=c++14 && ./main
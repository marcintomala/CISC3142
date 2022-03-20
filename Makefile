lab1:
	g++ ./Lab-1/file_in.cpp -o ./Lab-1/file_in.o -std=c++98
	cd Lab-1 && ./file_in.o
	cd Lab-1 && rm file_in.o
lab2:
	cd Lab-2 && g++ helper.cpp -c
	cd Lab-2 && g++ calculator.cpp helper.o -o calc && ./calc
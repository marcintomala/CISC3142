lab1:
	g++ ./Lab-1/file_in.cpp -o ./Lab-1/file_in.o -std=c++98
	cd Lab-1 && ./file_in.o
	cd Lab-1 && rm file_in.o
lab2:
	cd Lab-2 && g++ calculator.cpp -c -std=c++14
	cd Lab-2 && g++ main.cpp calculator.o -o main -std=c++14 && ./main
lab3:
	cd ./Lab-3/src/ && g++ section.h -c -std=c++14
	cd ./Lab-3/src/ && g++ student.h -c -std=c++14
	cd ./Lab-3/src/ && g++ instructor.h -c -std=c++14
	cd ./Lab-3/src/ && g++ term.h -c -std=c++14
	cd ./Lab-3/src/ && g++ college.cpp -c -std=c++14
	cd ./Lab-3/src/ && g++ io.cpp -c -std=c++14 
	cd ./Lab-3/src/ && g++ aggfunc.cpp -c -std=c++14
	cd ./Lab-3/src/ && g++ main.cpp -o main.exe -std=c++14 -lstdc++fs  && ./main.exe
	cd ./Lab-3/src/ && rm *.o && rm *.gch
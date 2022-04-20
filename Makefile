lab1:
	g++ ./Lab-1/file_in.cpp -o ./Lab-1/file_in.o -std=c++98
	cd Lab-1 && ./file_in.o
	cd Lab-1 && rm file_in.o
lab2:
	cd Lab-2 && g++ calculator.cpp -c -std=c++14
	cd Lab-2 && g++ main.cpp calculator.o -o main -std=c++14 && ./main
lab3:
	g++ -c ./Lab-3/src/section.h -std=c++14
	g++ -c ./Lab-3/src/term.h -std=c++14
	g++ -c ./Lab-3/src/student.h -std=c++14
	g++ -c ./Lab-3/src/instructor.h -std=c++14
	g++ -c ./Lab-3/src/college.h -std=c++14
	g++ -c ./Lab-3/src/io.cpp -std=c++14
	g++ -c ./Lab-3/src/aggfunc.cpp -std=c++14
	cd ./Lab-3/src/ && g++ main.cpp -o main -std=c++14 -lstdc++fs  && ./main

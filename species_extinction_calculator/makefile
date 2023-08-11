extinction_plot: main.o ../functions/extinction_functions.o
	g++ -std=c++11 main.o ../functions/extinction_functions.o -o extinction_calc 
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
extinction_functions.o: ../functions/extinction_functions.cpp ../functions/extinction_functions.hpp
	g++ -std=c++11 -c ../functions/extinction_functions.cpp
clean:
	rm -f main.o extinction_functions.o
veryclean: clean
	rm -f extinction_plot extinction_calc

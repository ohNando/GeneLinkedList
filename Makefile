# @file				Makefile  
# @description		Bu dosya kodun derlenip calistirildigi dosyadir.
# @course			1. Ogretim C grubu
# @assignment		1. Odev
# @date				03/11/2024 pazar
# @author			Emirhan Buldurucu - emirhan.buldurucu@ogr.sakarya.edu.tr

all: bin/program lib/main.o lib/Kromozom.o lib/Gen.o
	./bin/program

bin/program: lib/main.o lib/DNA.o lib/Kromozom.o lib/Gen.o
	g++ -std=c++11 -o bin/program lib/main.o lib/DNA.o lib/Kromozom.o lib/Gen.o

lib/main.o: src/main.cpp include/DNA.hpp include/Kromozom.hpp include/Gen.hpp
	g++ -std=c++11 -Iinclude -c src/main.cpp -o lib/main.o

lib/DNA.o: src/DNA.cpp include/DNA.hpp include/Kromozom.hpp
	g++ -std=c++11 -Iinclude -c src/DNA.cpp -o lib/DNA.o

lib/Kromozom.o: src/Kromozom.cpp include/Kromozom.hpp include/Gen.hpp
	g++ -std=c++11 -Iinclude -c src/Kromozom.cpp -o lib/Kromozom.o

lib/Gen.o: src/Gen.cpp include/Gen.hpp
	g++ -std=c++11 -Iinclude -c src/Gen.cpp -o lib/Gen.o

proj1: driver.o helpers.o
	g++ -o proj1 driver.o helpers.o -g

driver.o: driver.cpp helpers.h
	gcc -c driver.cpp -g

helpers.o: helpers.cpp helpers.h
	gcc -c helpers.cpp -g

clean:
	rm *.o proj1
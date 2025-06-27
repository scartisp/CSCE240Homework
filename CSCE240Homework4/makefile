compiler = g++
flags = -std=c++17 -Wall 

weight.o : weight.cc weight.h
	$(compiler) $(flags) -c $< 

testweight1 : testweight1.cc weight.o
	$(compiler) $(flags) $^
	./a.out

testweight2 : testweight2.cc weight.o
	$(compiler) $(flags) $^
	./a.out

testweight3 : testweight3.cc weight.o
	$(compiler) $(flags) $^
	./a.out

testweight4 : testweight4.cc weight.o
	$(compiler) $(flags) $^
	./a.out

weightrange.o : weightrange.cc weightrange.h weight.h
	$(compiler) $(flags) -c $< 

testweightrange1 : testweightrange1.cc weightrange.o weight.o
	$(compiler) $(flags) $^
	./a.out

testweightrange2 : testweightrange2.cc weightrange.o weight.o
	$(compiler) $(flags) $^
	./a.out

testweightrange3 : testweightrange3.cc weightrange.o weight.o
	$(compiler) $(flags) $^
	./a.out

testweightrange4 : testweightrange4.cc weightrange.o weight.o
	$(compiler) $(flags) $^
	./a.out

clean :
	rm  *.o a.out studentoutput.txt


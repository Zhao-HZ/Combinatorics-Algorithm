SOURCE = $(wildcard ./src/*)
OBJECT = $(patsubst %.c, %.o, $(SOURCE))
INCLUDE = -I/include
FLAG = -g

all: main.o $(OBJECT)
	gcc $(FLAG) $^ -o pp1 

main.o: main.c
	gcc -c -o $@ $^ $(FLAG)

./src/%.o: ./src/%.c
	gcc -c -o $@ $^ $(INCLUDE) $(FLAG)
	
clean:
	rm *.o ./src/*.o ./pp1

run:
	./pp1

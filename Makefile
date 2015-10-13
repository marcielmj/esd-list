compile:
	gcc -Wall node.c list.c main.c

test: compile
	./test.sh >> test.log
	diff result.log test.log

clean:
	rm a.out test.log

run: | compile test clean

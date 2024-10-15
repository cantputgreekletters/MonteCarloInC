main.c:
	gcc src/main.c src/mymath.c src/simulation.c src/array_handling.c -I include -o main.out

testing.c:
	gcc src/testing.c src/mymath.c src/simulation.c src/array_handling.c -I include -o test.out
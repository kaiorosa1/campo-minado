all:
	gcc -Wall -o minesweeper main.c tGame.c

clean:
	rm -f main

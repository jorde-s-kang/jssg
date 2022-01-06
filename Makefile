all:
	gcc main.c article_gen.c util.c -o jssg
test:
	./jssg

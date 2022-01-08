.EXPORT_ALL_VARIABLES:
JSSG_ARTICLES=articles/
JSSG_HEADER=header
JSSG_FOOTER=footer
JSSG_INDEX=index.html

all:
	gcc main.c article_gen.c util.c command.c -o jssg
test: all
	./jssg

.EXPORT_ALL_VARIABLES:
JSSG_ARTICLES=articles/
JSSG_HEADER=header
JSSG_FOOTER=footer
JSSG_CONTENTS=contents	

all:
	gcc main.c article_gen.c util.c -o jssg
test: all
	./jssg

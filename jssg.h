#include <stdio.h>

#ifndef JSSG_H
#define JSSG_H

// Data types
typedef struct Article
{
	char *title, *date, *fname;
} Article;

// util.c
void read_file(char *file_buf, char* path, int count);
void get_line(char* buffer, FILE *fp);
char get_char(FILE *fp);

// article_gen.c
Article generate_article(char* header, char* footer, char* fname);
#endif

	


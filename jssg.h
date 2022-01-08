#include <stdio.h>

#ifndef JSSG_H
#define JSSG_H
#define MAX_LINE_LEN 500
#define _GNU_SOURCE

// Data types
typedef struct Article
{
        char title[MAX_LINE_LEN];
	char date[MAX_LINE_LEN] ;
	char fname[MAX_LINE_LEN];
} Article;

// util.c
void read_file(char *file_buf, char* path, int count);
void get_line(char* buffer, FILE *fp);
char get_char(FILE *fp);
void write_str(FILE *wp, char* fmt, char* str);

// article_gen.c
Article generate_article(char* header, char* footer, char* fname);
#endif       

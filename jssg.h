#ifndef JSSG_H
#define JSSG_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define MAX_LINE_LEN 500

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
void parse_char(int c, FILE *fp, FILE *wp);
Article generate_article(char* header, char* footer, char* fname);

// command.c
void parse_command(FILE *fp, FILE *wp);
#endif       

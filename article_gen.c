#include "jssg.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LEN 500

void parse_char(int c, FILE *fp);



void parse_command(FILE *fp) {
	char cmd = get_char(fp);
	printf("command(%c)", cmd);

}

void handle_newline(FILE *fp) {
	char next;
	next = get_char(fp);
	if (next == '\n') {
		printf("</p>\n<p>");			
	} else {
		parse_char(next, fp);
	}
}

void parse_char(int c, FILE *fp) {
	switch(c) {
	case '\n':
		handle_newline(fp);
		break;
	case '\\':
		parse_command(fp);
		break;
	default:
		if (c != 0)
			printf("%c", c);
		break;
	}	
}

Article generate_article(char* header, char* footer, char* fname) {
	printf("%s\n", header);
	char c;
	FILE *fp;
	fp = fopen(fname, "r");
	char title[MAX_LINE_LEN];
	char date[MAX_LINE_LEN];
	get_line(title, fp);
	get_line(date, fp);
	printf("<h1>%s</h1>\n", title);
	printf("<h3>%s</h3>\n", date);
	printf("<p>");
	while ((c = get_char(fp)) != 0) {
		parse_char(c, fp);
	}
	printf("</p>\n");
	printf("%s", footer);
	Article a;

	a.date  = date;
	a.title = title;
	strcat(fname, ".html");
	a.fname = fname;

	return a;
}

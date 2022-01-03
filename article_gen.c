#include "jssg.h"
#include <stdio.h>

void parse_char(int c, FILE *fp);

char get_char(FILE *fp) {
	char c;
	if ((c = getc(fp)) != EOF) {
		return c;
	}
	else {
		return 0;
	}
}

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

void generate_article(char* header, char* footer, char* fname) {
	printf("%s\n", header);
	printf("<p>");
	char c;
	FILE *fp;
	fp = fopen(fname, "r");
	while ((c = get_char(fp)) != 0) {
		parse_char(c, fp);
	}
	printf("</p>\n");
	printf("%s", footer);
}

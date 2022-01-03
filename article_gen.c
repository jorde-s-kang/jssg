#include "jssg.h"
#include <stdio.h>

void parse_char(int c);

void parse_command() {
	int cmd = getchar();
	printf("command(%c)", cmd);

}

void handle_newline() {
	int next;
	next = getchar();
	if (next == '\n') {
		printf("</p>\n<p>");			
	} else {
		parse_char(next);
	}
}

void parse_char(int c) {
	switch(c) {
	case '\n':
		handle_newline();
		break;
	case '\\':
		parse_command();
		break;
	default:
		printf("%c", c);
		break;
	}	
}

void generate_article(char* header, char* footer, char* fname) {
	printf("%s\n", header);
	printf("<p>");
	printf("contents of %s", fname);
	/* int c; */
	/* while ((c = getchar()) != EOF) { */
	/* 	parse_char(c); */
	/* } */
	printf("</p>\n");
	printf("%s", footer);
}

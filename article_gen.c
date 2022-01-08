#include "jssg.h"

void handle_newline(FILE *fp, FILE *wp) {
	char next;
	next = get_char(fp);
	if (next == '\n') {
		fputs("</p>\n<p>", wp);			
	} else {
		parse_char(next, fp, wp);
	}
}

void parse_char(int c, FILE *fp, FILE *wp) {
	switch(c) {
	case '\n':
		handle_newline(fp, wp);
		break;
	case '\\':
		parse_command(fp, wp);
		break;
	default:
		if (c != 0)
			putc(c, wp);
		break;
	}	
}

Article generate_article(char* header, char* footer, char* fname) {
	char c;
	FILE *fp;
	fp = fopen(fname, "r");
	
	char title[MAX_LINE_LEN] = {0};
	char date[MAX_LINE_LEN] = {0};
	get_line(title, fp);
	get_line(date, fp);

	strcat(fname, ".html");
	FILE *wp;
	wp = fopen(fname, "w+");	

	char* header_str;

	
	write_str(wp, "%s\n", header);
	write_str(wp, "<h1>%s</h1>\n", title);
	write_str(wp, "<h3>%s</h3>\n", date);

	fputs("<p>", wp);
	while ((c = get_char(fp)) != 0) {
		parse_char(c, fp, wp);
	}
	fputs("</p>\n", wp);
	write_str(wp, "%s", footer);

	fclose(fp);
	fclose(wp);

	Article a;
	strcpy(a.date, date);
	strcpy(a.title, title);
	strcpy(a.fname, fname);

	return a;
}

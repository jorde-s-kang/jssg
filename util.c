#include <stdio.h>
#include <string.h>

void read_file(char* file_buf, char* path, int count) {
	int i = 0;
	char c;
	FILE *fp;
	fp = fopen(path, "r");
	while ((c = getc(fp)) != EOF && i <= count) {
		file_buf[i] = c;
		i++;
	}
	fclose(fp);
}

void get_line(char* buffer, FILE *fp) {
	char c;
	int i = 0;
	while((c = getc(fp)) != EOF && c != '\n') {
		buffer[i] = c;
		i++;
	}
}

char get_char(FILE *fp) {
	char c;
	if ((c = getc(fp)) != EOF) {
		return c;
	}
	else {
		return 0;
	}
}

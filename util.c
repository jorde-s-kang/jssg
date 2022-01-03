#include <stdio.h>

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

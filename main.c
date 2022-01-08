#include "jssg.h"

#define MAX_FILE_SIZE 5000
#define MAX_ARTICLES 100
#define MAX_LINE_LEN 500

int main(int argc, char *argv[]) {
	char* header_path    = getenv("JSSG_HEADER");
	char* footer_path    = getenv("JSSG_FOOTER");
	char* contents_path  = getenv("JSSG_CONTENTS");
	char* articles_path  = getenv("JSSG_ARTICLES");

	if (!(header_path && footer_path && contents_path && articles_path)) {
		printf("Please set JSSG_HEADER, JSSG_FOOTER, JSSG_CONTENTS and JSSG_ARTICLES environment variables.\n");
		exit(1);
	}
		

	char header[MAX_FILE_SIZE];
	char footer[MAX_FILE_SIZE];
	read_file(header, header_path, MAX_FILE_SIZE);
	read_file(footer, footer_path, MAX_FILE_SIZE);

	DIR *d;
	struct dirent *dir;
	d = opendir(articles_path);
	Article articles[MAX_ARTICLES];
	int i = 0;
	while ((dir = readdir(d)) != NULL) {
		if (dir->d_name[0] != '.') {
			char* ext = strrchr(dir->d_name, '.');
			if(!ext) {
				char fullname[50] = {0};
				strcat(fullname, articles_path);
				strcat(fullname, dir->d_name);
				Article a = generate_article(header, footer, fullname);
				articles[i] = a;
				i++;
			}
		}
	}
	FILE *wp;
	wp = fopen(contents_path, "w+");
	write_str(wp, "%s\n", header);
	write_str(wp, "%s\n", "<ul>");
	int size;
	char* line_str;

	for (i = 0; i < MAX_ARTICLES; ++i) {

		Article a = articles[i];
		if(a.title[0] == '\0')
			break;
		size = asprintf(&line_str, "<li>%s - <a href='%s'>%s</a></li>\n", a.date, a.fname, a.title);
		fputs(line_str, wp);
		free(line_str);

	}
	write_str(wp, "%s\n", "</ul>");
	write_str(wp, "%s\n", footer);
	fclose(wp);
}

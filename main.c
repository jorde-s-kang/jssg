#include "jssg.h"

#define MAX_FILE_SIZE 5000
#define MAX_ARTICLES 100
#define MAX_LINE_LEN 500

int main(int argc, char *argv[]) {
	char* header_path    = getenv("JSSG_HEADER");
	char* footer_path    = getenv("JSSG_FOOTER");
	char* index_path  = getenv("JSSG_INDEX");
	char* articles_path  = getenv("JSSG_ARTICLES");

	if (!(header_path && footer_path && index_path && articles_path)) {
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
	int i = 0;
	FILE *cp;
	cp = fopen(index_path, "w+");
	write_str(cp, "%s\n", header);
	write_str(cp, "%s\n", "<ul>");	
	while ((dir = readdir(d)) != NULL) {
		if (dir->d_name[0] != '.') {
			char* ext = strrchr(dir->d_name, '.');
			if(!ext) {
				char fullname[50] = {0};
				strcat(fullname, articles_path);
				strcat(fullname, dir->d_name);
				generate_article(header, footer, fullname, cp);
			}
		}
	}

	write_str(cp, "%s\n", "</ul>");
	write_str(cp, "%s\n", footer);
	fclose(cp);	
	closedir(d);
	exit(0);
}

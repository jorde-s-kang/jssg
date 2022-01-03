#include "jssg.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILE_SIZE 5000

int main(int argc, char *argv[]) {
	char* header_path   = getenv("JSSG_HEADER");
	char* footer_path   = getenv("JSSG_FOOTER");
	char* contents_path = getenv("JSSG_CONTENTS");
	char* articles_path  = getenv("JSSG_ARTICLES");

	char header[MAX_FILE_SIZE];
	char footer[MAX_FILE_SIZE];
	read_file(header, header_path, MAX_FILE_SIZE);
	read_file(footer, footer_path, MAX_FILE_SIZE);

	DIR *d;
	struct dirent *dir;
	d = opendir(articles_path);
	while ((dir = readdir(d)) != NULL) {
		if (dir->d_name[0] != '.') {
			char* ext = strrchr(dir->d_name, '.');
			if(!ext) {
				char fullname[50];
				strcat(fullname, articles_path);
				strcat(fullname, dir->d_name);
				printf("%s\n", fullname);
				generate_article(header, footer, fullname);
				fullname[0] = 0;
			}
		}
	}
}

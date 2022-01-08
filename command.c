#include "jssg.h"

void parse_command(FILE *fp, FILE *wp) {
	char cmd[MAX_LINE_LEN] = {0};
	int i = 0;
	char c;
	while ((c = getc(fp)) != '{' && i < MAX_LINE_LEN) {
		cmd[i] = c;
		i++;
	}
	write_str(wp, "command(%s)", cmd);
}

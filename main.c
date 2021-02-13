#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

extern char *__progname;

int help(void) {
	fprintf(stderr, "Usage: %s [-h] [-c NAME]\n", __progname);
	return 1;
}

int main(int argc, char **argv) {
	char c;
	int opt;
	bool newline_printed = false;
	char *class = NULL;

	while ((opt = getopt(argc, argv, "c:h")) != -1) {
		switch (opt) {
		case 'c':
			class = optarg;
			break;
		case 'h':
			return help();
		}
	}

	if (class != NULL)
		printf("<div class=\"%s\">", class);

	while ((c = fgetc(stdin)) != EOF) {
		switch (c) {
		case '\n':
			if (!newline_printed)
				newline_printed = true;
			puts("<br>");
			break;
		default:
			putc(c, stdout);
		}
	}

	if (!newline_printed)
		puts("<br>");

	if (class != NULL)
		puts("</div>");

	return 0;
}

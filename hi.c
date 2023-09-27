/*

Copyright (c) 2018 Michel Martens

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NORMAL "%s"
#define STYLED "\033[33;1m%s\033[0m"

static char *format = NORMAL;

static void output(char *fmt, char *line, char *end) {
	char temp;

	temp = *end;
	*end = '\0';

	printf(fmt, line);

	*end = temp;
}

static void filter(char *line, char *text) {
	char *head;
	char *back;

	head = strstr(line, text);

	if (head != NULL) {
		back = head + (int) strlen(text);

		output(NORMAL, line, head);
		output(format, head, back);
		printf(NORMAL, back);
	}
}

int main(int argc, char **argv) {
	char   *text = argv[1];
	char   *line = NULL;
	size_t  lcap = 0;
	ssize_t llen;

	if (argc != 2) {
		fprintf(stderr, "usage: %s text\n", argv[0]);
		exit(1);
	}

	if (isatty(STDOUT_FILENO)) {
		format = STYLED;
	}

	while ((llen = getline(&line, &lcap, stdin)) > 0) {
		filter(line, text);
	}

	return 0;
}

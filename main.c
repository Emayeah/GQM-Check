#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
int main() {
	char file[256] = "";
	long counter = 0;
	bool check = false;
	char buf;
	bool detected = false;
	printf("GQM Check\nChecks for greek question marks inside files\n");
	printf("Enter the filepath (e.g. C:\\users\\<user>\\file.c): ");
	scanf("%s", file);
	const char* file2 = file;
	FILE* openfile = fopen(file2, "r");
	if (openfile == NULL) {
		printf("The file couldn't be opened");
		return 1;
	}
	while (1) {
		buf = fgetc(openfile);
		if (buf == '\xCD') {
			check = true;
		}
		else if (buf == '\xBE') {
			if (check == true) {
				printf("Greek question mark detected!\n");
				check = false;
				detected = true;
			}
		}
		else {
			check = false;
		}
		if (feof(openfile)) {
			break;
		}
	}
	if (detected == false) {
		printf("No greek question marks found!");
	}
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <ftw.h>

#define MAX_FTW_DEPTH 16


static int num_dirs, num_files;

static int callback(const char *fpath, const struct stat *sb, int typeflag){
	// if we found a file
	if (typeflag == FTW_F){
		num_files++;
	// otherwise, we've found a directory
	} else if (typeflag == FTW_D) {
		num_dirs++;
	}
	return 0;
}

int main(int argc, char** argv) {
	if(argc != 2){
	printf("Usage: %s <path>\n", argv[0]);
	printf("    where <path is the file or root of the tree you want to summarize");
		return 1;
	}

	num_dirs = 0;
	num_files = 0;

	ftw(argv[1], callback, MAX_FTW_DEPTH);

	printf("There were %d directories.\n", num_dirs);
	printf("There were %d regular files.\n", num_files);

	return 0;

}

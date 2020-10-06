#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// creating max string size for our path
#define PATH_MAX 4096

static int num_dirs, num_regular;

bool is_dir(const char* path) {
	struct stat buf;
	if (stat(path, &buf) == 0){
		if(S_ISDIR(buf.st_mode) > 0){
			return true;
		} else {
		       	return false;
		}
	} else {
		printf("Error calling stat");
		return 0;
	}
}


  /*
   * Use the stat() function (try "man 2 stat") to determine if the file
   * referenced by path is a directory or not.  Call stat, and then use
   * S_ISDIR to see if the file is a dir+ectory. Make sure you check the
   * return value from stat in case there is a problem, e.g., maybe the
   * the file doesn't actually exist.
   */

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {
	DIR *dir;
	// string to store our path for recursive calls
	//char* current_path = (char*)calloc(sizeof(char), PATH_MAX);
       	struct dirent *dp;
	chdir(path);
	dir = opendir(path);
	// make sure we actually have stuff
	if (dir == NULL) {
		exit(1);
	}
	
	
	while ((dp = readdir(dir)) != NULL) {
		// avoiding infinite looping by disregarding . and .. file names
		if(((strcmp(dp->d_name,".")) != 0) || ((strcmp(dp->d_name,"..")) != 0)){
			num_dirs++;
			//char dir_name[4096];
			//dir_name = dp->d_name;
			//strcat(dir_name, "/");
			process_path(dp->d_name);
		}
	}
	//free(current_path);
	chdir("..");
	closedir(dir);
}


  /*
   * Update the number of directories seen, use opendir() to open the
   * directory, and then use readdir() to loop through the entries
   * and process them. You have to be careful not to process the
   * "." and ".." directory entries, or you'll end up spinning in
   * (infinite) loops. Also make sure you closedir() when you're done.
   *
   * You'll also want to use chdir() to move into this new directory,
   * with a matching call to chdir() to move back out of it when you're
   * done.
   */

void process_file(const char* path) {
	num_regular++;
  /*
   * Update the number of regular files.
   */
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}

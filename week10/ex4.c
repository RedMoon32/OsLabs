#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	DIR *tmp = opendir("tmp");
	struct dirent *dp=readdir(tmp);	
	struct stat sdata;
	char fpath[64];
	char command[128];
	while (dp != NULL) {
		if (dp->d_name[0] != '.') {
			sprintf(fpath,"./tmp/%s",dp->d_name);
			stat(fpath,&sdata);
			if (sdata.st_nlink >= 2) {
				printf("Links for %s\n",dp->d_name );
				sprintf(command, "find -inum %lu", sdata.st_ino);
				system(command);
			}
		}
		dp=readdir(tmp);
	}
}


// dirTree.c
// print directory tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define N  10000

void print(char *newStr) 
{
	// char newStr[256];
	struct stat buf;
	DIR *p;
	struct dirent *p1;
	int ret;
	int len;

	stat(newStr, &buf);
	if (S_ISDIR(buf.st_mode)) {
		p = opendir(newStr);
		p1 = readdir(p);
		// strcpy(newStr, str);
		strcat(newStr, "/");
		len = strlen(newStr);
		while (p1) {
			if (strcmp(p1->d_name, ".") == 0 || strcmp(p1->d_name, "..") == 0) {
			}
			else {

				strcat(newStr, p1->d_name);
			
				stat(newStr, &buf);
				if (S_ISDIR(buf.st_mode)) { // directory
					printf("%s\n", newStr);
					print(newStr);
				} else if (S_ISREG(buf.st_mode)) { // regular file
					printf("%s\n", newStr);
				}
			}
			
			p1 = readdir(p);
			newStr[len] = '\0';
		}

	}				
}


int main(int argc, char *args[])
{
	char str[256];

	strcpy(str, args[1]);
	print(str);
	
    return 0;
}



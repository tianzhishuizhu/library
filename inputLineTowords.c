#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define N  1024

int _tmain(int argc, _TCHAR* argv[])
{
	char str[N];
	char word[100][N];
	int i;
	int j;
	int index;
	int len;
	int n;
	int substrLen;

	while (fgets(str, N, stdin)) {
		len = strlen(str);
		if (str[len - 1] == '\n') { // if the last is '\n', delete it.
			str[len - 1] = '\0';
			len--;
		}

		for (i = 0; i < len; i++) { // all ' ' would be replaced with '\0'
			if (str[i] == ' ') {
				str[i] = '\0';
			}
		}

		index = 0;
		j = 0;
		while (str[index] == '\0') { // skip the beginning '\0'
			index++;
		}

		while (index < len) {
			substrLen = strlen(str + index);
			strcpy(word[j], str + index); // copy to word[]
			j++;
			index = index + substrLen;

			while (str[index] == '\0') { // skip '\0'
				index++;
			}
		}
	}

	return 0;
}

#include <stdio.h>

extern char *environ;

int main(int argc, char *argv[]) {
	char **p;
	int counter = 0;

	if(argc < 2) return 0;

	int n = atoi(argv[1]);

	if(n <= 0) return 0;

	printf("Printing %d arguments\n",n);

	for(p = environ; (*p != NULL && counter < n); p++) {
		printf("Enviroment variable №%d : %s\n",counter,*p);
		counter++;

	}

	return 0;
}

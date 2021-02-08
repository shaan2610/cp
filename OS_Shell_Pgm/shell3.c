#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n, i;     // fibonacci sequence's size
int *fib; // fibonacci sequence
// *these variables will be accessed by all the threads

void *calc(void *arg) {
	if (i == 0) {
		fib[i] = 0;
	} else if (i == 1) {
		fib[i] = 1;
	} else {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        printf("Format:./a.out <sizeofFibSequence>\n");
        return -1;
    }    
    n = atoi(argv[1]);       
         
    if (n < 0) { // size of fibonacci Sequence invalid
        printf("Please enter a valid size i.e. (>0)\n");
        return -1;
    } 

    fib = (int *)malloc(n * sizeof(int)); // fib sequence memory allocation

    pthread_t tid; // thread identifier
    pthread_attr_t attr;  
    pthread_attr_init(&attr); // used to set the default attributes	

    for (i = 0; i < n; i++) {
        pthread_create(&tid, &attr, calc, NULL);
		pthread_join(tid, NULL);
    } 

    // printing fibonacci sequence
    printf("The Fibonacci Sequence :: ");
    for (int j = 0; j < n; j++) {
    	printf("%d ", fib[j]);
    }
    printf("\n");    
    return 0;
}                               
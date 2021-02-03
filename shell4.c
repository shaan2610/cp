#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct dpnt {
    int p;
    int q;
};

#define M 3
#define K 2
#define N 3
int A[M][K] = { {1,4}, {2,5}, {3,6}};
int B[K][N] = { {8,7,6}, {5,4,3} };
int C[M][N]; // represents the product of A and B

void *calc(void *arg) {
    struct dpnt *x = (struct dpnt *)arg;
    for (int i = 0; i < K; i++) {
        C[x->p][x->q] += A[x->p][i] * B[i][x->q];
    }
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
    
    pthread_t *threads; // worker threads 
    threads = (pthread_t*) malloc((M * N) * sizeof(pthread_t));

    pthread_attr_t attr;  
    pthread_attr_init(&attr); // used to set the default attributes 
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            struct dpnt *x = (struct dpnt *) malloc(sizeof(struct dpnt));
            x->p = i, x->q = j; 
            pthread_create(&threads[i * N + j], &attr, calc, x);
        }
    }

    for (int i = 0; i < M * N; i++) {
        pthread_join(threads[i], NULL); // waiting for threads
    }

    printf("Matrix A ::\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", A[i][j]);
        } printf("\n");
    }
    printf("\n");
    printf("Matrix B ::\n");
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        } printf("\n");
    }
    printf("\n");
    // printing multiplication of A and B
    printf("Matrix Multiplication of A and B\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n"); 
    }   
    return 0;
}

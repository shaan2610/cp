#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

using namespace std;

#define THREAD_NUMBER 8
#define BUFFER_SIZE 10

sem_t semEmpty, semFull;

pthread_mutex_t mutexBuffer;

int buffer[BUFFER_SIZE];
int counter = 0;

void* producer(void* args){
	while(1){
		sem_wait(&semEmpty);
		pthread_mutex_lock(&mutexBuffer);
		buffer[counter++] = 1;
		cout << counter << " :: producer\n";
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semFull);
	}
}
void* consumer(void* args){
	while(1){
		sem_wait(&semFull);
		pthread_mutex_lock(&mutexBuffer);
		buffer[--counter] = 0;
		cout << counter << " :: Consumer\n";
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semEmpty);
	}
}
int main(){
	pthread_mutex_init(&mutexBuffer, NULL);
	sem_init(&semEmpty, 0, BUFFER_SIZE);
	sem_init(&semFull, 0, 0);

	pthread_t pt, ct;
	pthread_create(&pt, NULL, &producer, NULL);
	pthread_create(&ct, NULL, &consumer, NULL);
	
	pthread_join(pt, NULL);
	pthread_join(ct, NULL);

	// for destroying the threads and semaphores
	sem_destroy(&semEmpty);
	sem_destroy(&semFull);	
	pthread_mutex_destroy(&mutexBuffer);
	return 0;
}
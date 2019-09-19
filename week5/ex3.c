#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

const int N = 1e9 + 7;

int bf_size; 

void *produce(){
	while(1){
		if(bf_size < N)
			bf_size++;
		else {
			while(1){
				if (bf_size < N)
					break;
			}
		}
	}
}
void *consume(){
	while(1){
		if (bf_size > 0)
			bf_size--;
		else {
			while(1){
				if (bf_size > 0)
					break;
			}
		}
	}
}
void *display(){
	while (1){
		printf("Buffer size %d\n", bf_size);
		sleep(60);
	}
}



int main(){
	pthread_t consumer, producer, display_bf_size;
	pthread_create (&consumer, NULL, consume, NULL);
	pthread_create (&producer, NULL, produce, NULL);
	pthread_create (&display_bf_size, NULL, display, NULL);
	pthread_exit(NULL);
	return 0;
}
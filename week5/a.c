#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int id;

void *my_thread(void *arg) {
	printf("Hello, I am thread number %d!\n", id);
	id++;
	printf("Bye, I am thread number %d!\n\n", id - 1);
	return NULL;
}

int main(){
	int n;
	scanf("%d", &n); //getting the number of threads from user
	id = 1;
	for(int i = 1; i <= n; i++) {
		pthread_t thread;
		printf("Creating the thread number %d \n...\n", id);	//informing about thread creation 
		pthread_create(&thread, NULL, my_thread, NULL);	//creating the thread
		pthread_join(thread, NULL); //blocks the calling threads untill current terminates
	}
	return 0;
}
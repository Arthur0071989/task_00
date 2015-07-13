#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t MTX = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t COND = PTHREAD_COND_INITIALIZER;

bool PRINT = false;

void foo(void *p)
{
	pthread_mutex_lock(&MTX);
	while(!PRINT)
		pthread_cond_wait(&COND, &MTX);
	printf("Can print");
	pthread_mutex_unlock(&MTX);
    return 0;
}


int main(int c, char** v){
pthread_t t  = 0;
pthread_create =(&t, 0, foo, 0);
sleep(5);
pthread_mutex_lock(&MTX);
	PRINT = true;
pthread_cond_signal (& COND);
pthread_mutex_unlock (& MTX);
pthread_join(t, 0);
return 0;
}

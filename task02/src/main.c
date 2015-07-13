#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t MTX = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t COND = PTHREAD_COND_INITIALIZER;

bool PRINT = false;

void foo(void *p)
{
	int i;
	pthread_mutex_lock(&MTX);
	while(i!=0)
		pthread_cond_wait(&COND, &MTX);
	printf("PING\n");
	pthread_mutex_unlock(&MTX);
	i=0;
    return 0;
}

void foo2(void *p)
{
	int i;
        pthread_mutex_lock(&MTX);
        while(i!=1)
                pthread_cond_wait(&COND, &MTX);
        printf("PONG\n");
        pthread_mutex_unlock(&MTX);
	i=1;
    return 0;
}



int main(int c, char** v){

pthread_t t = 0;
pthread_create(&t, 0, foo, 0);

sleep(5);
pthread_mutex_lock(&MTX);
PRINT = true;
pthread_cond_signal (& COND);
pthread_mutex_unlock (& MTX);
pthread_join(t, 0);

return 0;
}

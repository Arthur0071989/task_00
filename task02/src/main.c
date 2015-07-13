#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int amount = 0;
char print = 0;

pthread_mutex_t MTX = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t COND = PTHREAD_COND_INITIALIZER;

bool PRINT = false;

void foo(void *p)
{
	int i;
for (i=0; i<amount; ++i)
{
	pthread_mutex_lock(&MTX);
	while(print!=0)
		pthread_cond_wait(&COND, &MTX);
	printf("PING\n");
	print =1;
	pthread_cond_signal(&COND);
	pthread_mutex_unlock(&MTX);
}	
    return 0;
}

void foo2(void *p)
{
	int i;
for (i = 0 ; i <amount; ++i){

        pthread_mutex_lock(&MTX);
        while(print!=1)
                pthread_cond_wait(&COND, &MTX);
        printf("PONG\n");
	print = 0;
	pthread_cond_signal(&COND);
        pthread_mutex_unlock(&MTX);
}
    return 0;
}



int main(int c, char* v[]){

amount = atoi(v[1]);
pthread_t tid[2];
pthread_create(&tid[0], 0, foo, 0);
pthread_create(&tid[1], 0, foo2, 0);

pthread_mutex_lock(&MTX);

pthread_cond_signal (& COND);
pthread_mutex_unlock (& MTX);
pthread_join(tid[0], 0);
pthread_join(tid[1], 0);


return 0;
}

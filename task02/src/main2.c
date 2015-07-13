#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

int n;

scanf("%d", &n);

while(n)
{
	sleep(10);
	printf("PING\n");
	printf("PONG\n");
}

return 0;


}

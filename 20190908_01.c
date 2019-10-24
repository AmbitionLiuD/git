#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 50

int count = 0;
//pthread_mutex_t lock;

void *count_num(void *args)
{
    int i = 0;
	int tmp_arg = *((int*)args);
//	pthread_mutex_lock(&lock);
	while(i < 1000 )
	{
		count++;
		i++;
	}
//	pthread_mutex_unlock(&lock);
}

int main(void)
{
	int rc,t;
	pthread_t thread[NUM_THREADS];

	for( t = 0; t < NUM_THREADS; t++)
	{
		rc = pthread_create(&thread[t], NULL, count_num,NULL);
		if (rc)
		{
			printf("ERROR; return code is %d\n", rc);
			return EXIT_FAILURE;
		}
	}
	for (t = 0; t < NUM_THREADS; t++)
		pthread_join(thread[t], NULL);
	printf("%d\n",count);
	return 0;
}

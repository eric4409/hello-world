/*
 * thread_a创建了thread_b, thread_a结束后, thread_b继续运行
 */
#include <stdio.h>
#include <pthread.h>

void *thread_b(void *arg)
{
	while(1)
	{
		printf("thread_b\n");
		sleep(1);
	}
	pthread_exit(0);
}

void *thread_a(void *arg)
{
	int i;
	pthread_t tid;
	pthread_create(&tid, NULL, thread_b, NULL);

	for(i=0; i<5; i++)
	{
		printf("thread_a\n");
		sleep(1);
	}
	pthread_exit((void*)i);
}

int main(void)
{
	void *ret;
	pthread_t tid;
	pthread_create(&tid, NULL, thread_a, NULL);
	pthread_join(tid, &ret);
	printf("thread_a end[%d]\n", (int)ret);
	while(1)
	{
		printf("main\n");
		sleep(1);
	}
	return 0;
}


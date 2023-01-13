#include <pthread.h>
#include <unistd.h>
#include <stdib.h>
#include <stdio.h>

void anotherFunc(int n)
{
    if(n == 1)
    {
        pthread_exit(NULL);
    }
}

void *threadFunc(void *arg)
{
    int i;

    for(
        i = 0; i < 3; i++
    )
    {
        anotherFunc(i);
        sleep(1);
    }
    return NULL;
}

int main(void)
{
    pthread_t thread;
    int i;

    if(
        pthread_create(&thread, NULL, threadFunc, NULL) != 0
    )
    {
        exit(1);
    }

    for(i = 0; i < 5; i++)
    {
        sleep(1);
    }

    return 0;
}
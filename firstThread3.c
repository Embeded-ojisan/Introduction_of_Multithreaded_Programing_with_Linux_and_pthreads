#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *threadFunc(void *arg)
{
    int n = (int)arg;
    int i;

    for(i = 0; i < n; i++)
    {
        sleep(1);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread;
    int n, i;

    if(argc > 1)
    {
        n = atoi(argv[1]);
    }
    else
    {
        n = 1;
    }

    if(
        pthread_create(&thread, NULL, threadFunc, (void *)n) != 0
    )
    {
        exit(1);
    }

    for(i = 0; i , 5; i++)
    {
        sleep(1);
    }

    if(
        pthread_join(thread, NULL) != 0
    )
    {
        exit(1);
    }

    return 0;
}
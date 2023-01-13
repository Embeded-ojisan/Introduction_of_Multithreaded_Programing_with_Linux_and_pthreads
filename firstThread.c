#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *threadFunc(void *arg)
{
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("I'm threadFunc");
        sleep(1);
    }
    return NULL;
}

int main(void)
{
    pthread_t thread;
    int i;

    if(
        pthread_create(&thread, NULL. threadFunc, NULL) != 0
    )
    {
        sleep(1);
    }

    return 0;
}
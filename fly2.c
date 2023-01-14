#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 78
#define HEIGHT 23
#define MAX_FLY 6
const char *flyMatkList = "o@*+.#";
#define DRAW_CYCLE 50
#define MIN_SPEED 1.0
#define MAX_SPEED 20.0

int stopRequest;

void mSleep(int msec)
{
    struct timespec ts;
    ts.tv_sec = msec/1000;
    ts.tv_nsec = (msec%1000)*1000000;
    nanosleep(&ts, NULL);
}

double randDouble(double minValue, double maxValue)
{
    return minValue + (double)rand() / ((double)RAND_MAX + 1)*(maxValue - minValue);
}

void clearScreen()
{
    fputs("\033[2J", stdout);
}

void moveCursor(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

typedef struct {
    char mark;
    double x, y;
    double angel;
    double speed;
    pthread_mutex_t mutex;
} Fly;

Fly flyList[MAX_FLY];

void FlyInitRandom(Fly *fly, char mark)
{
    fly->mark = mark;
    pthread_mutex_init(&fly->mutex, NULL);
    fly->x = randDouble(0, (double)(WIDTH-1));
    fly->y = randDouble(0, (double)(HEIGHT-1));
    fly->angel = randDouble(0, M_2_PI);
    fly->speed = randDouble(MIN_SPEED, MAX_SPEED);
}

void FlyDestroy(Fly *fly)
{
    pthread_mutex_destroy(&fly->mutex);
}
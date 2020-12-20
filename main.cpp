#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_THREADS 16

void* function_id(void* param);
void* function_iter(void* param);

pthread_t threads[MAX_THREADS];

int main(){
    int amm;
    cout << "ENTER AMMOUNT OF THREADS : ";
    cin >> amm;

}

void* function_iter(void* param)
{
    double* arr = (double*)param;
    double step = arr[0], left = arr[1], right = arr[2];
    printf("\n (\033[32m%ld\033[0m) FUNCTION PARAMETERS: \n  step  :\033[33m %+.4f \033[0m \n  left  :\033[33m %+.4f \033[0m  \n  right :\033[33m %+.4f \033[0m\n", pthread_self(), step, left, right);
    double x;
    
    for (double i = left; i < right; i += step) {
        x = 1 + i / 3 - i * i / 9 + i * i * i * 5 / 81 - i * i * i * i * 80 / 1944;
        printf("\n \033[36m %ld\033[0m -> X: %+.4f | Y: %+.4f ",pthread_self(), i, x);
    }
    printf("\n\n (\033[32m%ld\033[0m) FINISHED!\n", pthread_self());
    return 0;

    pthread_exit(NULL);
}

void* function_id(void* param)
{
    int iter = *(int*)param;
    for (int i = 0; i < iter; i++) {
        printf("\n \033[36m %ld\033[0m -> Shevchuk Ilya #1245123451 ",pthread_self());
    }
    printf("\n\n (\033[32m%ld\033[0m) FINISHED!\n", pthread_self());
    return 0;

    pthread_exit(NULL);
}
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define MAX_THREADS 16

double  dataArray[16];

void* function_id(void* param);
void* function_iter(void* param);

pthread_t threads[MAX_THREADS];

int main(){
    int amm;
    cout << "ENTER AMMOUNT OF THREADS : ";
    cin >> amm;

    int choise;
    std::cout<<"\nENTER TYPE OF OPERATION (1-iter | 0-id) : ";
    std::cin>>choise;

    if(choise == 1){
        std::cout << " Enter step value : ";
        double left = -0.9, right = -0.9 + (1.8 / amm), step;
        std::cin >> step;

        for (int i = 0; i < amm; i++)
        {
            
            dataArray[0] = step;
            dataArray[1] = left;
            dataArray[2] = right;

            pthread_create(&threads[i], NULL, function_iter, &dataArray);

            left = left + (1.8 / amm);
            right = right + (1.8 / amm);
        }
    }else if (choise == 0){
        std::cout << "Enter ammount of cycles : ";
        int cycles;
        std::cin>>cycles;

        cycles = (int)(cycles/amm);
        for (int i = 0; i < amm; i++)
        {
            pthread_create(&threads[i], NULL, function_id, &cycles);
        }
    }
    
    
 
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < amm; i++)
    {
        pthread_join(threads[i], NULL);
    }
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    

    cout<<"\n\nTIME : "<< chrono::duration_cast<chrono::seconds>(end - begin).count()<<" seconds"<<endl;
    return 0;
}

void* function_iter(void* param)
{
    double* arr = (double*)param;
    double step = arr[0], left = arr[1], right = arr[2];
    printf("\n (\033[32m%ld\033[0m) FUNCTION PARAMETERS: \n  step  :\033[33m %+.4f \033[0m \n  left  :\033[33m %+.4f \033[0m  \n  right :\033[33m %+.4f \033[0m\n", gettid(), step, left, right);
    double x;
    
    for (double i = left; i < right; i += step) {
        x = 1 + i / 3 - i * i / 9 + i * i * i * 5 / 81 - i * i * i * i * 80 / 1944;
        printf("\n \033[36m %ld\033[0m -> X: %+.4f | Y: %+.4f ",gettid(), i, x);
    }
    printf("\n\n (\033[32m%ld\033[0m) FINISHED!\n", gettid());
    return 0;

    pthread_exit(NULL);
}

void* function_id(void* param)
{
    int iter = *(int*)param;
    for (int i = 0; i < iter; i++) {
        printf("\n \033[36m %ld\033[0m -> Shevchuk Ilya #1245123451 ",gettid());
    }
    printf("\n\n (\033[32m%ld\033[0m) FINISHED!\n", gettid());
    return 0;

    pthread_exit(NULL);
}
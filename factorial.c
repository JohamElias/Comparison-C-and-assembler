#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void cfactorial(int n,int *resp);
void extern asmfactorial(int n,int *resp);

int main(){
    int n=5,cResp=1,asmResp=1;
    struct timespec ti,tf;
    double elapsed;

    clock_gettime(CLOCK_REALTIME,&ti);
    cfactorial(n,&cResp);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%d\n",cResp);
    printf("El tiempo en nanosegundos que toma la función en C es: %lf\n",elapsed);

    clock_gettime(CLOCK_REALTIME,&ti);
    asmfactorial(n,&asmResp);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsed=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%d\n",asmResp);
    printf("El timepo en nanosegundos que toma la función en ASM es: %lf\n",elapsed);
    return 0;
}

void cfactorial(int n,int *resp){
    while(n!=1){
        resp[0]*=n;
        n--;
    }
}


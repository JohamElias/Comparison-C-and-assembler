#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float cMediana(float *arr,int cant);
float extern asmMediana(int cant,float *arr);
void llenarMatriz(float **arr,int cant);
float **matrizTraspuesta(float **arr,int cant);
void ordenarArreglo(float *arr,int N);
double speedUp(double ref,double cal);

int main(){
    float matriz[16][16],**mat;
    int N=16;
    double elapsedC,elapsedA;
    struct timespec ti,tf;

    llenarMatriz(matriz,N);

    imprimirMatriz(matriz,N);
    
    clock_gettime(CLOCK_REALTIME,&ti);
    mat=matrizTraspuesta(matriz,N);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedC=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    imprimirMatriz(matriz,N);
    printf("El tiempo en nanosegundos que toma la función en C es: %lf\n",elapsedC);

    /*
    clock_gettime(CLOCK_REALTIME,&ti);
    medASM=asmMediana(N,arr);
    clock_gettime(CLOCK_REALTIME,&tf);
    elapsedA=(tf.tv_sec-ti.tv_sec)*10e9+(tf.tv_nsec-ti.tv_nsec);
    printf("%f\n",medASM);
    printf("El tiempo en nanosegundos que toma la funcion en ASM es: %lf\n",elapsedA);
    double spdup=speedUp(elapsedC,elapsedA);
    printf("El speed up es: %lf\n",spdup);*/
}

float **matrizTraspuesta(float **arr,int cant){
    float **aux=(float**)malloc(sizeof(float*)*cant);
    for(int i = 0;i < cant;i++){
        aux[i]=(float*)malloc(sizeof(float)*cant);
      for(int j = 0;j < cant;j++){
            aux[i][j]=arr[j][i];
          }
  }
  return aux;
}

void llenarMatriz(float **arr,int cant){
    for(int i=0;i<cant;i++){
        for(int j=0;j<cant;j++)
            arr[i][j]=rand()%101;
    }
}

void imprimirMatriz(float **arr,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%f ",arr[i]);
        printf("\n");
    }
    printf("\n");
}


double speedUp(double ref,double cal){
    return ref/cal;
}

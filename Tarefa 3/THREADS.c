#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS     3

int a[NUM_THREADS] = {0};
int b[NUM_THREADS] = {0};
int c[NUM_THREADS] = {0};
int wa = 1;
int wb = 1;
FILE *arqfilho;

void *PrintHello(void *threadid)
{
   long tid;
   sleep(1);
   tid = (long)threadid;
   sleep(tid/3);
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void *calculaA(void *threadid)
{
   long tid;
   //sleep(1);
   tid = (long)threadid;
   //sleep(tid/3);
   //printf("Hello World! It's me, thread #%ld!\n", tid);
      int i;
      double mu,x0,x1;
      int cont;
      int result;
      for(i=(2400+tid*400); i<(2800+tid*400); i++){
        mu=((double)i)/1000.0;        
        x0=((double) rand() / (RAND_MAX)) ;
        //printf("%f\n",x0);
        //primeiras interações
        for(cont=0;cont<100;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
        }
        //ultimas interações
        for(cont=100;cont<300;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
          fprintf(arqfilho, "%f %f \n", mu, x1);
        }
      }
      pthread_exit(NULL);
}


int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;

   char fileName0[]="log.txt";
   arqfilho = fopen(fileName0, "w" ); 
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, calculaA, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(t=1; t<NUM_THREADS; t++){
     pthread_join(threads[t], NULL);
     printf("Thread %d terminou\n",t);
   }

   printf("Vetor C");
   for(t=0; t<NUM_THREADS; t++){
     printf("v[%d] = %d\n",t,c[t]);
   } 
 

   /* Last thing that main() should do */rc = pthread_create(&threads[t], NULL, calculaA, (void *)t);

   pthread_exit(NULL);
   //exit(0);
}

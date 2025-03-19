//exemplo de IPC - 1.

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int fileExists(char *cpfileName)
{
    FILE *arq;
    arq = fopen(cpfileName,"r");
    if(arq!=0)
    { 
        fclose(arq);
	return 1; /* existe */
    }  
    return 0; /* nao existe */
}

int main(void)
{
    pid_t childPID[6];
    pid_t myPID;
    pid_t PID;			// pid_t eh um data type integer
    pid_t PPID;
    
    pid_t wpid;

    int status;
    int filho;
    int p;
    // variaveis para o loop
    int result;
    int i;
    double mu;
    int cont;
    //arquivos
    FILE *arqfilho;
    char fileName0[]="mu0.txt";
    char fileName1[]="mu1.txt";
    char fileName2[]="mu2.txt";
    char fileName3[]="mu3.txt";
    char fileName4[]="mu4.txt";
    char fileNameF0[]="filhoTerminou0.txt";
    char fileNameF1[]="filhoTerminou1.txt";
    char fileNameF2[]="filhoTerminou2.txt";
    char fileNameF3[]="filhoTerminou3.txt";
    char fileNameF4[]="filhoTerminou4.txt";
    //
    
    PID = getpid();		// pega o pid do processo
    PPID = getppid();   // pega o pid do pai do processo
    myPID = getpid();
    for(p=0;p<5;p++){
        if (myPID == PID) //se eu sou o pai entao fork
	{
		childPID[p] = fork();
                myPID = getpid();
                filho = p;
        }
    }			

    if (myPID == PID) 
    {
      printf("I am the father. My PID is: %d. My father's PID is: %d. I have three children: child0's PID is: %d child1's PID is: %d child2's PID is: %d child3's PID is: %d child4's PID is: %d child5's PID is: %d\n", PID,PPID,childPID[0],childPID[1],childPID[2],childPID[3],childPID[4],childPID[5]);
    filho = -1; 
    } 	    



    if (filho==0) 
    {
      int i;
      double mu,x0,x1;
      int cont;
      int result;

      arqfilho = fopen(fileName0, "w"); 
      for(i=2400; i<2800; i++){
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
      fclose(arqfilho);
      //escrevendo arquivo terminou
      arqfilho = fopen(fileNameF0, "w");
      result = 1;
      fprintf(arqfilho, "%d", result);
      fclose(arqfilho);
      printf("Terminei meu PID é: %d\n",myPID); 
        //
    }
    if (filho==1)
    {
      int i;
      double mu,x0,x1;
      int cont;
      int result;
      arqfilho = fopen(fileName1, "w"); 

      for(i=2800; i<3200; i++){
        mu=((double)i)/1000.0;        
        x0=((double) rand() / (RAND_MAX))  ;
        //printf("%f\n",x0);
        //primeiras interações
        for(cont=0;cont<=100;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
        }
        //ultimas interações
        for(cont=100;cont<=300;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
          fprintf(arqfilho, "%f %f \n", mu, x1);
        }
         
      }


      fclose(arqfilho);
      //escrevendo arquivo terminou
      arqfilho = fopen(fileNameF1, "w");
      result = 1;
      fprintf(arqfilho, "%d", result);
      fclose(arqfilho);
      printf("Terminei meu PID é: %d\n",myPID); 
      
    }	
    if (filho==2)
    {
      int i;
      double mu,x0,x1;
      int cont;
      int result;
      arqfilho = fopen(fileName2, "w"); 
      for(i=3200; i<3600; i++){
        mu=((double)i)/1000.0;        
        x0=((double) rand() / (RAND_MAX))  ;
        //printf("%f\n",x0);
        //primeiras interações
        for(cont=0;cont<=100;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
        }
        //ultimas interações
        for(cont=100;cont<=300;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
          fprintf(arqfilho, "%f %f \n", mu, x1);
        }
         
      }
      fclose(arqfilho);
      //escrevendo arquivo terminou
      arqfilho = fopen(fileNameF2, "w");
      result = 1;
      fprintf(arqfilho, "%d", result);
      fclose(arqfilho);
      printf("Terminei meu PID é: %d\n",myPID); 
      
    }
        if (filho==3)
    {
      int i;
      double mu,x0,x1;
      int cont;
      int result;
      arqfilho = fopen(fileName3, "w"); 
      for(i=3600; i<4000; i++){
        mu=((double)i)/1000.0;        
        x0=((double) rand() / (RAND_MAX))  ;
        //printf("%f\n",x0);
        //primeiras interações
        for(cont=0;cont<=100;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
        }
        //ultimas interações
        for(cont=100;cont<=300;cont++){
          x1=mu*x0*(1.0-x0);
          x0=x1;
          fprintf(arqfilho, "%f %f \n", mu, x1);
        }
         
      }
      fclose(arqfilho);
      //escrevendo arquivo terminou
      arqfilho = fopen(fileNameF3, "w");
      result = 1;
      fprintf(arqfilho, "%d", result);
      fclose(arqfilho);
      printf("Terminei meu PID é: %d\n",myPID); 
     
    }


    if (filho==-1)
    {
      printf("I am the father. I am waiting for my children\n");
      while(fileExists(fileNameF0)==0); //arquivo existe ? 
      //
      while(fileExists(fileNameF1)==0); //arquivo existe ? 
      //
      while(fileExists(fileNameF2)==0); //arquivo existe ? 
      //
      while(fileExists(fileNameF3)==0); //arquivo existe ? 
      //

      arqfilho = fopen(fileName0, "r");
      int a;
      fscanf( arqfilho, "%d", &a );
      fclose(arqfilho);
      //
      arqfilho = fopen(fileName1, "r");
      int b;
      fscanf( arqfilho, "%d", &b );
      fclose(arqfilho);
      //
      arqfilho = fopen(fileName2, "r");
      int c;
      fscanf( arqfilho, "%d", &c );
      fclose(arqfilho);
      //
      arqfilho = fopen(fileName3, "r");
      int d;
      fscanf( arqfilho, "%d", &d );
      fclose(arqfilho);
      //


      //printf("I am the father. child's finished\n");
      //printf("A = %d\nB = %d\nC = %d\nD = %d\n res = %d\n",a,b,c,d,e,f,a+b+c+d);
      
    }   	

    //while ((wpid = wait(&status)) > 0); // this way, the father waits for all the child processes 	

exit(0);
}
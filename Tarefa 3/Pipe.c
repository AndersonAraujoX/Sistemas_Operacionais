//exemplo de IPC PIPE - 3.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

typedef enum {
    STR2INT_SUCCESS,
    STR2INT_OVERFLOW,
    STR2INT_UNDERFLOW,
    STR2INT_INCONVERTIBLE
} str2int_errno;

str2int_errno str2int(int *out, char *s, int base) {
    char *end;
    if (s[0] == '\0' || isspace((unsigned char) s[0]))
        return STR2INT_INCONVERTIBLE;
    errno = 0;
    long l = strtol(s, &end, base);
    /* Both checks are needed because INT_MAX == LONG_MAX is possible. */
    if (l > INT_MAX || (errno == ERANGE && l == LONG_MAX))
        return STR2INT_OVERFLOW;
    if (l < INT_MIN || (errno == ERANGE && l == LONG_MIN))
        return STR2INT_UNDERFLOW;
    if (*end != '\0')
        return STR2INT_INCONVERTIBLE;
    *out = l;
    return STR2INT_SUCCESS;
}

int main(void)
{
        int     fd0a[2], fd0b[2], fd1a[2], fd1b[2], fd2a[2], fd2b[2], fd3a[2], fd3b[2], fd4a[2], fd4b[2], nbytes;
        char    readbuffer[310];
        int numIn, numOut, result, result0, result1, result2,result3, result4, result5;

        pid_t childPID[6];
        pid_t myPID;
        pid_t PID;			// pid_t eh um data type integer
        pid_t PPID;
        
        pid_t wpid;

        int status;
        int filho;
        int p;

        FILE *arq;
        FILE *end;
        FILE *filhof;

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

        pipe(fd0a);
        pipe(fd0b);
        pipe(fd1a);
        pipe(fd1b);
        pipe(fd2a);
        pipe(fd2b); 
        pipe(fd3a);
        pipe(fd3b);
        pipe(fd4a);
        pipe(fd4b);    
    
        PID = getpid();		// pega o pid do processo
        PPID = getppid();   // pega o pid do pai do processo
        myPID = getpid();
        filho = -1;
        for(p=0;p<5;p++){
            if (myPID == PID) //se eu sou o pai entao fork
	    {
		        childPID[p] = fork();
                        myPID = getpid();
                        filho = p;
                        if (myPID == PID) filho = -1;
            }
        }

        if(filho == 0)
        {
                //
                /* Child process closes up input side of pipe */
                close(fd0a[0]);
                close(fd0b[1]);

                int i;
                double mu,x0;
                int cont;
                int result;


                /*printf("I am the child1. MyPID is: %d\n",myPID); 
                printf("I am running computation A\n");*/

                arq=fopen(fileName0,"w");
                for(i=2000; i<2400; i++){
                        mu=((double)i)/1000.0;        
                        x0=((double) rand() / (RAND_MAX)) ;


                        for(cont=0;cont<100;cont++){
                                x0=mu*x0*(1.0-x0);
                        }
                        //ultimas interações
                        for(cont=100;cont<300;cont++){
                                x0=mu*x0*(1.0-x0);
                                fprintf(arq, "%lf \t %lf \n",mu,x0);
                        }
                }

                /* Send "string" through the output side of pipe */
                write(fd0a[1],fileName0, 8);
                exit(0);
        }
        if(filho == 1)
        {
                //
                /* Child process closes up input side of pipe */
                close(fd1a[0]);
                close(fd1b[1]);

                int i;
                double mu,x0;
                int cont;
                int result;

                arq=fopen(fileName1,"w");
                /*printf("I am the child1. MyPID is: %d\n",myPID); 
                printf("I am running computation A\n");*/ 
                for(i=2400; i<2800; i++){
                        mu=((double)i)/1000.0;        
                        x0=((double) rand() / (RAND_MAX)) ;


                        for(cont=0;cont<100;cont++){
                                x0=mu*x0*(1.0-x0);
                        }
                        //ultimas interações
                        for(cont=100;cont<300;cont++){
                                x0=mu*x0*(1.0-x0);
                                fprintf(arq, "%lf \t %lf \n",mu,x0);
                        }
                }
                write(fd1a[1],fileName1, 8);
                exit(0);

        }
        if(filho == 2)
        {
                //
                /* Child process closes up input side of pipe */
                close(fd2a[0]);
                close(fd2b[1]);

                int i;
                double mu,x0;
                int cont;
                int result;


                /*printf("I am the child1. MyPID is: %d\n",myPID); 
                printf("I am running computation A\n");*/ 
                arq=fopen(fileName2,"w");
                for(i=2800; i<3200; i++){
                        mu=((double)i)/1000.0;        
                        x0=((double) rand() / (RAND_MAX)) ;


                        for(cont=0;cont<100;cont++){
                                x0=mu*x0*(1.0-x0);
                        }
                        //ultimas interações
                        for(cont=100;cont<300;cont++){
                                x0=mu*x0*(1.0-x0);
                                fprintf(arq, "%lf\t %lf \n",mu,x0);
                        }
                }
                write(fd2a[1],fileName2, 8);
                exit(0);
        }
        if(filho == 3)
        {
                               //
                /* Child process closes up input side of pipe */
                close(fd3a[0]);
                close(fd3b[1]);

                int i;
                double mu,x0;
                int cont;
                int result;


                /*printf("I am the child1. MyPID is: %d\n",myPID); 
                printf("I am running computation A\n");*/
                arq=fopen(fileName3,"w"); 
                for(i=3200; i<3600; i++){
                        mu=((double)i)/1000.0;        
                        x0=((double) rand() / (RAND_MAX)) ;


                        for(cont=0;cont<100;cont++){
                                x0=mu*x0*(1.0-x0);
                        }
                        //ultimas interações
                        for(cont=100;cont<300;cont++){
                                x0=mu*x0*(1.0-x0);
                                fprintf(arq, "%lf \t %lf \n",mu,x0);
                        }
                }
                write(fd3a[1],fileName3, 8);
                exit(0);
        }
        if(filho == 4){
                /* Child process closes up input side of pipe */
                close(fd4a[0]);
                close(fd4b[1]);

                int i;
                double mu,x0;
                int cont;
                int result;

                arq=fopen(fileName4,"w");
                /*printf("I am the child1. MyPID is: %d\n",myPID); 
                printf("I am running computation A\n");*/ 
                for(i=3600; i<4000; i++){
                        mu=((double)i)/1000.0;        
                        x0=((double) rand() / (RAND_MAX)) ;


                        for(cont=0;cont<100;cont++){
                                x0=mu*x0*(1.0-x0);
                        }
                        //ultimas interações
                        for(cont=100;cont<300;cont++){
                                x0=mu*x0*(1.0-x0);
                                fprintf(arq, "%lf \t %lf \n",mu,x0);
                        }
                }
                write(fd4a[1],fileName4, 8);
                exit(0);
        }
        printf("quem passaou aqui: %d",filho);
        if (filho = -1)
        {
                /* Parent process closes up output side of pipe */
                close(fd0a[1]);
                close(fd0b[0]);
                //
                close(fd1a[1]);
                close(fd1b[0]);
                //
                close(fd2a[1]);
                close(fd2b[0]);
                //
                close(fd3a[1]);
                close(fd3b[0]);
                //
                close(fd4a[1]);
                close(fd4b[0]);
                //
                end=fopen("log.txt","w");
                int path;
                /* Read in a string from the pipe */
                // child 0
                nbytes = read(fd0a[0], readbuffer, sizeof(readbuffer));
                filhof =  fopen(readbuffer,"r");
                path = fgetc(filhof);
                while(path != EOF){
                        fputc(path,end);
                        path = fgetc(filhof);
                }
                fclose(filhof);

                //
                /* Read in a string from the pipe */
                // child 1
                nbytes = read(fd1a[0], readbuffer, sizeof(readbuffer));
                printf("parent: Received string: %s\n", readbuffer);
                filhof =  fopen(readbuffer,"r");
                path = fgetc(filhof);
                while(path != EOF){
                        fputc(path,end);
                        path = fgetc(filhof);
                }
                fclose(filhof);

                //
                /* Read in a string from the pipe */
                // child 2
                nbytes = read(fd2a[0], readbuffer, sizeof(readbuffer));
                printf("parent: Received string: %s\n", readbuffer);
                filhof =  fopen(readbuffer,"r");
                path = fgetc(filhof);
                while(path != EOF){
                        fputc(path,end);
                        path = fgetc(filhof);
                }
                fclose(filhof);

                //
                /* Read in a string from the pipe */
                // child 3
                nbytes = read(fd3a[0], readbuffer, sizeof(readbuffer));
                printf("parent: Received string: %s\n", readbuffer);
                filhof =  fopen(readbuffer,"r");
                path = fgetc(filhof);
                while(path != EOF){
                        fputc(path,end);
                        path = fgetc(filhof);
                }
                fclose(filhof);

                //
                /* Read in a string from the pipe */
                // child 4
                nbytes = read(fd4a[0], readbuffer, sizeof(readbuffer));
                filhof =  fopen(readbuffer,"r");
                path = fgetc(filhof);
                while(path != EOF){
                        fputc(path,end);
                        path = fgetc(filhof);
                }
                fclose(filhof);
                //
                //int status;
                //while ((wpid = wait(&status)) > 0); 
                
        }
        
        return(0);
}

/*  Assignment No. 5: Thread synchronization and mutual exclusion using mutex. Application to demonstrate:
Reader-Writer problem with readers priority.*/


#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>


void reader();
void writer();
void readers();
void writers();

int i=0,j=0,arr[20]={0};
int count=0;

sem_t sread;
sem_t swrite;
pthread_t thr1,thr2,thr3,thr4;


int main()
{

sem_init(&sread,0,0);
sem_init(&swrite,0,1);

while(count<5)
{
pthread_create(&thr1,NULL,(void*)writer,NULL);
pthread_create(&thr2,NULL,(void*)reader,NULL);
pthread_create(&thr3,NULL,(void*)writers,NULL);
pthread_create(&thr4,NULL,(void*)readers,NULL);
count++;
}

printf("\n");
pthread_join(thr1,NULL);
pthread_join(thr2,NULL);
pthread_join(thr3,NULL);
pthread_join(thr4,NULL);
return(0);
}



void writer()
{
 	sem_wait(&swrite);
 	printf("\n Writer 1 is writing...");
 	if(i%2==0)
 	{
  	arr[j]=i;
  	j++;
 	}
	 i++;
 	sem_post(&sread);
}


void reader()
{
  	sem_wait(&sread);
 	printf("\n Reader 1 is reading...");
 	if((i-1)%2==0)
 	{
  	printf("even no:");
  	printf("%d",arr[j-1]);
  	//sleep(1);
 	}
 		else
 		{
 		printf("odd no:");
 		printf("%d",i-1);
 		//sleep(1);
 		}
	sem_post(&swrite);
}


void writers()
{
  	sem_wait(&swrite);
  	printf("\n Writer 2 is writing...");
 	if(i%2==0)
 	{
  	arr[j]=i;
  	j++;
 	}
	i++;
 	sem_post(&sread);
}


void readers()
{
  	sem_wait(&sread);
	printf("\n Reader 2 is reading...");
 	if((i-1)%2==0)
 	{
  	printf("even no:");
  	printf("%d",arr[j-1]);
  	//sleep(1);
 	}
 	else
 	{
 	printf("odd  no:");
 	printf("%d",i-1);
 	//sleep(1);
 	}
	sem_post(&swrite);
}

/* OUTPUT
amol@amol-Aspire-5742:~$ gcc rw.c -lpthread
amol@amol-Aspire-5742:~$ ./a.out

 Writer 1 is writing...
 Reader 2 is reading...even no:0
 Writer 2 is writing...
 Reader 1 is reading...odd no:1
 Writer 1 is writing...
 Reader 2 is reading...even no:2
 Writer 2 is writing...
 Reader 2 is reading...odd  no:3
 Writer 1 is writing...
 Reader 1 is reading...even no:4
 Writer 1 is writing...
 Reader 1 is reading...odd no:5
 Writer 2 is writing...
 Reader 1 is reading...even no:6
 Writer 2 is writing...

 Reader 2 is reading...odd  no:7
 Writer 1 is writing...
 Reader 1 is reading...even no:8
 Writer 2 is writing...
 Reader 2 is reading...odd  no:9amol@amol-Aspire-5742:~$
*/


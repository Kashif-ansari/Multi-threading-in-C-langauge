#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void *thread_function(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter =0;
int count = 0;
int array[20]= {1,5,7,10,12,14,15,18,20,22,25,27,30,64,110,220,23,657,43,2};
int main(){
pthread_t thread_id[5];
int iret[5];
for(int i=0;i<5;i++){

pthread_create(&thread_id[i],NULL,thread_function,NULL);
sleep(5);
}
return 0;
}
void *thread_function(void *){

pthread_mutex_lock(&mutex1);
printf("Please Enter a number: ");
scanf("%d",&counter);
for(int i; i <20; i++){
if(array[i] == counter){
count++;
}
}
if(count == 1){
printf("Search number Found\n");
}
else{
printf("Search number not Found\n");
}
printf("Thread ID :%d\n",pthread_self());
count = 0;
pthread_mutex_unlock(&mutex1);}

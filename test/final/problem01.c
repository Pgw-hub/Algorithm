/*

	This program implements the deadlock-free solution of the dining philosophers problem.
	Complete the program using pthread_mutex_t and pthread_cond_t.
	The program should work even if there are more than 5 philosophers, e.g., 6 or 7.

	Compile with '-pthread' option
		e.g., gcc my_solution.c -pthread

	Ex)
		$ ./a.out 5 10
		no_phil = 5, duration = 10
		Philosopher 0 is thinking.
		Philosopher 1 is thinking.
		Philosopher 2 is thinking.
		Philosopher 3 is thinking.
		Philosopher 4 is thinking.
		Philosopher 0 is Hungry.
		=== Philosopher 0 is EATING.
		Philosopher 4 is Hungry.
		Philosopher 2 is Hungry.
		=== Philosopher 2 is EATING.
		Philosopher 1 is Hungry.
		=== Philosopher 0 FINISHED EATING.
		Philosopher 0 is thinking.
		=== Philosopher 2 FINISHED EATING.
		=== Philosopher 4 is EATING.
		Philosopher 2 is thinking.
		=== Philosopher 1 is EATING.
		Philosopher 3 is Hungry.
		=== Philosopher 1 FINISHED EATING.
		Philosopher 1 is thinking.
		Philosopher 0 is Hungry.
		=== Philosopher 4 FINISHED EATING.
		Philosopher 2 is Hungry.
		=== Philosopher 0 is EATING.
		=== Philosopher 3 is EATING.
		Philosopher 1 is Hungry.
		Philosopher 4 is thinking.
		=== Philosopher 0 FINISHED EATING.
		Philosopher 0 is thinking.
		=== Philosopher 1 is EATING.
		=== Philosopher 1 FINISHED EATING.
		Philosopher 1 is thinking.
		=== Philosopher 3 FINISHED EATING.
		Philosopher 3 is thinking.
		=== Philosopher 2 is EATING.
		Philosopher 4 is Hungry.
		=== Philosopher 4 is EATING.
		Terminting threads...
		=== Philosopher 4 FINISHED EATING.
		Philosopher 3 is Hungry.
		Philosopher 0 is Hungry.
		=== Philosopher 0 is EATING.
		Philosopher 1 is Hungry.
		=== Philosopher 2 FINISHED EATING.
		=== Philosopher 3 is EATING.
		=== Philosopher 0 FINISHED EATING.
		=== Philosopher 1 is EATING.
		=== Philosopher 3 FINISHED EATING.
		=== Philosopher 1 FINISHED EATING.
		Bye!							# this message is important

	Ex)
		$ ./dining_philosophers 6 10	# 6 philosophers
		no_phil = 6, duration = 10
		Philosopher 0 is thinking.
		Philosopher 2 is thinking.
		Philosopher 1 is thinking.
		Philosopher 4 is thinking.
		Philosopher 5 is thinking.
		Philosopher 3 is thinking.
		Philosopher 1 is Hungry.
		=== Philosopher 1 is EATING.
		Philosopher 2 is Hungry.
		Philosopher 5 is Hungry.
		=== Philosopher 5 is EATING.
		=== Philosopher 1 FINISHED EATING.
		Philosopher 1 is thinking.
		=== Philosopher 2 is EATING.
		Philosopher 0 is Hungry.
		Philosopher 4 is Hungry.
		Philosopher 3 is Hungry.
		=== Philosopher 5 FINISHED EATING.
		Philosopher 5 is thinking.
		=== Philosopher 4 is EATING.
		=== Philosopher 0 is EATING.
		=== Philosopher 2 FINISHED EATING.
		Philosopher 2 is thinking.
		=== Philosopher 0 FINISHED EATING.
		Philosopher 0 is thinking.
		Philosopher 1 is Hungry.
		=== Philosopher 1 is EATING.
		=== Philosopher 4 FINISHED EATING.
		Philosopher 4 is thinking.
		=== Philosopher 3 is EATING.
		Philosopher 5 is Hungry.
		=== Philosopher 5 is EATING.
		Philosopher 2 is Hungry.
		=== Philosopher 1 FINISHED EATING.
		Philosopher 1 is thinking.
		=== Philosopher 3 FINISHED EATING.
		Philosopher 3 is thinking.
		=== Philosopher 2 is EATING.
		Philosopher 0 is Hungry.
		Terminting threads...
		Philosopher 4 is Hungry.
		Philosopher 3 is Hungry.
		Philosopher 1 is Hungry.
		=== Philosopher 5 FINISHED EATING.
		=== Philosopher 4 is EATING.
		=== Philosopher 2 FINISHED EATING.
		=== Philosopher 0 is EATING.
		=== Philosopher 4 FINISHED EATING.
		=== Philosopher 3 is EATING.
		=== Philosopher 3 FINISHED EATING.
		=== Philosopher 0 FINISHED EATING.
		=== Philosopher 1 is EATING.
		=== Philosopher 1 FINISHED EATING.
		Bye!							# this message is important

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0


// data members of monitor

enum State { THINKING = 0, HUNGRY = 1, EATING = 2 };

typedef struct {
	int no_phil;
	pthread_mutex_t mutex;
	int *state;				// to allocate array of State
	pthread_cond_t *self;		// to allocate array of pthread_cond_t
} DiningPhilosophers;

void Init(DiningPhilosophers *dp, int no_phil);
void Destroy(DiningPhilosophers *dp);
void PickUp(DiningPhilosophers *dp, int idx);
void PutDown(DiningPhilosophers *dp, int idx);
void Test(DiningPhilosophers *dp, int idx);


// structure for thread parameters
typedef struct {
	int idx;				// index of current philosopher
	DiningPhilosophers *dp;
} ThreadInfo;

void *Philosopher(void *vparam);		// thread function
int repeat = TRUE;


int main(int argc, char *argv[])
{
	if(argc < 3){
		printf("Usage: %s <no_phil> <duration>\n", argv[0]);
		return 0;
	}

	int no_phil = atoi(argv[1]);
	int duration = atoi(argv[2]);
	printf("no_phil = %d, duration = %d\n", no_phil, duration);

	srand(time(NULL));

	DiningPhilosophers dp;
	Init(&dp, no_phil);

	pthread_t *phil = (pthread_t *)malloc(no_phil * sizeof(pthread_t));
	ThreadInfo *info = (ThreadInfo *)malloc(no_phil * sizeof(ThreadInfo));
	if(phil == NULL || info == NULL){
		printf("Failed to allocate memory.\n");
		exit(-1);
	}

	// TO DO: create philosopher threads
	// 		  deliver the index of the each thread and the address of 'dp' through 'info'.
	pthread_attr_t attr;
	int ret;

	pthread_attr_init(&attr);

	for(int i = 0; i < no_phil; i++){
		info[i].idx = i;
		info[i].dp = &dp;		
		ret = pthread_create(&phil[i],NULL,Philosopher,&info[i]);
		if(ret){
			printf("error pthread_create\n");
			exit(1);
		}
	}
	

	sleep(duration);
	
	printf("Terminting threads...\n");
	// TO DO: terminate threads by setting 'repeat' to zero
	repeat = FALSE;


	// TO DO: wait until all philosopher threads terminate
	for(int i = 0; i < no_phil; i++){
		pthread_join(phil[i],NULL);
	}
	

	// TO DO: destroy all dynamically allocated memory blocks, including the ones in 'dp'
	Destroy(&dp);
	free(phil);
	free(info);



	printf("Bye!\n");			// this message should be displayed.

	return 0;
}

void *Philosopher(void *vparam)
// the thread function for each philosopher
// DO NOT modify this function
{
	ThreadInfo *param = (ThreadInfo*)vparam;

	DiningPhilosophers *dp = param->dp;
	int idx = param->idx;
	printf("thread id = %d", idx);
	int left = (idx + dp->no_phil - 1) % dp->no_phil;
	int right = (idx + 1) % dp->no_phil;

	while(repeat){
		// remainder section
		printf("Philosopher %d is thinking.\n", param->idx);
		fflush(stdout);
		sleep(rand() % 3 + 2);		// wait for 2 ~ 4 sec

		// entry section
		printf("Philosopher %d is Hungry.\n", param->idx);
		fflush(stdout);
		PickUp(param->dp, param->idx);

		// critical section

		// error check
		if(param->dp->state[left] == EATING || param->dp->state[right] == EATING){
			printf("ERROR! phil[%d] = %d, phil[%d] = %d, phil[%d] = %d\n",
				left, dp->state[left], param->idx, dp->state[param->idx], right, dp->state[right]);
			exit(-1);
		}

		printf("=== Philosopher %d is EATING.\n", param->idx);
		fflush(stdout);
		sleep(rand() % 3 + 1);		// wait for 1 ~ 3 sec

		printf("=== Philosopher %d FINISHED EATING.\n", param->idx);
		fflush(stdout);

		// exit section
		PutDown(param->dp, param->idx);
	}

	return NULL;
}

// monitor functions
void Init(DiningPhilosophers *dp, int no_phil)
{
	pthread_mutex_init(&dp->mutex, NULL);

	dp->state = (int*)malloc(no_phil * sizeof(int));
	dp->self = (pthread_cond_t*)malloc(no_phil * sizeof(pthread_cond_t));
	if(dp->state == NULL || dp->self == NULL){
		printf("Failed to allocate memory.\n");
		exit(-1);
	}

	for(int i = 0; i < no_phil; i++){
		dp->state[i] = THINKING;//basic is thinking
		pthread_cond_init(&dp->self[i], NULL);
	}

	dp->no_phil = no_phil;
}

void Destroy(DiningPhilosophers *dp)
{
	pthread_mutex_destroy(&dp->mutex);

	free(dp->state);
	dp->state = NULL;

	for(int i = 0; i < dp->no_phil; i++)
		pthread_cond_destroy(&dp->self[i]);

	free(dp->self);
	dp->self = NULL;
}

void PickUp(DiningPhilosophers *dp, int idx)
{
	// TO DO: implement this function.
	//		if necessary, use pthread_mutex_t to ensure mutual exclusion
	//		use pthread_cond_t for the condition variables
	dp -> state[idx] = HUNGRY;
	dp -> state[idx] = HUNGRY;
	Test(dp,idx);
	if(dp -> state[idx] != EATING)
		pthread_cond_wait(&dp -> self[idx],&dp -> mutex);
}

void PutDown(DiningPhilosophers *dp, int idx)
{
	// TO DO: implement this function.
	//		if necessary, use pthread_mutex_t to ensure mutual exclusion
	//		use pthread_cond_t for the condition variables
	int size = dp -> no_phil;
	dp -> state[idx] = THINKING;
	Test(dp,(idx + 4) % size);
	Test(dp,(idx + 1) % size);
}

void Test(DiningPhilosophers *dp, int idx)
{
	// TO DO: implement this function.
	//		if necessary, use pthread_mutex_t to ensure mutual exclusion
	//		use pthread_cond_t for the condition variables
	int size = dp -> no_phil;
	if(dp -> state[(idx + 4) % size] != EATING && dp -> state[idx] == HUNGRY && dp -> state[(idx + 1) % size] != EATING ){
		dp -> state[idx] =EATING;
		pthread_cond_signal(&dp -> self[idx]);
	}
}

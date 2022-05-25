#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREAD 16

typedef struct {
	int thread_idx;			// the index of the current thread
	int no_thread;			// total # of threads
	int upper;				// the upper bound
	int sum;				// partial sum of the current thread
} ThreadInfo;

int GetSum(int upper);      // returns the sum of integers in range [1, upper] (single-threaded version)

int GetSum_MT(int upper, int no_thread); // returns the sum of intergers in range [1, upper] (multi-threaded version)
void *thread_fn(void *vparam);

int main(int argc, char *argv[])
{
	int upper = 0;
	int no_thread = 0; 
	if(argc <= 2){
		printf("Usage: %s <upper> <no_thread>\n", argv[0]);
		return 0;
	}

	upper = atoi(argv[1]);
	no_thread = atoi(argv[2]);

	if(upper <= 0 || no_thread <= 0){
		printf("Invalide input, upper = %d, no_thread = %d\n", upper, no_thread);
		return -1;
	}

    // The results of GetSum() and GetSum_MT() should be same.
    printf("total_sum (single thread) = %d\n", GetSum(upper));
    printf("total_sum (%d threads) = %d\n", no_thread, GetSum_MT(upper, no_thread));


	return 0;
}

int GetSum(int upper)
// returns the sum of integers in range [1, upper] (single-threaded version)
{
    int sum = 0;
    for(int i = 1; i <= upper; i++)
        sum += i;

    return sum;
}

int GetSum_MT(int upper, int no_thread)
// returns the sum of integers in range [1, upper] (multi-threaded version)
// TO DO: complete this function
{
    pthread_t tid[MAX_THREAD];
    ThreadInfo info[MAX_THREAD];
	int ret;

    for(int i = 0; i < no_thread; i++){
        // TO DO: fill info[i] with appropriate values and create a child thread using it.
        info[i].thread_idx = i;
        info[i].no_thread = no_thread;//인덱스랑 idx설정해주기.

		// write your code here
		ret = pthread_create(&tid[i],NULL,&thread_fn,(void *)i);//i개의 thread를 만들고 돌게 한다.
		if(ret){
			printf("error pthread_join\n");
			exit(1);
		}
    }

    int total_sum = 0;
    // Wait for all the threads and accumulate the partial sums of all threads to compute the total sum.
    for(int i = 0; i < no_thread; i++){
        // TO DO:
        //  Wait for the i-th thread.
        //  Display its partial sum.
        //  Accumulate the partial sum in total_sum.

    }

    return total_sum;
}

void *thread_fn(void *vparam)
{
	ThreadInfo *param = (ThreadInfo*)vparam;
	printf("thread id = %d\n", param -> thread_idx);
	// TO DO: Compute the sum of numbers i, i + m, i + 2m, i + 3m, ...,
	//		where i is the index of current thread and m is the total number of threads
	// 	If the current thread the 2nd and there are totally 4 threads,
	//		the current thread computes the sum of 2, 6, 10, 14, ...
	//  Store the partial sum in param->sum.

	return NULL;
}


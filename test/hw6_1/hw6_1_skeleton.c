#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MesgQueueParent2Child 1024	// replace this number with an arbitrary number
#define MesgQueueChild2Parent 1025	// replace this number with an arbitrary number


// TO DO: declare a structure for messages
typedef struct Number{
	int input;
	int sum;
} Number;

void Parent(int msgq_snd, int msgq_rcv);
int Child(int msgq_rcv, int msgq_snd);
// void clear_stdin() {
// 	int ch;
// 	while ((ch = getchar()) != EOF && ch != '\n') {};
// }

int main()
{
	// TO DO: Create two messsage queues using the keys MesgQueueParent2Child and MesgQueueChild2Parent
	// 		  On failure, display an error message.
	key_t p2c = MesgQueueParent2Child;
	key_t c2p = MesgQueueChild2Parent;
	int msgq_p2c;
	int msgq_c2p;
	// clear_stdin();

	if(msgq_p2c = msgget(p2c, IPC_CREAT|0666) == -1){
		printf("msgget_p2c failed \n");
		exit(0);
	}
	if(msgq_c2p = msgget(c2p, IPC_CREAT|0666) == -1){
		printf("msgget_c2p failed \n");
		exit(0);
	}

	pid_t child_pid = fork();
	if(child_pid < 0){
		printf("Failed to create process.\n");
		return -1;
	} else if(child_pid > 0){
		Parent(msgq_p2c, msgq_c2p);						// DO NOT modify this line

		// TO DO: Destroy the two message queues.

		printf("Parent terminating.\n");				// This smessage should be displayed.

	} else {
		int sum = Child(msgq_p2c, msgq_c2p);			// DO NOT modify this line
		printf("Child terminating. sum = %d\n", sum);	// This smessage should be displayed.
	}

	return 0;
}

void Parent(int msgq_snd, int msgq_rcv)
// TO DO: implement this function
{
	/* TO DO:
        - Repeat
            . Read an integer from the user.(0)
            . Send the number to the child using msgsnd().(0)
			  On failure, display an error message.(0)
            . If the input number is negative, break the loop.(0)
            . Receive the sum of the input numbers from the child using msgrcv().(0)
			  On failure, display an error message.(0)
            . Display the sum. Put a prefix "[parent]" to indicate it was printed by the parent.(0)
	*/
	Number n;
	// n.sum = 0;
	printf("Input integer numbers and child will accumulate (-1 to finish).\n");
	while(1){
		scanf("%d",&n.input);
		getchar();

		if(msgsnd(msgq_snd,&n,sizeof(Number),0) == -1){
			printf("msgsnd failed in parent\n");
			exit(0);
		}
		if(n.input < 0) break;

		if(msgrcv(msgq_rcv,&n,sizeof(Number),0,0) == -1){
			printf("msgrcv failed in parent\n");
			exit(0);
		}
		printf("[parent] sum = %d\n",n.sum);
	}
}

int Child(int msgq_rcv, int msgq_snd)
// TO DO: implement this function
{
	/* TO DO:
		- Initialize sum by zero.(0)
		- Repeat
			. Receive a number from the parent using msgrcv().(0)
			  On failure, display an error message.(0)
			. If the number is negative, break the loop.(0)
			. Display the input number. Put a prefix "[child]" to indicate it was printed by the child.(0)
			. Add the number to sum.(0)
			. Send the sum to the parent using msgsnd(). (0)
			  On failure, display an error message.(0)
		- Return sum.(0)
	*/
	Number n;
	n.sum = 0;
	while(1){
		if(msgrcv(msgq_rcv,&n,sizeof(Number),0,0) == -1){
			printf("msgrcv failed in child\n");
			exit(0);
		}

		if(n.input < 0) break;
		printf("[child] input number = %d\n",n.input);
		n.sum += n.input;

		if(msgsnd(msgq_snd,&n,sizeof(Number),0) == -1){
			printf("msgsnd failed in child\n");
			exit(0);
		}
	}
	return n.sum;
}


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
} Num;

void Parent(int msgq_snd, int msgq_rcv);
int Child(int msgq_rcv, int msgq_snd);

Num n;

int main()
{
	// TO DO: Create two messsage queues using the keys MesgQueueParent2Child and MesgQueueChild2Parent
	// 		  On failure, display an error message.
	key_t p2c = MesgQueueParent2Child;
	key_t c2p = MesgQueueChild2Parent;
	int msgq_p2c = msgget(p2c, IPC_CREAT|0666);
	int msgq_c2p = msgget(c2p, IPC_CREAT|0666);

	if(msgq_p2c == -1 || msgq_c2p == -1){
		printf("masget failed\n");
		exit(0);
	}

	printf("msgqp2c : %d , msgqc2p : %d\n", msgq_p2c,msgq_c2p);


	pid_t child_pid = fork();
	if(child_pid < 0){
		printf("Failed to create process.\n");
		return -1;
	} else if(child_pid > 0){
		Parent(msgq_p2c, msgq_c2p);						// DO NOT modify this line

		// TO DO: Destroy the two message queues.
		msgctl(msgq_p2c,IPC_RMID,NULL);
		msgctl(msgq_c2p,IPC_RMID,NULL);
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
            . Read an integer from the user.
            . Send the number to the child using msgsnd().
			  On failure, display an error message.
            . If the input number is negative, break the loop.
            . Receive the sum of the input numbers from the child using msgrcv().
			  On failure, display an error message.
            . Display the sum. Put a prefix "[parent]" to indicate it was printed by the parent.
	*/
	
	printf("Input integer numbers and child will accumulate (-1 to finish).\n");
	while(1){
		scanf("%d",&n.input);
		getchar();
		
		if(msgsnd(msgq_snd,&n,sizeof(Num),0) == -1){
			printf("msgsnd failed in parent\n");
			exit(0);
		}
		if(n.input < 0) break;
		

		if(msgrcv(msgq_rcv,&n,sizeof(Num),0,0) == -1){
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
		- Initialize sum by zero.
		- Repeat
			. Receive a number from the parent using msgrcv().
			  On failure, display an error message.
			. If the number is negative, break the loop.
			. Display the input number. Put a prefix "[child]" to indicate it was printed by the child.
			. Add the number to sum.
			. Send the sum to the parent using msgsnd(). 
			  On failure, display an error message.
		- Return sum.
	*/
	
	n.sum = 0;
	while(1){
		if(msgrcv(msgq_rcv, &n, sizeof(Num),0,0) == -1){
			printf("msgrcv failed in child\n");
			exit(0);
		}
		if(n.input < 0) break;
		printf("[child] input number = %d\n",n.input);
		n.sum = n.sum + n.input;

		// printf("[child] sum number = %d\n",n.sum);

		if(msgsnd(msgq_snd,&n,sizeof(Num),0) == -1){
			printf("msgsnd failed in child\n");
			exit(0);
		}
	}

	return n.sum;
}


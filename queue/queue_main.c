#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include "queue_structure.h"
typedef struct info {
	char MIS[10];
	char Name[20];
	int marks;
} info;
int main(int argc, char**argv) {
	info *first, *tmp;
	//info *pp;
	queue *q;
	
	//Memory Allocation
	first = (info *) malloc(sizeof(info));
	q = (queue *) malloc(sizeof(queue));
	if(first == NULL || q == NULL) {
		perror("Memory Allocation Failed!\n");
		exit(1);
	}

	//Data Filling
	strcpy(first->MIS, "111303025");
	strcpy(first->Name, "Vaibhav");
	first->marks = 90;
	
	q_init(q);
	if(!q_full(q)) {
		enqueue(q, first);
	}
	/*pp = s->top->data;
	printf("\nmarks; %d\n", pp->marks);
	printf("\nmis; %s\n", pp->MIS);
	printf("\nname; %s\n", pp->Name);
	printf("\nPushed first node into queue successfully\n");*/
	
	//print the contents of the queue
	tmp = dequeue(q);
	printf("\nMarks: %d\n", tmp->marks);
	printf("Popped into tmp success\n");
	printf("\nMIS: %s\n", tmp->MIS);
	printf("\nName: %s\n", tmp->Name);
	free(tmp);
	return 0;
}

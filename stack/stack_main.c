#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include "stack_structure.h"
typedef struct info {
	char MIS[10];
	char Name[20];
	int marks;
} info;
int main(int argc, char**argv) {
	info *first, *tmp;
	//info *pp;
	stack *s;
	
	//Memory Allocation
	first = (info *) malloc(sizeof(info));
	s = (stack *) malloc(sizeof(stack));
	if(first == NULL || s == NULL) {
		perror("Memory Allocation Failed!\n");
		exit(1);
	}

	//Data Filling
	strcpy(first->MIS, "111303025");
	strcpy(first->Name, "Vaibhav");
	first->marks = 90;
	
	s_init(s);
	if(!s_full(s)) {
		push(s, first);
	}
	/*pp = s->top->data;
	printf("\nmarks; %d\n", pp->marks);
	printf("\nmis; %s\n", pp->MIS);
	printf("\nname; %s\n", pp->Name);
	printf("\nPushed first node into stack successfully\n");*/
	
	//print the contents of the stack
	tmp = pop(s);
	printf("\nMarks: %d\n", tmp->marks);
	printf("Popped into tmp success\n");
	printf("\nMIS: %s\n", tmp->MIS);
	printf("\nName: %s\n", tmp->Name);
	free(tmp);
	return 0;
}

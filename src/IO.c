#include "include/IO.h"

#include <stdio.h>
#include <stdlib.h>

void readInput(char* filename, struct User **firstUser, int *nrUsers)
{
	FILE *fin = fopen(filename, "r");
	int i, j, nrProcesses;
	*firstUser = malloc(sizeof(struct User));
	struct User *currUser = *firstUser, *prevUser = *firstUser;

	if(fin == NULL){
		printf("Error opening input.txt");

		exit(0);
	}

	fscanf(fin, "%d", nrUsers);

	for(i = 0; i < *nrUsers; i++){
		if(i != 0){
			currUser = malloc(sizeof(struct User));
		
			prevUser->next = currUser;
		}

		fscanf(fin, "%d %d", &(currUser->priority), &nrProcesses);

		currUser->first = malloc(sizeof(struct Process));
		fscanf(fin, "%ld", &(currUser->first->duration));
		struct Process* prev = currUser->first, *newProcess;

		for(j = 1; j < nrProcesses; j++){
			newProcess = malloc(sizeof(struct Process));
			fscanf(fin, "%ld", &(newProcess->duration));

			prev->next = newProcess;
			prev = newProcess;
		}

		newProcess->next = NULL;

		prevUser = currUser;
	}

	prevUser->next = NULL;
}

void printUsers(struct User* firstUser)
{

	struct User *currUser = firstUser;
	int i = 0;

	while(currUser != NULL){
		printf("%d: %d ", i, currUser->priority);
		
		struct Process *p = currUser->first;

		while(p != NULL){
			printf("%ld ", p->duration);

			p = p->next;
		}

		printf("\n");

		currUser = currUser->next;

		i++;
	}	
}
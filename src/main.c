#include <stdio.h>
#include <stdlib.h>

#include "include/main.h"

int main()
{
	FILE *fin = fopen("../input/input.txt", "r");
	int nrUsers, i, j, nrProcesses;
	struct User *users;

	if(fin == NULL){
		printf("Error opening input.txt");

		return 0;
	}

	fscanf(fin, "%d", &nrUsers);
	users = malloc(nrUsers * sizeof(struct User));

	if(users == NULL){
		printf("Could not allocate memory for users");

		return 0;
	}

	for(i = 0; i < nrUsers; i++){
		fscanf(fin, "%d %d", &(users[i].priority), &nrProcesses);
		
		user[i].first = malloc(sizeof(struct Process));
		fscanf(fin, "%ld", &(users[i].first->duration));
		struct Process* prev = users[i].first, *newProcess;

		for(j = 0; j < nrProcesses; j++){
			newProcess = malloc(sizeof(struct Process));
			fscanf(fin, "%ld", &(newProcess->duration));

			prev->next=newProcess;
		}

		newProcess->next=NULL;
	}

	for(i = 0; i < nrUsers; i++){
		printf("%d: %d ", i, users[i].priority);
		
		struct Process *p=users[i].first;

		while(p!=NULL){
			printf("%ld ", p->duration);

			p=p->next;
		}

		printf("\n");
	}	

	//TO DO: deallocate memory for processes
	
	free(users);

	return 0;
}

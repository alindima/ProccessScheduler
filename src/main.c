#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/main.h"
#include "include/IO.h"

int main()
{
	struct User *firstUser, *currUser;
	int nrUsers, i;

	readInput("input/input.txt", &firstUser, &nrUsers);

	schedule(firstUser);

	//printUsers(firstUser);

	//TO DO: deallocate memory for processes and for users

	return 0;
}

void schedule(struct User* firstUser)
{
	bool hasWork = true;
	struct User *currUser = firstUser, *prevUser = NULL;
	//TODO: check if initial work needs to be done

	//if(firstUser == NULL){
	//	printf("lalalalalaaalal\n");
	//	return;
	//}

	while(hasWork){
		bool isLast=false, deleted=false;

		executeProcess(currUser->priority, currUser->id, currUser->first);

		if(currUser->next==NULL){
			isLast=true;
		}

		//delete process if done
		if(currUser->first->duration <= 0){
			struct Process *newProcess = currUser->first->next;
			free(currUser->first);
			currUser->first = newProcess;
		}

		//delete user if no more processes
		if(currUser->first == NULL){
			
			struct User *newUser = currUser->next;
			free(currUser);

			if(prevUser == NULL){
				firstUser = newUser;
			}else{
				prevUser->next = newUser;
			}


			currUser = newUser;
			
			deleted=true;
		}

		if(firstUser == NULL){
			hasWork = false;
			continue;
		}

		//go back to start if at end

		if(isLast){
			currUser = firstUser;
			prevUser = NULL;
		}else if(!deleted){
			prevUser = currUser;
			currUser = currUser->next;
		}
	}
}

void executeProcess(int priority, int userId, struct Process* p)
{
	printf("Process %d from user %d has executed\n", p->id, userId);

	(p->duration) -= priority;
}

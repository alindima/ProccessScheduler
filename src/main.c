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

	printUsers(firstUser);

	//TO DO: deallocate memory for processes and for users

	return 0;
}

void schedule(struct User* firstUser)
{
	//bool 
}

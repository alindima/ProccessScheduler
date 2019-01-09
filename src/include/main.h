#ifndef MAIN_H
#define MAIN_H

struct Process
{
	long int duration;
	struct Process *next;	
};

struct User
{
	int priority;
	struct Process *first;
};


#endif
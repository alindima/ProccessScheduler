#ifndef DATATYPES_H
#define DATATYPES_H

struct Process
{
	long int duration;
	struct Process *next;	
};

struct User
{
	int priority;
	struct Process *first;
	struct User* next;
};

#endif
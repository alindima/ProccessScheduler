#ifndef DATATYPES_H
#define DATATYPES_H

struct Process
{
	int id;
	long int duration;
	struct Process *next;	
};

struct User
{
	int id;
	int priority;
	struct Process *first;
	struct User* next;
};

#endif
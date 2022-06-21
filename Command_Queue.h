#pragma once
#include "Command_Node.h"

//Implemented from https://github.com/ivanahristova/data-structures-fmi/blob/main/sem04/linked-queue.cpp

class Command_Queue
{

    Command_Node* head;
    Command_Node* tail;

    void copy(const Command_Queue& other);    
	
public:

    Command_Queue();
    Command_Queue(const Command_Queue& other);
    Command_Queue& operator=(const Command_Queue& other);
    ~Command_Queue();

    void enqueue(const Command& value);
    void dequeue();

    Command front();
    bool empty();

    void clear();

};


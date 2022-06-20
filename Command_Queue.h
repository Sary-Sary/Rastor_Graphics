#pragma once
#include "Command_Node.h"

class Command_Queue
{

    Command_Node* head;
    Command_Node* tail;

    void copy(const Command_Queue& other);
    void free();
	
public:

    Command_Queue();
    Command_Queue(const Command_Queue& other);
    Command_Queue& operator=(const Command_Queue& other);
    ~Command_Queue();

    void enqueue(const Command& value);
    void dequeue();

    Command front();
    bool empty();

};


#include "Command_Queue.h"

void Command_Queue::copy(const Command_Queue& other) {

    Command_Node* iter = other.head;

    while (iter != nullptr)
    {
        enqueue(iter->node);
        iter = iter->next;
    }

    return;

}

void Command_Queue::free() {

    Command_Node* iter = head;

    while (iter != nullptr)
    {
        Command_Node* toDelete = iter;
        iter = iter->next;
        delete toDelete;
    }

}

Command_Queue::Command_Queue() {



}

Command_Queue::Command_Queue(const Command_Queue& other) {


}

Command_Queue& Command_Queue::operator=(const Command_Queue& other) {



}

Command_Queue::~Command_Queue() {


}


void Command_Queue::enqueue(const Command& value) {


}

void Command_Queue::dequeue() {


}

Command Command_Queue::front() {


}

bool Command_Queue::empty() {



} 
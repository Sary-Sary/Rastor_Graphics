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

void Command_Queue::clear() {

    Command_Node* iter = head;

    while (iter != nullptr)
    {
        Command_Node* toDelete = iter;
        iter = iter->next;
        delete toDelete;
    }

}

Command_Queue::Command_Queue() : head(nullptr), tail(nullptr) {}

Command_Queue::Command_Queue(const Command_Queue& other) {

    copy(other);

}

Command_Queue& Command_Queue::operator=(const Command_Queue& other) {

    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;

}

Command_Queue::~Command_Queue() {

    clear();

}


void Command_Queue::enqueue(const Command& value) {

    Command_Node* newNode = new Command_Node(value);

    if (empty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

}

void Command_Queue::dequeue() {

    if (empty())
    {
        throw std::runtime_error("Pop called on an empty queue.");
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Command_Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

}

Command Command_Queue::front() {

    if (empty())
    {
        throw std::runtime_error("Front called on an empty queue.");
    }

    return head->node;

}

bool Command_Queue::empty() {

    return head == nullptr;

} 
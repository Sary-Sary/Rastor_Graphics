#pragma once
#include "Command.h"

struct Command_Node {

	Command node;
	Command_Node* next;

	Command_Node(Command data) : node(data), next(nullptr) {}
	//~Command_Node() { delete[] next; }
};


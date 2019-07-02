#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
//Node class setup with protected and public functions and values.
class Node
{
protected:
	Node*next;
public:
	Node(Node*n)
	{
		this->next = n;
	}
	virtual Node*goNext()
	{
		return next;
	}
	Node() = default;
}; //End of Node

//Switch class setup as a subclass of a node inheriting all node function.
class Switch : public Node
{
	enum State{ LEFT, RIGHT };
//Protected and public function set for only switches and not other nodes.
protected:
	State state = RIGHT;
	Node* left = nullptr;
	Node* right = nullptr;
public:
	Switch(Node*l, Node*r)
	{
		this->left = l;
		this->right = r;
	}

	Node* goNext(){
		if (this->state >= RIGHT)
		{
			this->next = right;
			this->state = LEFT;
		}
		else
		{
			this->next = left;
			this->state = RIGHT;
		}
		return next;
	}
};//End of Switch
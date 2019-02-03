#pragma once
#ifndef LIST_H
#define LIST_H
#include <cstddef>

template <class Type>
class List
{
public:
	//constructor of List class
	List()
	{
		//Head and Tail are assigned Null values when the Object is constructed in Memory
		Head=nullptr;
		Tail = nullptr;
	}
	~List()
	{
		
	}
	//Insert function uses a pointer to the NODE object and Insert()Method contains the type of data being passed into the list
	NODE * Insert(Type Data)
	{
		//declaring an reference to an Object of NODE class using the variable current.
		NODE *current = new NODE();
		//Assigning a value to the Null value of data using the pointer
		current->Data = Data;
		//check to see if the list is empty.  If the list is empty assign head and tail to the value of current
		if(Head==NULL)
		{
			Head = current;
			Tail = current;
		}
		//If the list is not Empty point the value of tail to current; then point the value of previous to tail;  Last assign the current value of current too tail;
		else
		{
			Tail->next = current;
			current->previous = Tail;
			Tail = current;
		}	
		
		return current;
	}
	void display(){
		NODE* pointer;
		pointer = Head;
		while(pointer!=nullptr)
		{
			std::cout<<pointer->data<<" ";
			pointer = pointer->next;
		}
	}
	

private:
	
	struct NODE
	{
		//You must declare these initial values to create a node.  Data is the value of the information stored within the node.
		//Next and Previous are values pointing to Areas within the Heap memory
		Type Data;
		NODE *next;
		NODE *previous;

		NODE()
		{
			//the constructor of the Node class assigns Null values to the pointers and the Data type
			Data = NULL;
			next = nullptr;
			previous = nullptr;
		}
	};
	//Head and tails are pointers to an Area of Memory to show the beginning of the list and the end of the list.
	NODE* Head;
	NODE* Tail;
	
};
#endif

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
		//declaring an reference to an Object of NODE class using the variable temp.
		NODE *temp = new NODE();
		//Assigning a value to Data with
		temp->Data = Data;

		if(Head==NULL)
		{
			Head = temp;
			Tail = temp;
		}
		else
		{
			Tail->next = temp;
			temp->previous = Tail;
			Tail = temp;
		}
			
		
		return temp;
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

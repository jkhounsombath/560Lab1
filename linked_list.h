#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

#include "node.h"

class linkedList
{
	private:
		Node* m_front;
	
	public:
		linkedList();
		~linkedList();
		bool isEmpty();
		int getLength();
		void insert(int newEntry, int index);
		void removeFromList(int value);
		void remove(int index);
		void deleteDuplicates();
		bool find(int value);
		void FindNext(int value);
		void print();
		void reverseList();
		void reverseHelper(Node* front);
		void findAt(int index);
};
#endif

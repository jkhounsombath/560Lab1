#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	private:
		int m_entry= 0;
		Node* m_next= nullptr;

	public:
		/**
		* @post constructor
		**/
		Node();

		/**
		* @pre entry for a node
		* @post inserts a new node at a position with entry
		* @param entry: A new entry to put in the list
		**/
		Node(int entry);

		/**
		* @pre entry for a node
		* @post inserts a new node at a position with entry
		* @param entry: A new entry to put in the list
		* @param nextNode: pointer to nextNode
		**/
		Node(int entry, Node* nextNode);

		/**
		* @post destructor
		**/
		~Node();

		/**
		* @pre entry for a node
		* @post sets the entry of a node
		* @param entry: the entry of a node
		**/
		void setEntry(int entry) ;

		/**
		* @post returns the value in a node
		**/
		int getEntry() const;

		/**
		* @post sets the nextNode
		* @param nextNode: pointer to nextNode
		**/
		void setNext(Node* nextNode);

		/**
		* @post returns a ptr to the next node in a list
		**/
		Node* getNext() const;
};
#endif

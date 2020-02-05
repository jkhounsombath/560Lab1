#include <iostream>

#include "node.h"

Node::Node()
{
	m_entry= 0;
	m_next= nullptr;
}

Node::Node(int entry)
{
	m_entry= entry;
	m_next= nullptr;
}

Node::Node(int entry, Node* nextNode)
{
	m_entry= entry;
	m_next= nextNode;
}

Node::~Node()
{
}

void Node::setEntry(int entry)
{
	m_entry= entry;
}

int Node::getEntry() const
{
	return( m_entry );
}

void Node::setNext(Node* nextNode)
{
	m_next= nextNode;
}

Node* Node::getNext() const
{
	return ( m_next );
}

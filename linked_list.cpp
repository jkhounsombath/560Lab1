#include "linked_list.h"

linkedList::linkedList()
{
	m_front= nullptr;
}

linkedList::~linkedList()
{
	Node* temp= nullptr;
	for(int i=0 ; i < getLength() ; i++)
	{
		temp= m_front;
		m_front= m_front->getNext();
		delete temp;
	}
}

bool linkedList::isEmpty()
{
	if (m_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int linkedList::getLength()
{
	int size= 0;
	Node* front= m_front;
	while(front != nullptr)
	{
		size++;
		front= front->getNext();
	}
	return size;
}

void linkedList::insert(int newEntry, int index)
{
	if (index > 0 && index <= getLength()+1)
	{
		Node* temp= nullptr;
		if (index == 1 && getLength() == 0)
		{
			m_front= new Node(newEntry);
		}
		else if(index == 1 && getLength() > 0)
		{
			temp= new Node(newEntry);
			temp->setNext(m_front);
			m_front= temp;
			temp= nullptr;
		}
		else
		{
			Node* prevPtr= m_front;
			for(int i=1; i<index-1; i++)
			{
				prevPtr = prevPtr->getNext();
			}
			temp= new Node(newEntry);
			temp->setNext(prevPtr->getNext());
			prevPtr->setNext(temp);
		}
	}
	else
	{
		throw (std::runtime_error ("Invalid index\n"));
	}
}

void linkedList::remove(int index)
{
	Node* temp= nullptr;
	if (index > 0 && index <= getLength())
	{
		if (index == 1)
		{
			temp= m_front;
			m_front= m_front->getNext();
			delete temp;
		}
		else
		{
			Node* prevPtr= m_front;
			temp= m_front;
			for(int i=1; i<index-1; i++)
			{
				prevPtr= prevPtr->getNext();
			}
			temp= prevPtr->getNext();
			prevPtr->setNext(temp->getNext());
			delete temp;
		}
	}
	else
	{
		throw(std::runtime_error("Invalid index\n"));
	}
}

void linkedList::deleteDuplicates()
{
	int outerIndex= 0;
	int innerIndex= 0;
	Node* front= m_front;
	Node* tempPtr= front->getNext();
	while(front != nullptr)
	{
		tempPtr= front->getNext();
		outerIndex++;
		while(tempPtr != nullptr)
		{
			innerIndex= outerIndex+1;
			if(tempPtr->getEntry() == front->getEntry())
			{
				remove(innerIndex);
			}
		}
	}
}

bool linkedList::find(int value)
{
	Node* front = m_front;
	while(front != nullptr)
	{
		if(front->getEntry() == value)
		{
			front = nullptr;
			return true;
		}
		else
		{
			front= front->getNext();
		}
	}
	return false;
}

void linkedList::FindNext(int value)
{
	Node* front = m_front;
	while(front != nullptr)
	{
		if(front->getEntry() == value)
		{
			if(front->getNext() != nullptr)
			{
				std::cout<<"Here is the next value from " << value << ": " << (front->getNext())->getEntry() << "\n";
			}
			else
			{
				std::cout<<"The value is the last element in the list!\n";
			}
		}
		else
		{
			front= front->getNext();
		}
	}
	std::cout<<"The value is not in the list!\n";
}

void linkedList::print()
{
	Node* front = m_front;
	while(front != nullptr)
	{
		std::cout << "Here is your linked list: ";
		std::cout << front->getEntry() << std::endl;
		front= front->getNext();
	}
}

void linkedList::reverseList()
{
	Node* next= nullptr;
	Node* prev= nullptr;
	Node* curr= m_front;
	while(curr != m_front)
	{
		next= curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = next;
	}
	m_front = prev;
	next= nullptr;
	prev= nullptr;
	curr= nullptr;
}

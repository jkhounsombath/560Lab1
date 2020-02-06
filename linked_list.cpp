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

void linkedList::removeFromList(int value)
{
	if(find(value))
	{
		int target= 0;
		Node* front= m_front;
		for(int i=1; i<=getLength(); i++)
		{
			if(front->getEntry() == value)
			{
				target = i;
			}
			front= front->getNext();
		}
		remove(target);
	}
	else
	{
		std::cout <<"Value is not in the list\n";
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
	Node* front= m_front;
	Node* second= nullptr;
	Node* deleteThis= nullptr;
	while (front != nullptr && front->getNext() != nullptr)
	{
		second = front;
		while (second->getNext() != nullptr)
		{
			if(front->getEntry() == second->getNext()->getEntry())
			{
				deleteThis= second->getNext();
				second->setNext((second->getNext())->getNext());
				delete deleteThis;
			}
			else
			{
				second= second->getNext();
			}
		}
		front= front->getNext();
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
				return;
			}
			else
			{
				std::cout<<"The value is the last element in the list!\n";
				return;
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
	std::cout << "Here is your linked list: ";
	while(front != nullptr)
	{
		std::cout << front->getEntry() << " -> ";
		front= front->getNext();
	}
	std::cout <<"NULL\n";
}

void linkedList::reverseList()
{
	std::cout<<"Here is your reversed list: ";
	reverseHelper(m_front);
	std::cout<<"NULL\n";
}

void linkedList::reverseHelper(Node* front)
{
	if(front != nullptr)
	{
		reverseHelper(front->getNext());
		std::cout<<front->getEntry()<<" -> ";
	}
}

void linkedList::findAt(int index)
{
	if(index <= getLength() && index > 0)
	{
		Node* front= m_front;
		for(int i=2; i<=index; i++)
		{
			front=front->getNext();
		}
		std::cout<<"The node at "<<index<<" is: "<<front->getEntry()<<std::endl;
	}
	else
		std::cout<<"The index is invalid.\n";
}

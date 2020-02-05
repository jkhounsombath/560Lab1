#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "linked_list.h"


class Executive
{
	private:
		linkedList list;
	public:
		Executive();
		~Executive();
		void run();
};
#endif

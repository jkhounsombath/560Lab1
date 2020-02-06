#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include "linked_list.h"


class Executive
{
	private:
		linkedList List;
	public:
		Executive(std::string fileName);
		~Executive();
		void run();
};
#endif

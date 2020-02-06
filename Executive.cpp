#include "Executive.h"

Executive::Executive(std::string fileName)
{
	std::ifstream inFile (fileName);
	int value;
	while(inFile>>value)
	{
		List.insert(value, 1);
	}
}

Executive::~Executive()
{

}

void Executive::run()
{
	int choice;
	do
	{
		
		std::cout <<"Choose one operation from the list below: \n";
		std::cout <<"1. isEmpty()\n" << "2. Length\n" << "3. Insert\n" << "4. Delete\n" << "5. Delete Duplicates\n" << "6. Find\n" << "7. Find Next\n" << "8. Print\n" << "9. Reverse List\n" << "10. Print At\n" << "11. Exit\n";
		std::cin>>choice;
		if(choice < 1 || choice > 11)
		{
			std::cout << "Invalid choice\n";
		}
	}while(choice != 11); 
}

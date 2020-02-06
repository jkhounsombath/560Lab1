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
		std::cout <<"Choice: ";
		std::cin>>choice;
		if(choice == 1)
		{
			std::cout <<"isEmpty() returns: ";
			if(List.isEmpty() == true)
			{
				std::cout<<"True"<<std::endl;
			}
			else
			{
				std::cout<<"False"<<std::endl;
			}
		}
		else if(choice == 2)
		{
			std::cout << "The list is " << List.getLength() << " nodes long\n";
		}
		else if(choice == 3)
		{
			int value = 0;
			std::cout << "Choose a number to be inserted: ";
			std::cin >> value;
			List.insert(value, 1);
			std::cout <<value <<" is inserted.\n";
		}
		else if(choice == 4)
		{
			int value= 0;
			std::cout << "Choose a number to be deleted: ";
			std::cin >> value;
			List.removeFromList(value);
		}
		else if(choice == 5)
		{
			List.deleteDuplicates();
			std::cout <<"Duplicates deleted.\n";
		}
		else if(choice == 6)
		{
			int value;
			std::cout <<"Choose a number to find: ";
			std::cin >>value;
			std::cout<<"Find() for "<<value<<" returns: ";
			if(List.find(value) == true)
			{
				std::cout<<"True"<<std::endl;
			}
			else
			{
				std::cout<<"False"<<std::endl;
			}
		}
		else if(choice == 7)
		{
			int value=0;
			std::cout<<"Enter a value to find its next value: ";
			std::cin>>value;
			List.FindNext(value);
		}
		else if(choice == 8)
		{
			List.print();
		}
		else if(choice == 9)
		{
			List.reverseList();
		}
		else if(choice == 10)
		{
			int value=0;
			std::cout<<"Choose a position to print element: ";
			std::cin>>value;
			List.findAt(value);		
		}
		else if(choice == 11)
		{
			std::cout <<"Goodbye!\n";
		}
		else
		{
			std::cout << "Invalid choice\nChoices are between 1-11 and must be in numeric form\n";
		}
		std::cout <<"-----------------------------------------------\n\n\n";
	}while(choice != 11); 
}

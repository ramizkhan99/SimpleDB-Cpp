#include <iostream>
#include "Author/Author.h"
#include "Author/AuthorDatabase.h"

void ShowMenu()
{
	std::cout << "\n\nComposer Database" << "\n---------------------------------------------\n";
	std::cout << "1) Add a new author\n";
	std::cout << "2) Retrieve an author's data\n";
	std::cout << "3) Promote or demote an author's rank\n";
	std::cout << "4) List all authors\n";
	std::cout << "5) List all authors by rank\n";
	std::cout << "0) Quit\n";
}

int main()
{
	int ch = 0;
	AuthorDatabase authorDB;
	Author* author = new Author();
	do
	{
		ShowMenu();
		std::cout << "> ";
		std::cin >> ch;
		switch ( ch )
		{
			case 1:
			{
				std::cout << "Enter author details:\n";
				std::string firstName, lastName, genre, fact;
				std::cin >> firstName >> lastName >> genre >> fact;
				author = authorDB.AddAuthor(firstName, lastName, genre, fact);
				author->Display();
				std::cout << "Author added successfully!!\n";
				break;
			}
			case 2:
			{
				std::cout << "Enter author's last name: ";
				std::string lastName;
				std::cin >> lastName;
				author = authorDB.GetAuthor(lastName);
				author->Display();
				break;
			}
			case 3:
			{
				std::cout << "1) Promote\n2) Demote\nEnter your choice: ";
				int c;
				std::cin >> c;
				std::cout << "Enter value: ";
				uint16_t value;
				std::cin >> value;
				if ( c == 1 )
				{
					author->Promote(value);
				}
				else if ( c == 2 )
				{
					author->Demote(value);
				}
				else
				{
					std::cout << "Wrong choice!\n";
					continue;
				}
				author->Display();
				break;
			}
			case 4:
			{
				authorDB.DisplayAll();
				break;
			}
			case 5:
			{
				authorDB.DisplayByRank();
				break;
			}
		}
	} while ( ch != 0 );
}

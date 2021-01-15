#pragma once

#include "Author.h"

const int kMaxAuthors = 100;

class AuthorDatabase
{
public:
	/* Constructors and Destructors */
	AuthorDatabase();
	~AuthorDatabase();

	/* Methods */
	// Method to add new author to db
	Author* AddAuthor(const std::string firstName, const std::string lastName,
		const std::string genre, const std::string fact);
	// Method to add author as an object
	void AddAuthor(const Author& author);
	// Method to find author by last name
	Author* GetAuthor(const std::string& lastName);
	// Display all authors
	void DisplayAll();
	// Display authors sorted by rank
	void DisplayByRank();
	// Clear all items in the db
	void ClearAll();

private:
	// Storing authors in an array
	Author m_Authors[kMaxAuthors];
	// Next slot in array
	int m_NextSlot;
};


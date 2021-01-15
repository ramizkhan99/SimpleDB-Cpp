#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Author/Author.h"
#include "Author/AuthorDatabase.h"

class IOManager
{
public:
	/* Constructors and destructors */
	IOManager();
	IOManager(const std::string fileName);
	~IOManager();

	/* Accessors and Mutators */
	void SetFile(const std::string fileName);

	/* Methods */
	// Method to read the entire database into the m_Authors array
	void ReadAll();
	// Method to read the last database entry
	void ReadLast();
	// Write an entry to the database
	void Write(Author& author);
	// Write all entries from m_Authors to the db after clearing it
	void WriteAll();
	// Clear contents of the db
	void ClearDB();

private:
	AuthorDatabase m_AuthorDB;
	std::string m_FilePath;
	std::fstream m_File;
};


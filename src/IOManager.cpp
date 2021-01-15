#include "IOManager.h"

IOManager::IOManager()
{

}

IOManager::IOManager(const std::string fileName)
{
	m_FilePath = fileName;
	m_File.open(m_FilePath, std::ios::in | std::ios::out | std::ios::app);
}

IOManager::~IOManager()
{

}

void IOManager::SetFile(const std::string fileName)
{
	m_FilePath = fileName;
	m_File.open(m_FilePath, std::ios::in | std::ios::out | std::ios::app);
}

void IOManager::ReadAll()
{
	Author author;
	AuthorDatabase authorDB;
	authorDB.ClearAll();
	while ( !m_File.eof() )
	{
		m_File >> author;
		std::cout << author;
		authorDB.AddAuthor(author);
	}
}

void IOManager::ReadLast()
{}

void IOManager::Write(Author& author)
{

}

void IOManager::WriteAll()
{
	ClearDB();
	// Write all to file
}

void IOManager::ClearDB()
{
	m_AuthorDB.ClearAll();
	const int deleteResult = std::remove(m_FilePath.c_str());
	if ( !deleteResult )
	{
		std::cout << "Unable to clear db\n";
	}
	else
	{
		std::cout << "DB cleard successfully\n";
	}
}

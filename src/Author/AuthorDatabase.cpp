#include <vector>
#include <algorithm>
#include "AuthorDatabase.h"
#include "Author.h"

AuthorDatabase::AuthorDatabase() : m_NextSlot(0)
{

}

AuthorDatabase::~AuthorDatabase()
{

}

Author* AuthorDatabase::AddAuthor(const std::string firstName, const std::string lastName, const std::string genre, const std::string fact)
{
	Author author;
	author.SetFirstName(firstName);
	author.SetLastName(lastName);
	author.SetGenre(genre);
	author.SetFact(fact);
	author.SetRank(10);
	m_Authors[m_NextSlot++] = author;
	return &m_Authors[m_NextSlot - 1];
}

void AuthorDatabase::AddAuthor(const Author& author)
{
	m_Authors[m_NextSlot++] = author;
}

Author* AuthorDatabase::GetAuthor(const std::string& lastName)
{
	for ( int i = 0; i <= m_NextSlot; i++ )
	{
		if ( m_Authors[i].GetLastName() == lastName )
		{
			return &m_Authors[i];
		}
	}
	return nullptr;
}

void AuthorDatabase::DisplayAll()
{
	std::cout << "Displaying all Authors..." << '\n';
	for ( int i = 0; i < m_NextSlot; i++ )
	{
		std::cout << m_Authors[i] << '\n';
	}
	std::cout << "----END----" << '\n';
}

void AuthorDatabase::DisplayByRank()
{
	std::vector<Author> authorsByRank(m_Authors, m_Authors + m_NextSlot);
	std::sort(authorsByRank.begin(), authorsByRank.end(),
		[](const Author& a, const Author& b)
		{
			return a.GetRank() > b.GetRank();
		});
	for ( int i = 0; i < m_NextSlot; i++ )
	{
		std::cout << authorsByRank[i];
	}
}

void AuthorDatabase::ClearAll()
{
	m_NextSlot = 0;
}

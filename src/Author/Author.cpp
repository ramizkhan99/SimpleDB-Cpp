#include "Author.h"

Author::Author() : m_Rank(10)
{

}

Author::~Author()
{

}

void Author::SetFirstName(const std::string& firstName)
{
	m_FirstName = firstName;
}

const std::string& Author::GetFirstName() const
{
	return m_FirstName;
}

void Author::SetLastName(const std::string& lastName)
{
	m_LastName = lastName;
}

const std::string& Author::GetLastName() const
{
	return m_LastName;
}

const std::string Author::GetFullName() const
{
	return GetFirstName() + " " + GetLastName();
}

void Author::SetGenre(const std::string& genre)
{
	m_Genre = genre;
}

const std::string& Author::GetGenre() const
{
	return m_Genre;
}

void Author::SetRank(uint16_t rank)
{
	m_Rank = rank;
}

uint16_t Author::GetRank() const
{
	return m_Rank;
}

void Author::SetFact(const std::string& fact)
{
	m_Fact = fact;
}

const std::string& Author::GetFact() const
{
	return m_Fact;
}

void Author::Promote(uint16_t increment)
{
	m_Rank += increment;
}

void Author::Demote(uint16_t decrement)
{
	m_Rank -= decrement;
}

void Author::Display()
{
	std::cout << "Name: " << GetFullName() << "\nGenre: " << GetGenre() << "\nRank: " << GetRank()
		<< "\nFact: " << GetFact() << '\n';
}

std::ostream& operator<<(std::ostream& os, const Author& author)
{
	os << author.GetFullName() << '\t' << author.GetGenre() << '\t' << author.GetRank()
		<< '\t' << author.GetFact() << '\n';
	return os;
}

std::istream& operator>>(std::istream& ins, Author& author)
{
	ins >> author.m_FirstName >> author.m_LastName >> author.m_Genre >> author.m_Fact >> author.m_Rank;
	return ins;
}

#pragma once

#include <iostream>

class Author
{
public:
	/* Constructor & Destructor */
	Author();
	~Author();

	/* Accessors and Mutators */
	void SetFirstName(const std::string& firstName);
	const std::string& GetFirstName() const;
	void SetLastName(const std::string& lastName);
	const std::string& GetLastName() const;
	const std::string GetFullName() const;
	void SetGenre(const std::string& genre);
	const std::string& GetGenre() const;
	void SetRank(uint16_t rank);
	uint16_t GetRank() const;
	void SetFact(const std::string& fact);
	const std::string& GetFact() const;

	/* Operator Overloads */
	friend std::ostream& operator<<(std::ostream& os, const Author& author);
	friend std::istream& operator>>(std::istream& ins, Author& author);

	/* Methods */
	// Method to increase the ranking of the author
	void Promote(uint16_t increment);
	// Method to decrease the ranking of the author
	void Demote(uint16_t decrement);
	// Method to display the author details
	void Display();

private:
	std::string m_FirstName;
	std::string m_LastName;
	std::string m_Genre;
	std::string m_Fact;
	uint16_t m_Rank;
};


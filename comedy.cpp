#include "comedy.h"

Comedy::Comedy(char type, int stock, string director, string title, int year) 
	: Movie(type, stock, director, title, year)
{
	
}

Comedy::~Comedy()
{

}

bool Comedy::operator<(const Comedy& other) const
{
	if (title < other.title)
	{
		return true;
	}
	else if (title == other.title)
	{
		if (year < other.year)
		{
			return true;
		}
	}

	return false;
}

bool Comedy::operator==(const Comedy& other) const
{
	//If the movies are exactly the same
	if (stock == other.stock && director == other.director
		&& title == other.title && year == other.year)
	{
		return true;
	}

	return false;
}
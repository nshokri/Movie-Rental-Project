#include "drama.h"

Drama::Drama(char type, int stock, string director, string title, int year)
	: Movie(type, stock, director, title, year)
{

}

Drama::~Drama()
{

}

bool Drama::operator<(const Drama& other) const
{
	if (director < other.director)
	{
		return true;
	}
	else if (director == other.director)
	{
		if (title < other.title)
		{
			return true;
		}
	}

	return false;
}

bool Drama::operator==(const Drama& other) const
{
	//If the movies are exactly the same
	if (stock == other.stock && director == other.director
		&& title == other.title && year == other.year)
	{
		return true;
	}

	return false;
}
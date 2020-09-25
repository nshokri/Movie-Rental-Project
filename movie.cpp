#include "movie.h"

Movie::Movie(char type, int stock, string director, string title, int year)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
}

Movie::~Movie()
{

}

void Movie::addStock()
{
	stock++;
}

void Movie::removeStock()
{
	stock--;
}

void Movie::print() const
{
	cout << type << ", " << stock << ", " + director + ", " + title + ", " << year;
}

string Movie::getDirector() const
{
	return director;
}

string Movie::getTitle() const
{
	return title;
}

char Movie::getType() const
{
	return type;
}

int Movie::getStock() const
{
	return stock;
}

int Movie::getYear() const
{
	return year;
}

bool Movie::operator<(const Movie& other) const
{
	return true;
}

bool Movie::operator==(const Movie& other) const
{
	//If the movies are exactly the same
	if (stock == other.stock && director == other.director
		&& title == other.title && year == other.year)
	{
		return true;
	}

	return false;
}
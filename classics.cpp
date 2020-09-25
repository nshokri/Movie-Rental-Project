#include "classics.h"

Classics::Classics(char type, int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear)
	: Movie(type, stock, director, title, releaseYear)
{
	this->majorActor = majorActor;
	this->releaseMonth = releaseMonth;
	this->releaseYear = releaseYear;
}

Classics::~Classics()
{

}

void Classics::print() const
{
	cout << type << ", " << stock << ", " + director + ", " + title 
		+ ", " <<	majorActor + " " << releaseMonth << " " << releaseYear;
}

string Classics::getMajorActor() const
{
	return majorActor;
}

int Classics::getYear() const
{
	return releaseYear;
}

int Classics::getMonth() const
{
	return releaseMonth;
}

bool Classics::operator<(const Classics& other) const
{
	if (releaseYear < other.releaseYear)
	{
		return true;
	}
	else if (releaseYear == other.releaseYear && releaseMonth < other.releaseMonth)
	{
		return true;
	}
	else if (releaseYear == other.releaseYear && releaseMonth == other.releaseMonth)
	{
		if (majorActor < other.majorActor)
		{
			return true;
		}
	}

	return false;
}

bool Classics::operator==(const Classics& other) const
{
	//If the movies are exactly the same
	if (stock == other.stock && director == other.director
		&& title == other.title && year == other.year
		&& majorActor == other.majorActor && releaseMonth == other.releaseMonth
		&& releaseYear == other.releaseYear)
	{
		return true;
	}

	return false;
}
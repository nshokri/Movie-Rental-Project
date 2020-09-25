#include "moviefactory.h"

MovieFactory::MovieFactory()
{

}

MovieFactory::~MovieFactory()
{

}

bool MovieFactory::createMovie(Movie*& movie, string line)
{
	size_t currentComma = line.find(",");
	size_t nextComma = line.find(",", currentComma + 1);

	char type = line[0];

	//Adding 2 to the currentComma to skip comma and space
	//Subtract 1 from next comma to remove the comma from the substr

	int stock = stoi(line.substr(currentComma + 2, nextComma - 1));

	currentComma = nextComma;

	nextComma = line.find(",", currentComma + 1);
	
	string director = line.substr(currentComma + 2, nextComma - currentComma - 2);

	currentComma = nextComma;
	nextComma = line.find(",", currentComma + 1);

	string title = line.substr(currentComma + 2, nextComma - currentComma - 2);

	currentComma = nextComma;

	string majorActor;
	int releaseYear;
	int releaseMonth;

	if (type != 'C')
	{
		releaseYear = stoi(line.substr(currentComma + 2));
	}
	else
	{
		//The major actor name has one space to split first and last name
		//the second space is to indicate the end of the name
		size_t findSpace1 = line.find(" ", currentComma + 2);
		size_t findSpace2 = line.find(" ", findSpace1 + 1);

		majorActor = line.substr(currentComma + 2, findSpace2 - currentComma - 2);

		findSpace1 = findSpace2;
		findSpace2 = line.find(" ", findSpace1 + 1);

		releaseMonth = stoi(line.substr(findSpace1 + 1, findSpace2 - currentComma - 2));
		releaseYear = stoi(line.substr(findSpace2 + 1));
	}

	if (type == 'F')
	{
		movie = new Comedy('F', stock, director, title, releaseYear);
		return true;
	}
	else if (type == 'D')
	{
		movie = new Drama('D', stock, director, title, releaseYear);
		return true;
	}
	else if (type == 'C')
	{
		movie = new Classics('C', stock, director, title, majorActor, releaseMonth, releaseYear);
		return true;
	}
	//False input
	else
	{
		movie = NULL;
	}

	return false;
}
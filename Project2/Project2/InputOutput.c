/*
This file is where all of my inputs and outputs are taken care of.
input takes a file and variables from Main and stores a cities statistics inside of it. This is rewritten everytime the while loop iterates.
output takes the current city name, population density, and livability and prints it out.
summary is the report at the end of the program which takes the best city and its livability and prints that out.
Then it takes the number of cities, sum of the livabilities and prints out the average of the cities.
*/

#include "CityRating.h"

//input takes the whole line with the statistics at a time so that way you don't have to go through every item.
int input(FILE* *f1, char *CityName, int *Pop, int *SquareMil, int *PolVal, int *CrimeVal, int *ExpVal, int *NumHighway) {
	return fscanf(f1, "%s %d %d %d %d %d %d", CityName, Pop, SquareMil, PolVal, CrimeVal, ExpVal, NumHighway);
}

//output prints out the statistics calculated at regular intervals to make nice neat columns.
void output(char CityName[20], double PopDens, double Liv) {
	printf("%13s%10s%3.3f%10s%2.3f\n", CityName, "", PopDens, "", Liv);
}

//summary calculates the average livability of the cities. Then it prints out a report stating the best city and it's livability
//along with a number of cities and it's average livability.
void summary(int NumCities, double TotalLiv, double *AvgLiv, double BestLiv, char BestCity[20]) {
	*AvgLiv = TotalLiv / NumCities;
	printf("\n\nBest city:  %s, with a livability of %2.3f\n", BestCity,	BestLiv);
	printf("The %d cities have an average livability of %2.3f\n\n", NumCities, *AvgLiv);
}
/*
Cameron Bradshaw
CSC 362 Programming Assignment 2
This program takes a file from the user and inputs the statistics of a city.
Then the program calls upon functions in a while loop to calculate the population density, pollution value, traffic rating, crime per capita,
expense per capita, and finally it uses those values to calculate the livability for a city. Once it has the livability it calls upon a
function to count the number of cities, adds the livability to a sum, and then decides if the current city has a higher livability than
the cities before it. If it does than it stores that city and it's livability as the best in the list.
Finally once the loop reaches the end of the file it closes the file and calls a summary function which gives a small report on
which city was the best and what it's livability was. It then also reports on the average of the cities livabilities.
*/

#include "CityRating.h"

void main() {
	//These are all the variables I used for the program
	char filename[20], CityName[20], BestCity[20];
	FILE* f1;
	int Population, SquareMileage, PollutionValue, CrimeValue, ExpenseValue, NumHighways, count;
	double PopulationDensity, Pollution, TrafficRating, CrimePer, ExpensePer, Livability, TotalLivability, BestLivability, AvgLivability;
	count = 0;
	TotalLivability = 0;
	AvgLivability = 0;

	//This is where it takes a filename from the user
	printf("Enter the input File: ");
	scanf("%s", filename);
	f1 = fopen(filename, "r");
	printf("\n%9sCity%6sPopulation Dens.%3sLivability\n", "", "", "");

	//this is the while loop which loops until there is nothing left to read in the file. Inside contains the calls for all of the functions except for summary
	while (input(f1, &CityName, &Population, &SquareMileage, &PollutionValue, &CrimeValue, &ExpenseValue, &NumHighways) != EOF) {
		PopulationDensity = ComputePopulationDensity(Population, SquareMileage);
		Compute(PopulationDensity, &Pollution, &TrafficRating, &CrimePer, &ExpensePer, PollutionValue, NumHighways, CrimeValue, ExpenseValue);
		Livability = LivabilityFunc(Pollution, TrafficRating, CrimePer, ExpensePer);
		output(CityName, PopulationDensity, Livability);
		update(CityName, &BestCity, &count, Livability, &TotalLivability, &BestLivability);
	}
	
	//close the file
	fclose(f1);

	//This is the call function for summary which writes the final report
	summary(count, TotalLivability, &AvgLivability, BestLivability, BestCity);
}
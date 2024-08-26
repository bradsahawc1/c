/*
The Computations file is the one that contains all of my functions that calculate the statistics.
ComputePopulationDensity well computes the population density using the population of the city and it's square mileage.
Compute is a function that computes 4 things:
   Pollution
   Traffic Rating
   Crime per Capita
   Expense per Capita
LivabilityFunc is a function that computes the livability of a city.
update is a function which counts the number of cities, sums the total of the livabilities, and then it also tests to see if the current city has a higher livability than the current best
if the current city is better then it updates the best city and best livability with the current city and it's livability.
*/

#include "CityRating.h"

//had to cast population and square mileage to doubles since they were both integers.
double ComputePopulationDensity(int pop, int sqmil) {
	return (double)pop / (double)sqmil;
}

void Compute(double PopDens, double *Poll, double *TraffRat, double *CrimePer, double *ExpensePer, int PollVal, int NumHigh, int CrimeVal, int ExpVal) {
	*Poll = (PollVal * PopDens) / PollutionCon;   //multiplies the pollution value and population density and then divides that by a constant which was defined in the header.
	*TraffRat = (PopDens * TrafficCon) / NumHigh;   //multiplies the pollution value and a constant which was defined in the header and then divides it by the number of highways.
	*CrimePer = (CrimeVal * PopDens) / CrimeCon;   //multiplies the crime value and population density and then divides that by a constant which was defined in the header.
	*ExpensePer = (ExpVal * PopDens) / ExpenseCon;   //multiplies the expense value and population density and then divides that by a constant which was defined in the header.
}

//add together the results from ComputePopulationDensity and Compute and then divides it by the constant defined in the header. Once it does that it subtracts it from 100.
double LivabilityFunc(double Poll, double TraffRat, double CrimePer, double ExpensePer) {
	return 100 - (Poll + TraffRat + CrimePer + ExpensePer) / LivabilityCon;
}

//it tests for which city is better by testing if the current livability is greater than the best livability, if so then it updates the best if not then nothing happens.
void update(char CurrentCity[20], char *BestCity[20], int *count, double Liv, double *TotalLiv, double *HighLiv) {
	*count += 1;
	*TotalLiv += Liv;
	if (Liv > * HighLiv) {
		strcpy(BestCity, CurrentCity);
		*HighLiv = Liv;
	}
}
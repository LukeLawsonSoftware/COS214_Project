#include "LandUnit.h"
// #include "Soldier.h"
LandUnit::LandUnit(int powerRating) : Soldier(powerRating)
{
}

int LandUnit::calculateAirOffense()
{
	return 0;
}
int LandUnit::calculateAirDefense()
{
	return 0;
}
int LandUnit::calculateSeaOffense()
{
	return 0;
}
int LandUnit::calculateSeaDefense()
{
	return 0;
}
int LandUnit::calculateLandOffense()
{
	int mean = this->trainingLevel * 10;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int LandUnit::calculateLandDefense()
{
	int mean = this->trainingLevel * 5;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
#include "AirUnit.h"

AirUnit::AirUnit(int powerRating) : Soldier(powerRating)
{
}

int AirUnit::calculateAirOffense()
{
	int mean = this->trainingLevel * 10;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirUnit::calculateAirDefense()
{
	int mean = this->trainingLevel * 5;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirUnit::calculateSeaOffense()
{
	return 0;
}
int AirUnit::calculateSeaDefense()
{
	return 0;
}
int AirUnit::calculateLandOffense()
{
	int mean = this->trainingLevel * 8;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirUnit::calculateLandDefense()
{
	return 0;
}

#include "SeaUnit.h"

SeaUnit::SeaUnit(int powerRating) : Soldier(powerRating)
{
}
int SeaUnit::calculateAirOffense()
{
	return 0;
}
int SeaUnit::calculateAirDefense()
{
	return 0;
}
int SeaUnit::calculateSeaOffense()
{
	int mean = this->trainingLevel * 10;
	double stdDev = sqrt(mean);

	static int seeder = 1235;
	seeder += 8;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int SeaUnit::calculateSeaDefense()
{
	int mean = this->trainingLevel * 5;
	double stdDev = sqrt(mean);

	static int seeder = 996;
	seeder += 80085;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int SeaUnit::calculateLandOffense()
{
	return 0;
}
int SeaUnit::calculateLandDefense()
{
	return 0;
}

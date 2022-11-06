#include "SeaVehicle.h"

SeaVehicle::SeaVehicle(int powerRating) : Vehicle(powerRating)
{
}

int SeaVehicle::calculateAirOffense()
{
	int mean = this->weaponClass * 5;
	double stdDev = sqrt(mean);

	static int seeder = 58008;
	seeder += 800;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int SeaVehicle::calculateAirDefense()
{
	return 0;
}
int SeaVehicle::calculateSeaOffense()
{
	int mean = this->weaponClass * 20;
	double stdDev = sqrt(mean);

	static int seeder = 1237;
	seeder += 8628;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int SeaVehicle::calculateSeaDefense()
{
	int mean = this->armourRating * 20;
	double stdDev = sqrt(mean);

	static int seeder = 2735;
	seeder += 8748;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int SeaVehicle::calculateLandOffense()
{
	return 0;
}
int SeaVehicle::calculateLandDefense()
{
	return 0;
}
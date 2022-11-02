#include "LandVehicle.h"
// #include "Vehicle.h"

LandVehicle::LandVehicle(int powerRating) : Vehicle(powerRating)
{
}

int LandVehicle::calculateAirOffense()
{
	return 0;
}
int LandVehicle::calculateAirDefense()
{
	int mean = this->armourRating;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int LandVehicle::calculateSeaOffense()
{
	return 0;
}
int LandVehicle::calculateSeaDefense()
{
	return 0;
}
int LandVehicle::calculateLandOffense()
{
	int mean = this->weaponClass * 15;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int LandVehicle::calculateLandDefense()
{
	int mean = this->armourRating * 25;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}

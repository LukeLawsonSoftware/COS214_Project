#include "AirVehicle.h"
// #include "Vehicle.h"

AirVehicle::AirVehicle(int powerRating) : Vehicle(powerRating)
{
}

int AirVehicle::calculateAirOffense()
{
	int mean = this->weaponClass * 20;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateAirDefense()
{
	int mean = this->armourRating * 8;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateSeaOffense()
{
	int mean = this->weaponClass * 15;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateSeaDefense()
{
	return 0;
}
int AirVehicle::calculateLandOffense()
{
	int mean = this->weaponClass * 8;
	double stdDev = sqrt(mean);

	srand(time(0)); // random seed
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateLandDefense()
{
	return 0;
}

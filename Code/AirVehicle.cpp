#include "AirVehicle.h"
// #include "Vehicle.h"

AirVehicle::AirVehicle(int powerRating) : Vehicle(powerRating)
{
}

int AirVehicle::calculateAirOffense()
{
	int mean = this->weaponClass * 20;
	double stdDev = sqrt(mean);

	static int seeder = 12121212;
	seeder += 121314;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateAirDefense()
{
	int mean = this->armourRating * 8;
	double stdDev = sqrt(mean);

	static int seeder = 333;
	seeder += 123456789;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateSeaOffense()
{
	int mean = this->weaponClass * 15;
	double stdDev = sqrt(mean);

	static int seeder = 535344;
	seeder += 123;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
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

	static int seeder = 7937490;
	seeder += 77727272;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	float u1 = (float)rand() / (float)RAND_MAX;
	float u2 = (float)rand() / (float)RAND_MAX;
	double randNorm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller Transformation
	return (int)(randNorm * stdDev + mean);					   // uses z-score formula to adjustment to non-standard normal dist.
}
int AirVehicle::calculateLandDefense()
{
	return 0;
}

#ifndef BATTLESTATISTICS_H
#define BATTLESTATISTICS_H

class BattleStatistics
{
	friend class Defensive;
	friend class Neutral;
	friend class Offensive;

private:
	int airAttack;
	int airDefence;
	int landAttack;
	int landDefence;
	int seaAttack;
	int seaDefence;
	int morale;
	int availableAmmo;
	int medical;

public:
	int getAirAttack();
	int getAirDefence();
	int getLandAttack();
	int getLandDefence();
	int getSeaAttack();
	int getSeaDefence();
	int getMorale();
	int getAvailableAmmo();
	int getMedical();

	void setAirAttack(int in);
	void setAirDefence(int in);
	void setLandAttack(int in);
	void setLandDefence(int in);
	void setSeaAttack(int in);
	void setSeaDefence(int in);
	void setMorale(int in);
	void setAvailableAmmo(int in);
	void setMedical(int in);
};

#endif

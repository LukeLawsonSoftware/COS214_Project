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
};

#endif

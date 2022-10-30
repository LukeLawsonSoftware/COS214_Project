#ifndef ECONOMICSTATE_H
#define ECONOMICSTATE_H

class EconomicState
{

public:
	virtual int decideMyTurn() = 0;
	// This method needs to return an int corresponding with the decision
	//  Some general rules for making decisions:
	//   Once you are in an alliance, you cannot use formAlliance. This is only for making neutral countries join an alliance
	//   If you already have an army, the code will not allow you to create another one so you can only deicde this if army is null
	//  You can only enterArmyIntoTheatre, attackTransport, or change army strategy if you alreayd have an army
	//  You can only send supplies if you have an army
};

#endif

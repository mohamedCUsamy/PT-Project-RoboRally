#pragma once
#include "GameObject.h"

class Belt : public GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the belt's "Start Cell Position"
	Output* pOut;// needed akid
	CellPosition endCellPos; // here is the belt's End Cell Position
public:


	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	virtual ~Belt();
};

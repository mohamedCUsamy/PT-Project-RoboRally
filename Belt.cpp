#include "Belt.h"

Belt::Belt(const CellPosition &startCellPos, const CellPosition &endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	/// TODO: Do the needed validation
}
void Belt::Draw(Output *pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a belt.Click to continue ...: ");
	pIn->GetCellClicked();

	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	// 
	//	pGrid->AddObjectToCell();              // no need for this 
	//	pGrid->RemoveObjectFromCell(position); // no need neither this
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}

Belt::~Belt()
{
}

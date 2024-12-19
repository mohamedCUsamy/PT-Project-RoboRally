#include "Cell.h"
#include "Flag.h"
#include "Grid.h"
#include "GameObject.h"
#include "Belt.h"
#include "WaterPit.h"
#include "DangerZone.h"


Flag * Cell::HasFlag() const
{

	///TODO: Implement the following function like HasBelt() function
	//done
	return dynamic_cast<Flag*>(pGameObject); // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION

}
WaterPit* Cell::HasWaterPit() const
{

	///TODO: Implement the following function like HasBelt() function
	//done
	return dynamic_cast<WaterPit*>(pGameObject); // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION

}

DangerZone* Cell::HasDangerZone() const
{
	///TODO: Implement the following function like HasBelt() function
	//done
	return dynamic_cast<DangerZone*>(pGameObject);; // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION
}

void Cell::DrawCellOrWaterPitOrDangerZone(Output * pOut) const
{
pOut->DrawCell(position, UI.CellColor); // draw empty cell 
}


//TODO
// separate from the above function 
//because other game objects should be drawn AFTER All Cells are drawn
//because other game objects don't change color of the cell
void Cell::DrawGameObject(Output* pOut) const
{
	////////TODO: edit this incomplete implemntation to check for other game objects (excluding waterpits and dangerzones)
	if ((HasFlag() || HasBelt()) && (!HasDangerZone() && !HasWaterPit()))
		pGameObject->Draw(pOut); // draw game object
	else
		pOut->DrawCell(position, UI.CellColor);
}
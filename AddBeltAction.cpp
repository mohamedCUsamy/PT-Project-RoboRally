#include "AddBeltAction.h"

AddBeltAction::AddBeltAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddBeltAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Belt: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Belt: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (  (startPos.GetCellNum() != endPos.GetCellNum())   &&    ((startPos.IsValidCell() && endPos.IsValidCell()))   &&    ( (startPos.VCell() == endPos.VCell())||(startPos.HCell() == endPos.HCell()) )   )
	{
		string toprint = "Belt set from start from cell " + to_string(startPos.GetCellNum()) + " and the end cell is " + to_string(endPos.GetCellNum());
		pOut->PrintMessage(toprint);
		pIn->GetCellClicked();

	}
	else {
		pOut->PrintMessage("Invalid position for belt ");
		pIn->GetCellClicked();
	}
		//done
	//same cell condition working
	// pressing not on a cell is working
	// horizontall working
	//want to check their is an object or not in all cells

	
	// Clear messages
	pOut->ClearStatusBar();
}

void AddBeltAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();

	// Create a belt object with the parameters read from the user
	Belt *pBelt = new Belt(startPos, endPos);

	Grid *pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	bool added = pGrid->AddObjectToCell(pBelt);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction
}

AddBeltAction::~AddBeltAction()
{
}

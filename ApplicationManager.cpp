#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "AddDangerZoneAction.h"
#include "AddWaterPitAction.h"
#include "AddWorkshopAction.h"
#include "AddAntennaAction.h"

/// TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid *ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case Add_Belt:
		pAct = new AddBeltAction(this);
		break;

	case Add_Rotating_Gear:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case Add_Flag:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:				   // TODO:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case TO_DESIGN_MODE:				 // TODO:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

		/// TODO: Add a case for EACH Action type in the Design mode or Play mode
	case Add_Danger_Zone:
		pAct = new AddDangerZoneAction(this);
		break;
	case Add_Water_Pit:
		pAct = new AddWaterPitAction(this);
		break;
	case Add_Workshop:
		pAct = new AddWorkshopAction(this);
		break;
	case Add_Antenna:
		pAct = new AddAntennaAction(this);
		break;

	case STATUS: // a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}

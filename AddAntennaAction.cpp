#include "AddAntennaAction.h"
#include "Antenna.h"

AddAntennaAction::AddAntennaAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddAntennaAction::ReadActionParameters()
{
    Input *pIn = pManager->GetGrid()->GetInput();
    Output *pOut = pManager->GetGrid()->GetOutput();

    pOut->PrintMessage("New Antenna: Click on its Cell ...");
    Pos = pIn->GetCellClicked();

    if (!Pos.IsValidCell())
    {
        pOut->PrintMessage("Invalid parameters! Please try again.");
        return;
    }
    pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
    ReadActionParameters();

    Antenna *pAntenna = new Antenna(Pos);

    Grid *pGrid = pManager->GetGrid();
    if (pGrid->CountGameObject(pAntenna) > 0)
    {
        pGrid->PrintErrorMessage("Error: Game already has an antenna!");
        return;
    }
    Output *pOut = pGrid->GetOutput();

    bool added = pGrid->AddObjectToCell(pAntenna);

    if (!added)
    {
        pOut->PrintMessage("Error: Cell already has an object!");
    }
}

AddAntennaAction::~AddAntennaAction()
{
}
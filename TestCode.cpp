#include "Input.h"
#include "Output.h"

// This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	// Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	// Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:
	//			- Create The FULL Tool bar of Design Mode, the grid area, the status bar
	//				and an empty command bar
	//			- This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid, Status bar and Empty Command bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 1.1- Drawing the Command bar in the Game mode
	// =============================================
	pOut->PrintMessage("1.1- Drawing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click
	{
		Command savedCommands[5];
		for (int i = 0; i < 5; i++)
			savedCommands[i] = NO_COMMAND;
		Command availableCommands[10];
		for (int i = 0; i < 10; i++)
			availableCommands[i] = MOVE_FORWARD_ONE_STEP;
		pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 10);
	}
	pOut->PrintMessage("1.1.1- Finished Drawing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.2- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// DONE: Draw the command bar with only 4 available commands and 4 empty slots for saved commands
	// DONE NADY
	{
		Command savedCommands[4];
		for (int i = 0; i < 4; i++)
			savedCommands[i] = NO_COMMAND;
		Command availableCommands[4];
		for (int i = 0; i < 4; i++)
			availableCommands[i] = MOVE_FORWARD_ONE_STEP;
		pOut->CreateCommandsBar(savedCommands, 4, availableCommands, 4);
	}
	pOut->PrintMessage("1.1.2- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.3- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// DONE: Draw the command bar with 5 saved commands and 7 available commands,
	///  	but the first saved command will be MOVE_FORWARD_ONE_STEP
	///		and the first available command will be NO_COMMAND
	// DONE NADY
	{
		Command savedCommands[5];
		savedCommands[0] = MOVE_FORWARD_ONE_STEP;
		for (int i = 1; i < 5; i++)
			savedCommands[i] = NO_COMMAND;
		Command availableCommands[7];
		availableCommands[0] = NO_COMMAND;
		for (int i = 1; i < 7; i++)
			availableCommands[i] = MOVE_FORWARD_ONE_STEP;
		pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 7);
	}

	pOut->PrintMessage("1.1.3- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.4- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TODO: Draw the command bar with 5 saved commands and 6 available commands,
	///  	but the first saved command will be MOVE_FORWARD_TWO_STEPS
	///		and the first available command will be NO_COMMAND as previous test

	{
		Command savedCommands[5];
		savedCommands[0] = MOVE_FORWARD_TWO_STEPS;
		for (int i = 1; i < 5; i++)
			savedCommands[i] = NO_COMMAND;
		Command availableCommands[6];
		availableCommands[0] = NO_COMMAND;
		for (int i = 1; i < 6; i++)
			availableCommands[i] = MOVE_FORWARD_ONE_STEP;
		pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 6);
	}

	pOut->PrintMessage("1.1.4- Finished Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.1- Drawing Water Pits Cells //
	// =============================

	pOut->PrintMessage("2.1- Drawing (Water Pits Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_10(10); // cell num 10
	CellPosition cell_53(53); // cell num 53
	CellPosition cell_1(1);	  // cell num 1

	// TODO: Draw Water Pits in cell_10 and cell_53 and cell_1 (Invalid)

	pOut->DrawWaterPit(cell_1);
	pOut->DrawWaterPit(cell_10);
	pOut->DrawWaterPit(cell_53);

	pOut->PrintMessage("FINISHED - Drawing (Water Pits) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.2- Drawing DangerZone Cells //
	// =============================
	pOut->PrintMessage("2.2- Drawing (DangerZone Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_20(20); // cell num 20
	CellPosition cell_60(60); // cell num 60

	pOut->DrawDangerZone(cell_20);
	pOut->DrawDangerZone(cell_60);

	// TODO: Draw DangerZone in cell_20, [cell_60 and cell_1] (Invalid)

	pOut->PrintMessage("FINISHED - Drawing (DangerZone) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.3- Drawing Players Test //
	// =========================
	pOut->PrintMessage("2.3- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition player_1(1);
	CellPosition player_2(2);
	CellPosition player_15(2, 18);
	CellPosition player_99(2, 5);

	/// DONE: Call Function DrawPlayer of Class Ouput Multiple Times
	///        to draw the following players:
	///        playerNum (0) with color (PlayerColors[0] defined in UI object)
	///			in cell position (player_1 declared above) pointing to right direction
	pOut->DrawPlayer(player_1, 0, UI.PlayerColors[0], RIGHT);
	///        playerNum (1) with color (PlayerColors[1] defined in UI object)
	///			in cell position (player_1 declared above) pointing to the up direction
	pOut->DrawPlayer(player_1, 1, UI.PlayerColors[1], UP);
	///        playerNum (2) with color (PlayerColors[2] defined in UI object)
	///			in cell position (player_1 declared above) pointing to the down direction --> Invalid
	pOut->DrawPlayer(player_1, 2, UI.PlayerColors[2], DOWN);
	///        playerNum (3) with color (PlayerColors[3] defined in UI object)
	///			in cell position (player_1 declared above) pointing to the left direction --> Invalid
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[3], LEFT);
	///        playerNum (0) with color (PlayerColors[0] defined in UI object)
	///			in cell position (player_15 declared above) pointing to the left direction --> Invalid
	pOut->DrawPlayer(player_15, 0, UI.PlayerColors[0], LEFT);
	///        playerNum (1) with color (PlayerColors[1] defined in UI object)
	///			in cell position (player_99 declared above) pointing up
	pOut->DrawPlayer(player_99, 1, UI.PlayerColors[1], UP);
	///        playerNum (5) with color (PlayerColors[1] defined in UI object)
	///			in cell position (player_99 declared above) pointing down--> Invalid
	pOut->DrawPlayer(player_99, 5, UI.PlayerColors[1], DOWN);
	///        playerNum (-1) with color (PlayerColors[1] defined in UI object)
	///			in cell position (player_99 declared above) pointing left--> Invalid
	pOut->DrawPlayer(player_99, -1, UI.PlayerColors[1], LEFT);

	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 2.4- Drawing Flags
	/// ====================
	///
	pOut->PrintMessage("2.4- Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition flag_1(9);
	CellPosition flag_60(60);
	CellPosition flag_99(99);

	// DONE: Draw Flags in cell positions (flag_1, flag_60, flag_99)
	pOut->DrawFlag(flag_1);
	pOut->DrawFlag(flag_60);
	pOut->DrawFlag(flag_99);

	pOut->PrintMessage("FINISHED - Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 2.5- Drawing Belts
	/// ====================
	///
	pOut->PrintMessage("2.5- Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition belt_start_1(1);
	CellPosition belt_end_1(5);
	CellPosition belt_start_2(12);
	CellPosition belt_end_2(45);
	CellPosition belt_start_3(54);
	CellPosition belt_end_3(32);
	CellPosition belt_end_4(33);

	// DONE: Draw 5 belts
	//		1- from belt_start_1 to belt_end_1
	pOut->DrawBelt(belt_start_1, belt_end_1);
	// 2- from belt_start_2 to belt_end_2
	pOut->DrawBelt(belt_start_2, belt_end_2);
	// 3- from belt_start_3 to belt_end_3
	pOut->DrawBelt(belt_start_3, belt_end_3);
	// 4- from belt_start_3 to belt_end_4 --> Invalid
	pOut->DrawBelt(belt_start_3, belt_end_4);
	// 5- from belt_end_1 to belt_end_2 --> Invalid
	pOut->DrawBelt(belt_end_1, belt_end_2);
	// 6- from belt_end_3 to belt_end_4 --> Invalid
	pOut->DrawBelt(belt_end_3, belt_end_4);

	pOut->PrintMessage("FINISHED - Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.6- Drawing Rotating Gears //
	// ===========================

	pOut->PrintMessage("2.6- Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_13(13);
	CellPosition cell_19(19);

	// DONE: Draw Rotating Gears in cell positions (cell_13, cell_19)
	//        1. At cell_13 with rotation left (anticlockwise)
	pOut->DrawRotatingGear(cell_13, false);
	//        2. At cell_19 with rotation right (clockwise)
	pOut->DrawRotatingGear(cell_19, true);

	pOut->PrintMessage("FINISHED - Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.7- Drawing Antenna //
	// ======================
	pOut->PrintMessage("2.7- Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_25(25);

	// DONE: Draw Antenna in cell position (cell_25)
	pOut->DrawAntenna(cell_25);

	pOut->PrintMessage("FINISHED - Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.8- Drawing Workshop //
	// =======================

	pOut->PrintMessage("2.8- Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_30(30);

	// DONE: Draw Workshop in cell position (cell_30)
	pOut->DrawWorkshop(cell_30);

	pOut->PrintMessage("FINISHED - Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3:
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	/// TODO: Add code here to
	// 1- Call GetInteger Function and receive its returned integer
	// 2- Print it in the status bar in this format:   You Entered: 116
	//    (assuming the entered number is 116)
	// 3- Call GetPointClicked() function
	int returnedinteger = pIn->GetInteger(pOut);
	if (returnedinteger != -95469)
		pOut->PrintMessage("You Entered: " + to_string(returnedinteger));
	else
		pOut->PrintMessage("Didn't enter an integer.");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TODO: Add code here to
	// 1- Call function GetCellClicked
	// 2- Print on the status bar the vCell and hCell of the clicked cell
	// 3- Repeat Step 1 and 2 five times
	pOut->PrintMessage(" Click on 5 cells. ");
	for (int i = 0; i < 5; i++)
	{
		CellPosition clickedCell = pIn->GetCellClicked();
		pOut->PrintMessage("You clicked cell at vCell: " + to_string(clickedCell.VCell()) + ", hCell: " + to_string(clickedCell.HCell()));
	}

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TODO: Add code here to
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	// NOTE: GetString() is already implemented. It is just required from you to call it

	pOut->PrintMessage("Please enter a string: ");
	string userInput = pIn->GetSrting((pOut));
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered: " + userInput);
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("FINISHED - (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cellpos_1(0, 0);

	for (int i = 0; i < 5; i++)
	{

		// Ask the user for vCell input
		pOut->PrintMessage("Enter an integer vertical vCell = ");
		// int integerv = -1;
		int integerv = pIn->GetInteger(pOut);
		// Set vCell and display the result
		if (integerv != -95469)
		{
			if (cellpos_1.SetVCell(integerv) && cellpos_1.IsValidCell())
			{
				string toprintV = "Now the vCell = " + to_string(cellpos_1.VCell());
				pOut->PrintMessage(toprintV);
			}
			else
				pOut->PrintMessage("Invalid vCell number");
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	for (int i = 0; i < 5; i++)
	{
		// Set hCell and display the result
		pOut->PrintMessage("Enter an integer horizontal hCell  : ");
		int integerh = -1;
		integerh = pIn->GetInteger(pOut);
		// Ask the user for hCell input
		if (integerh != -95469)
		{
			if (cellpos_1.SetHCell(integerh) && cellpos_1.IsValidCell())
			{
				string toprintH = "Now the hCell = " + to_string(cellpos_1.HCell());
				pOut->PrintMessage(toprintH);
			}
			else
				pOut->PrintMessage("Invalid hCell number");
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		// Call GetPointClicked() if needed
		pIn->GetPointClicked(x, y); // Uncomment if you want to capture a point click event
	}
	// Done

	// After repeating the process, the user will have interacted with both the vCell and hCell values 5 times.

	///  TODO:
	// 1-  Ask user to enter an integer and read it using GetInteger()
	// 2-  Call SetVCell() of cellpos_1 with that integer
	// 3-  Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5)
	// 4-  Call GetPointClicked()
	// 5-  Repeat the above steps FIVE TIMES
	// 6-  Repeat all the above steps to test SetHCell() function instead with the needed modifications
	// DONE SAMY

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter an integer vCell: ");
		int pos1 = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter an integer hCell: ");
		int pos2 = pIn->GetInteger(pOut);
		CellPosition p1(pos1, pos2);
		if (pos1 != -95469 || pos2 != -95469)
		{

			if (p1.IsValidCell())
			{
				string toprint = "The CellNumber is " + to_string(p1.GetCellNum());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell
	// 2- Creates a CellPosition object of them
	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it)
	// 4- Print the Cell Number on the status bar
	// 5- Repeat the above steps Five TIMES
	// DONE SAMY
	//
	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter an integer number: ");
		int integer1 = -1;
		integer1 = pIn->GetInteger(pOut);
		CellPosition c1(integer1);
		if (integer1 != -95469)
		{

			if (c1.IsValidCell())
			{
				string toprint = "The vCell is " + to_string(c1.VCell()) + " and the hCell is " + to_string(c1.HCell());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	/// TODO: ||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// 1- Read from user one integer representing cellNum
	// 2- Creates a CellPosition object of that integer using that constructor:
	//		CellPosition (int cellNum);
	//			--> it uses the function : GetCellPositionFromNum () inside it
	// 4- Print the Cell vCell and hCell on the status bar
	// 5- Repeat the above steps Five TIMES
	// DONE SAMY

	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.4- (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TODO:
	// 1- Read from user two integers representing cellNum and addedNum
	// 2- Creates a CellPosition object of cellNum
	// 3- Use the function AddCellNum() to add the addedNum to the cellNum
	// 4- Print the vCell and hCell of the new Cell Position on the status bar
	// 5- Repeat the above steps Four TIMES with each time a different direction
	// DONE SAMY
	//*/
	// First direction right
	{
		pOut->PrintMessage("Enter cell number: ");
		int CellNum = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter added number RIGHT: ");
		int addNum = pIn->GetInteger(pOut);
		CellPosition c1(CellNum);
		c1.AddCellNum(addNum, RIGHT);
		if (CellNum != -95469 && addNum != -95469)
		{

			if (c1.IsValidCell())
			{
				string toprint = "The vCell is " + to_string(c1.VCell()) + " and the hCell is " + to_string(c1.HCell()) + " and the new cell Number is " + to_string(c1.GetCellNum());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	// second direction left
	{
		pOut->PrintMessage("Enter cell number: ");
		int CellNum = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter added number LEFT: ");
		int addNum = pIn->GetInteger(pOut);
		CellPosition c1(CellNum);
		c1.AddCellNum(addNum, LEFT);

		if (CellNum != -95469 && addNum != -95469)
		{

			if (c1.IsValidCell())
			{
				string toprint = "The vCell is " + to_string(c1.VCell()) + " and the hCell is " + to_string(c1.HCell()) + " and the new cell Number is " + to_string(c1.GetCellNum());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	// third direction up
	{
		pOut->PrintMessage("Enter cell number: ");
		int CellNum = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter added number UP: ");
		int addNum = pIn->GetInteger(pOut);
		CellPosition c1(CellNum);
		c1.AddCellNum(addNum, UP);

		if (CellNum != -95469 && addNum != -95469)
		{

			if (c1.IsValidCell())
			{
				string toprint = "The vCell is " + to_string(c1.VCell()) + " and the hCell is " + to_string(c1.HCell()) + " and the new cell Number is " + to_string(c1.GetCellNum());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	// fourth direction down
	{
		pOut->PrintMessage("Enter cell number: ");
		int CellNum = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter added number DOWN: ");
		int addNum = pIn->GetInteger(pOut);
		CellPosition c1(CellNum);
		c1.AddCellNum(addNum, DOWN);

		if (CellNum != -95469 && addNum != -95469)
		{

			if (c1.IsValidCell())
			{
				string toprint = "The vCell is " + to_string(c1.VCell()) + " and the hCell is " + to_string(c1.HCell()) + " and the new cell Number is " + to_string(c1.GetCellNum());
				pOut->PrintMessage(toprint);
			}
			else
			{
				pOut->PrintMessage("The is an invalid cell");
			}
		}
		else
			pOut->PrintMessage("Didn't enter an integer.");

		pIn->GetPointClicked(x, y); // Wait for any click
	}

	pOut->PrintMessage("FINISHED - (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5:
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	/// TODO:
	// You must add a case for EACH action (both Design mode and Game mode actions)
	// Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		int clickedCommandItemIndex; // if the action is SELECT_COMMAND, this will have the icon index
		switch (ActType)
		{
		case SET_FLAG_CELL:
			pOut->PrintMessage("Action: SET_FLAG_CELL , Click anywhere");
			break;

		case EXIT:
			break;

		case TO_PLAY_MODE:

			pOut->PrintMessage("Action: TO_PLAY_MODE , Click anywhere");
			pOut->CreatePlayModeToolBar();

			/// TODO:  Call Function (PrintPlayersInfo) of Class Output with a string similar to
			//        the one given in the screenshot of project document

			break;

		case Add_Antenna:
			pOut->PrintMessage("Action: Add Antenna,");
			break;

		case Add_Flag:
			pOut->PrintMessage("Action: Add_Flag , Click anywhere");
			break;
		case Add_Belt:
			pOut->PrintMessage("Action: Add_Belt , Click anywhere");
			break;
		case Add_Water_Pit:
			pOut->PrintMessage("Action: Add_Water_Pit , Click anywhere");
			break;
		case Add_Danger_Zone:
			pOut->PrintMessage("Action: Add_Danger_Zone , Click anywhere");
			break;
		case Add_Workshop:
			pOut->PrintMessage("Action: Add_Workshop , Click anywhere");
			break;
		case Add_Rotating_Gear:
			pOut->PrintMessage("Action: Add_Rotating_Gear , Click anywhere");
			break;
		case Copy_Game_Object:
			pOut->PrintMessage("Action: Copy_Game_Object , Click anywhere");
			break;
		case Cut_Game_Object:
			pOut->PrintMessage("Action: Cut_Game_Object , Click anywhere");
			break;
		case Paste_Game_Object:
			pOut->PrintMessage("Action: Paste_Game_Object , Click anywhere");
			break;
		case Delete_Game_Object:
			pOut->PrintMessage("Action: Delete_Game_Object , Click anywhere");
			break;
		case Save_Grid:
			pOut->PrintMessage("Action: Save_Grid , Click anywhere");
			break;
		case Load_OR_Open_Grid:
			pOut->PrintMessage("Action: Load_OR_Open_Grid , Click anywhere");
			break;

		case EXECUTE_COMMANDS:
			pOut->PrintMessage("Action: EXECUTE_COMMAND , Click anywhere");
			break;
		case SELECT_COMMAND:
			pOut->PrintMessage("Action: SELECT_COMMAND , Select a command");
			clickedCommandItemIndex = pIn->GetSelectedCommandIndex();
			pOut->PrintMessage("Action: SELECT_COMMAND " + to_string(clickedCommandItemIndex) + " , Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: EMPTY , Click anywhere");
			break;

		case GRID_AREA:
			pOut->PrintMessage("Action: GRID_AREA , Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: STATUS , Click anywhere");
			break;

		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
			pOut->CreateDesignModeToolBar();
			break;

		case Select_Movement_Commands:
			pOut->PrintMessage("Action: Select_Movement_Commands , Click anywhere");
			break;
		case Execute_Saved_Commands:
			pOut->PrintMessage("Action: Execute_Saved_Commands , Click anywhere");
			break;
		case Reboot_and_Repair:
			pOut->PrintMessage("Action: Reboot_and_Repair , Click anywhere");
			break;
		case Use_Consumable:
			pOut->PrintMessage("Action: Use_Consumable , Click anywhere");
			break;
		case New_Game:
			pOut->PrintMessage("Action: New_Game , Click anywhere");
			break;
		}
	} while (ActType != EXIT);

	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);

	delete pIn;
	delete pOut;
	return 0;
}

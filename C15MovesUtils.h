int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	char l;
	while (1)
	{
		scanf("%c", &l);
		if (isValidInput(l))
			break;
	}
	return l;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter)
{
	char ch = letter;
	if (ch =='W' || ch == 'A' || ch == 'a' || ch=='s' || ch=='S' || ch=='d' || ch=='D'|| ch=='w')
		return 1;
	else
	    return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{

	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	int t;
	if (inputChar == 'a' || inputChar == 'A')
		t=goLeft(board);
	else if (inputChar == 'w' || inputChar == 'W')
		t=goUp(board);
	else if (inputChar == 'S' || inputChar == 's')
		t=goDown(board);
	else if (inputChar == 'D' || inputChar == 'd')
		t=goRight(board);
	else
		t = 0;
	return t;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	//printf("Play move not implemented yet , Remove this printf btw ");
	int t=processInput(board, choice);
	modifyMoveCountBasedOnProccessInput(user, t);
	clearAndRedrawScreen(board);
	printUser(user);
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	int i = board->emptyTileRow;
	int j = board->emptyTileCol;
	if (j == board->cols - 1)
		return 0;
	else
	{
			swap(board, i, j, i,j+1);
			board->emptyTileCol = j + 1;
		return 1;
	}
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	int i = board->emptyTileRow;
	int j = board->emptyTileCol;
	if (j ==0)
		return 0;
	else
	{
		swap(board, i, j, i,j-1);
		board->emptyTileCol = j-1;
		return 1;
	}
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){

	int i = board->emptyTileRow;
	int j = board->emptyTileCol;
	if (i == board->rows-1)
		return 0;
	else
	{
		swap(board, i, j, i+1,j);
		board->emptyTileRow =i+1;
		return 1;
	}
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	int i = board->emptyTileRow;
	int j = board->emptyTileCol;
	if (i == 0)
		return 0;
	else
	{
		swap(board, i, j, i-1, j);
		board->emptyTileRow = i-1;
		return 1;
	}
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{
	board->table[x1][y1] = board->table[x2][y2];
	board->table[x2][y2] = 0;
}
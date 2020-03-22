/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y)
{
	ReversiMove *move = (ReversiMove*)malloc(sizeof(ReversiMove));
	move->x = x;
	move->y = y;
	return move;
}
int isvalidCoordinate(ReversiGame *game, int x, int y);
/*
Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game)
{
	int x, y;
	while (1)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		if (isvalidCoordinate(game, x, y))
			break;
	}
	ReversiMove *move = createMove(x, y);
	return move;
}


/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y)
{
	if ((x >= 1 && x <= game->rows) && (y >= 1 && y <= game->cols))
		return 1;
	return 0;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/
int isValidMoveLeft(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = y - 2;
	if (i < 0)
		return 0;
	for (; i >= 0; i--)
	{
		if (game->turn == 1)
		{
			if (i == y - 2)
			{
				if (game->board[x - 1][i] == ' ' || game->board[x - 1][i] == 'w')
					return 0;
				continue;
			}
			if (game->board[x - 1][i] == 'b')
				continue;
			if (game->board[x - 1][i] == 'w')
				return 1;
			if (game->board[x - 1][i] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == y - 2)
			{
				if (game->board[x - 1][i] == ' ' || game->board[x - 1][i] == 'b')
					return 0;
				continue;
			}
			if (game->board[x - 1][i] == 'w')
				continue;
			if (game->board[x - 1][i] == 'b')
				return 1;
			if (game->board[x - 1][i] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveRight(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = y;
	if (i >= game->cols)
		return 0;
	for (; i <game->cols; i++)
	{
		if (game->turn == 1)
		{
			if (i == y)
			{
				//char c = game->board[x - 1][i];
				if (game->board[x - 1][i] == ' ' || game->board[x - 1][i] == 'w')
					return 0;
				continue;
			}
			if (game->board[x - 1][i] == 'b')
				continue;
			if (game->board[x - 1][i] == 'w')
				return 1;
			if (game->board[x - 1][i] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == y)
			{
				if (game->board[x - 1][i] == ' ' || game->board[x - 1][i] == 'b')
					return 0;
				continue;
			}
			if (game->board[x - 1][i] == 'w')
				continue;
			if (game->board[x - 1][i] == 'b')
				return 1;
			if (game->board[x - 1][i] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveUp(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x - 2;
	if (i < 0)
		return 0;
	for (; i >= 0; i--)
	{
		if (game->turn == 1)
		{
			if (i == x - 2)
			{
				char c = game->board[i][y - 1];
				if (game->board[i][y - 1] == ' ' || game->board[i][y - 1] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][y - 1] == 'b')
				continue;
			if (game->board[i][y - 1] == 'w')
				return 1;
			if (game->board[i][y - 1] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x - 2)
			{
				if (game->board[i][y - 1] == ' ' || game->board[i][y - 1] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][y - 1] == 'w')
				continue;
			if (game->board[i][y - 1] == 'b')
				return 1;
			if (game->board[i][y - 1] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveDown(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x;
	if (i >= game->rows)
		return 0;
	for (; i < game->rows; i++)
	{
		if (game->turn == 1)
		{
			if (i == x)
			{
				if (game->board[i][y - 1] == ' ' || game->board[i][y - 1] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][y - 1] == 'b')
				continue;
			if (game->board[i][y - 1] == 'w')
				return 1;
			if (game->board[i][y - 1] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x)
			{
				if (game->board[i][y - 1] == ' ' || game->board[i][y - 1] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][y - 1] == 'w')
				continue;
			if (game->board[i][y - 1] == 'b')
				return 1;
			if (game->board[i][y - 1] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveDiagonalLT(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x - 2;
	int j = y - 2;
	if (i < 0 || j < 0)
		return 0;
	for (; i >= 0 && j >= 0; i--, j--)
	{
		if (game->turn == 1)
		{
			if (i == x - 2 && j == y - 2)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'b')
				continue;
			if (game->board[i][j] == 'w')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x - 2 && j == y - 2)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'w')
				continue;
			if (game->board[i][j] == 'b')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveDiagonalLB(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x - 2;
	int j = y;
	if (i < 0 || j >= game->cols)
	{
		return 0;
	}
	for (; i >= 0 && j < game->cols; i--, j++)
	{
		if (game->turn == 1)
		{
			if (i == x - 2 && j == y)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'b')
				continue;
			if (game->board[i][j] == 'w')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x - 2 && j == y)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'w')
				continue;
			if (game->board[i][j] == 'b')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveDiagonalRB(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x;
	int j = y;
	if (i >= game->rows || y >= game->cols)
		return 0;
	for (; i <game->rows && j < game->cols; i++, j++)
	{
		if (game->turn == 1)
		{
			if (i == x && j == y)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'b')
				continue;
			if (game->board[i][j] == 'w')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x && j == y)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'w')
				continue;
			if (game->board[i][j] == 'b')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMoveDiagonalRT(ReversiGame *game, ReversiMove *move)
{
	int x = move->x;
	int y = move->y;
	int i = x;
	int j = y - 2;
	if (i >= game->rows || j < 0)
		return 0;
	for (; i <game->rows && j >= 0; i++, j--)
	{
		if (game->turn == 1)
		{
			if (i == x && j == y - 2)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'w')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'b')
				continue;
			if (game->board[i][j] == 'w')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
		else if (game->turn == -1)
		{
			if (i == x && j == y - 2)
			{
				if (game->board[i][j] == ' ' || game->board[i][j] == 'b')
					return 0;
				continue;
			}
			if (game->board[i][j] == 'w')
				continue;
			if (game->board[i][j] == 'b')
				return 1;
			if (game->board[i][j] == ' ')
				return 0;
		}
	}
	return 0;
}
int isValidMove(ReversiGame *game, ReversiMove *move)
{
	if (move->x <= 0 || move->x > game->rows || move->y <= 0 || move->y > game->cols)
		return 0;
	if (game->board[move->x - 1][move->y - 1] != ' ')
		return 0;
	if (isValidMoveLeft(game, move))
		return 1;
	if (isValidMoveRight(game, move))
		return 1;
	if (isValidMoveUp(game, move))
		return 1;
	if (isValidMoveDown(game, move))
		return 1;
	if (isValidMoveDiagonalLT(game, move))
		return 1;
	if (isValidMoveDiagonalLB(game, move))
		return 1;
	if (isValidMoveDiagonalRB(game, move))
		return 1;
	if (isValidMoveDiagonalRT(game, move))
		return 1;
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/
int hasMove1(ReversiGame *game)
{
	int t=hasMove(game);
	if (t == 0)
	{
		modifyTurn(game);
		t = hasMove(game);
		if (t == 0)
		{
			endGame(game);
			return 0;
		}
		else
			return 1;
	}
	else
		return 1;
}

int hasMove(ReversiGame *game)
{
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->board[i][j] == ' ')
			{
				ReversiMove *mv = createMove(i + 1, j + 1);
				if (isValidMove(game, mv))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game)
{
	game->NumberofMoves++;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game)
{
	if (game->turn == 1)
		game->turn = -1;
	else
		game->turn = 1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game)
{
	int i = game->blackCount;
	int j = game->whiteCount;
	game->state = 1;
	if (i > j)
	{
		game->winner = -1;
	}
	else if (j > i)
	{
		game->winner = 1;
	}
	else
	{
		game->winner = 0;
	}
	return;

}

/*
Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game)
{
	incrementMoves(game);
	modifyTurn(game);
}


/*
This function performs move action on the board
Note : call validity check performs using above functions before making a move
returns :
true on move sucess
false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move)
{
	if (!isValidMove(game, move))
	{
			return false;
	}
	else
	{
		if (isValidMoveLeft(game, move))
		{
			for (int i = move->y - 2; i >= 0; i--)
			{
				if (game->turn == 1)
				{
					if (game->board[move->x - 1][i] == 'b')
					{
						game->board[move->x - 1][i] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[move->x - 1][i] == 'w')
					{
						game->board[move->x - 1][i] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveRight(game, move))
		{
			for (int i = move->y; i < game->cols; i++)
			{
				if (game->turn == 1)
				{
					if (game->board[move->x - 1][i] == 'b')
					{
						game->board[move->x - 1][i] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[move->x - 1][i] == 'w')
					{
						game->board[move->x - 1][i] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveUp(game, move))
		{
			for (int i = move->x - 2; i >= 0; i--)
			{
				if (game->turn == 1)
				{
					int j = move->y - 1;
					if (game->board[i][j] == 'b')
					{
						game->board[i][move->y - 1] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][move->y - 1] == 'w')
					{
						game->board[i][move->y - 1] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveDown(game, move))
		{
			for (int i = move->x; i < game->rows; i++)
			{
				if (game->turn == 1)
				{
					if (game->board[i][move->y - 1] == 'b')
					{
						game->board[i][move->y - 1] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][move->y - 1] == 'w')
					{
						game->board[i][move->y - 1] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveDiagonalLT(game, move))
		{
			int i = move->x - 2;
			int j = move->y - 2;
			for (; i >= 0, j >= 0; i--, j--)
			{
				if (game->turn == 1)
				{
					if (game->board[i][j] == 'b')
					{
						game->board[i][j] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][j] == 'w')
					{
						game->board[i][j] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveDiagonalLB(game, move))
		{
			int i = move->x - 2;
			int j = move->y;
			for (; i >= 0, j < game->cols; i--, j++)
			{
				if (game->turn == 1)
				{
					if (game->board[i][j] == 'b')
					{
						game->board[i][j] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][j] == 'w')
					{
						game->board[i][j] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveDiagonalRB(game, move))
		{
			int i = move->x;
			int j = move->y;
			for (; i < game->rows, j < game->cols; i++, j++)
			{
				if (game->turn == 1)
				{
					if (game->board[i][j] == 'b')
					{
						game->board[i][j] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][j] == 'w')
					{
						game->board[i][j] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (isValidMoveDiagonalRT(game, move))
		{
			int i = move->x;
			int j = move->y - 2;
			for (; i < game->rows, j >= 0; i++, j--)
			{
				if (game->turn == 1)
				{
					if (game->board[i][j] == 'b')
					{
						game->board[i][j] = 'w';
						game->whiteCount++;
						game->blackCount--;
					}
					else
					{
						break;
					}
				}
				else if (game->turn == -1)
				{
					if (game->board[i][j] == 'w')
					{
						game->board[i][j] = 'b';
						game->whiteCount--;
						game->blackCount++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (game->turn == 1)
		{
			game->whiteCount++;
			game->board[move->x - 1][move->y - 1] = 'w';
		}
		else if (game->turn == -1)
		{
			game->blackCount++;
			game->board[move->x - 1][move->y - 1] = 'b';
		}
		int c = game->whiteCount;
		int b = game->blackCount;
		modify(game);
		if (!hasMove(game))
			modifyTurn(game);
		return true;
	}
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 0)
		printf("Game os Drawn");
	else if (game->winner == 1)
	{
		printf("Result %s has won", game->player1name);
	}
	else if (game->winner == -1)
	{
		printf("Result %s has won", game->player2name);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3


void draw_board(char board[])
{
	system("cls");
	printf("# 1 2 3\n");

	// Rows
	for (int i = 0, n = 0; i < SIZE; i++)
	{
		// Columns
		printf("%d ", i + 1);
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c ", board[n]);
			n++;
		}
		printf("\n");
	}
}


void init_board(char board[])
{
	for (int i = 0; i <  SIZE * SIZE; i++)
	{
		board[i] = '-';
	}
}


bool place(char board[], char player)
{
	char posinput[64];

	printf("%c, pick your position (xy, rc): ", player);
	scanf("%s", posinput); 

	int row = (posinput[0] - '0') - 1;
	int col = (posinput[1] - '0') - 1;

	int pos = col + row * SIZE;

	if (pos >= 0 && pos < SIZE * SIZE)
	{
		if (board[pos] == 'x' || board[pos] == 'o')
			return false;

		board[pos] = player;
		return true;
	}

	return false;
}


bool check(char b[], char p) 
{
	// Check rows
	if (b[0] == p && b[1] == p && b[2] == p)
		return true;
	if (b[3] == p && b[4] == p && b[5] == p)
		return true;
	if (b[6] == p && b[7] == p && b[8] == p)
		return true;


	
	if (b[0] == p && b[3] == p && b[6] == p)
		return true;
	if (b[1] == p && b[4] == p && b[7] == p)
		return true;
	if (b[2] == p && b[5] == p && b[8] == p)
		return true;


	
	if (b[0] == p && b[4] == p && b[8] == p)
		return true;
	if (b[2] == p && b[4] == p && b[6] == p)
		return true;

	return false;
}

int main(void)
{
	char board[SIZE * SIZE];
	char player = 'x';
	init_board(board);

	while (true)
	{
		draw_board(board);
		
		if (place(board, player))
		{
			if (check(board, player))
				break;

			if (player == 'x')
				player = 'o';
			else
				player = 'x';
		}
	}

	draw_board(board);
	printf("-----------------------------\n");
	printf("Player %c wins!!!\n", player);
	printf("-----------------------------\n");
}
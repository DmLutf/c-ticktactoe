#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

typedef enum Mark
{
	Empty,
	Cross,
	Circle
} Mark;

char mark_to_char(Mark mark);
void switch_turn(Mark *turn);
Mark has_winner(Mark field[3][3]);
void display_field(Mark field[3][3]);
void declare_turn(Mark turn);
bool is_full(Mark field[3][3]);
void move(Mark turn, Mark field[3][3]);

int main()
{
	Mark field[][3] = {
		{ Empty, Empty, Empty },
		{ Empty, Empty, Empty },
		{ Empty, Empty, Empty } };
	Mark turn = Cross;

	while (!(is_full(field)) && has_winner(field) == Empty)
	{
		display_field(field);
		declare_turn(turn);
		move(turn, field);
		switch_turn(&turn);
	}

    display_field(field);
	switch (has_winner(field))
	{
		case Empty:  printf("Draw!\n");
					 return 0;
		case Cross:  printf("Cross wins!\n");
					 return 0;
		case Circle: printf("Circle wins!\n");
					 return 0;
	}
}

char mark_to_char(Mark mark)
{
	switch (mark)
	{
		case Empty:  return ' ';
		case Cross:  return 'X';
		case Circle: return 'O';
	}
}

void switch_turn(Mark *turn)
{
	if (*turn == Cross)
		*turn = Circle;
	else
		*turn = Cross;
}

Mark has_winner(Mark field[3][3])
{
	for (int i = 0; i < 3; i++)
		if (field[i][0] != Empty && field[i][0] == field[i][1] && field[i][1] == field[i][2])
			return field[i][0];

	for (int i = 0; i < 3; i++)
		if (field[0][i] != Empty && field[0][i] == field[1][i] && field[1][i] == field[2][i])
			return field[0][i];

	if (field[0][0] != Empty && field[0][0] == field[1][1] && field[1][1] == field[2][2])
		return field[0][0];

	if (field[0][2] != Empty && field[0][2] == field[1][1] && field[1][1] == field[2][0])
		return field[0][2];

	return Empty;
}

void display_field(Mark field[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c \n", field[i][0], field[i][1], field[i][2]);
		if (i < 2)
			printf("---+---+---\n");
	}
}

void declare_turn(Mark turn)
{
	switch (turn)
	{
		case Cross:  printf("Cross's turn!\n");
					 return;
		case Circle: printf("Circle's turn!\n");
					 return;
	}
}

bool is_full(Mark field[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (field[i][j] == Empty)
				return false;
	return true;
}

void move(Mark turn, Mark field[3][3])
{
	int x, y;

	input: printf("Enter X and Y - ");
	scanf("%d %d", &x, &y);

	if (x < 1 || x > 3 || y < 1 || y > 3)
	{
		printf("X and Y must be 1, 2 or 3!\n");
		goto input;
	}
	if (field[y - 1][x - 1] != Empty)
	{
		printf("Spot taken!\n");
		goto input;
	}

	field[y - 1][x - 1] = Cross;
}

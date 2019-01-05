#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include"head.h"

//开局库

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//白棋
extern int b;//黑棋
extern bool ai_first;



int open_base(int step_count)
{
	int vector;
	srand(time(0));
	vector = rand() % 2 ? 1 : -1;//随机生成±1
	if (ai_first)
	{//下面是直指开局，使用花月，coordinate会存储上一步的落子位置，因此可以用它来判断是直指还是斜指
		if (step_count == 2)
		{
			if ((coordinate[0] == 7) && ((coordinate[1] == 6) || (coordinate[1] == 8)))//水平方向的直指，即白子落在了8I或者8G处
				coordinate[0] += vector;
			else if ((coordinate[1] == 7) && ((coordinate[0] == 6) || (coordinate[0] == 8)))
				coordinate[1] += vector;
			//下面是斜指开局，使用浦月
			else if ((coordinate[0] == 6 && coordinate[1] == 8)//9I浦月
				|| (coordinate[0] == 8 && coordinate[1] == 6))//7G浦月
			{
				coordinate[0] = 7 + vector;
				coordinate[1] = 7 + vector;//随机落在7I和9G处
			}
			else if ((coordinate[0] == 8 && coordinate[1] == 8)//7I浦月
				|| (coordinate[0] == 6 && coordinate[1] == 6))//9G浦月
			{
				coordinate[0] = 7 + vector;
				coordinate[1] = 7 - vector;//随机落在7G和9I处
			}
			else//不是斜指也不是直指
				randomly_choose_a_point(7, 7);
			return 1;
		}
		else if (step_count == 4)
		{
			if (board[6][7] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;

				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][7] == w && board[6][6] == b)
			{
				if (board[5][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][8] == w && board[8][7] == b)
			{
				if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 7;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][8] == w && board[6][7] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 7;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][7] == w && board[7][8] == b)
			{
				if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][7] == w && board[7][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][6] == w && board[8][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][6] == w && board[6][6] == b)
			{
				if (board[5][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][8] == w && board[8][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][8] == w && board[6][6] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][8] == w && board[8][6] == b)
			{
				if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;

			}

			else if (board[8][8] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][6] == w && board[8][8] == b)
			{
				if (board[7][9] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][6] == w && board[6][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else
					return 0;
			}
		
			else if (board[6][6] == w && board[8][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][6] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else
				return 0;
		}
		else
			return 0;

		

	}
	else
		randomly_choose_a_point(coordinate[0], coordinate[1]);
	return 1;
}

void randomly_choose_a_point(int raw, int column)
{
	int vector1;
	int vector2;
	do
	{
		vector1 = rand() % 3 - 1;
		vector2 = rand() % 3 - 1;
	} while (vector1 == 0 && vector2 == 0);

	coordinate[0] = raw + vector1;
	coordinate[1] = column + vector2;
}
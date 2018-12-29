#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern bool BoardFull;
extern unsigned long long ZobristTable[15][15][2];//梅森旋转的哈希键值表
extern unsigned long long hashValue;//梅森旋转算法下，棋盘的哈希值
//extern unsigned long long hashing_value2[depth_of_hashing][3];
//extern unsigned long long hashing_value3[depth_of_hashing][4];
extern HE hashing_value4[depth_of_hashing];
extern bool banned_point_sheet[15][15];
extern int temp_point[2];

void pvp(long int value)
{
	int step_count = 0; //游戏下了几个子的计数
	bool continue_playing = true; //确认游戏是否继续
	bool my_turn = true; //这个东西是确认这一步是哪一方下子了
	bool find_forbidden_step = false;
	initTable();//初始化哈希表（键值表）
	DrawBoard(value, 1, -1);
	while (continue_playing)
	{
		char c_getback = ' ';
		int i_getback;
		int temp_cor[2];
		temp_cor[0] = coordinate[0];
		temp_cor[1] = coordinate[1];
		get_coordinate(step_count);
		roaming = board[coordinate[0]][coordinate[1]];
		chess_play_ver2(step_count);
		temp_point[0] = coordinate[0];
		temp_point[1] = coordinate[1];
		//测试用
		if (coordinate[0] == 6 && coordinate[1] == 9)
		{
			printf("\n");
		}
		hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
		value = Searching_Hashing(step_count, my_turn, 0, false, 0);
		if (value == 0)
		{
			value = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
			Searching_Hashing(step_count, my_turn, value, true, 0);
		}
		DrawBoard(value, 1, step_count);
		return_to_normal_chess(step_count);
		refresh_banned_point_whole();
		if (step_count % 2 == 0)//黑子才执行判断禁手
		{
			find_forbidden_step = banned_point_sheet[coordinate[0]][coordinate[1]];
			if (find_forbidden_step)
			{
				printf("禁手\n");
				system("pause");
			}
		}
		else
		{
			find_forbidden_step = banned_point_sheet[coordinate[0]][coordinate[1]];
			if (find_forbidden_step)
			{
				printf("对方的禁手\n");
				system("pause");
			}
		}

		printf("是否想要悔棋？按y悔棋，按别的任意键正常继续游戏.\n");
		c_getback = getchar();
		while (getchar() != '\n')
			continue;
		i_getback = c_getback;
		if (i_getback == 89 || i_getback == 121)
		{
			board[coordinate[0]][coordinate[1]] = roaming;
			coordinate[0] = temp_cor[0];
			coordinate[1] = temp_cor[1];
			DrawBoard(value, 1, step_count);
			hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];//再一次异或回来
			continue;
		}
		continue_playing = judgement(step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(value, 1, step_count);
	if (BoardFull)
		printf("平局\n");
	else
	{
		if (step_count % 2)
		{
			printf("黑子获胜");
		}
		else
		{
			printf("白子获胜");
		}

	}
	return;
}



void chess_play_ver2(int step_count)
{
	int black = 1;// "△"
	int white = 2;//"▲"
	int raw = coordinate[0];
	int column = coordinate[1];
	if (step_count % 2 == 0)
		board[raw][column] = black;
	else
		board[raw][column] = white;
}

void return_to_normal_chess(int step_count)
{//此函数是用来将△类型的棋子恢复成○类型的棋子
	int white = 119;//白棋
	int black = 98;//黑棋
	int raw = coordinate[0];
	int column = coordinate[1];
	if (step_count % 2 == 0)
		board[raw][column] = black;
	else
		board[raw][column] = white;
}



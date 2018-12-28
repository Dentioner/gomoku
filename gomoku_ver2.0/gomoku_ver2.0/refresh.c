#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"
#include<stdlib.h>

extern int board[15][15];
extern int w;//白棋
extern int b;//黑棋
extern int coordinate[2];
//extern bool show_me_the_array;//测试用
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
extern int  temp_point[2];
extern int all_vector[4][2];


void refresh_score(int step_count, bool my_turn)//重新刷新刚落下的子的四个方向上6个单位以内的空格的分数，如果速度过慢，就修改为4个单位以内的空格
{
	int i;
	for (i = 0; i < 4; i++)
		re_calculate(all_vector[i], step_count, my_turn);
}

void re_calculate(int vector[], int step_count, bool my_turn)
{
	int i, j;
	int raw, column, point;
	long int white_value, black_value;
	for (i = -6, j = -6; i < 7 && j < 7; i++, j++)
	{
		raw = temp_point[0] + vector[0] * i;
		column = temp_point[1] + vector[1] * j;
		if (raw >= 0 && raw <= 14 && column >= 0 && column <= 14)
		{
			point = board[raw][column];
			if (point != w && point != b && (raw != temp_point[0] || column != temp_point[1]))
			{//判断条件为：不是棋子，且不是刚刚下落的那个点, 之所以添加后面那个条件是因为在撤回棋子并重新让分数变回去的时候，刚刚下落的那个位置也会被重新算一遍，但是实际上那个位置不用算
				if (banned_point_sheet[raw][column])//如果在本方向上检测到了禁手
					empty_score_total_black[raw][column] = 0;
				else
				{
					black_value = evaluation(2, true, raw, column);//将step_count强行令为偶数2，保证是黑子得分，并将my_turn强行置为true，保证输出得分为正数
					empty_score_total_black[raw][column] = black_value;
				}
				white_value = evaluation(3, true, raw, column);//将step_count强行令为奇数3，保证是白子得分，并将my_turn强行置为true，保证输出得分为正数
				empty_score_total_white[raw][column] = white_value;
				//if (empty_score_total_white[4][12] == 10000)
					//printf("test\n");
			}
		}

	}
}

void refresh_banned_point_whole()//整个刷新禁手点的一系列函数的最高层模块
{
	int i;
	for (i = 0; i < 4; i++)
		refresh_banned_point_single_line(all_vector[i]);
}

void refresh_banned_point_single_line(int vector[])//对于落子的点的单个方向上空位的禁手判断
{
	int i, j;
	int raw, column, point;
	for (i = -6, j = -6; i < 7 && j < 7; i++, j++)
	{
		raw = temp_point[0] + vector[0] * i;
		column = temp_point[1] + vector[1] * j;
		if (raw >= 0 && raw <= 14 && column >= 0 && column <= 14)
		{
			point = board[raw][column];
			if (point != w && point != b && (raw != temp_point[0] || column != temp_point[1]))//判断条件为：不是棋子，且不是刚刚下落的那个点, 之所以添加后面那个条件是因为在撤回棋子并重新让分数变回去的时候，刚刚下落的那个位置也会被重新算一遍，但是实际上那个位置不用算
				banned_point_sheet[raw][column] = detect_forbidden_step(raw, column);
		}
	}
}
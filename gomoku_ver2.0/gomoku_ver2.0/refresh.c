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
//启发式搜索，按照优先级顺序，对分支进行排序，提高剪枝速度
//见https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js


void refresh_score(int step_count, bool my_turn)//重新刷新刚落下的子的四个方向上6个单位以内的空格的分数，如果速度过慢，就修改为4个单位以内的空格
{

	int horizon[2] = { 0,1 };//水平方向单位矢量
	int perpendicular[2] = { 1,0 };//垂直方向单位矢量
	int up_right_down_left[2] = { -1,1 };//右上左下方向单位矢量
	int up_left_down_right[2] = { 1,1 };//左上右下方向单位矢量
	/*
	for (i = -6, j = -6; i < 6 && j < 6; i++, j++)
	{
		re_calculate(horizon, i, j, step_count, my_turn);//刷新水平方向的空格的分数
		re_calculate(perpendicular, i, j, step_count, my_turn);//刷新竖直方向的空格的分数
		re_calculate(up_right_down_left, i, j, step_count, my_turn);//刷新右上左下方向的空格的分数
		re_calculate(up_left_down_right, i, j, step_count, my_turn);//刷新左上右下方向的空格的分数

	}
	*/
	//if (temp_point[0] == 8 && temp_point[1] == 6)
		//DrawBoard(0, 2, step_count);

	re_calculate(horizon, step_count, my_turn);//刷新水平方向的空格的分数
	re_calculate(perpendicular, step_count, my_turn);//刷新竖直方向的空格的分数
	re_calculate(up_right_down_left, step_count, my_turn);//刷新右上左下方向的空格的分数
	re_calculate(up_left_down_right, step_count, my_turn);//刷新左上右下方向的空格的分数
}

void re_calculate(int vector[], int step_count, bool my_turn)
{
	/*
	int raw, column;
	long int value;
	raw = temp_point[0] + vector[0] * i;
	column = temp_point[1] + vector[1] * j;
	value = evaluation_ver2(step_count, my_turn, raw, column);
	empty_score_total[raw][column] = value;
	*/
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
			{//判断条件为：不是棋子，且不是刚刚下落的那个点
//之所以添加后面那个条件是因为在撤回棋子并重新让分数变回去的时候，刚刚下落的那个位置也会被重新算一遍，但是实际上那个位置不用算
			
				if (banned_point_sheet[raw][column])//如果在本方向上检测到了禁手
				{
					empty_score_total_black[raw][column] = 0;
				}
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
	int horizon[2] = { 0,1 };//水平方向单位矢量
	int perpendicular[2] = { 1,0 };//垂直方向单位矢量
	int up_right_down_left[2] = { -1,1 };//右上左下方向单位矢量
	int up_left_down_right[2] = { 1,1 };//左上右下方向单位矢量
	refresh_banned_point_single_line(horizon);
	refresh_banned_point_single_line(perpendicular);
	refresh_banned_point_single_line(up_right_down_left);
	refresh_banned_point_single_line(up_left_down_right);
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
			if (point != w && point != b && (raw != temp_point[0] || column != temp_point[1]))
			{//判断条件为：不是棋子，且不是刚刚下落的那个点
//之所以添加后面那个条件是因为在撤回棋子并重新让分数变回去的时候，刚刚下落的那个位置也会被重新算一遍，但是实际上那个位置不用算
				banned_point_sheet[raw][column] = detect_forbidden_step(raw, column);
			}
		}

	}
}
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"
#include<stdlib.h>

extern int board[15][15];
extern int w;//����
extern int b;//����
extern int coordinate[2];
//extern bool show_me_the_array;//������
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
extern int  temp_point[2];
//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js


void refresh_score(int step_count, bool my_turn)//����ˢ�¸����µ��ӵ��ĸ�������6����λ���ڵĿո�ķ���������ٶȹ��������޸�Ϊ4����λ���ڵĿո�
{

	int horizon[2] = { 0,1 };//ˮƽ����λʸ��
	int perpendicular[2] = { 1,0 };//��ֱ����λʸ��
	int up_right_down_left[2] = { -1,1 };//�������·���λʸ��
	int up_left_down_right[2] = { 1,1 };//�������·���λʸ��
	/*
	for (i = -6, j = -6; i < 6 && j < 6; i++, j++)
	{
		re_calculate(horizon, i, j, step_count, my_turn);//ˢ��ˮƽ����Ŀո�ķ���
		re_calculate(perpendicular, i, j, step_count, my_turn);//ˢ����ֱ����Ŀո�ķ���
		re_calculate(up_right_down_left, i, j, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
		re_calculate(up_left_down_right, i, j, step_count, my_turn);//ˢ���������·���Ŀո�ķ���

	}
	*/
	//if (temp_point[0] == 8 && temp_point[1] == 6)
		//DrawBoard(0, 2, step_count);

	re_calculate(horizon, step_count, my_turn);//ˢ��ˮƽ����Ŀո�ķ���
	re_calculate(perpendicular, step_count, my_turn);//ˢ����ֱ����Ŀո�ķ���
	re_calculate(up_right_down_left, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
	re_calculate(up_left_down_right, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
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
			{//�ж�����Ϊ���������ӣ��Ҳ��Ǹո�������Ǹ���
//֮������Ӻ����Ǹ���������Ϊ�ڳ������Ӳ������÷������ȥ��ʱ�򣬸ո�������Ǹ�λ��Ҳ�ᱻ������һ�飬����ʵ�����Ǹ�λ�ò�����
			
				if (banned_point_sheet[raw][column])//����ڱ������ϼ�⵽�˽���
				{
					empty_score_total_black[raw][column] = 0;
				}
				else
				{
					black_value = evaluation(2, true, raw, column);//��step_countǿ����Ϊż��2����֤�Ǻ��ӵ÷֣�����my_turnǿ����Ϊtrue����֤����÷�Ϊ����
					empty_score_total_black[raw][column] = black_value;
				}

				
				white_value = evaluation(3, true, raw, column);//��step_countǿ����Ϊ����3����֤�ǰ��ӵ÷֣�����my_turnǿ����Ϊtrue����֤����÷�Ϊ����
				empty_score_total_white[raw][column] = white_value;
				//if (empty_score_total_white[4][12] == 10000)
					//printf("test\n");
			}
		}

	}
}

void refresh_banned_point_whole()//����ˢ�½��ֵ��һϵ�к�������߲�ģ��
{
	int horizon[2] = { 0,1 };//ˮƽ����λʸ��
	int perpendicular[2] = { 1,0 };//��ֱ����λʸ��
	int up_right_down_left[2] = { -1,1 };//�������·���λʸ��
	int up_left_down_right[2] = { 1,1 };//�������·���λʸ��
	refresh_banned_point_single_line(horizon);
	refresh_banned_point_single_line(perpendicular);
	refresh_banned_point_single_line(up_right_down_left);
	refresh_banned_point_single_line(up_left_down_right);
}

void refresh_banned_point_single_line(int vector[])//�������ӵĵ�ĵ��������Ͽ�λ�Ľ����ж�
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
			{//�ж�����Ϊ���������ӣ��Ҳ��Ǹո�������Ǹ���
//֮������Ӻ����Ǹ���������Ϊ�ڳ������Ӳ������÷������ȥ��ʱ�򣬸ո�������Ǹ�λ��Ҳ�ᱻ������һ�飬����ʵ�����Ǹ�λ�ò�����
				banned_point_sheet[raw][column] = detect_forbidden_step(raw, column);
			}
		}

	}
}
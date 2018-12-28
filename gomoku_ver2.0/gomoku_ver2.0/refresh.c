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
extern int all_vector[4][2];


void refresh_score(int step_count, bool my_turn)//����ˢ�¸����µ��ӵ��ĸ�������6����λ���ڵĿո�ķ���������ٶȹ��������޸�Ϊ4����λ���ڵĿո�
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
			{//�ж�����Ϊ���������ӣ��Ҳ��Ǹո�������Ǹ���, ֮������Ӻ����Ǹ���������Ϊ�ڳ������Ӳ������÷������ȥ��ʱ�򣬸ո�������Ǹ�λ��Ҳ�ᱻ������һ�飬����ʵ�����Ǹ�λ�ò�����
				if (banned_point_sheet[raw][column])//����ڱ������ϼ�⵽�˽���
					empty_score_total_black[raw][column] = 0;
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
	int i;
	for (i = 0; i < 4; i++)
		refresh_banned_point_single_line(all_vector[i]);
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
			if (point != w && point != b && (raw != temp_point[0] || column != temp_point[1]))//�ж�����Ϊ���������ӣ��Ҳ��Ǹո�������Ǹ���, ֮������Ӻ����Ǹ���������Ϊ�ڳ������Ӳ������÷������ȥ��ʱ�򣬸ո�������Ǹ�λ��Ҳ�ᱻ������һ�飬����ʵ�����Ǹ�λ�ò�����
				banned_point_sheet[raw][column] = detect_forbidden_step(raw, column);
		}
	}
}
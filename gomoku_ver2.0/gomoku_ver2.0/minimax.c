#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
#include<time.h>
#include<math.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//����
extern int b;//����
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
//extern unsigned long long hashing_value2[depth_of_hashing][3];
//extern unsigned long long hashing_value3[depth_of_hashing][4];
extern HE hashing_value4[depth_of_hashing];
extern long int best_score_of_upper[11];
extern bool not_in_the_same_branch[11];
extern long int value_for_board;//�¼�
extern long int best_score_of_upper_ver2[12];
//bool show_me_the_array = false;//�����õĲ���ֵ
extern bool ai_first;
extern int temp_point[2];//��ʱ�������꣬��minimax�����������ʱ�����ӵ�ʱ����
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];


long int deepest(int step_count, bool my_turn)//��ײ�����������ȡ������
{
	long int temp_score;

	long int ai_score, p_score;
	int raw, column;
	//����ɾ��һ��ע�ͣ�Ҫ�ָ���ȥ����ĵط��浵��minimax�ļ�
	long int board_score = 0;
	if (ai_first)
	{		//���forѭ����һ��ʼ���еģ���������ɾ��
		for (raw = 0; raw < 15; raw++)
		{
			for (column = 0; column < 15; column++)
			{
				if ((board[raw][column] != b)
					&& (board[raw][column] != w))
				{
					//temp_score = evaluation(board, step_count, my_turn, raw, column);

					ai_score = empty_score_total_black[raw][column];
					p_score = empty_score_total_white[raw][column];
					/*
					temp_score1 = labs(temp_score1) * 1.5;
					temp_score2 = labs(temp_score2) * 0.75;
					temp_score = temp_score1 + temp_score2;
					*/
					temp_score = ai_score * 1.1 - p_score * 0.9;
					board_score += temp_score;
					/*
					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_raw = raw;
						best_column = column;

					}
					else
					{
						if (temp_score > best_score)
						{
							best_score = temp_score;

						}
					}
					*/

				}
			}
		}
	}
	else
	{
		for (raw = 0; raw < 15; raw++)
		{
			for (column = 0; column < 15; column++)
			{
				if ((board[raw][column] != b)
					&& (board[raw][column] != w))
				{
					//temp_score = evaluation(board, step_count, my_turn, raw, column);

					ai_score = empty_score_total_white[raw][column];
					p_score = empty_score_total_black[raw][column];
					/*
					temp_score1 = labs(temp_score1) * 1.5;
					temp_score2 = labs(temp_score2) * 0.75;
					temp_score = temp_score1 + temp_score2;
					*/
					temp_score = ai_score * 1.1 - p_score * 0.9;
					board_score += temp_score;
					/*
					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_raw = raw;
						best_column = column;

					}
					else
					{
						if (temp_score > best_score)
						{
							best_score = temp_score;

						}
					}
					*/

				}
			}
		}
	}

	return board_score;
}

void shallowest(int step_count, bool my_turn)//�������������ֻ����һ������
{
	long int temp_score1 = 0;
	long int temp_score2 = 0;

	bool initialized = false;
	long int temp_score = 0;
	long int best_score;
	int best_coordinate[2] = { 0,0 };
	//���forѭ����һ��ʼ���еģ���������ɾ��
	for (int raw = 0; raw < 15; raw++)
	{
		for (int column = 0; column < 15; column++)
		{
			if ((board[raw][column] != w)
				&& (board[raw][column] != b))
			{
				//temp_score = evaluation(board, step_count, my_turn, raw, column);
				if (ai_first && (!detect_forbidden_step(raw, column)))//���ڴ˺���ֻ����AI���ӵ�ʱ���õ������ai_first�ʹ�����ai�ú��ӣ��н���
				{
					temp_score1 = evaluation(step_count, my_turn, raw, column);
					temp_score2 = evaluation(step_count + 1, !my_turn, raw, column);

					temp_score1 = labs(temp_score1) * 1.1;
					temp_score2 = labs(temp_score2) * 0.9;
					temp_score = temp_score1 + temp_score2;

					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_coordinate[0] = raw;
						best_coordinate[1] = column;

					}
					else
					{
						if (temp_score > best_score)
							//֮���Բ�ȡ�ȣ�����Ϊ������з�֧�ķ�ֵ��Ϊ0�Ļ��������ʼ���ֵ��Ǹ�������£���Ϊ�ʼ������Ǳ���������ߵ�
						{
							best_score = temp_score;
							best_coordinate[0] = raw;
							best_coordinate[1] = column;
						}
					}
				}
				else if (!ai_first)
				{
					temp_score1 = evaluation(step_count, my_turn, raw, column);
					temp_score2 = evaluation(step_count + 1, !my_turn, raw, column);

					temp_score1 = labs(temp_score1) * 1.1;
					temp_score2 = labs(temp_score2) * 0.9;
					temp_score = temp_score1 + temp_score2;

					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_coordinate[0] = raw;
						best_coordinate[1] = column;

					}
					else
					{
						if (temp_score > best_score)
							//֮���Բ�ȡ�ȣ�����Ϊ������з�֧�ķ�ֵ��Ϊ0�Ļ��������ʼ���ֵ��Ǹ�������£���Ϊ�ʼ������Ǳ���������ߵ�
						{
							best_score = temp_score;
							best_coordinate[0] = raw;
							best_coordinate[1] = column;



						}
					}
				}
			}
		}
	}
	*coordinate = *best_coordinate;
	*(coordinate + 1) = *(best_coordinate + 1);
}
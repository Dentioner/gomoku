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
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
//extern unsigned long long hashing_value2[depth_of_hashing][3];
//extern unsigned long long hashing_value3[depth_of_hashing][4];
extern HE hashing_value4[depth_of_hashing];
extern bool banned_point_sheet[15][15];
extern int temp_point[2];

void pvp(long int value)
{
	int step_count = 0; //��Ϸ���˼����ӵļ���
	bool continue_playing = true; //ȷ����Ϸ�Ƿ����
	bool my_turn = true; //���������ȷ����һ������һ��������
	bool find_forbidden_step = false;
	initTable();//��ʼ����ϣ����ֵ��
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
		//������
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
		if (step_count % 2 == 0)//���Ӳ�ִ���жϽ���
		{
			find_forbidden_step = banned_point_sheet[coordinate[0]][coordinate[1]];
			if (find_forbidden_step)
			{
				printf("����\n");
				system("pause");
			}
		}
		else
		{
			find_forbidden_step = banned_point_sheet[coordinate[0]][coordinate[1]];
			if (find_forbidden_step)
			{
				printf("�Է��Ľ���\n");
				system("pause");
			}
		}

		printf("�Ƿ���Ҫ���壿��y���壬��������������������Ϸ.\n");
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
			hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];//��һ��������
			continue;
		}
		continue_playing = judgement(step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(value, 1, step_count);
	if (BoardFull)
		printf("ƽ��\n");
	else
	{
		if (step_count % 2)
		{
			printf("���ӻ�ʤ");
		}
		else
		{
			printf("���ӻ�ʤ");
		}

	}
	return;
}



void chess_play_ver2(int step_count)
{
	int black = 1;// "��"
	int white = 2;//"��"
	int raw = coordinate[0];
	int column = coordinate[1];
	if (step_count % 2 == 0)
		board[raw][column] = black;
	else
		board[raw][column] = white;
}

void return_to_normal_chess(int step_count)
{//�˺����������������͵����ӻָ��ɡ����͵�����
	int white = 119;//����
	int black = 98;//����
	int raw = coordinate[0];
	int column = coordinate[1];
	if (step_count % 2 == 0)
		board[raw][column] = black;
	else
		board[raw][column] = white;
}



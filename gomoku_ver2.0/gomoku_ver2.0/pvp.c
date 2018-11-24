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
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
extern unsigned long long hashing_value2[depth_of_hashing][3];


void pvp(long int value)
{
	int step_count = 0; //��Ϸ���˼����ӵļ���
	bool continue_playing = true; //ȷ����Ϸ�Ƿ����
	bool my_turn = true; //���������ȷ����һ������һ��������
	initTable();//��ʼ����ϣ����ֵ��
		//��������ǲ��Թ�ϣ���
		/*
		for (int raw01 = 0; raw01 < 15; raw01++)
		{
			for (int raw02 = 0; raw02 < 15; raw02++)
			{

				printf("%ull, %ull\n", ZobristTable[raw01][raw02][0], ZobristTable[raw01][raw02][1]);

			}
		}
		system("pause");
		*/
	DrawBoard(value, 1, -1);
	while (continue_playing)
	{
		get_coordinate(coordinate, board, step_count);
		roaming = board[coordinate[0]][coordinate[1]];
		chess_play_ver2(step_count);

		//������
		if (coordinate[0] == 6 && coordinate[1] == 9)
		{
			printf("\n");
		}
		
		//������PVP�������ù�ϣ����������PVP�������������˼·�ǣ��Ȼ��壬Ȼ���ٿ�����û�н���ϣֵ���������
		//hashValue = computeHash(board, ZobristTable);//���㵱ǰ��ֵĹ�ϣֵ
		//�����Ǹ�hashValue�ȹ��𣬿�����Ҫ�Ż��������������������
		hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];

		value = Searching_Hashing(step_count, my_turn, 0, false);
		if (value == 0)
		{
			value = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
			Searching_Hashing(step_count, my_turn, value, true);
		}

		//my_value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
		//opponent_value = evaluation(board, step_count + 1, !my_turn, coordinate[0], coordinate[1]);
		//value = my_value + opponent_value;
		//��������ֿ���ֵĿ���������
		DrawBoard(value, 1, step_count);
		return_to_normal_chess(step_count);



		printf("�Ƿ���Ҫ���壿��y���壬��������������������Ϸ.\n");
		char c_getback = ' ';
		c_getback = getchar();
		while (getchar() != '\n')
			continue;
		int i_getback = c_getback;
		if (i_getback == 89 || i_getback == 121)
		{
			board[coordinate[0]][coordinate[1]] = roaming;
			DrawBoard(value, 1, step_count);
			hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];//��һ��������

			continue;
		}
		continue_playing = judgement(step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(value, 1, step_count);
	if (step_count % 2)
	{
		printf("���ӻ�ʤ");
	}
	else
	{
		printf("���ӻ�ʤ");
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
	{
		//strncpy(board[raw][column], black, 2);
		board[raw][column] = black;
	}
	else
	{
		//strncpy(board[raw][column], white, 2);
		board[raw][column] = white;
	}

}

void return_to_normal_chess(int step_count)
	//�˺����������������͵����ӻָ��ɡ����͵�����
{
	
	int white = 119;//����
	int black = 98;//����
	int raw = coordinate[0];
	int column = coordinate[1];
	if (step_count % 2 == 0)
	{
		board[raw][column] = black;
	}
	else
	{
		board[raw][column] = white;
	}
}



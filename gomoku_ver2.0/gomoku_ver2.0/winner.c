#include<stdio.h>
#include<string.h>
#include<stdbool.h>
extern int board[15][15];
extern int w;//����
extern int b;//����
bool judgement(int step_count)
//���������ж�����һ��Ӯ
//����ֵ����ɲ�����
{
	int i, j, k;
	bool continue_playing = true;
	bool not_full = false;//�������ֵ�����жϣ������Ƿ�������
	char *chess;
	if (step_count % 2)//���step����������2�Ļ������ǰ���
	{
		chess = w;
	}
	else
	{
		chess = b;
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
			//������ˮƽ����������ӵ��ж�
		{
			if ((board[i][j] == chess)
				&& (board[i][j + 1] == chess)
				&& (board[i][j + 2] == chess)
				&& (board[i][j + 3] == chess)
				&& (board[i][j + 4] == chess))
			{
				continue_playing = false;
			}
			//��������ֱ����������ӵ��ж�
			if ((board[i][j] == chess)
				&& (board[i + 1][j] == chess)
				&& (board[i + 2][j] == chess)
				&& (board[i + 3][j] == chess)
				&& (board[i + 4][j] == chess))
			{
				continue_playing = false;
			}
			//��������������б�ߵ������ж�
			if ((board[i][j] == chess)
				&& (board[i + 1][j + 1] == chess)
				&& (board[i + 2][j + 2] == chess)
				&& (board[i + 3][j + 3] == chess)
				&& (board[i + 4][j + 4] == chess))
			{
				continue_playing = false;
			}

			//��������������б�ߵ������ж�
			if ((board[i][j] == chess)
				&& (board[i + 1][j - 1] == chess)
				&& (board[i + 2][j - 2] == chess)
				&& (board[i + 3][j - 3] == chess)
				&& (board[i + 4][j - 4] == chess))
			{
				continue_playing = false;
			}
		}
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if ((board[i][j] == 4)
				|| (board[i][j] == 10)
				|| (board[i][j] == 7)
				|| (board[i][j] == 6)
				|| (board[i][j] == 0)
				|| (board[i][j] == 9)
				|| (board[i][j] == 5)
				|| (board[i][j] == 11)
				|| (board[i][j] == 8))
			{
				not_full = true;
			}
		}
	}

	if (not_full == false)
		continue_playing = false;

	return continue_playing;

}
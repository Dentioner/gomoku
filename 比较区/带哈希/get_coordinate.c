#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
extern int board[15][15];
extern int coordinate[2];
extern int w;//����
extern int b;//����


void get_coordinate(int step_count)
{
	char column_c;//��ĸ��ʽ��������
	int raw, column;
	int raw_input_index = 0;//����scanf�ķ���ֵ
	bool invalid_coordinate = true;//�ж�ѡ����Ǹ����������ǲ����Ѿ�������������
	bool invalid_raw = true;//�ж������raw�Ƿ�Ϸ�

	while (invalid_coordinate)
	{
		//�������û���������꣬���账��
		printf("��ѡ����һ����������һ�����������磺2\n");

		while (invalid_raw)
		{
			raw_input_index = scanf("%d", &raw);
			while (getchar() != '\n')
				continue;

			if (raw_input_index != 1)
			{
				printf("��Ч���룬������\n");
				continue;
			}

			if (1 > raw || 15 < raw)
			{
				printf("��Ч���룬������\n");
				continue;
			}

			invalid_raw = false;
		}

		//����������ʱ�����޸�
		/*while (getchar() != '\n')
			continue;*/

		printf("������һ�����������磺B\n");
		column_c = getchar();
		while (getchar() != '\n')
			continue;
		while (column_c<'A' || (column_c > 'O'&&column_c < 'a') || column_c>'o')
		{
			printf("��Ч���룬������\n");

			column_c = getchar();
			while (getchar() != '\n')
				continue;

		}

		//�����ǽ��û����������ת��Ϊ������ʶ�������
		column_c = toupper(column_c);
		column = column_c - 'A';
		raw = 15 - raw;
		//�ж��Ƿ�������Ѿ���������
		if ((board[raw][column] == b)
			||(board[raw][column] == w))
		{
			printf("��λ���Ѿ��������ˣ�������ѡ��һ������\n");
			invalid_raw = true;//��������ڰ�֮ǰraw��ѭ�����ж�ֵ��ʼ����
			//���򲻻�������raw��ѭ��
			continue;
		}
		else
		{
			invalid_coordinate = false;
		}

	}

	coordinate[0] = raw;
	coordinate[1] = column;

}
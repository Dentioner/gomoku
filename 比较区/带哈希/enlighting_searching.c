#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"

extern int board[15][15];
extern int w;//����
extern int b;//����

//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js

int before_evaluation_ver4(int priority_ver2[][2], int floor, int step_count, bool my_turn)
{
	//char * temp = *chess_pointer;
	long int temp_priority[255][3] = { 0 };//�Ƚ�255���������ȫ��������
	int my_raw = 0;
	int my_column = 0;

	int index = 0;
	int i = 0;
	long int my_value = 0;
	long int opponent_value = 0;
	long int temp_value = 0;

	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ����壬�������Է�����

	for (my_raw = 0; my_raw < 15; my_raw++)
	{
		for (my_column = 0; my_column < 15; my_column++)
		{
			if ((board[my_raw][my_column] != b)
				&& (board[my_raw][my_column] != w))
			{
				/*
				if (temp != *chess_pointer)
				{
					printf(" ");
				}
				*/

				my_value = evaluation_ver2(step_count, my_turn, my_raw, my_column);
				my_value = labs(my_value);
				opponent_value = evaluation_ver2(step_count + 1, !my_turn, my_raw, my_column);
				opponent_value = labs(opponent_value);
				temp_value = my_value + opponent_value;
				if (temp_value != 0)
				{
					if (my_value >= Consecutive_Five)//�����ҷ����壬����
					{
						status = 1;
						return status;
					}
					/*
					else if (opponent_value >= Consecutive_Five)//���ֶԷ����壬����
					{
						status = 1;
						return status;
					}
					*/
					else//�������¼������
					{


						temp_priority[index][0] = temp_value;
						temp_priority[index][1] = my_raw;
						temp_priority[index][2] = my_column;
						index++;
					}
				}
			}
		}
	}

	//���ԣ���ӡtemp����
	/*
	for (int ceshi = 0; ceshi < 255; ceshi++)
	{
		printf("���֣�%d�����꣺(%d, %d)\n", temp_priority[ceshi][0], temp_priority[ceshi][1], temp_priority[ceshi][2]);
	}
	system("pause");
	*/

	quick_sort(temp_priority, 0, index - 1);//index��ֵ�ǵ�һ��0Ԫ�ص�λ��
	//���ԣ���ӡtemp����

	if (show_me_the_array)
	{

		for (int ceshi = 0; ceshi < 10; ceshi++)
		{
			printf("���֣�%d�����꣺(%d, %d)\n", temp_priority[ceshi][0], temp_priority[ceshi][1], temp_priority[ceshi][2]);
		}
		//system("pause");
	}


	for (i = 0; (i < index) && (i < 10); i++)//��temp��ǰʮ������긳ֵ�������prioriy_ver2
	{
		priority_ver2[i][0] = temp_priority[i][1];
		priority_ver2[i][1] = temp_priority[i][2];
		/*
		if (temp != *chess_pointer)
		{
			printf(" ");
		}
		*/
	}

	//���ԣ���ӡpriority����
	/*
	for (int ceshi = 0; ceshi < 10; ceshi++)
	{
		printf("���꣺(%d, %d)\n", priority_ver2[ceshi][0], priority_ver2[ceshi][1]);
	}
	system("pause");
	*/
	/*
	if (temp != *chess_pointer)
	{
		printf(" ");
	}
	*/
	return status;
}




void quick_sort(int temp_priority[][3], int l, int r)//�Զ�ά������н���Ŀ�������
{//�˺����ο�https://blog.csdn.net/morewindows/article/details/6684558
	if (l < r)
	{
		
		int i = l, j = r;
		int x[3];
		x[0] = temp_priority[l][0];
		x[1] = temp_priority[l][1];
		x[2] = temp_priority[l][2];
		while (i < j)
		{
			while (i < j && temp_priority[j][0] < x[0])
				j--;
			if (i < j)
			{
				temp_priority[i][0] = temp_priority[j][0];
				temp_priority[i][1] = temp_priority[j][1];
				temp_priority[i][2] = temp_priority[j][2];

				//system("pause");
				i++;
			}


			while (i < j && temp_priority[i][0] >= x[0])
				i++;
			if (i < j)
			{
				temp_priority[j][0] = temp_priority[i][0];
				temp_priority[j][1] = temp_priority[i][1];
				temp_priority[j][2] = temp_priority[i][2];

				//system("pause");
				j--;
			}


		}
		temp_priority[i][0] = x[0];
		temp_priority[i][1] = x[1];
		temp_priority[i][2] = x[2];
		quick_sort(temp_priority, l, i - 1);
		quick_sort(temp_priority, i + 1, r);
	}
}
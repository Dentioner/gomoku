#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>
#include<stdlib.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
unsigned long long hashing_value2[depth_of_hashing][3];

long int Searching_Hashing(int step_count, bool my_turn, long temp_score, bool write)
{
	int black = 0;
	int white = 1;
	int chess;
	int index = 0;
	if ((step_count % 2) == 0)
	{
		chess = black;
	}
	else
	{
		chess = white;
	}
	if (!write)//ֻ��ģʽ
	{


		for (index = 0; index < depth_of_hashing; index++)
		{
			//�������߼��ǣ�������û�з�0�Ĺ�ϣֵ��
			//����У��ٿ����Ƿ���������ڵĹ�ϣֵ��ȣ������ڵ�һ��Ϊ0��λ�ü�¼�������ֵ
			if (hashing_value2[index][0] != 0)//��������ϣֵ��Ϊ0
			{
				if (hashing_value2[index][0] == hashValue)//��������ϣֵ������Ĺ�ϣֵ���
				{
					//�������������������ű��Ƿ����ã���������ʱҪ������
					/*
					printf("\nfind it\n");
					system("pause");
					*/
					//�ڱ��о��ҵ��˶�Ӧ�Ĺ�ϣֵ���Ǿͷ��ض�Ӧ������
					if (my_turn)
					{//Ŀǰ[1]��¼�����ҷ��ĵ÷�
						if (hashing_value2[index][1] != 0)
						{
							return (long)hashing_value2[index][1];
						}
					}
					else//[2]��¼���ǶԷ��ĵ÷�
					{
						if (hashing_value2[index][2] != 0)
						{
							return (long)hashing_value2[index][2];
						}

					}

				}

			}

		}

		//ѭ�����꣬ʣ�µ�����ǣ���ϣ�����ˣ����ǻ���û��Ӧ��ֵ

		return 0;

	}
	else//��дģʽ
	{

		for (index = 0; index < depth_of_hashing; index++)
		{
			if (hashing_value2[index][0] == hashValue)//����ڼ�¼�Ĺ����з����Ѿ��������еļ�¼��
			{
				if (my_turn)
				{
					if ((hashing_value2[index][1] == 0) && (temp_score != 0))//�����еļ�¼�У��ҷ��÷�Ϊ0��û�еǼǹ��ҷ��÷֣����ҽ�Ҫ�Ǽǵ��ҷ��÷ֲ�Ϊ0����Ǽ��ҷ��÷�
					{
						hashing_value2[index][1] = (unsigned long long)temp_score;
						return 0; //�������Ҳֻ��ִ��һ�Σ����ִ���ˣ��ͱ�������ѭ��
					}
				}
				else
				{
					if ((hashing_value2[index][2] == 0) && (temp_score != 0))//�����еļ�¼�У��Է��÷�Ϊ0��û�еǼǹ��Է��÷֣����ҽ�Ҫ�ǼǵĶԷ��÷ֲ�Ϊ0����ǼǶԷ��÷�
					{
						hashing_value2[index][2] = (unsigned long long)temp_score;
						return 0; //�������Ҳֻ��ִ��һ�Σ����ִ���ˣ��ͱ�������ѭ��
					}
				}

			}


			else if (hashing_value2[index][0] == 0)//���û���ֳɼ�¼������һ����ϣֵΪ0�Ŀ�λ
			{

				if (my_turn)
				{
					if (temp_score != 0)//���ǼǷ�0�ĵ÷�
					{
						hashing_value2[index][0] = hashValue;
						hashing_value2[index][1] = (unsigned long long)temp_score;
					}
				}
				else
				{
					if (temp_score != 0)

					{
						hashing_value2[index][0] = hashValue;
						hashing_value2[index][2] = (unsigned long long)temp_score;
					}
				}


				return 0; //�������Ҳֻ��ִ��һ�Σ����ִ���ˣ��ͱ�������ѭ��
			}

		}
		//ѭ�����꣬ʣ�µ�����ǣ���ϣ������
		printf("full!!\n");
		system("pause");
		return 0;


	}


}
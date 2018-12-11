#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>

int board[15][15] = {0};
int coordinate[2] = { 0, 0 };
int w = 119;//����
int b = 98;//����
int roaming = 0;//���ڻ���ģ�������¼��һ���Ŀո����ĸ�λ��
unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
unsigned long long hashValue = 0;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
unsigned long long hashing_value2[depth_of_hashing][3] = { {0,0,0} };
//�ڶ�ά�ȵ�[0]���������̵Ĺ�ϣֵ
//[1]��[2]�Ǵ˹�ϣֵ��Ӧ���������֣�Ӧ�ö����ں�������
//����������µ����̹�ϣ��ע�������������ʱ��Ҫ��������ת��

void main()
{
	//int step_count = 0; //��Ϸ���˼����ӵļ���
	
	bool continue_playing = true; //ȷ����Ϸ�Ƿ����
	
	long int value = 0;//���ֺ����Ĵ��
	long int my_value = 0;//�ҷ��÷�
	long int opponent_value = 0;//�Է��÷�
	int mode_choice = 0;


	initial_board();
	mode_choice = mode_choose(mode_choice);
	if (mode_choice == 1)
	{
		pvp(value);
	}
	else
	{
		pve(value);
	}

	//DrawBoard(value, mode_choice, step_count);
}

void myprintf(int array[], int length)
{
	int index = 0;
	for (index = 0; index < length; index++)
	{
		printf("%d,", array[index]);
	}
	printf("\n");
}

void initial_board()
{
	int raw = 0;
	int column = 0;
	for (raw = 0; raw < 15; raw++)
	{
		for (column = 0; column < 15; column++)
		{
			if (column == 0)
			{
				if (raw == 0)//(0,0)�������̵����Ͻǩ���������4����
				{
					board[raw][column] = 4;
				}
				else if (raw == 14)//(14,0)�������̵����½ǩ���������5����
				{
					board[raw][column] = 5;
				}
				else//�����(x,0)�������̵�����ةģ�������6����
				{
					board[raw][column] = 6;
				}
			}
			else if (column == 14)
			{
				if (raw == 0)//(0,14)�������̵����Ͻǩ���������7����
				{
					board[raw][column] = 7;
				}
				else if (raw == 14)//(14,14)�������̵����½ǩ���������8����
				{
					board[raw][column] = 8;
				}
				else//�����(x,14)�������̵��ұ��ة̣�������9����
				{
					board[raw][column] = 9;
				}
			}
			else
			{
				if (raw == 0)//(0,x)�������̵��ϱ��أ�������10����
				{
					board[raw][column] = 10;
				}
				else if (raw == 14)//(14,x)�������̵��±��أ�������11����
				{
					board[raw][column] = 11;
				}
				else//ʣ�µĿյĵ㶼����ͨ�Ŀ�λ�࣬������0����
				{
					board[raw][column] = 0;
				}
			}
		}
	}
}

void DrawBoard(long int value, int mode_choice, int step_count)
{
	int raw, column = 0;

	char c_column;
	int i_raw;
	i_raw = 15 - coordinate[0];
	c_column = 'A' + coordinate[1];
	char *mode;
	if (mode_choice == 1)
	{
		mode = "PVP";
	}
	else
	{
		mode = "PVE";
	}
	system("cls");   //����
	printf("  ==Welcome to FiveInRow Game==\n");
	printf("          ==%s mode==\n\n", mode);
	printf("   A B C D E F G H I J K L M N O \n");

	for (raw = 0; raw < 15; raw++)
	{
		printf("%2d", 15 - raw);
		for (column = 0; column < 15; column++)
		{
			
			switch (board[raw][column])
			{
			case 0:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("��");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			case 10:
				printf("��");
				break;
			case 11:
				printf("��");
				break;
			case 119://119��ӦASCII�����Сд��ĸw����white
				printf("��");
				break;
			case 98://98��Ӧb����black
				printf("��");
				break;
			case 1://1��Ӧ���Ǹ��µ��Ǹ��������εĺ�ɫ��
				printf("��");
				break;
			case 2://2��Ӧ���Ǹ��µİ�ɫ����
				printf("��");
				break;
			default:
				break;
			}
			
		}
		printf("%2d\n", 15 - raw);
		
	}
	printf("   A B C D E F G H I J K L M N O \n");


	if (step_count != -1)
	{
		printf("�������(%d, %c), value = %ld\n", i_raw, c_column, value);
	}
}

int mode_choose(int mode_choice)
{
	
	int mode_choice_index;
	bool invalid_mode = true;

	printf("************************************************\n");
	printf("��ѡ��ģʽ\n");
	printf("1.pvp\t\t2.pve\n");
	printf("************************************************\n");
	while (invalid_mode)
	{

		mode_choice_index = scanf("%d", &mode_choice);
		while (getchar() != '\n')
			continue;
		if (mode_choice_index != 1)
		{
			printf("��Ч���룬������\n");

			continue;
		}
		if ((mode_choice != 1) && (mode_choice != 2))
		{
			printf("��Ч���룬������\n");

			continue;
		}

		invalid_mode = false;
	}


	return mode_choice;
}

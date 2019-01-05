#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include"head.h"

//���ֿ�

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//����
extern int b;//����
extern bool ai_first;



int open_base(int step_count)
{
	int vector;
	srand(time(0));
	vector = rand() % 2 ? 1 : -1;//������ɡ�1
	if (ai_first)
	{//������ֱָ���֣�ʹ�û��£�coordinate��洢��һ��������λ�ã���˿����������ж���ֱָ����бָ
		if (step_count == 2)
		{
			if ((coordinate[0] == 7) && ((coordinate[1] == 6) || (coordinate[1] == 8)))//ˮƽ�����ֱָ��������������8I����8G��
				coordinate[0] += vector;
			else if ((coordinate[1] == 7) && ((coordinate[0] == 6) || (coordinate[0] == 8)))
				coordinate[1] += vector;
			//������бָ���֣�ʹ������
			else if ((coordinate[0] == 6 && coordinate[1] == 8)//9I����
				|| (coordinate[0] == 8 && coordinate[1] == 6))//7G����
			{
				coordinate[0] = 7 + vector;
				coordinate[1] = 7 + vector;//�������7I��9G��
			}
			else if ((coordinate[0] == 8 && coordinate[1] == 8)//7I����
				|| (coordinate[0] == 6 && coordinate[1] == 6))//9G����
			{
				coordinate[0] = 7 + vector;
				coordinate[1] = 7 - vector;//�������7G��9I��
			}
			else//����бָҲ����ֱָ
				randomly_choose_a_point(7, 7);
			return 1;
		}
		else if (step_count == 4)
		{
			if (board[6][7] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;

				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][7] == w && board[6][6] == b)
			{
				if (board[5][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][8] == w && board[8][7] == b)
			{
				if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 7;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][8] == w && board[6][7] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 7;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][7] == w && board[7][8] == b)
			{
				if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][7] == w && board[7][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][6] == w && board[8][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else
					return 0;
			}

			else if (board[7][6] == w && board[6][6] == b)
			{
				if (board[5][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][8] == w && board[8][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][8] == w && board[6][6] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][8] == w && board[8][6] == b)
			{
				if (board[7][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;

			}

			else if (board[8][8] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][6] == w && board[8][8] == b)
			{
				if (board[7][9] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][9] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[9][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else if (board[8][6] == w && board[6][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 5;
					return 1;
				}
				else
					return 0;
			}
		
			else if (board[6][6] == w && board[8][6] == b)
			{
				if (board[6][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][7] == w)
				{
					coordinate[0] = 9;
					coordinate[1] = 5;
					return 1;
				}
				else if (board[9][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[9][5] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[8][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 6;
					coordinate[1] = 8;
					return 1;
				}
				else
					return 0;
			}

			else if (board[6][6] == w && board[6][8] == b)
			{
				if (board[5][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[6][9] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 7;
					return 1;
				}
				else if (board[7][9] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[7][8] == w)
				{
					coordinate[0] = 5;
					coordinate[1] = 9;
					return 1;
				}
				else if (board[8][8] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[8][6] == w)
				{
					coordinate[0] = 7;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[7][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][5] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][6] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[5][8] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else if (board[6][7] == w)
				{
					coordinate[0] = 8;
					coordinate[1] = 6;
					return 1;
				}
				else
					return 0;
			}

			else
				return 0;
		}
		else
			return 0;

		

	}
	else
		randomly_choose_a_point(coordinate[0], coordinate[1]);
	return 1;
}

void randomly_choose_a_point(int raw, int column)
{
	int vector1;
	int vector2;
	do
	{
		vector1 = rand() % 3 - 1;
		vector2 = rand() % 3 - 1;
	} while (vector1 == 0 && vector2 == 0);

	coordinate[0] = raw + vector1;
	coordinate[1] = column + vector2;
}
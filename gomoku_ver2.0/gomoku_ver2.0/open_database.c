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


void open_base()
{
	int vector;
	//int empty_point[8][2] = { {6,6},{6,7},{6,8},{7,6},{7,8},{8,6},{8,7},{8,8} };
	srand(time(0));
	vector = rand() % 2 ? 1 : -1;//������ɡ�1
	if (ai_first)
	{
		//������ֱָ���֣�ʹ�û���
		//coordinate��洢��һ��������λ�ã���˿����������ж���ֱָ����бָ
		if ((coordinate[0] == 7) &&
			((coordinate[1] == 6) || (coordinate[1] == 8)))//ˮƽ�����ֱָ��������������8I����8G��
		{
			coordinate[0] += vector;
		}
		else if ((coordinate[1] == 7) &&
			((coordinate[0] == 6) || (coordinate[0] == 8)))
		{
			coordinate[1] += vector;
		}
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
		{
			randomly_choose_a_point(7, 7);
		}
	}
	else
	{
		randomly_choose_a_point(coordinate[0], coordinate[1]);
	}
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
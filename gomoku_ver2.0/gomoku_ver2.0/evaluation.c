#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"head.h"
//��̬�Ķ����https://www.cnblogs.com/songdechiu/p/5768999.html
//https://baike.1688.com/doc/view-d3091513.html

extern int board[15][15];
extern int w;//����
extern int b;//����
long int evaluation(int step_count, bool my_turn, int raw, int column)
	//step_count�������ǣ�ȷ�������Ǻ��ӻ��ǰ���
	//my_turn �������ǣ�ȷ���������ҷ����ǵз�
	//raw��column�Ǵ������꣬�����������ĸ�λ����Ҫ����
{
	//��ȷ������ǰ����»��Ǻ�����
	int chess;
	int opponent_chess;


	long int value = 0;
	if (step_count % 2)//���step����������2�Ļ������ǰ���
	{
		chess = w;
		opponent_chess = b;
	}
	else
	{
		chess = b;
		opponent_chess = w;
	}


	//�������
		//ˮƽ����
			//�����?��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess) 
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess))
	{
		value += Consecutive_Five;
	}
	//����?����
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column + 1] == chess))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess))
	{
		value += Consecutive_Five;
	}

	//��ֱ����
		//�����?��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw + 1][column] == chess))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess))
	{
		value += Consecutive_Five;
	}

	//��?������

	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��

	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw - 1][column + 1] == chess))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw + 1][column - 1] == chess))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw + 1][column + 1] == chess))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess))
	{
		value += Consecutive_Five;
	}


	//������
		//ˮƽ����
			//_?����_��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column + 4 <= 14) && (column - 1 >= 0))
	{
		value += Open_Four;
	}

	//_��?���_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column - 2] !=chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column + 3 <= 14) && (column - 2 >= 0))
	{
		value += Open_Four;
	}

	//_���?��_��
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0) && (column + 2 <= 14))
	{
		value += Open_Four;
	}

	//_����?_��
	if ((board[raw][column - 3] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 1] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0) && (column + 1 <= 14))
	{
		value += Open_Four;
	}

	//��ֱ����
		//_?����_��
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw + 4 <= 14) && (raw - 1 >= 0))
	{
		value += Open_Four;
	}

	//_��?���_��

	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 3 <= 14))
	{
		value += Open_Four;
	}

	//_���?��_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 2 <= 14))
	{
		value += Open_Four;
	}

	//_����?_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0) && (raw + 1 <= 14))
	{
		value += Open_Four;
	}

	//����������
		//_?����_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (raw + 1 <= 14) && (column + 4 <= 14) && (column - 1 >= 0))
	{
		value += Open_Four;
	}

	//_��?���_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (raw - 3 >= 0) && (column - 2 >= 0) && (column + 3 <= 14))
	{
		value += Open_Four;
	}

	//_���?��_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 3 <= 14) && (column + 2 <= 14) && (column - 3 >= 0))
	{
		value += Open_Four;
	}

	//_����?_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (raw + 4 <= 14) && (column + 1 <= 14) && (column - 4 >= 0))
	{
		value += Open_Four;
	}

	//����������
		//_?����_��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw + 4 <= 14) && (raw - 1 >= 0) && (column - 1 >= 0) && (column + 4 <= 14))
	{
		value += Open_Four;
	}

	//_��?���_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 3 <= 14) && (column - 2 >= 0) && (column + 3 <= 14))
	{
		value += Open_Four;
	}

	//_���?��_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 2 <= 14) && (column - 3 >= 0) && (column + 2 <= 14))
	{
		value += Open_Four;
	}

	//_����?_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (raw + 1 <= 14) && (column + 1 <= 14) && (column - 4 >= 0))
	{
		value += Open_Four;
	}

	//�����ͳ����е�һ��һ���ж�
	//�ֱ�������_����__ �� _����_���
	//���Ե���������һ�֣�__����_�� ��_����_
	//��������������
		//ˮƽ����
			//_?���__��_?���_��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column - 1 >= 0))
	{
		if ((board[raw][column + 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column + 4] != chess)
			&& (board[raw][column + 4] != opponent_chess)
			&& (column + 4 <= 14))
		{
			value += Open_Three;
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0))
	{
		if ((board[raw][column + 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column + 3] != chess)
			&& (board[raw][column + 3] != opponent_chess)
			&& (column + 3 <= 14))
		{
			value += Open_Three;
		}
	}

	//_���?__��_���?_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column - 3 >= 0))
	{
		if ((board[raw][column + 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column + 2] != chess)
			&& (board[raw][column + 2] != opponent_chess)
			&& (column + 2 <= 14))
		{
			value += Open_Three;
		}
	}

	//_����_?,�������ֻ�г�����
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 5] != chess)
		&& (board[raw][column - 5] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column - 5 >= 0))
	{
		value += Gapped_Four;
	}

	//��ֱ����
		//_?���__��_?���_��
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw - 1 >= 0))
	{
		if ((board[raw + 4][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 4][column] != chess)
			&& (board[raw + 4][column] != opponent_chess)
			&& (raw + 4 <= 14))
		{
			value += Open_Three;
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw - 2 >= 0))
	{
		if ((board[raw + 3][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 3][column] != chess)
			&& (board[raw + 3][column] != opponent_chess)
			&& (raw + 3 <= 14))
		{
			value += Open_Three;
		}
	}


	//_���?__��_���?_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0))
	{
		if ((board[raw + 2][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 2][column] != chess)
			&& (board[raw + 2][column] != opponent_chess)
			&& (raw + 2 <= 14))
		{
			value += Open_Three;
		}
	}

	//_����_?,�������ֻ�г�����
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 5][column] != chess)
		&& (board[raw - 5][column] != opponent_chess)
		&& (raw - 5 >= 0))
	{
		value += Gapped_Four;
	}

	//�������µ����
		//_?���__��_?���_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
	{
		if ((board[raw - 4][column + 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 4][column + 4] != chess)
			&& (board[raw - 4][column + 4] != opponent_chess)
			&& (raw - 4 >= 0) && (column + 4 <= 14))
		{
			value += Open_Three;
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		if ((board[raw - 3][column + 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 3][column + 3] != chess)
			&& (board[raw - 3][column + 3] != opponent_chess)
			&& (raw - 3 >= 0) && (column + 3 <= 14))
		{
			value += Open_Three;
		}
	}


	//_���?__��_���?_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		if ((board[raw - 2][column + 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 2][column + 2] != chess)
			&& (board[raw - 2][column + 2] != opponent_chess)
			&& (raw - 2 >= 0) && (column + 2 <= 14))
		{
			value += Open_Three;
		}
	}

	//_����_?,�������ֻ�г�����
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 5][column - 5] != chess)
		&& (board[raw + 5][column - 5] != opponent_chess)
		&& (raw + 5 <= 14) && (column - 5 >= 0))
	{
		value += Gapped_Four;
	}

	//�������·���
		//_?���__��_?���_��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
	{
		if ((board[raw + 4][column + 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 4][column + 4] != chess)
			&& (board[raw + 4][column + 4] != opponent_chess)
			&& (raw + 4 <= 14) && (column + 4 <= 14))
		{
			value += Open_Three;
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		if ((board[raw + 3][column + 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 3][column + 3] != chess)
			&& (board[raw + 3][column + 3] != opponent_chess)
			&& (raw + 3 <= 14) && (column + 3 <= 14))
		{
			value += Open_Three;
		}
	}


	//_���?__��_���?_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		if ((board[raw + 2][column + 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 2][column + 2] != chess)
			&& (board[raw + 2][column + 2] != opponent_chess)
			&& (raw + 2 <= 14) && (column + 2 <= 14))
		{
			value += Open_Three;
		}
	}

	//_����_?,�������ֻ�г�����
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 5][column - 5] != chess)
		&& (board[raw - 5][column - 5] != opponent_chess)
		&& (raw - 5 >= 0) && (column - 5 >= 0))
	{
		value += Gapped_Four;
	}

	//�����ͳ����е�һ��һ���ж�
	//�ֱ�������_����__ �� _����_���
	//���Ե���������һ�֣�__����_�� ��_����_
	//����������������  ��Ҫ�ų��������__����__�����־ͺ�֮ǰ���ظ��ˡ�
	//����Ҫ�ų�__����_��������
		//ˮƽ����
			//__���?_�� ��_���?_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)//�ų�__����_��������
		&& (column + 1 <= 14))
	{
		if ((board[raw][column - 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column - 4] != chess)
			&& (board[raw][column - 4] != opponent_chess)
			&& (column - 4 >= 0))
		{
			value += Open_Three;

			if ((board[raw][column + 2] != chess)
				&& (board[raw][column + 2] != opponent_chess)
				&& (column + 2 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__��?��_�� ��_��?��_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)//�ų�__����_��������
		&& (column + 2 <= 14))
	{
		if ((board[raw][column - 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column - 3] != chess)
			&& (board[raw][column - 3] != opponent_chess)
			&& (column - 3 >= 0))
		{
			value += Open_Three;
			if ((board[raw][column + 3] != chess)
				&& (board[raw][column + 3] != opponent_chess)
				&& (column + 3 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__?���_�� ��_?���_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 4] != chess)//�ų�__����_��������
		&& (column + 3 <= 14))
	{
		if ((board[raw][column - 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw][column - 2] != chess)
			&& (board[raw][column - 2] != opponent_chess)
			&& (column - 2 >= 0))
		{
			value += Open_Three;
			if ((board[raw][column + 4] != chess)
				&& (board[raw][column + 4] != opponent_chess)
				&& (column + 4 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//?_����_�������ֻ�г�����
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 5] != chess)
		&& (board[raw][column + 5] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 6] != chess)//�ų�__����_��������
		&& (column + 5 <= 14))
	{
		value += Gapped_Four;
	}

	//��ֱ����
		//__���?_�� ��_���?_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)//�ų�__����_��������
		&& (raw + 1 <= 14))
	{
		if ((board[raw - 4][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 4][column] != chess)
			&& (board[raw - 4][column] != opponent_chess)
			&& (raw - 4 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 2][column] != chess)
				&& (board[raw + 2][column] != opponent_chess)
				&& (raw + 2 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__��?��_�� ��_��?��_
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)//�ų�__����_��������
		&& (raw + 2 <= 14))
	{
		if ((board[raw - 3][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 3][column] != chess)
			&& (board[raw - 3][column] != opponent_chess)
			&& (raw - 3 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 3][column] != chess)
				&& (board[raw + 3][column] != opponent_chess)
				&& (raw + 3 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__?���_�� ��_?���_
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)//�ų�__����_��������
		&& (raw + 3 <= 14))
	{
		if ((board[raw - 2][column] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 2][column] != chess)
			&& (board[raw - 2][column] != opponent_chess)
			&& (raw - 2 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 4][column] != chess)
				&& (board[raw + 4][column] != opponent_chess)
				&& (raw + 4 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//?_����_�������ֻ�г�����
	if ((board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 5][column] != chess)
		&& (board[raw + 5][column] != opponent_chess)
		&& (board[raw + 6][column] != chess)//�ų�__����_��������
		&& (raw + 5 <= 14))
	{
		value += Gapped_Four;
	}



	//�������·���
		//__���?_�� ��_���?_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)//�ų�__����_��������
		&& (raw - 1 >= 0) && (column + 1 <= 14))
	{
		if ((board[raw + 4][column - 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 4][column - 4] != chess)
			&& (board[raw + 4][column - 4] != opponent_chess)
			&& (raw + 4 <= 14) && (column - 4 >= 0))
		{
			value += Open_Three;
			if ((board[raw - 2][column + 2] != chess)
				&& (board[raw - 2][column + 2] != opponent_chess)
				&& (raw - 2 >= 0) && (column + 2 <= 14))
			{
				value -= Open_Three;
			}
		}
	}


	//__��?��_�� ��_��?��_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)//�ų�__����_��������
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		if ((board[raw + 3][column - 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 3][column - 3] != chess)
			&& (board[raw + 3][column - 3] != opponent_chess)
			&& (raw + 3 <= 14) && (column - 3 >= 0))
		{
			value += Open_Three;
			if ((board[raw - 3][column + 3] != chess)
				&& (board[raw - 3][column + 3] != opponent_chess)
				&& (raw - 3 >= 0) && (column + 3 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__?���_�� ��_?���_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)//�ų�__����_��������
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		if ((board[raw + 2][column - 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw + 2][column - 2] != chess)
			&& (board[raw + 2][column - 2] != opponent_chess)
			&& (raw + 2 <= 14) && (column - 2 >= 0))
		{
			value += Open_Three;
			if ((board[raw - 4][column + 4] != chess)
				&& (board[raw - 4][column + 4] != opponent_chess)
				&& (raw - 4 >= 0) && (column + 4 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//?_����_�������ֻ�г�����
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 5][column + 5] != chess)
		&& (board[raw - 5][column + 5] != opponent_chess)
		&& (board[raw - 6][column + 6] != chess)//�ų�__����_��������
		&& (raw - 5 >= 0) && (column + 5 <= 14))
	{
		value += Gapped_Four;
	}

	//�������·���
		//__���?_�� ��_���?_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)//�ų�__����_��������
		&& (raw + 1 <= 14) && (column + 1 <= 14))
	{
		if ((board[raw - 4][column - 4] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 4][column - 4] != chess)
			&& (board[raw - 4][column - 4] != opponent_chess)
			&& (raw - 4 >= 0) && (column - 4 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 2][column + 2] != chess)
				&& (board[raw + 2][column + 2] != opponent_chess)
				&& (raw + 2 <= 14) && (column + 2 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//__��?��_�� ��_��?��_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)//�ų�__����_��������
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		if ((board[raw - 3][column - 3] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 3][column - 3] != chess)
			&& (board[raw - 3][column - 3] != opponent_chess)
			&& (raw - 3 >= 0)&(column - 3 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 3][column + 3] != chess)
				&& (board[raw + 3][column + 3] != opponent_chess)
				&& (raw + 3 <= 14) && (column + 3 <= 14))
			{
				value -= Open_Three;
			}
		}
	}


	//__?���_�� ��_?���_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)//�ų�__����_��������
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		if ((board[raw - 2][column - 2] == chess))
		{
			value += Gapped_Four;
		}
		else if ((board[raw - 2][column - 2] != chess)
			&& (board[raw - 2][column - 2] != opponent_chess)
			&& (raw - 2 >= 0)&(column - 2 >= 0))
		{
			value += Open_Three;
			if ((board[raw + 4][column + 4] != chess)
				&& (board[raw + 4][column + 4] != opponent_chess)
				&& (raw + 4 <= 14) && (column + 4 <= 14))
			{
				value -= Open_Three;
			}
		}
	}

	//?_����_�������ֻ�г�����
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 5][column + 5] != chess)
		&& (board[raw + 5][column + 5] != opponent_chess)
		&& (board[raw + 6][column + 6] != chess)//�ų�__����_��������
		&& (raw + 5 <= 14) && (column + 5 <= 14))
	{
		value += Gapped_Four;
	}



	//�����ġ��_���Gapped22
		//ˮƽ����
			//?��_���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//��?_���
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_?��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_��?
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//��ֱ����
		//?��_���
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//��?_���
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_?��
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_��?
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//�������·���
		//?��_���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//��?_���
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_?��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_��?
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//�������·���
		//?��_���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//��?_���
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_?��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}

	//���_��?
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess))
	{
		value += Gapped_Two_Two;
	}


	//������Capped_Four ������_������һ�ַ�����������棬������дһ�ַ���
		// ˮƽ����
			// ��?����_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column - 1] == opponent_chess) || (column - 1 < 0))
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Four;
	}

	// ���?���_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column - 2] == opponent_chess) || (column - 2 < 0))
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14))
	{
		value += Capped_Four;
	}
	// ����?��_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] == chess)
		&& ((board[raw][column - 3] == opponent_chess)|| (column - 3 < 0))
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 2 <= 14))
	{
		value += Capped_Four;
	}
	// �����?_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column - 4] == opponent_chess)|| (column - 4 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column + 1 <= 14))
	{
		value += Capped_Four;
	}
	//��ֱ����
		// ��?����_
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw - 1][column] == opponent_chess)|| (raw - 1 < 0))
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Four;
	}

	// ���?���_

	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw - 2][column] == opponent_chess)|| (raw - 2 < 0))
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14))
	{
		value += Capped_Four;
	}
	// ����?��_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& ((board[raw - 3][column] == opponent_chess)|| (raw - 3 < 0))
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 2 <= 14))
	{
		value += Capped_Four;
	}
	// �����?_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw - 4][column] == opponent_chess)|| (raw - 4 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (raw + 1 <= 14))
	{
		value += Capped_Four;
	}

	//�������·���
		// ��?����_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw + 1][column - 1] == opponent_chess)|| (raw + 1 > 14) || (column - 1 < 0))
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		value += Capped_Four;
	}

	// ���?���_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw + 2][column - 2] == opponent_chess)|| (raw + 2 > 14) || (column - 2 < 0))
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		value += Capped_Four;
	}

	// ����?��_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& ((board[raw + 3][column - 3] == opponent_chess)|| (raw + 3 > 14) || (column - 3 < 0))
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		value += Capped_Four;
	}

	// �����?_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw + 4][column - 4] == opponent_chess)|| (raw + 4 > 14) || (column - 4 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Capped_Four;
	}

	//�������·���
		// ��?����_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw - 1][column - 1] == opponent_chess)|| (raw - 1 < 0) || (column - 1 < 0))
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14))
	{
		value += Capped_Four;
	}

	// ���?���_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw - 2][column - 2] == opponent_chess)|| (raw - 2 < 0) || (column - 2 < 0))
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		value += Capped_Four;
	}

	// ����?��_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& ((board[raw - 3][column - 3] == opponent_chess)|| (raw - 3 < 0) || (column - 3 < 0))
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		value += Capped_Four;
	}

	// �����?_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw - 4][column - 4] == opponent_chess)|| (raw - 4 < 0) || (column - 4 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Capped_Four;
	}

	//���ĵ�����һ�ַ���_������
		// ˮƽ����
			// _����?��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column + 1] == opponent_chess)|| (column + 1 > 14))
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Capped_Four;
	}
	// _���?���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column + 2] == opponent_chess)|| (column + 2 > 14))
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0))
	{
		value += Capped_Four;
	}

	// _��?����
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column - 1] == chess)
		&& ((board[raw][column + 3] == opponent_chess)|| (column + 3 > 14))
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}

	// _?�����
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column + 4] == opponent_chess)|| (column + 4 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column - 1 >= 0))
	{
		value += Capped_Four;
	}

	//��ֱ����
		// _����?��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw + 1][column] == opponent_chess)|| (raw + 1 > 14))
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Capped_Four;
	}

	// _���?���
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw + 2][column] == opponent_chess)|| (raw + 2 > 14))
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0))
	{
		value += Capped_Four;
	}

	// _��?����
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& ((board[raw + 3][column] == opponent_chess)|| (raw + 3 > 14))
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 2 >= 0))
	{
		value += Capped_Four;
	}

	// _?�����
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw + 4][column] == opponent_chess)|| (raw + 4 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw - 1 >= 0))
	{
		value += Capped_Four;
	}

	//�������·���
		// _����?��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw - 1][column + 1] == opponent_chess)|| (raw - 1 < 0) || (column + 1 > 14))
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		value += Capped_Four;
	}

	// _���?���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw - 2][column + 2] == opponent_chess)|| (raw - 2 < 0) || (column + 2 > 14))
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Four;
	}

	// _��?����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& ((board[raw - 3][column + 3] == opponent_chess)|| (raw - 3 < 0) || (column + 3 > 14))
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Four;
	}

	// _?�����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw - 4][column + 4] == opponent_chess)|| (raw - 4 < 0) || (column + 4 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Four;
	}

	//�������·���
		// _����?��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw + 1][column + 1] == opponent_chess)|| (raw + 1 > 14) || (column + 1 > 14))
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0))
	{
		value += Capped_Four;
	}

	// _���?���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw + 2][column + 2] == opponent_chess)|| (raw + 2 > 14) || (column + 2 > 14))
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		value += Capped_Four;
	}


	// _��?����
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& ((board[raw + 3][column + 3] == opponent_chess)|| (raw + 3 > 14) || (column + 3 > 14))
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Capped_Four;
	}

	// _?�����
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw + 4][column + 4] == opponent_chess)|| (raw + 4 > 14) || (column + 4 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Capped_Four;
	}


	//���������Gapped_Three  _��_���_��_���_��_

		//ˮƽ����
		//�ȼ��_��_���_
			//_?_���_
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//_��_?��_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0) && (column + 2 <= 14))
	{
		value += Gapped_Three;
	}

	//_��_��?_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//_��?_��_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 2 >= 0))
	{
		value += Gapped_Three;
	}

	//_?��_��_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}


	//��ֱ����
	//�ȼ��_��_���_
		//_?_���_
	if ((board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14) && (raw - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//_��_?��_
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 2 <= 14))
	{
		value += Gapped_Three;
	}

	//_��_��?_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0) && (raw + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0) && (raw + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//_��?_��_
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 2 >= 0))
	{
		value += Gapped_Three;
	}

	//_?��_��_
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14) && (raw - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//�������·���
	//�ȼ��_��_���_
		//_?_���_
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14) && (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//_��_?��_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0) && (raw - 2 >= 0) && (column + 2 <= 14))
	{
		value += Gapped_Three;
	}

	//_��_��?_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0) && (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0) && (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//_��?_��_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column + 3 <= 14) && (raw + 2 <= 14) && (column - 2 >= 0))
	{
		value += Gapped_Three;
	}

	//_?��_��_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14) && (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//�������·���
	//�ȼ��_��_���_
		//_?_���_
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14) && (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//_��_?��_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0) && (raw + 2 <= 14) && (column + 2 <= 14))
	{
		value += Gapped_Three;
	}

	//_��_��?_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0) && (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0) && (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Gapped_Three;
	}

	//_��?_��_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column + 3 <= 14) && (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Gapped_Three;
	}

	//_?��_��_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14) && (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Gapped_Three;
	}

	//���������Capped_Three
	//1. �����__��__�������
		//ˮƽ����
		//���ǡ����__
			//��?���__

	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column - 1] == opponent_chess)|| (column - 1 < 0))
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?��__

	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& ((board[raw][column - 2] == opponent_chess)|| (column - 2 < 0))
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����?__

	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column - 3] == opponent_chess)|| (column - 3 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//����__�����
		//__���?��

	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column + 1] == opponent_chess)|| (column + 1 > 14))
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//__��?���

	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] == chess)
		&& ((board[raw][column + 2] == opponent_chess)|| (column + 2 > 14))
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//__?����

	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column + 3] == opponent_chess)|| (column + 3 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//��ֱ����
	//���ǡ����__
		//��?���__

	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw - 1][column] == opponent_chess)|| (raw - 1 < 0))
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?��__

	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& ((board[raw - 2][column] == opponent_chess)|| (raw - 2 < 0))
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����?__

	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw - 3][column] == opponent_chess)|| (raw - 3 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 2 <= 14))
	{
		value += Capped_Three;
	}

	//����__�����
		//__���?��

	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw + 1][column] == opponent_chess)|| (raw + 1 > 14))
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Capped_Three;
	}

	//__��?���

	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& ((board[raw + 2][column] == opponent_chess)|| (raw + 2 > 14))
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0))
	{
		value += Capped_Three;
	}

	//__?����

	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw + 3][column] == opponent_chess)|| (raw + 3 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 2 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ����__
		//��?���__

	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw + 1][column - 1] == opponent_chess)|| (raw + 1 > 14) || (column - 1 < 0))
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?��__

	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& ((board[raw + 2][column - 2] == opponent_chess)|| (raw + 2 > 14) || (column - 2 < 0))
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����?__

	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw + 3][column - 3] == opponent_chess)|| (raw + 3 > 14) || (column - 3 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//����__�����
		//__���?��

	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw - 1][column + 1] == opponent_chess)|| (raw - 1 < 0) || (column + 1 > 14))
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//__��?���

	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& ((board[raw - 2][column + 2] == opponent_chess)|| (raw - 2 < 0) || (column + 2 > 14))
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//__?����

	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw - 3][column + 3] == opponent_chess)|| (raw - 3 < 0) || (column + 3 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ����__
		//��?���__

	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw - 1][column - 1] == opponent_chess)|| (raw - 1 < 0) || (column - 1 < 0))
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?��__

	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& ((board[raw - 2][column - 2] == opponent_chess)|| (raw - 2 < 0) || (column - 2 < 0))
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����?__

	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw - 3][column - 3] == opponent_chess)|| (raw - 3 < 0) || (column - 3 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//����__�����
		//__���?��

	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw + 1][column + 1] == opponent_chess)|| (raw + 1 > 14) || (column + 1 > 14))
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//__��?���

	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& ((board[raw + 2][column + 2] == opponent_chess)|| (raw + 2 > 14) || (column + 2 > 14))
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//__?����

	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw + 3][column + 3] == opponent_chess)|| (raw + 3 > 14) || (column + 3 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//2.����_��_��_��_����
		//ˮƽ����
		//���ǡ���_��_
			//��?��_��_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column - 1] == opponent_chess)|| (column - 1 < 0))
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?_��_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column - 2] == opponent_chess)|| (column - 2 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����_?_
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column - 4] == opponent_chess)|| (column - 4 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_��_����
		//_��_��?��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column + 1] == opponent_chess)|| (column + 1 > 14))
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��_?���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column + 2] == opponent_chess)|| (column + 2 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//_?_����
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column + 4] == opponent_chess)|| (column + 4 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//��ֱ����
	//���ǡ���_��_
		//��?��_��_
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw - 1][column] == opponent_chess)|| (raw - 1 < 0))
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?_��_
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw - 2][column] == opponent_chess)|| (raw - 2 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����_?_
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw - 4][column] == opponent_chess)|| (raw - 4 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_��_����
		//_��_��?��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw + 1][column] == opponent_chess)|| (raw + 1 > 14))
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��_?���
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw + 2][column] == opponent_chess)|| (raw + 2 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0))
	{
		value += Capped_Three;
	}

	//_?_����
	if ((board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw + 4][column] == opponent_chess)|| (raw + 4 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (raw - 1 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ���_��_
		//��?��_��_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw + 1][column - 1] == opponent_chess)|| (raw + 1 > 14) || (column - 1 < 0))
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?_��_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw + 2][column - 2] == opponent_chess)|| (raw + 2 > 14) || (column - 2 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����_?_
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw + 4][column - 4] == opponent_chess)|| (raw + 4 > 14) || (column - 4 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_��_����
		//_��_��?��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw - 1][column + 1] == opponent_chess)|| (raw - 1 < 0) || (column + 1 > 14))
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��_?���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw - 2][column + 2] == opponent_chess)|| (raw - 2 < 0) || (column + 2 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//_?_����
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw - 4][column + 4] == opponent_chess)|| (raw - 4 < 0) || (column + 4 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ���_��_
		//��?��_��_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw - 1][column - 1] == opponent_chess)|| (raw - 1 < 0) || (column - 1 < 0))
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���?_��_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw - 2][column - 2] == opponent_chess)|| (raw - 2 < 0) || (column - 2 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		value += Capped_Three;
	}

	//����_?_
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw - 4][column - 4] == opponent_chess)|| (raw - 4 < 0) || (column - 4 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_��_����
		//_��_��?��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw + 1][column + 1] == opponent_chess)|| (raw + 1 > 14) || (column + 1 > 14))
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��_?���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw + 2][column + 2] == opponent_chess)|| (raw + 2 > 14) || (column + 2 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//_?_����
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw + 4][column + 4] == opponent_chess)|| (raw + 4 > 14) || (column + 4 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//3.���_���_��_���_���
		//ˮƽ����
		//���ǡ��_���_
			//��?_���_
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column - 1] == opponent_chess)|| (column - 1 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���_?��_
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column - 3] == opponent_chess)|| (column - 3 < 0))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//���_��?_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column - 4] == opponent_chess)|| (column - 4 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_���_���
		//_���_?��
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column + 1] == opponent_chess)|| (column + 1 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��?_���
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column + 3] == opponent_chess)|| (column + 3 > 14))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 > 1))
	{
		value += Capped_Three;
	}

	//_?��_���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column + 4] == opponent_chess)|| (column + 4 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column - 1 > 1))
	{
		value += Capped_Three;
	}

	//��ֱ����
	//���ǡ��_���_
		//��?_���_
	if ((board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw - 1][column] == opponent_chess)|| (raw - 1 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���_?��_
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw - 3][column] == opponent_chess)|| (raw - 3 < 0))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 2 <= 14))
	{
		value += Capped_Three;
	}

	//���_��?_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw - 4][column] == opponent_chess)|| (raw - 4 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_���_���
		//_���_?��
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw + 1][column] == opponent_chess)|| (raw + 1 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��?_���
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw + 3][column] == opponent_chess)|| (raw + 3 > 14))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 2 >= 0))
	{
		value += Capped_Three;
	}

	//_?��_���
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw + 4][column] == opponent_chess)|| (raw + 4 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw - 1 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ��_���_
		//��?_���_
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw + 1][column - 1] == opponent_chess)|| (raw + 1 > 14) || (column - 1 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���_?��_
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw + 3][column - 3] == opponent_chess)|| (raw + 3 > 14) || (column - 3 < 0))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//���_��?_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw + 4][column - 4] == opponent_chess)|| (raw + 4 > 14) || (column - 4 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_���_���
		//_���_?��
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw - 1][column + 1] == opponent_chess)|| (raw - 1 < 0) || (column + 1 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��?_���
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw - 3][column + 3] == opponent_chess)|| (raw - 3 < 0) || (column + 3 > 14))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//_?��_���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw - 4][column + 4] == opponent_chess)|| (raw - 4 < 0) || (column + 4 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ��_���_
		//��?_���_
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw - 1][column - 1] == opponent_chess)|| (raw - 1 < 0) || (column - 1 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (raw + 4 <= 14) && (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//���_?��_
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw - 3][column - 3] == opponent_chess)|| (raw - 3 < 0) || (column - 3 < 0))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		value += Capped_Three;
	}

	//���_��?_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw - 4][column - 4] == opponent_chess)|| (raw - 4 < 0) || (column - 4 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Capped_Three;
	}

	//����_���_���
		//_���_?��
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw + 1][column + 1] == opponent_chess)|| (raw + 1 > 14) || (column + 1 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (raw - 4 >= 0) && (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//_��?_���
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw + 3][column + 3] == opponent_chess)|| (raw + 3 > 14) || (column + 3 > 14))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//_?��_���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw + 4][column + 4] == opponent_chess)|| (raw + 4 > 14) || (column + 4 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}
	//�������������п��ܲ�̫��
	//��Ϊ��֪�������֡��__�񣬻���_���__��_֮���
	//4. ���__��͡�__���
		//ˮƽ����
		//���ǡ��__��
			//?��__��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���ǡ�__���
		//��__��?
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��ֱ����
	//���ǡ��__��
		//?��__��
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���ǡ�__���
		//��__��?
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ��__��
		//?��__��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���ǡ�__���
		//��__��?
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
	//���ǡ��__��
		//?��__��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//���ǡ�__���
		//��__��?
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//5. ��_��_��
	//ע������������_��_�����_��_��_��_�ǲ�̫һ����
	//��ʱ�Ȳ�����������������
		//ˮƽ����
			//?_��_��
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��ֱ����
		//?_��_��
	if ((board[raw + 2][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw + 2][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
		//?_��_��
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
		//?_��_��
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess))
	{
		value += Capped_Three;
	}

	//6. ��_����_����
		//ˮƽ����
			//��_?���_��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column - 2] == opponent_chess)|| (column - 2 < 0))
		&& ((board[raw][column + 4] == opponent_chess)|| (column + 4 > 14))
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��?��_��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] == chess)
		&& ((board[raw][column + 3] == opponent_chess)|| (column + 3 > 14))
		&& ((board[raw][column - 3] == opponent_chess)|| (column - 3 < 0))
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_���?_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column + 2] == opponent_chess)|| (column + 2 > 14))
		&& ((board[raw][column - 4] == opponent_chess)|| (column - 4 < 0))
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��ֱ����
		//��_?���_��
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw - 2][column] == opponent_chess)|| (raw - 2 < 0))
		&& ((board[raw + 4][column] == opponent_chess)|| (raw + 4 > 14))
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��?��_��
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& ((board[raw + 3][column] == opponent_chess)|| (raw + 3 > 14))
		&& ((board[raw - 3][column] == opponent_chess)|| (raw - 3 < 0))
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_���?_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw + 2][column] == opponent_chess)|| (raw + 2 > 14))
		&& ((board[raw - 4][column] == opponent_chess)|| (raw - 4 < 0))
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
		//��_?���_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw + 2][column - 2] == opponent_chess)|| (raw + 2 > 14) || (column - 2 < 0))
		&& ((board[raw - 4][column + 4] == opponent_chess)|| (raw - 4 < 0) || (column + 4 > 14))
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_��?��_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& ((board[raw - 3][column + 3] == opponent_chess)|| (raw - 3 < 0) || (column + 3 > 14))
		&& ((board[raw + 3][column - 3] == opponent_chess)|| (raw + 3 > 14) || (column - 3 < 0))
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_���?_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw - 2][column + 2] == opponent_chess)|| (raw - 2 < 0) || (column + 2 > 14))
		&& ((board[raw + 4][column - 4] == opponent_chess)|| (raw + 4 > 14) || (column - 4 < 0))
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess))
	{
		value += Capped_Three;
	}

	//�������·���
		//��_?���_��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw - 2][column - 2] == opponent_chess)|| (raw - 2 < 0) || (column - 2 < 0))
		&& ((board[raw + 4][column + 4] == opponent_chess)|| (raw + 4 > 14) || (column + 4 > 14))
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess, 2)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess, 2))
	{
		value += Capped_Three;
	}

	//��_��?��_��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& ((board[raw + 3][column + 3] == opponent_chess)|| (raw + 3 > 14) || (column + 3 > 14))
		&& ((board[raw - 3][column - 3] == opponent_chess)|| (raw - 3 < 0) || (column - 3 < 0))
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess, 2)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess))
	{
		value += Capped_Three;
	}

	//��_���?_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw + 2][column + 2] == opponent_chess)|| (raw + 2 > 14) || (column + 2 > 14))
		&& ((board[raw - 4][column - 4] == opponent_chess)|| (raw - 4 < 0) || (column - 4 < 0))
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess, 2)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess, 2))
	{
		value += Capped_Three;
	}
	//���� ___���__ & __���___
		//ˮƽ����
		//�ȼ��___���__
			//___?��__
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0))
	{
		value += Open_two;
	}

	//___��?__
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column - 4] != chess)
		&& (board[raw][column - 4] != opponent_chess)
		&& (column + 2 <= 14) && (column - 4 >= 0))
	{
		value += Open_two;
	}
	//�ټ��__���___
		//__��?___
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0))
	{
		value += Open_two;
		if ((board[raw][column - 4] != chess)
			&& (board[raw][column - 4] != opponent_chess)
			&& (column - 4 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//__?��___
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (board[raw][column + 4] != chess)
		&& (board[raw][column + 4] != opponent_chess)
		&& (column + 4 <= 14) && (column - 2 >= 0))
	{
		value += Open_two;

		if ((board[raw][column - 3] != chess)
			&& (board[raw][column - 3] != opponent_chess)
			&& (column - 3 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//��ֱ����
	//�ȼ��___���__
		//___?��__
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
	}

	//___��?__
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (board[raw - 4][column] != chess)
		&& (board[raw - 4][column] != opponent_chess)
		&& (raw + 2 <= 14) && (raw - 4 >= 0))
	{
		value += Open_two;
	}
	//�ټ��__���___
		//__��?___
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
		if ((board[raw - 4][column] != chess)
			&& (board[raw - 4][column] != opponent_chess)
			&& (raw - 4 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//__?��___
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (board[raw + 4][column] != chess)
		&& (board[raw + 4][column] != opponent_chess)
		&& (raw + 4 <= 14) && (raw - 2 >= 0))
	{
		value += Open_two;
		if ((board[raw - 3][column] != chess)
			&& (board[raw - 3][column] != opponent_chess)
			&& (raw - 3 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//�������·���
		//�ȼ��___���__
			//___?��__
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0) && (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
	}

	//___��?__
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw + 4][column - 4] != chess)
		&& (board[raw + 4][column - 4] != opponent_chess)
		&& (column + 2 <= 14) && (column - 4 >= 0) && (raw + 4 <= 14) && (raw - 2 >= 0))
	{
		value += Open_two;
	}
	//�ټ��__���___
		//__��?___
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0) && (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
		if ((board[raw + 4][column - 4] != chess)
			&& (board[raw + 4][column - 4] != opponent_chess)
			&& (raw + 4 <= 14) && (column - 4 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//__?��___
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (board[raw - 4][column + 4] != chess)
		&& (board[raw - 4][column + 4] != opponent_chess)
		&& (column + 4 <= 14) && (column - 2 >= 0) && (raw + 2 <= 14) && (raw - 4 >= 0))
	{
		value += Open_two;
		if ((board[raw + 3][column - 3] != chess)
			&& (board[raw + 3][column - 3] != opponent_chess)
			&& (raw + 3 <= 14) && (column - 3 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//�������·���
	//�ȼ��___���__
		//___?��__
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0) && (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
	}

	//___��?__
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (board[raw - 4][column - 4] != chess)
		&& (board[raw - 4][column - 4] != opponent_chess)
		&& (column + 2 <= 14) && (column - 4 >= 0) && (raw + 2 <= 14) && (raw - 4 >= 0))
	{
		value += Open_two;
	}

	//�ټ��__���___
		//__��?___
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (column + 3 <= 14) && (column - 3 >= 0) && (raw + 3 <= 14) && (raw - 3 >= 0))
	{
		value += Open_two;
		if ((board[raw - 4][column - 4] != chess)
			&& (board[raw - 4][column - 4] != opponent_chess)
			&& (raw - 4 >= 0) && (column - 4 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//__?��___
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (board[raw + 4][column + 4] != chess)
		&& (board[raw + 4][column + 4] != opponent_chess)
		&& (column + 4 <= 14) && (column - 2 >= 0) && (raw + 4 <= 14) && (raw - 2 >= 0))
	{
		value += Open_two;
		if ((board[raw - 3][column - 3] != chess)
			&& (board[raw - 3][column - 3] != opponent_chess)
			&& (raw - 3 >= 0) && (column - 3 >= 0))
		{//�ų�___���___
			value -= Open_two;
		}
	}
	//���������������Է��ķ����������Ϊ��
	//���ڵ������ǣ���������Ǽ����Է�����һ�Σ�����һ���������潫˫��������һ�Σ�
	//Ŀǰ�Ĵ����ǣ���������������Է�����һ�Σ��ò�����my_turn����


	if (!my_turn)
	{
		value *= -1;
	}
	return value;

}






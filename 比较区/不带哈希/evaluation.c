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
	//int state = 0;//״̬�����������ڲ���˫����˫����֮���
	bool state[4] = { false, false, false, false };//״̬��¼����Ϊ4�����򣬷ֱ���ˮƽ����ֱ���������£���������

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
		&& (board[raw][column - 4] == chess)
		&& (column - 4 >= 0))
	{
		value += Consecutive_Five;
	}
	//����?����
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column + 1] == chess)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (column - 2 >= 0 ) && (column + 2 <= 14))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (column + 4 <= 14))
	{
		value += Consecutive_Five;
	}

	//��ֱ����
		//�����?��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (raw - 4 >= 0))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (raw - 3 >=0 )&& (raw + 1 <= 14))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (raw - 2 >= 0)&&(raw + 2 <= 14))
	{
		value += Consecutive_Five;
	}

	//��?������

	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (raw - 1 >= 0) && (raw + 3 <= 14))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (raw + 4 <= 14))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��

	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0) 
		&& (column - 3 >= 0) && (column + 1 <= 14))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (raw + 2 <= 14) && (raw - 2 >= 0)
		&& (column - 2 >= 0) && (column + 2 <= 14))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0)
		&& (column - 1 >= 0) && (column + 3 <= 14))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (raw - 4 >= 0)
		&& (column + 4 <= 14))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (raw - 4 >= 0)
		&& (column - 4 >= 0))
	{
		value += Consecutive_Five;
	}

	//����?����
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0)
		&& (column - 3 >= 0) && (column + 1 <= 14))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (raw + 2 <= 14) && (raw - 2 >= 0)
		&& (column - 2 >= 0) && (column + 2 <= 14))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0)
		&& (column - 1 >= 0) && (column + 3 <= 14))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (raw + 4 <= 14)
		&& (column + 4 <= 14))
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
		&& (column - 1 >= 0)
		&& (column + 4 <= 14))
	{
		if ((board[raw][column + 4] == chess))
		{
			value += Gapped_Four;
			state[0] = true;
		}
		else if ((board[raw][column + 4] != chess)
			&& (board[raw][column + 4] != opponent_chess)
			&& (column + 4 <= 14))
		{
			value += Open_Three;
			state[0] = true;
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0)
		&& (column + 3 <= 14))
	{
		if ((board[raw][column + 3] == chess))
		{
			value += Gapped_Four;
			state[0] = true;
		}
		else if ((board[raw][column + 3] != chess)
			&& (board[raw][column + 3] != opponent_chess)
			&& (column + 3 <= 14))
		{
			value += Open_Three;
			state[0] = true;
		}
	}

	//_���?__��_���?_��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column - 3 >= 0)
		&& (column + 2 <= 14))
	{
		if ((board[raw][column + 2] == chess))
		{
			value += Gapped_Four;
			state[0] = true;
		}
		else if ((board[raw][column + 2] != chess)
			&& (board[raw][column + 2] != opponent_chess)
			&& (column + 2 <= 14))
		{
			value += Open_Three;
			state[0] = true;
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
		state[0] = true;
	}

	//��ֱ����
		//_?���__��_?���_��
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw - 1 >= 0)
		&& (raw + 4 <= 14))
	{
		if ((board[raw + 4][column] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw + 4][column] != chess)
			&& (board[raw + 4][column] != opponent_chess)
			&& (raw + 4 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw - 2 >= 0)
		&& (raw + 3 <= 14))
	{
		if ((board[raw + 3][column] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw + 3][column] != chess)
			&& (board[raw + 3][column] != opponent_chess)
			&& (raw + 3 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
	}


	//_���?__��_���?_��
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0)
		&& (raw + 2 <= 14))
	{
		if ((board[raw + 2][column] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw + 2][column] != chess)
			&& (board[raw + 2][column] != opponent_chess)
			&& (raw + 2 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	//�������µ����
		//_?���__��_?���_��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		if ((board[raw - 4][column + 4] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw - 4][column + 4] != chess)
			&& (board[raw - 4][column + 4] != opponent_chess)
			&& (raw - 4 >= 0) && (column + 4 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		if ((board[raw - 3][column + 3] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw - 3][column + 3] != chess)
			&& (board[raw - 3][column + 3] != opponent_chess)
			&& (raw - 3 >= 0) && (column + 3 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
	}


	//_���?__��_���?_��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		if ((board[raw - 2][column + 2] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw - 2][column + 2] != chess)
			&& (board[raw - 2][column + 2] != opponent_chess)
			&& (raw - 2 >= 0) && (column + 2 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	//�������·���
		//_?���__��_?���_��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 4 <= 14) && (column + 4 <= 14))
	{
		if ((board[raw + 4][column + 4] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw + 4][column + 4] != chess)
			&& (board[raw + 4][column + 4] != opponent_chess)
			&& (raw + 4 <= 14) && (column + 4 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
	}

	//_��?��__��_��?��_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		if ((board[raw + 3][column + 3] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw + 3][column + 3] != chess)
			&& (board[raw + 3][column + 3] != opponent_chess)
			&& (raw + 3 <= 14) && (column + 3 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
	}


	//_���?__��_���?_��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		if ((board[raw + 2][column + 2] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw + 2][column + 2] != chess)
			&& (board[raw + 2][column + 2] != opponent_chess)
			&& (raw + 2 <= 14) && (column + 2 <= 14))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		&& (column + 1 <= 14)
		&& (column - 4 >= 0))
	{
		if ((board[raw][column - 4] == chess))
		{
			value += Gapped_Four;
			if (state[1] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}
		else if ((board[raw][column - 4] != chess)
			&& (board[raw][column - 4] != opponent_chess)
			&& (column - 4 >= 0))
		{
			value += Open_Three;
			if (state[1] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}

			if ((board[raw][column + 2] != chess)
				&& (board[raw][column + 2] != opponent_chess)
				&& (column + 2 <= 14))
			{
				value -= Open_Three;
				if (state[1] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[0] = true;
				}
				
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
		&& (column + 2 <= 14)
		&& (column - 3 >= 0))
	{
		if ((board[raw][column - 3] == chess))
		{
			value += Gapped_Four;
			if (state[1] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}
		else if ((board[raw][column - 3] != chess)
			&& (board[raw][column - 3] != opponent_chess)
			&& (column - 3 >= 0))
		{
			value += Open_Three;
			if (state[1] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
			if ((board[raw][column + 3] != chess)
				&& (board[raw][column + 3] != opponent_chess)
				&& (column + 3 <= 14))
			{
				value -= Open_Three;
				if (state[1] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[0] = true;
				}
				
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
		&& (column + 3 <= 14)
		&& (column - 2 >= 0))
	{
		if ((board[raw][column - 2] == chess))
		{
			value += Gapped_Four;
			if (state[1] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}
		else if ((board[raw][column - 2] != chess)
			&& (board[raw][column - 2] != opponent_chess)
			&& (column - 2 >= 0))
		{
			value += Open_Three;
			if (state[1] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
			if ((board[raw][column + 4] != chess)
				&& (board[raw][column + 4] != opponent_chess)
				&& (column + 4 <= 14))
			{
				value -= Open_Three;
				if (state[1] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[0] = true;
				}
				
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		&& (raw + 1 <= 14)
		&& (raw - 4 >= 0))
	{
		if ((board[raw - 4][column] == chess))
		{
			value += Gapped_Four;
			if (state[0]||state[2]||state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw - 4][column] != chess)
			&& (board[raw - 4][column] != opponent_chess)
			&& (raw - 4 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
			if ((board[raw + 2][column] != chess)
				&& (board[raw + 2][column] != opponent_chess)
				&& (raw + 2 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[1] = true;
				}
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
		&& (raw + 2 <= 14)
		&& (raw - 3 >= 0))
	{
		if ((board[raw - 3][column] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw - 3][column] != chess)
			&& (board[raw - 3][column] != opponent_chess)
			&& (raw - 3 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
			if ((board[raw + 3][column] != chess)
				&& (board[raw + 3][column] != opponent_chess)
				&& (raw + 3 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[1] = true;
				}
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
		&& (raw + 3 <= 14)
		&& (raw - 2 >= 0))
	{
		if ((board[raw - 2][column] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[2] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
		else if ((board[raw - 2][column] != chess)
			&& (board[raw - 2][column] != opponent_chess)
			&& (raw - 2 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[2] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
			if ((board[raw + 4][column] != chess)
				&& (board[raw + 4][column] != opponent_chess)
				&& (raw + 4 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[2] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[1] = true;
				}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		&& (raw - 1 >= 0) && (column + 1 <= 14)
		&& (raw + 4 <= 14) && (column - 4 >= 0))
	{
		if ((board[raw + 4][column - 4] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw + 4][column - 4] != chess)
			&& (board[raw + 4][column - 4] != opponent_chess)
			&& (raw + 4 <= 14) && (column - 4 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
			if ((board[raw - 2][column + 2] != chess)
				&& (board[raw - 2][column + 2] != opponent_chess)
				&& (raw - 2 >= 0) && (column + 2 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[2] = true;
				}
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
		&& (raw - 2 >= 0) && (column + 2 <= 14)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		if ((board[raw + 3][column - 3] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw + 3][column - 3] != chess)
			&& (board[raw + 3][column - 3] != opponent_chess)
			&& (raw + 3 <= 14) && (column - 3 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
			if ((board[raw - 3][column + 3] != chess)
				&& (board[raw - 3][column + 3] != opponent_chess)
				&& (raw - 3 >= 0) && (column + 3 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[2] = true;
				}
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
		&& (raw - 3 >= 0) && (column + 3 <= 14)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		if ((board[raw + 2][column - 2] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[3])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
		else if ((board[raw + 2][column - 2] != chess)
			&& (board[raw + 2][column - 2] != opponent_chess)
			&& (raw + 2 <= 14) && (column - 2 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[3])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
			if ((board[raw - 4][column + 4] != chess)
				&& (board[raw - 4][column + 4] != opponent_chess)
				&& (raw - 4 >= 0) && (column + 4 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[3])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[2] = true;
				}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		&& (raw + 1 <= 14) && (column + 1 <= 14)
		&& (raw - 4 >= 0) && (column - 4 >= 0))
	{
		if ((board[raw - 4][column - 4] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw - 4][column - 4] != chess)
			&& (board[raw - 4][column - 4] != opponent_chess)
			&& (raw - 4 >= 0) && (column - 4 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
			if ((board[raw + 2][column + 2] != chess)
				&& (board[raw + 2][column + 2] != opponent_chess)
				&& (raw + 2 <= 14) && (column + 2 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[2])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[3] = true;
				}
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
		&& (raw + 2 <= 14) && (column + 2 <= 14)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		if ((board[raw - 3][column - 3] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw - 3][column - 3] != chess)
			&& (board[raw - 3][column - 3] != opponent_chess)
			&& (raw - 3 >= 0)&(column - 3 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
			if ((board[raw + 3][column + 3] != chess)
				&& (board[raw + 3][column + 3] != opponent_chess)
				&& (raw + 3 <= 14) && (column + 3 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[2])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[3] = true;
				}
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
		&& (raw + 3 <= 14) && (column + 3 <= 14)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		if ((board[raw - 2][column - 2] == chess))
		{
			value += Gapped_Four;
			if (state[0] || state[1] || state[2])
			{
				value -= Gapped_Four;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
		else if ((board[raw - 2][column - 2] != chess)
			&& (board[raw - 2][column - 2] != opponent_chess)
			&& (raw - 2 >= 0)&(column - 2 >= 0))
		{
			value += Open_Three;
			if (state[0] || state[1] || state[2])
			{
				value -= Open_Three;
				value += Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
			if ((board[raw + 4][column + 4] != chess)
				&& (board[raw + 4][column + 4] != opponent_chess)
				&& (raw + 4 <= 14) && (column + 4 <= 14))
			{
				value -= Open_Three;
				if (state[0] || state[1] || state[2])
				{
					value += Open_Three;
					value -= Double_Chess;
					state[3] = true;
				}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}



	//�����ġ��_���Gapped22
		//ˮƽ����
			//?��_���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Gapped_Two_Two;
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	//��?_���
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column + 3 <= 14) && (column - 1 >= 0)) 
	{
		value += Gapped_Two_Two;
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	//���_?��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	//���_��?
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	//��ֱ����
		//?��_���
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	//��?_���
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	//���_?��
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	//���_��?
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	//�������·���
		//?��_���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 4 >= 0) && (column + 4 <= 14))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	//��?_���
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 1 <= 14)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	//���_?��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw - 1 >= 0) && (raw + 3 <= 14)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	//���_��?
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column - 4 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	//�������·���
		//?��_���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column + 4 <= 14))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	//��?_���
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (raw + 3 <= 14)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	//���_?��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 1 <= 14)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	//���_��?
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column - 4 >= 0))
	{
		value += Gapped_Two_Two;
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	// ���?���_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& ((board[raw][column - 2] == opponent_chess) || (column - 2 < 0))
		&& (board[raw][column + 3] != chess)
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 3 <= 14)
		&& (column - 1 >= 0))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}
	// ����?��_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] == chess)
		&& ((board[raw][column - 3] == opponent_chess)|| (column - 3 < 0))
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 2 <= 14)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}
	// �����?_
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column - 3] == chess)
		&& ((board[raw][column - 4] == opponent_chess)|| (column - 4 < 0))
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (column + 1 <= 14)
		&& (column - 3 >= 0))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	// ���?���_

	if ((board[raw - 1][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& ((board[raw - 2][column] == opponent_chess)|| (raw - 2 < 0))
		&& (board[raw + 3][column] != chess)
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 3 <= 14)
		&& (raw - 1 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}
	// ����?��_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] == chess)
		&& ((board[raw - 3][column] == opponent_chess)|| (raw - 3 < 0))
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 2 <= 14)
		&& (raw - 2 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}
	// �����?_
	if ((board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& ((board[raw - 4][column] == opponent_chess)|| (raw - 4 < 0))
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (raw + 1 <= 14)
		&& (raw - 3 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// ���?���_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& ((board[raw + 2][column - 2] == opponent_chess)|| (raw + 2 > 14) || (column - 2 < 0))
		&& (board[raw - 3][column + 3] != chess)
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column + 3 <= 14)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// ����?��_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] == chess)
		&& ((board[raw + 3][column - 3] == opponent_chess)|| (raw + 3 > 14) || (column - 3 < 0))
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column + 2 <= 14)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// �����?_
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& ((board[raw + 4][column - 4] == opponent_chess)|| (raw + 4 > 14) || (column - 4 < 0))
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column + 1 <= 14)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	// ���?���_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& ((board[raw - 2][column - 2] == opponent_chess)|| (raw - 2 < 0) || (column - 2 < 0))
		&& (board[raw + 3][column + 3] != chess)
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column + 3 <= 14)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	// ����?��_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] == chess)
		&& ((board[raw - 3][column - 3] == opponent_chess)|| (raw - 3 < 0) || (column - 3 < 0))
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column + 2 <= 14)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	// �����?_
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& ((board[raw - 4][column - 4] == opponent_chess)|| (raw - 4 < 0) || (column - 4 < 0))
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column + 1 <= 14)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}
	// _���?���
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 1] == chess)
		&& (board[raw][column - 2] == chess)
		&& ((board[raw][column + 2] == opponent_chess)|| (column + 2 > 14))
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 3 >= 0)
		&& (column + 1 <= 14))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}

	// _��?����
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column - 1] == chess)
		&& ((board[raw][column + 3] == opponent_chess)|| (column + 3 > 14))
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0)
		&& (column + 2 <= 14))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
	}
 
	// _?�����
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column + 2] == chess)
		&& (board[raw][column + 3] == chess)
		&& ((board[raw][column + 4] == opponent_chess)|| (column + 4 > 14))
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column - 1 >= 0)
		&& (column + 3 <= 14))
	{
		value += Capped_Four;
		if (state[1] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	// _���?���
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& ((board[raw + 2][column] == opponent_chess)|| (raw + 2 > 14))
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 3 >= 0)
		&& (raw + 1 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	// _��?����
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw - 1][column] == chess)
		&& ((board[raw + 3][column] == opponent_chess)|| (raw + 3 > 14))
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 2 >= 0)
		&& (raw + 2 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
	}

	// _?�����
	if ((board[raw + 1][column] == chess)
		&& (board[raw + 2][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& ((board[raw + 4][column] == opponent_chess)|| (raw + 4 > 14))
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw - 1 >= 0)
		&& (raw + 3 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[2] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// _���?���
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& ((board[raw - 2][column + 2] == opponent_chess)|| (raw - 2 < 0) || (column + 2 > 14))
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 3 <= 14) && (column - 3 >= 0)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// _��?����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw + 1][column - 1] == chess)
		&& ((board[raw - 3][column + 3] == opponent_chess)|| (raw - 3 < 0) || (column + 3 > 14))
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 2 <= 14) && (column - 2 >= 0)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
	}

	// _?�����
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw - 2][column + 2] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& ((board[raw - 4][column + 4] == opponent_chess)|| (raw - 4 < 0) || (column + 4 > 14))
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw + 1 <= 14) && (column - 1 >= 0)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[3])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	// _���?���
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& ((board[raw + 2][column + 2] == opponent_chess)|| (raw + 2 > 14) || (column + 2 > 14))
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 3 >= 0) && (column - 3 >= 0)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}


	// _��?����
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw - 1][column - 1] == chess)
		&& ((board[raw + 3][column + 3] == opponent_chess)|| (raw + 3 > 14) || (column + 3 > 14))
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (column - 2 >= 0)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}

	// _?�����
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw + 2][column + 2] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& ((board[raw + 4][column + 4] == opponent_chess)|| (raw + 4 > 14) || (column + 4 > 14))
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
	{
		value += Capped_Four;
		if (state[0] || state[1] || state[2])
		{
			value -= Capped_Four;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
	}


	//���������Gapped_Three  _��_���_��_���_��_
		//Ҫ�ų�_��_���_��_�������
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
		//�ų�_��_���_?_
		if ((board[raw][column - 5] == chess)
			&& (board[raw][column - 6] != chess)
			&& (board[raw][column - 6] != opponent_chess)
			&& (column - 6 >= 0))
		{
			value -= Gapped_Three;
			if (state[1] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}
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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
		//�ų�_��_��?_��_
		if ((board[raw][column - 3] == chess)
			&& (board[raw][column - 4] != chess)
			&& (board[raw][column - 4] != opponent_chess)
			&& (column - 4 >= 0))
		{
			value -= Gapped_Three;
			if (state[1] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}

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
		if (state[1] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[0] = true;
		}
		else
		{
			state[0] = true;
		}
		//�ų�_��_?��_��_
		if ((board[raw][column - 2] == chess)
			&& (board[raw][column - 3] != chess)
			&& (board[raw][column - 3] != opponent_chess)
			&& (column - 3 >= 0))
		{
			value -= Gapped_Three;
			if (state[1] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[0] = true;
			}
			else
			{
				state[0] = true;
			}
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
		//�ų�_��_���_?_
		if ((board[raw - 5][column] == chess)
			&& (board[raw - 6][column] != chess)
			&& (board[raw - 6][column] != opponent_chess)
			&& (raw - 6 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
		//�ų�_��_��?_��_
		if ((board[raw - 3][column] == chess)
			&& (board[raw - 4][column] != chess)
			&& (board[raw - 4][column] != opponent_chess)
			&& (raw - 4 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
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
		if (state[0] || state[2] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[1] = true;
		}
		else
		{
			state[1] = true;
		}
		//�ų�_��_?��_��_
		if ((board[raw - 2][column] == chess)
			&& (board[raw - 3][column] != chess)
			&& (board[raw - 3][column] != opponent_chess)
			&& (raw - 3 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[2] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[1] = true;
			}
			else
			{
				state[1] = true;
			}
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
		//�ų�_��_���_?_
		if ((board[raw + 5][column - 5] == chess)
			&& (board[raw + 6][column - 6] != chess)
			&& (board[raw + 6][column - 6] != opponent_chess)
			&& (column - 6 >= 0)
			&& (raw + 6 <= 14))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
		//�ų�_��_��?_��_
		if ((board[raw + 3][column - 3] == chess)
			&& (board[raw + 4][column - 4] != chess)
			&& (board[raw + 4][column - 4] != opponent_chess)
			&& (column - 4 >= 0)
			&& (raw + 4 <= 14))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
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
		if (state[0] || state[1] || state[3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[2] = true;
		}
		else
		{
			state[2] = true;
		}
		//�ų�_��_?��_��_
		if ((board[raw + 2][column - 2] == chess)
			&& (board[raw + 3][column - 3] != chess)
			&& (board[raw + 3][column - 3] != opponent_chess)
			&& (column - 3 >= 0)
			&& (raw + 3 <= 14))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[2] = true;
			}
			else
			{
				state[2] = true;
			}
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
		//�ų�_��_���_?_
		if ((board[raw - 5][column - 5] == chess)
			&& (board[raw - 6][column - 6] != chess)
			&& (board[raw - 6][column - 6] != opponent_chess)
			&& (column - 6 >= 0)
			&& (raw - 6 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[2])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
		//�ų�_��_��?_��_
		if ((board[raw - 3][column - 3] == chess)
			&& (board[raw - 4][column - 4] != chess)
			&& (board[raw - 4][column - 4] != opponent_chess)
			&& (column - 4 >= 0)
			&& (raw - 4 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[2])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
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
		if (state[0] || state[1] || state[2])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			state[3] = true;
		}
		else
		{
			state[3] = true;
		}
		//�ų�_��_?��_��_
		if ((board[raw - 2][column - 2] == chess)
			&& (board[raw - 3][column - 3] != chess)
			&& (board[raw - 3][column - 3] != opponent_chess)
			&& (column - 3 >= 0)
			&& (raw - 3 >= 0))
		{
			value -= Gapped_Three;
			if (state[0] || state[1] || state[2])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[3] = true;
			}
			else
			{
				state[3] = true;
			}
		}
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
		&& (column + 3 <= 14)
		&& (column - 1 >= 0))
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
		&& (column + 2 <= 14)
		&& (column - 2 >= 0))
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
		&& (column - 3 >= 0)
		&& (column + 1 <= 14))
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
		&& (column - 2 >= 0)
		&& (column + 2 <= 14))
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
		&& (raw + 3 <= 14)
		&& (raw - 1 >= 0))
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
		&& (raw + 2 <= 14)
		&& (raw - 2 >= 0))
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
		&& (raw - 3 >= 0)
		&& (raw + 1 <= 14))
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
		&& (raw - 2 >= 0)
		&& (raw + 2 <= 14))
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
		&& (raw - 3 >= 0) && (column + 3 <= 14)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
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
		&& (raw - 2 >= 0) && (column + 2 <= 14)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
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
		&& (raw + 3 <= 14) && (column - 3 >= 0)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
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
		&& (raw + 2 <= 14) && (column - 2 >= 0)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
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
		&& (raw + 3 <= 14) && (column + 3 <= 14)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
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
		&& (raw + 2 <= 14) && (column + 2 <= 14)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
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
		&& (raw - 3 >= 0) && (column - 3 >= 0)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
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
		&& (raw - 2 >= 0) && (column - 2 >= 0)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
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
		&& (column + 3 <= 14)
		&& (column - 1 >= 0))
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
		&& (column + 1 <= 14)
		&& (column - 3 >= 0))
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
		&& (column - 3 >= 0)
		&& (column + 1 <= 14))
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
		&& (column - 1 >= 0)
		&& (column + 3 <= 14))
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
		&& (raw + 3 <= 14)
		&& (raw - 1 >= 0))
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
		&& (raw + 1 <= 14)
		&& (raw - 3 >= 0))
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
		&& (raw - 3 >= 0)
		&& (raw + 1 <= 14))
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
		&& (raw - 1 >= 0)
		&& (raw + 3 <= 14))
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
		&& (raw - 3 >= 0) && (column + 3 <= 14)
		&& (raw + 1 <= 14) && (column - 1 >= 0))
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
		&& (raw - 1 >= 0) && (column + 1 <= 14)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
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
		&& (raw + 3 <= 14) && (column - 3 >= 0)
		&& (raw - 1 >= 0) && (column + 1 <= 14))
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
		&& (raw + 1 <= 14) && (column - 1 >= 0)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
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
		&& (raw + 3 <= 14) && (column + 3 <= 14)
		&& (raw - 1 >= 0) && (column - 1 >= 0))
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
		&& (raw + 1 <= 14) && (column + 1 <= 14)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
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
		&& (raw - 3 >= 0) && (column - 3 >= 0)
		&& (raw + 1 <= 14) && (column + 1 <= 14))
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
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
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
		&& (column + 2 <= 14)
		&& (column - 2 >= 0))
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
		&& (column + 1 <= 14)
		&& (column - 3 >= 0))
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
		&& (column - 2 > 1)
		&& (column + 2 <= 14))
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
		&& (column - 1 > 1)
		&& (column + 3 <= 14))
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
		&& (raw + 2 <= 14)
		&& (raw - 2 >= 0))
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
		&& (raw + 1 <= 14)
		&& (raw - 3 >= 0))
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
		&& (raw - 2 >= 0)
		&& (raw + 2 <= 14))
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
		&& (raw - 1 >= 0)
		&& (raw + 3 <= 14))
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
		&& (raw - 2 >= 0) && (column + 2 <= 14)
		&& (raw + 2 <= 14) && (column - 2 >= 0))
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
		&& (raw - 1 >= 0) && (column + 1 <= 14)
		&& (raw + 3 <= 14) && (column - 3 >= 0))
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
		&& (raw + 2 <= 14) && (column - 2 >= 0)
		&& (raw - 2 >= 0) && (column + 2 <= 14))
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
		&& (raw + 1 <= 14) && (column - 1 >= 0)
		&& (raw - 3 >= 0) && (column + 3 <= 14))
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
		&& (raw + 2 <= 14) && (column + 2 <= 14)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
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
		&& (raw + 1 <= 14) && (column + 1 <= 14)
		&& (raw - 3 >= 0) && (column - 3 >= 0))
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
		&& (raw - 2 >= 0) && (column - 2 >= 0)
		&& (raw + 2 <= 14) && (column + 2 <= 14))
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
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 3 <= 14) && (column + 3 <= 14))
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
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw][column - 1] == chess)
		&& (board[raw][column + 3] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw][column - 3] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 4 >= 0))
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
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw][column + 1] == chess)
		&& (board[raw][column - 3] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 2] != chess)
		&& (board[raw][column - 2] != opponent_chess)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw][column + 3] == chess)
		&& (board[raw][column + 4] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column + 2] != chess)
		&& (board[raw][column + 2] != opponent_chess)
		&& (column + 4 <= 14))
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
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw - 1][column] == chess)
		&& (board[raw + 3][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw - 3][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 4 >= 0))
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
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 4 >= 0))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw + 1][column] == chess)
		&& (board[raw - 3][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 2][column] != chess)
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw + 3][column] == chess)
		&& (board[raw + 4][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw + 2][column] != chess)
		&& (board[raw + 2][column] != opponent_chess)
		&& (raw + 4 <= 14))
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
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (column + 4 <= 14) && (raw - 4 >= 0))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw + 1][column - 1] == chess)
		&& (board[raw - 3][column + 3] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw + 3][column - 3] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column - 4 >= 0))
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
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw - 1][column + 1] == chess)
		&& (board[raw + 3][column - 3] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 2][column - 2] != chess)
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw - 3][column + 3] == chess)
		&& (board[raw - 4][column + 4] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw - 2][column + 2] != chess)
		&& (board[raw - 2][column + 2] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column + 4 <= 14))
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
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw - 1][column - 1] == chess)
		&& (board[raw + 3][column + 3] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 3 <= 14) && (raw - 1 >= 0)
		&& (column + 3 <= 14) && (column - 1 >= 0))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw - 3][column - 3] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column - 4 >= 0))
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
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column - 4 >= 0))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw + 1][column + 1] == chess)
		&& (board[raw - 3][column - 3] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 2][column - 2] != chess)
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw + 1 <= 14) && (raw - 3 >= 0)
		&& (column + 1 <= 14) && (column - 3 >= 0))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw + 3][column + 3] == chess)
		&& (board[raw + 4][column + 4] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw + 2][column + 2] != chess)
		&& (board[raw + 2][column + 2] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column + 4 <= 14))
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
		&& (board[raw][column + 3] != opponent_chess)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw][column + 2] == chess)
		&& (board[raw][column - 2] == chess)
		&& (board[raw][column + 1] != chess)
		&& (board[raw][column + 1] != opponent_chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (column + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw][column - 2] == chess)
		&& (board[raw][column - 4] == chess)
		&& (board[raw][column - 1] != chess)
		&& (board[raw][column - 1] != opponent_chess)
		&& (board[raw][column - 3] != chess)
		&& (board[raw][column - 3] != opponent_chess)
		&& (column - 4 >= 0))
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
		&& (board[raw + 3][column] != opponent_chess)
		&& (raw + 4 <= 14))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw + 2][column] == chess)
		&& (board[raw - 2][column] == chess)
		&& (board[raw + 1][column] != chess)
		&& (board[raw + 1][column] != opponent_chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw + 2 <= 14) && (raw - 2 >= 0))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw - 2][column] == chess)
		&& (board[raw - 4][column] == chess)
		&& (board[raw - 1][column] != chess)
		&& (board[raw - 1][column] != opponent_chess)
		&& (board[raw - 3][column] != chess)
		&& (board[raw - 3][column] != opponent_chess)
		&& (raw - 4 >= 0))
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
		&& (board[raw - 3][column + 3] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw - 2][column + 2] == chess)
		&& (board[raw + 2][column - 2] == chess)
		&& (board[raw - 1][column + 1] != chess)
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw + 2 <= 14) && (raw - 2 >= 0)
		&& (column + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw + 2][column - 2] == chess)
		&& (board[raw + 4][column - 4] == chess)
		&& (board[raw + 1][column - 1] != chess)
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (board[raw + 3][column - 3] != chess)
		&& (board[raw + 3][column - 3] != opponent_chess)
		&& (raw + 4 <= 14)
		&& (column - 4 >= 0))
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
		&& (board[raw + 3][column + 3] != opponent_chess)
		&& (raw + 4 <= 14) 
		&& (column + 4 <= 14))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw + 2][column + 2] == chess)
		&& (board[raw - 2][column - 2] == chess)
		&& (board[raw + 1][column + 1] != chess)
		&& (board[raw + 1][column + 1] != opponent_chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (raw + 2 <= 14) && (raw - 2 >= 0)
		&& (column + 2 <= 14) && (column - 2 >= 0))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw - 2][column - 2] == chess)
		&& (board[raw - 4][column - 4] == chess)
		&& (board[raw - 1][column - 1] != chess)
		&& (board[raw - 1][column - 1] != opponent_chess)
		&& (board[raw - 3][column - 3] != chess)
		&& (board[raw - 3][column - 3] != opponent_chess)
		&& (raw - 4 >= 0)
		&& (column - 4 >= 0))
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
		&& (board[raw][column - 1] != opponent_chess)
		&& (column - 1 >= 0) && (column + 3 <= 14))
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
		&& (board[raw][column - 2] != opponent_chess)
		&& (column - 2 >= 0) && (column + 2 <= 14))
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
		&& (board[raw][column + 1] != opponent_chess)
		&& (column - 3 >= 0) && (column + 1 <= 14))
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
		&& (board[raw - 1][column] != opponent_chess)
		&& (raw - 1 >= 0) && (raw + 3 <= 14))
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
		&& (board[raw - 2][column] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 2 <= 14))
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
		&& (board[raw + 1][column] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 1 <= 14))
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
		&& (board[raw + 1][column - 1] != opponent_chess)
		&& (raw - 3 >= 0) && (raw + 1 <= 14)
		&& (column - 1 >= 0) && (column + 3 <= 14))
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
		&& (board[raw + 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 2 <= 14)
		&& (column - 2 >= 0) && (column + 2 <= 14))
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
		&& (board[raw - 1][column + 1] != opponent_chess)
		&& (raw - 1 >= 0) && (raw + 3 <= 14)
		&& (column - 3 >= 0) && (column + 1 <= 14))
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
		&& (board[raw - 1][column - 1] != opponent_chess, 2)
		&& (raw - 1 >= 0) && (raw + 3 <= 14)
		&& (column - 1 >= 0) && (column + 3 <= 14))
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
		&& (board[raw - 2][column - 2] != opponent_chess)
		&& (raw - 2 >= 0) && (raw + 2 <= 14)
		&& (column - 2 >= 0) && (column + 2 <= 14))
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
		&& (board[raw + 1][column + 1] != opponent_chess, 2)
		&& (raw - 3 >= 0) && (raw + 1 <= 14)
		&& (column - 3 >= 0) && (column + 1 <= 14))
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






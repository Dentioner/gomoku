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
	long int value = 0;
	//int state = 0;//״̬�����������ڲ���˫����˫����֮���
	bool state[4] = { false, false, false, false };//״̬��¼����Ϊ4�����򣬷ֱ���ˮƽ����ֱ���������£���������

	int horizon[2] = { 0,1 };//ˮƽ����λʸ��
	int perpendicular[2] = { 1,0 };//��ֱ����λʸ��
	int up_right_down_left[2] = { -1,1 };//�������·���λʸ��
	int up_left_down_right[2] = { 1,1 };//�������·���λʸ��
	//int all_vector[4][2] = { {0,1}, {1,0}, {-1,1}, {1,1} };
	int i;
	/*���ѭ���������⣬��ʱ��Ҫ�ã�������all_vectorһ��ʹ�ã�ʹ�õ�ʱ���ĸ���λ��ע�͵�
	for (i = 0; i<4 && value > Consecutive_Five; i++)
	{
		value += line(state, all_vector[i], raw, column, step_count);
	}
	*/
	value += line(state, horizon, raw, column, step_count);//ˮƽ�Ʒ�
	value += line(state, perpendicular, raw, column, step_count);//��ֱ�Ʒ�
	value += line(state, up_right_down_left, raw, column, step_count);//�������¼Ʒ�
	value += line(state, up_left_down_right, raw, column, step_count);//�������¼Ʒ�
	
	//���������������Է��ķ����������Ϊ��
	//���ڵ������ǣ���������Ǽ����Է�����һ�Σ�����һ���������潫˫��������һ�Σ�
	//Ŀǰ�Ĵ����ǣ���������������Է�����һ�Σ��ò�����my_turn����

	if (value > Consecutive_Five)//�ٴ������÷֣����ų���ͬ��λ���ӵ��µķ�����������
		value = Consecutive_Five;
	if (!my_turn)
		value *= -1;
	return value;

}

long int line(bool state[], int vector[], int raw, int column, int step_count)//��һ������
{
	//vector�Ǵ�����ĵ�λʸ������Ϊ{0,1}{1,0},{-1,1},{1,1}����
	//�ֱ����ˮƽ������ֱ�����������·����������·���
	int chess;
	int opponent_chess;
	long int value = 0;
	int dx = vector[0];
	int dy = vector[1];
	int direct_now, other_direct1, other_direct2, other_direct3;//���ڰ���ȷ��state��
	//bool special_state_for_four = false;//���״̬�������ж�ͬһֱ���ϵ�˫�����͵ģ�˫��û���������
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

	if (dx == 0 && dy == 1)//{0,1}
	{

		direct_now = 0;
		other_direct1 = 1;
		other_direct2 = 2;
		other_direct3 = 3;

	}
	else if (dx == 1 && dy == 0)//{1,0}
	{
		direct_now = 1;
		other_direct1 = 0;
		other_direct2 = 2;
		other_direct3 = 3;
	}
	else if (dx == -1 && dy == 1)//{-1,1}
	{
		direct_now = 2;
		other_direct1 = 0;
		other_direct2 = 1;
		other_direct3 = 3;
	}
	else if (dx == 1 && dy == 1)//{1,1}
	{
		direct_now = 3;
		other_direct1 = 0;
		other_direct2 = 1;
		other_direct3 = 2;
	}
	else
	{
		printf("error\n");
		system("pause");
	}
	//�������
		//��ˮƽ����Ϊ��
			//�����?��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Consecutive_Five;
	}
	//����?����
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Consecutive_Five;
	}

	//���?�����
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Consecutive_Five;
	}

	//��?������
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Consecutive_Five;
	}

	//?�������
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Consecutive_Five;
	};


	//������
		//ˮƽ����
			//_?����_��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Open_Four;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 5 * dx][column + 5 * dy] == chess)//_?����_����һ�˲����£����ǻ���
				&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
				&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
			{
				if ((board[raw - 2 * dx][column - 2 * dy] == chess)//��_?����_�������ģ�û��
					&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
					&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
				
				{
					value -= Open_Four;
				}
				else//X_?����_���ǳ��ģ�X�����Ǻ���
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
			else if ((board[raw - 2 * dx][column - 2 * dy] == chess)//��_?����_����һ�˲����£����ǻ���
				&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
				&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
			{
				if ((board[raw + 5 * dx][column + 5 * dy] == chess)//��_?����_�������ģ�û��
					&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
					&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
				{
					value -= Open_Four;
				}
				else
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
		}
	}

	//_��?���_��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Open_Four;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 4 * dx][column + 4 * dy] == chess)//_��?���_����һ�˲����£����ǻ���
				&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
				&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
			{
				if ((board[raw - 3 * dx][column - 3 * dy] == chess)//��_��?���_�������ģ�û��
					&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
					&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))

				{
					value -= Open_Four;
				}
				else//X_��?���_���ǳ��ģ�X�����Ǻ���
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
			else if ((board[raw - 3 * dx][column - 3 * dy] == chess)//��_��?���_����һ�˲����£����ǻ���
				&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
				&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
			{
				if ((board[raw + 4 * dx][column + 4 * dy] == chess)//��_��?���_�������ģ�û��
					&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
					&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
				{
					value -= Open_Four;
				}
				else
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
		}
	}

	//_���?��_��
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Open_Four;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 3 * dx][column + 3 * dy] == chess)//_���?��_����һ�˲����£����ǻ���
				&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
				&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
			{
				if ((board[raw - 4 * dx][column - 4 * dy] == chess)//��_���?��_�������ģ�û��
					&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
					&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))

				{
					value -= Open_Four;
				}
				else//X_���?��_���ǳ��ģ�X�����Ǻ���
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
			else if ((board[raw - 4 * dx][column - 4 * dy] == chess)//��_���?��_����һ�˲����£����ǻ���
				&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
				&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
			{
				if ((board[raw + 3 * dx][column + 3 * dy] == chess)//��_���?��_�������ģ�û��
					&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
					&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
				{
					value -= Open_Four;
				}
				else
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
		}
	}

	//_����?_��
	if ((board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Open_Four;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 2 * dx][column + 2 * dy] == chess)//_����?_����һ�˲����£����ǻ���
				&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
				&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
			{
				if ((board[raw - 5 * dx][column - 5 * dy] == chess)//��_����?_�������ģ�û��
					&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
					&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))

				{
					value -= Open_Four;
				}
				else//X_����?_���ǳ��ģ�X�����Ǻ���
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
			else if ((board[raw - 5 * dx][column - 5 * dy] == chess)//��_����?_����һ�˲����£����ǻ���
				&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
				&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
			{
				if ((board[raw + 2 * dx][column + 2 * dy] == chess)//��_����?_�������ģ�û��
					&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
					&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
				{
					value -= Open_Four;
				}
				else
				{
					value -= Open_Four;
					value += Capped_Four;
				}
			}
		}
	}

	//һ�ֳ���
	//���� ����_���
	//����������һ�֣��� ��_����
	//������������
		//ˮƽ����
			//?���_��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 5 * dx][column + 5 * dy] == chess)//?���_���
				&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
				&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw - 1 * dx][column - 1 * dy] == chess)//��?���_��
				&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
				&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//��?��_��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 4 * dx][column + 4 * dy] == chess)//��?��_���
				&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
				&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw - 2 * dx][column - 2 * dy] == chess)//���?��_��
				&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
				&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//���?_��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 3 * dx][column + 3 * dy] == chess)//���?_���
				&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
				&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw - 3 * dx][column - 3 * dy] == chess)//���?��_��
				&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
				&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//����_?,�������ֻ�г�����
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 5 * dx][column - 5 * dy] == chess)//�����_?
				&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
				&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw + 1 * dx][column + 1 * dy] == chess)//����_?��
				&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
				&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}


	//����
	//����_��
	//����������һ�֣���_����
	//��������������

		//ˮƽ����
			//�� ��_���?
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 5 * dx][column - 5 * dy] == chess)//���_���?
				&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
				&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw + 1 * dx][column + 1 * dy] == chess)//��_���?��
				&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
				&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//��_��?��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 4 * dx][column - 4 * dy] == chess)//���_��?��
				&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
				&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw + 2 * dx][column + 2 * dy] == chess)//��_��?���
				&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
				&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}


	//��_?���
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 3 * dx][column - 3 * dy] == chess)//���_?���
				&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
				&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
			{
				state[direct_now] = false;
				value += Capped_Three;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw + 3 * dx][column + 3 * dy] == chess)//��_?����
				&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
				&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//?_����
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Gapped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 5 * dx][column + 5 * dy] == chess)//?_�����
				&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
				&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
			else if ((board[raw - 1 * dx][column - 1 * dy] == chess)//��?_����
				&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
				&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Four;
			}
		}
	}

	//����
	//�ֱ�������_����__
	//����������һ�֣�__����_
	//��������������
		//ˮƽ����
			//_?���__
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)


		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}
	}

	//_��?��__
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}
	}

	//_���?__
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}
	}

	//����
	//�ֱ�������_����__ 
	//����������һ�֣�__����_
	//��������������  ��Ҫ�ų��������__����__�����־ͺ�֮ǰ���ظ��ˡ�
	//����Ҫ�ų�__����_����������������൱���ڳ��������ټ���һ������������ǿ�����Ҫ�ų��ģ�Ҳ���ܲ���Ҫ��������������
		//ˮƽ����
			//__���?_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)//�ų�__����_��������

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}

		if ((board[raw + 2 * dx][column + 2 * dy] != chess)
			&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

			&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
			&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
		{
			value -= Open_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Open_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}

		}

	}

	//__��?��_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)//�ų�__����_��������

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}
		if ((board[raw + 3 * dx][column + 3 * dy] != chess)
			&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

			&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
			&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
		{
			value -= Open_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Open_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}

		}
	}

	//__?���_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)//�ų�__����_��������

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Open_Three;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Open_Three;
			value += Double_Chess;
			state[direct_now] = true;
		}
		else
		{
			state[direct_now] = true;
		}
		if ((board[raw + 4 * dx][column + 4 * dy] != chess)
			&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

			&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
			&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
		{
			value -= Open_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Open_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}

		}

	}

	//�����ġ��_���Gapped22
		//ˮƽ����
			//?��_���
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Gapped_Two_Two;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 5 * dx][column + 5 * dy] == chess)//?��_����
				&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
				&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
			else if ((board[raw - 1 * dx][column - 1 * dy] == chess)//��?��_���
				&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
				&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
		}
	}

	//��?_���
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Gapped_Two_Two;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 4 * dx][column + 4 * dy] == chess)//��?_����
				&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
				&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
			else if ((board[raw - 2 * dx][column - 2 * dy] == chess)//���?_���
				&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
				&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
		}
	}

	//���_?��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Gapped_Two_Two;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 2 * dx][column + 2 * dy] == chess)//���_?���
				&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
				&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
			else if ((board[raw - 4 * dx][column - 4 * dy] == chess)//����_?��
				&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
				&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
		}
	}

	//���_��?
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Gapped_Two_Two;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Two_Two;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 1 * dx][column + 1 * dy] == chess)//���_��?��
				&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
				&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
			else if ((board[raw - 5 * dx][column - 5 * dy] == chess)//����_��?
				&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
				&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Gapped_Two_Two;
			}
		}
	}


	//������Capped_Four ������_������һ�ַ�����������棬������дһ�ַ���
		// ˮƽ����
			// ��?����_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw - 1 * dx][column - 1 * dy] == opponent_chess) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 5 * dx][column + 5 * dy] == chess)//��?����_��
				&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
				&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}
			
		}
	}

	// ���?���_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw - 2 * dx][column - 2 * dy] == opponent_chess) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 4 * dx][column + 4 * dy] == chess)//���?���_��
				&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
				&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}
	// ����?��_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& ((board[raw - 3 * dx][column - 3 * dy] == opponent_chess) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 3 * dx][column + 3 * dy] == chess)//����?��_��
				&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
				&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}
	// �����?_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw - 4 * dx][column - 4 * dy] == opponent_chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw + 2 * dx][column + 2 * dy] == chess)//�����?_��
				&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
				&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}


	//���ĵ�����һ�ַ���_������
		// ˮƽ����
			// _����?��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw + 1 * dx][column + 1 * dy] == opponent_chess) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 5 * dx][column - 5 * dy] == chess)//��_����?��
				&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
				&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}
	// _���?���
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw + 2 * dx][column + 2 * dy] == opponent_chess) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 4 * dx][column - 4 * dy] == chess)//��_���?���
				&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
				&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}

	// _��?����
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& ((board[raw + 3 * dx][column + 3 * dy] == opponent_chess) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 3 * dx][column - 3 * dy] == chess)//��_��?����
				&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
				&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}

	// _?�����
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw + 4 * dx][column + 4 * dy] == opponent_chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Four;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Capped_Four;
			value += Double_Chess;
		}
		state[direct_now] = true;
		if (chess == b)//�����漰������Ҫ��������
		{
			if ((board[raw - 2 * dx][column - 2 * dy] == chess)//��_?�����
				&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
				&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
			{
				state[direct_now] = false;
				if (state[other_direct1] || state[other_direct2] || state[other_direct3])//�����������Ҫ�۳�˫��˫���ķ���
					value -= Double_Chess;
				else
					value -= Capped_Four;
			}

		}
	}


	//���ⵣ�ģ�
	//X���_���_���X & X����_��_����X & X��_����_��X
	//ע���X��λ�㲻�����Լ����ӣ������Ǽ��������м�Ŀ�λ������������ֶ���������
	//ע������λ��ֻ���м䲿�֣����ϵ��Ǽ����Ӳ�Ҫ��
	//�ȼ��X���_���_���X
	//X���_?��_���X
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& ((board[raw + 5 * dx][column + 5 * dy] != chess) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 4 * dx][column - 4 * dy] != chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dx < 0) || (column - 4 * dx > 14))

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value -= Gapped_Two_Two;
		value += Double_Chess;
	}
	//X���_��?_���X
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& ((board[raw + 4 * dx][column + 4 * dy] != chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dx < 0) || (column + 4 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != chess) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value -= Gapped_Two_Two;
		value += Double_Chess;
	}
	//���X����_��_����X
	//X����_?_����X
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& ((board[raw + 5 * dx][column + 5 * dy] != chess) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != chess) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value -= Gapped_Four;
		value += Double_Chess;
	}

	//���X��_����_��X
	//X��_?���_��X
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& ((board[raw + 5 * dx][column + 5 * dy] != chess) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 3 * dx][column - 3 * dy] != chess) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dx < 0) || (column - 3 * dx > 14))

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value -= Gapped_Four;
		value += Double_Chess;
	}

	//X��_��?��_��X
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& ((board[raw + 4 * dx][column + 4 * dy] != chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dx < 0) || (column + 4 * dx > 14))
		&& ((board[raw - 4 * dx][column - 4 * dy] != chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dx < 0) || (column - 4 * dx > 14))

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value -= Gapped_Four;
		value += Double_Chess;
	}

	//X��_���?_��X
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& ((board[raw + 3 * dx][column + 3 * dy] != chess) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dx < 0) || (column + 3 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != chess) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value -= Gapped_Four;
		value += Double_Chess;
	}
	//���������Gapped_Three  _��_���_��_���_��_
		//Ҫ�ų�_��_���_��_�������
		//ˮƽ����
		//�ȼ��_��_���_
			//_?_���_
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			
		}
		//�ų�_?_���_��_
		if ((board[raw + 5 * dx][column + 5 * dy] == chess)
			&& (board[raw + 6 * dx][column + 6 * dy] != chess)
			&& (board[raw + 6 * dx][column + 6 * dy] != opponent_chess)

			&& (raw + 6 * dx >= 0) && (raw + 6 * dx <= 14)
			&& (column + 6 * dy >= 0) && (column + 6 * dy <= 14))
		{
			value -= Gapped_Three;
			if (chess == w)//���ڰ�����˵���������˫������
				value += Double_Gapped_Three;
			else//���Ƕ��ں���������������н������ƣ���˫���������������
				value += 2 * Capped_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}
			else
			{
				state[direct_now] = true;
			}
		}

	}

	//_��_?��_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
			
		}
	}

	//_��_��?_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
		}
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;			
		}
		//�ų�_��_���_?_
		if ((board[raw - 5 * dx][column - 5 * dy] == chess)
			&& (board[raw - 6 * dx][column - 6 * dy] != chess)
			&& (board[raw - 6 * dx][column - 6 * dy] != opponent_chess)

			&& (raw - 6 * dx >= 0) && (raw - 6 * dx <= 14)
			&& (column - 6 * dy >= 0) && (column - 6 * dy <= 14))
		{
			value -= Gapped_Three;
			if (chess == w)//���ڰ�����˵���������˫������
				value += Double_Gapped_Three;
			else//���Ƕ��ں���������������н������ƣ���˫���������������
				value += 2 * Capped_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}
			else
			{
				state[direct_now] = true;
			}
		}
	}

	//_��?_��_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;
		}
		//�ų�_��_��?_��_
		if ((board[raw - 3 * dx][column - 3 * dy] == chess)
			&& (board[raw - 4 * dx][column - 4 * dy] != chess)
			&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

			&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
			&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
		{
			value -= 2 * Gapped_Three;
			if (chess == w)//���ڰ�����˵���������˫������
				value += Double_Gapped_Three;
			else//���Ƕ��ں���������������н������ƣ���˫���������������
				value += 2 * Capped_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}
			else
			{
				state[direct_now] = true;
			}
		}

	}

	//_?��_��_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Gapped_Three;
		state[direct_now] = true;
		if (state[other_direct1] || state[other_direct2] || state[other_direct3])
		{
			value -= Gapped_Three;
			value += Double_Chess;		
		}
		//�ų�_��_?��_��_
		if ((board[raw - 2 * dx][column - 2 * dy] == chess)
			&& (board[raw - 3 * dx][column - 3 * dy] != chess)
			&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

			&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
			&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
		{
			value -= 2 * Gapped_Three;
			if (chess == w)//���ڰ�����˵���������˫������
				value += Double_Gapped_Three;
			else//���Ƕ��ں���������������н������ƣ���˫���������������
				value += 2 * Capped_Three;
			if (state[other_direct1] || state[other_direct2] || state[other_direct3])
			{
				value += Gapped_Three;
				value -= Double_Chess;
				state[direct_now] = true;
			}
			else
			{
				state[direct_now] = true;
			}
		}
	}


	//���������Capped_Three
	//1. �����__��__�������
		//ˮƽ����
		//���ǡ����__
			//��?���__

	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw - 1 * dx][column - 1 * dy] == opponent_chess) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���?��__

	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] == chess)
		&& ((board[raw - 2 * dx][column - 2 * dy] == opponent_chess) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//����?__

	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw - 3 * dx][column - 3 * dy] == opponent_chess) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//����__�����
		//__���?��

	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw + 1 * dx][column + 1 * dy] == opponent_chess) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//__��?���

	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& ((board[raw + 2 * dx][column + 2 * dy] == opponent_chess) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//__?����

	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw + 3 * dx][column + 3 * dy] == opponent_chess) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//2.����_��_��_��_����
		//ˮƽ����
		//���ǡ���_��_
			//��?��_��_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw - 1 * dx][column - 1 * dy] == opponent_chess) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���?_��_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw - 2 * dx][column - 2 * dy] == opponent_chess) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//����_?_
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw - 4 * dx][column - 4 * dy] == opponent_chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//����_��_����
		//_��_��?��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw + 1 * dx][column + 1 * dy] == opponent_chess) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//_��_?���
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw + 2 * dx][column + 2 * dy] == opponent_chess) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//_?_����
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw + 4 * dx][column + 4 * dy] == opponent_chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//3.���_���_��_���_���
		//ˮƽ����
		//���ǡ��_���_
			//��?_���_
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw - 1 * dx][column - 1 * dy] == opponent_chess) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���_?��_
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw - 3 * dx][column - 3 * dy] == opponent_chess) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���_��?_
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw - 4 * dx][column - 4 * dy] == opponent_chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//����_���_���
		//_���_?��
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 3 * dx][column - 3 * dy] == chess)
		&& ((board[raw + 1 * dx][column + 1 * dy] == opponent_chess) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//_��?_���
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw + 3 * dx][column + 3 * dy] == opponent_chess) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//_?��_���
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& ((board[raw + 4 * dx][column + 4 * dy] == opponent_chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//�������������п��ܲ�̫��
	//��Ϊ��֪�������֡��__�񣬻���_���__��_֮���
	//4. ���__��͡�__���
		//ˮƽ����
		//���ǡ��__��
			//?��__��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//��?__��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���__?
	if ((board[raw - 3 * dx][column - 3 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���ǡ�__���
		//��__��?
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//��__?��
	if ((board[raw + 1 * dx][column + 1 * dx] == chess)
		&& (board[raw - 3 * dx][column - 3 * dx] == chess)
		&& (board[raw - 1 * dx][column - 1 * dx] != chess)
		&& (board[raw - 1 * dx][column - 1 * dx] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dx] != chess)
		&& (board[raw - 2 * dx][column - 2 * dx] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//?__���
	if ((board[raw + 3 * dx][column + 3 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//5. ��_��_��
	//ע������������_��_�����_��_��_��_�ǲ�̫һ����
	//��ʱ�Ȳ�����������������
		//ˮƽ����
			//?_��_��
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw + 4 * dx][column + 4 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		//���������б�֤���������಻���Լ����ӣ���������_��_�������ͣ��ͻᱻ�����⵽
		&& ((board[raw - 1 * dx][column - 1 * dy] != chess)||(raw - 1 * dx > 14) || (raw - 1 * dx < 0) || (column - 1 * dy > 14) || (column - 1 * dy < 0))
		&& ((board[raw + 5 * dx][column + 5 * dy] != chess) || (raw + 5 * dx > 14) || (raw + 5 * dx < 0) || (column + 5 * dy > 14) || (column + 5 * dy < 0))
		


		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Capped_Three;
	}
	//��_?_��
	if ((board[raw + 2 * dx][column + 2 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		
		&& ((board[raw - 3 * dx][column - 3 * dy] != chess) || (raw - 3 * dx > 14) || (raw - 3 * dx < 0) || (column - 3 * dy > 14) || (column - 3 * dy < 0))
		&& ((board[raw + 3 * dx][column + 3 * dy] != chess) || (raw + 3 * dx > 14) || (raw + 3 * dx < 0) || (column + 3 * dy > 14) || (column + 3 * dy < 0))


		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//��_��_?
	if ((board[raw - 2 * dx][column - 2 * dy] == chess)
		&& (board[raw - 4 * dx][column - 4 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& ((board[raw - 5 * dx][column - 5 * dy] != chess) || (raw - 5 * dx > 14) || (raw - 5 * dx < 0) || (column - 5 * dy > 14) || (column - 5 * dy < 0))
		&& ((board[raw + 1 * dx][column + 1 * dy] != chess) || (raw + 1 * dx > 14) || (raw + 1 * dx < 0) || (column + 1 * dy > 14) || (column + 1 * dy < 0))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		value += Capped_Three;
	}

	//6. ��_����_����
		//ˮƽ����
			//��_?���_��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] == chess)
		&& ((board[raw - 2 * dx][column - 2 * dy] == opponent_chess) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& ((board[raw + 4 * dx][column + 4 * dy] == opponent_chess) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess, 2)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess, 2)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Capped_Three;
	}

	//��_��?��_��
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] == chess)
		&& ((board[raw + 3 * dx][column + 3 * dy] == opponent_chess) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		&& ((board[raw - 3 * dx][column - 3 * dy] == opponent_chess) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess, 2)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Capped_Three;
	}

	//��_���?_��
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] == chess)
		&& ((board[raw + 2 * dx][column + 2 * dy] == opponent_chess) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		&& ((board[raw - 4 * dx][column - 4 * dy] == opponent_chess) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess, 2)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess, 2)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		value += Capped_Three;
	}

	//���� ___���__ & __���___
		//ˮƽ����
		//�ȼ��___���__
			//___?��__
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Open_two;
	}

	//___��?__
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != chess)
		&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		value += Open_two;
	}

	//�ټ��__���___
		//__��?___
	if ((board[raw - 1 * dx][column - 1 * dy] == chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != chess)
		&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != chess)
		&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		value += Open_two;
		if ((board[raw - 4 * dx][column - 4 * dy] != chess)
			&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)

			&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
			&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
		{//�ų�___���___
			value -= Open_two;
		}
	}

	//__?��___
	if ((board[raw + 1 * dx][column + 1 * dy] == chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != chess)
		&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != chess)
		&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != chess)
		&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != chess)
		&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != chess)
		&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		value += Open_two;
		if ((board[raw - 3 * dx][column - 3 * dy] != chess)
			&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
			&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
			&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))
		{//�ų�___���___
			value -= Open_two;
		}
	}


	//��������¼���������ͣ�û�����������ɼƷ֣������ڽ��ֵ��µļƷ�©������Ҫ��������
	if (chess == b)//ֻ�к��Ӳ���Ҫ���������������������в���
	{
		//1. X����_����X�ͣ��м�Ŀ�λ�ǽ��֣�ʵ������������������
		//X����_?���X
		if ((board[raw + 1 * dx][column + 1 * dy] == chess)
			&& (board[raw + 2 * dx][column + 2 * dy] == chess)
			&& (board[raw - 2 * dx][column - 2 * dy] == chess)
			&& (board[raw - 3 * dx][column - 3 * dy] == chess)
			&& (board[raw - 4 * dx][column - 4 * dy] == chess)
			&& (board[raw - 1 * dx][column - 1 * dy] != chess)
			&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
			&& ((board[raw + 3 * dx][column + 3 * dy] != chess) || (raw + 3 * dx > 14) || (raw + 3 * dx < 0) || (column + 3 * dy > 14) || (column + 3 * dy < 0))
			&& ((board[raw - 5 * dx][column - 5 * dy] != chess) || (raw - 5 * dx > 14) || (raw - 5 * dx < 0) || (column - 5 * dy > 14) || (column - 5 * dy < 0))
			&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
			&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
			&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
			&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
		{
			value = value - 2 * Gapped_Four - Gapped_Two_Two;
			if ((board[raw + 3 * dx][column + 3 * dy] != chess)
				&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
				&& (board[raw + 4 * dx][column + 4 * dy] != chess)
				&& (board[raw + 4 * dx][column + 4 * dy] != opponent_chess)
				&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
				&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))//����_?���__ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}

		//X���?_����X
		if ((board[raw - 1 * dx][column - 1 * dy] == chess)
			&& (board[raw - 2 * dx][column - 2 * dy] == chess)
			&& (board[raw + 2 * dx][column + 2 * dy] == chess)
			&& (board[raw + 3 * dx][column + 3 * dy] == chess)
			&& (board[raw + 4 * dx][column + 4 * dy] == chess)
			&& (board[raw + 1 * dx][column + 1 * dy] != chess)
			&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
			&& ((board[raw - 3 * dx][column - 3 * dy] != chess) || (raw - 3 * dx > 14) || (raw - 3 * dx < 0) || (column - 3 * dy > 14) || (column - 3 * dy < 0))
			&& ((board[raw + 5 * dx][column + 5 * dy] != chess) || (raw + 5 * dx > 14) || (raw + 5 * dx < 0) || (column + 5 * dy > 14) || (column + 5 * dy < 0))
			&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
			&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14)
			&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
			&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))
		{
			value = value - 2 * Gapped_Four - Gapped_Two_Two;
			if ((board[raw - 3 * dx][column - 3 * dy] != chess)
				&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
				&& (board[raw - 4 * dx][column - 4 * dy] != chess)
				&& (board[raw - 4 * dx][column - 4 * dy] != opponent_chess)
				&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
				&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))//__���?_����ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}
		//X����_��?��X
		if ((board[raw + 1 * dx][column + 1 * dy] == chess)
			&& (board[raw - 1 * dx][column - 1 * dy] == chess)
			&& (board[raw - 3 * dx][column - 3 * dy] == chess)
			&& (board[raw - 4 * dx][column - 4 * dy] == chess)
			&& (board[raw - 5 * dx][column - 5 * dy] == chess)
			&& (board[raw - 2 * dx][column - 2 * dy] != chess)
			&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
			&& ((board[raw + 2 * dx][column + 2 * dy] != chess) || (raw + 2 * dx > 14) || (raw + 2 * dx < 0) || (column + 2 * dy > 14) || (column + 2 * dy < 0))
			&& ((board[raw - 6 * dx][column - 6 * dy] != chess) || (raw - 6 * dx > 14) || (raw - 6 * dx < 0) || (column - 6 * dy > 14) || (column - 6 * dy < 0))
			&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
			&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14)
			&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
			&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
		{
			value = value - Gapped_Four - Gapped_Two_Two;
			if ((board[raw + 2 * dx][column + 2 * dy] != chess)
				&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
				&& (board[raw + 3 * dx][column + 3 * dy] != chess)
				&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
				&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
				&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))//����_��?��__ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}
		//X��?��_����X
		if ((board[raw - 1 * dx][column - 1 * dy] == chess)
			&& (board[raw + 1 * dx][column + 1 * dy] == chess)
			&& (board[raw + 3 * dx][column + 3 * dy] == chess)
			&& (board[raw + 4 * dx][column + 4 * dy] == chess)
			&& (board[raw + 5 * dx][column + 5 * dy] == chess)
			&& (board[raw + 2 * dx][column + 2 * dy] != chess)
			&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
			&& ((board[raw - 2 * dx][column - 2 * dy] != chess) || (raw - 2 * dx > 14) || (raw - 2 * dx < 0) || (column - 2 * dy > 14) || (column - 2 * dy < 0))
			&& ((board[raw + 6 * dx][column + 6 * dy] != chess) || (raw + 6 * dx > 14) || (raw + 6 * dx < 0) || (column + 6 * dy > 14) || (column + 6 * dy < 0))
			&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
			&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14)
			&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
			&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14))
		{
			value = value - Gapped_Four - Gapped_Two_Two;
			if ((board[raw - 2 * dx][column - 2 * dy] != chess)
				&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
				&& (board[raw - 3 * dx][column - 3 * dy] != chess)
				&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
				&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
				&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14))//__��?��_����ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}
		//X����_���?X
		if ((board[raw - 1 * dx][column - 1 * dy] == chess)
			&& (board[raw - 2 * dx][column - 2 * dy] == chess)
			&& (board[raw - 4 * dx][column - 4 * dy] == chess)
			&& (board[raw - 5 * dx][column - 5 * dy] == chess)
			&& (board[raw - 6 * dx][column - 6 * dy] == chess)
			&& (board[raw - 3 * dx][column - 3 * dy] != chess)
			&& (board[raw - 3 * dx][column - 3 * dy] != opponent_chess)
			&& ((board[raw + 1 * dx][column + 1 * dy] != chess) || (raw + 1 * dx > 14) || (raw + 1 * dx < 0) || (column + 1 * dy > 14) || (column + 1 * dy < 0))
			&& ((board[raw - 7 * dx][column - 7 * dy] != chess) || (raw - 7 * dx > 14) || (raw - 7 * dx < 0) || (column - 7 * dy > 14) || (column - 7 * dy < 0))
			&& (raw - 6 * dx >= 0) && (raw - 6 * dx <= 14)
			&& (column - 6 * dy >= 0) && (column - 6 * dy <= 14))
		{
			value -= Gapped_Four;
			if ((board[raw + 1 * dx][column + 1 * dy] != chess)
				&& (board[raw + 1 * dx][column + 1 * dy] != opponent_chess)
				&& (board[raw + 2 * dx][column + 2 * dy] != chess)
				&& (board[raw + 2 * dx][column + 2 * dy] != opponent_chess)
				&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
				&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))//����_���?__ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}
		//X?���_����X
		if ((board[raw + 1 * dx][column + 1 * dy] == chess)
			&& (board[raw + 2 * dx][column + 2 * dy] == chess)
			&& (board[raw + 4 * dx][column + 4 * dy] == chess)
			&& (board[raw + 5 * dx][column + 5 * dy] == chess)
			&& (board[raw + 6 * dx][column + 6 * dy] == chess)
			&& (board[raw + 3 * dx][column + 3 * dy] != chess)
			&& (board[raw + 3 * dx][column + 3 * dy] != opponent_chess)
			&& ((board[raw - 1 * dx][column - 1 * dy] != chess) || (raw - 1 * dx > 14) || (raw - 1 * dx < 0) || (column - 1 * dy > 14) || (column - 1 * dy < 0))
			&& ((board[raw + 7 * dx][column + 7 * dy] != chess) || (raw + 7 * dx > 14) || (raw + 7 * dx < 0) || (column + 7 * dy > 14) || (column + 7 * dy < 0))
			&& (raw + 6 * dx >= 0) && (raw + 6 * dx <= 14)
			&& (column + 6 * dy >= 0) && (column + 6 * dy <= 14))
		{
			value -= Gapped_Four;
			if ((board[raw - 1 * dx][column - 1 * dy] != chess)
				&& (board[raw - 1 * dx][column - 1 * dy] != opponent_chess)
				&& (board[raw - 2 * dx][column - 2 * dy] != chess)
				&& (board[raw - 2 * dx][column - 2 * dy] != opponent_chess)
				&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
				&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14))//__?���_����ʱ����������һ�������ķ�����
			{
				value -= Open_Three;
			}
			value += 2 * Capped_Three;
		}
	}

	return value;
}
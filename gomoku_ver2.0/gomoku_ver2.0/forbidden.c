#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"head.h"

extern int board[15][15];
extern int w;//����
extern int b;//����
//�жϽ��ֵĺ���

//����������û�������ǰ���ִ�л��Ǻ���ִ�У�Ҳ����˵���һ�����ֿ�λ����׼���Ű��壬�������ǻ��������
//�������������ô˺�����ʱ�򿴿��ǰ����߻��Ǻ�����
bool detect_forbidden_step(int raw, int column)
{
	int horizon[2] = { 0,1 };//ˮƽ����λʸ��
	int perpendicular[2] = { 1,0 };//��ֱ����λʸ��
	int up_right_down_left[2] = { -1,1 };//�������·���λʸ��
	int up_left_down_right[2] = { 1,1 };//�������·���λʸ��
	bool forbid_three[4] = { false, false, false, false };//״̬��¼����Ϊ4�����򣬷ֱ���ˮƽ����ֱ���������£���������
	bool forbid_four[4] = { false, false, false, false };//״̬��¼����Ϊ4�����򣬷ֱ���ˮƽ����ֱ���������£���������
	int find_it[4] = { 0 };
	int index;
	//0����û�����壬Ҳû�н��֣�1���������壻2�����н���

	find_it[0] = line_forbid(forbid_three, forbid_four, horizon, raw, column);
	find_it[1] = line_forbid(forbid_three, forbid_four, perpendicular, raw, column);
	find_it[2] = line_forbid(forbid_three, forbid_four, up_right_down_left, raw, column);
	find_it[3] = line_forbid(forbid_three, forbid_four, up_left_down_right, raw, column);
	
	for (index = 0; index < 4; index++)//�ȿ����ĸ�����������û������
	{
		if (find_it[index] == 1)
			return false;
	}
	for (index = 0; index < 4; index++)//���û�У���������һ�飬������û�н���
	{
		if (find_it[index] == 2)
			return true;
	}
	return false;
}

int line_forbid(bool forbid_three[], bool forbid_four[], int vector[], int raw, int column)
{
	int dx = vector[0];
	int dy = vector[1];
	int direct_now, other_direct1, other_direct2, other_direct3;//���ڰ���ȷ��forbid��λ�����
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

	//���ȼ������
	//��ô��Ӧ���ǵ�����λ�ò����Ǻ��ӡ����λ�ÿ����ǰ��ӣ������ǿ�λ��Ҳ���������̱�Ե
	// X�����?X�ͣ�X�����Ǻ���
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)//����

		&& ((board[raw - 5 * dx][column - 5 * dy] != b) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dy < 0) || (column - 5 * dy > 14))
		&& ((board[raw + 1 * dx][column + 1 * dy] != b) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		//����ϵ�λ�ò��Ǻ���
		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		return 1;
	}
	// X����?��X�ͣ�X�����Ǻ���
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)//����

		&& ((board[raw - 4 * dx][column - 4 * dy] != b) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& ((board[raw + 2 * dx][column + 2 * dy] != b) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		//����ϵ�λ�ò��Ǻ���
		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		return 1;
	}

	// X���?���X�ͣ�X�����Ǻ���

	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)

		&& ((board[raw - 3 * dx][column - 3 * dy] != b) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& ((board[raw + 3 * dx][column + 3 * dy] != b) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		//����ϵ�λ�ò��Ǻ���

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		return 1;
	}
	
	// X��?����X�ͣ�X�����Ǻ���
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)

		&& ((board[raw - 2 * dx][column - 2 * dy] != b) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& ((board[raw + 4 * dx][column + 4 * dy] != b) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		//����ϵ�λ�ò��Ǻ���

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		return 1;
	}

	//X?�����X��
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)

		&& ((board[raw - 1 * dx][column - 1 * dy] != b) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& ((board[raw + 5 * dx][column + 5 * dy] != b) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dy < 0) || (column + 5 * dy > 14))
		//����ϵ�λ�ò��Ǻ���

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		return 1;
	}

	//��鳤��
	//��ˮƽ����Ϊ��
			//������?��
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw - 5 * dx][column - 5 * dy] == b)
		&& (raw - 5 * dx >= 0) && (raw - 5 * dx <= 14)
		&& (column - 5 * dy >= 0) && (column - 5 * dy <= 14))
	{
		return 2;
	}
			//�����?����
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		return 2;
	}
	//����?�����
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		return 2;
	}

	//���?������
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		return 2;
	}

	//��?�������
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		return 2;
	}
	//?��������
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw + 5 * dx][column + 5 * dy] == b)

		&& (raw + 5 * dx >= 0) && (raw + 5 * dx <= 14)
		&& (column + 5 * dy >= 0) && (column + 5 * dy <= 14))
	{
		return 2;
	}
	//������
	//д��������
		//ˮƽ����
			//_?����_��
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] != b)
		&& (board[raw + 4 * dx][column + 4 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}
	//_��?���_��
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//_���?��_��
	if ((board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//_����?_��
	if ((board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 4 * dx][column - 4 * dy] != b)
		&& (board[raw - 4 * dx][column - 4 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//һ�ֳ���
	//���� ����_���
	//����������һ�֣��� ��_����
	//������������
		//ˮƽ����
			//?���_��
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//��?��_��
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//���?_��
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//����_?,�������ֻ�г�����
	if ((board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//����
	//����_��
	//����������һ�֣���_����
	//��������������

		//ˮƽ����
			//�� ��_���?
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//��_��?��
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}


	//��_?���
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//?_����
	if ((board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//����
	//�ֱ�������_����__
	//����������һ�֣�__����_
	//��������������
		//ˮƽ����
			//_?���__
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw + 4 * dx][column + 4 * dy] != b)
		&& (board[raw + 4 * dx][column + 4 * dy] != w)


		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_��?��__
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_���?__
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//����
	//�ֱ�������_����__ 
	//����������һ�֣�__����_
	//��������������  ��Ҫ�ų��������__����__�����־ͺ�֮ǰ���ظ��ˡ�
	//����Ҫ�ų�__����_����������������൱���ڳ��������ټ���һ������������ǿ�����Ҫ�ų��ģ�Ҳ���ܲ���Ҫ��������������
		//ˮƽ����
			//__���?_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 4 * dx][column - 4 * dy] != b)
		&& (board[raw - 4 * dx][column - 4 * dy] != w)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)//�ų�__����_��������

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	
		//����ɾ����һ���ж�__����__�Ĵ���

	}

	//__��?��_
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)//�ų�__����_��������

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}

		//����ɾ����һ���ж�__����__�Ĵ���
	}

	//__?���_
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& (board[raw + 4 * dx][column + 4 * dy] != b)//�ų�__����_��������

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}

		//����ɾ����һ���ж�__����__�Ĵ���
	}

	//�����ġ��_���Gapped22
		//ˮƽ����
			//?��_���
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
		
	}

	//��?_���
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}

	}

	//���_?��
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}

	}

	//���_��?
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}

	}

	//������Capped_Four ������_������һ�ַ�����������棬������дһ�ַ���
		// ˮƽ����
			// ��?����_
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& ((board[raw - 1 * dx][column - 1 * dy] == w) || (raw - 1 * dx < 0) || (raw - 1 * dx > 14) || (column - 1 * dy < 0) || (column - 1 * dy > 14))
		&& (board[raw + 4 * dx][column + 4 * dy] != b)
		&& (board[raw + 4 * dx][column + 4 * dy] != w)

		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	// ���?���_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& ((board[raw - 2 * dx][column - 2 * dy] == w) || (raw - 2 * dx < 0) || (raw - 2 * dx > 14) || (column - 2 * dy < 0) || (column - 2 * dy > 14))
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}
	// ����?��_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] == b)
		&& ((board[raw - 3 * dx][column - 3 * dy] == w) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dy < 0) || (column - 3 * dy > 14))
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}
	// �����?_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& ((board[raw - 4 * dx][column - 4 * dy] == w) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dy < 0) || (column - 4 * dy > 14))
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//���ĵ�����һ�ַ���_������
		// ˮƽ����
			// _����?��
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& ((board[raw + 1 * dx][column + 1 * dy] == w) || (raw + 1 * dx < 0) || (raw + 1 * dx > 14) || (column + 1 * dy < 0) || (column + 1 * dy > 14))
		&& (board[raw - 4 * dx][column - 4 * dy] != b)
		&& (board[raw - 4 * dx][column - 4 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}
	// _���?���
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& ((board[raw + 2 * dx][column + 2 * dy] == w) || (raw + 2 * dx < 0) || (raw + 2 * dx > 14) || (column + 2 * dy < 0) || (column + 2 * dy > 14))
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	// _��?����
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& ((board[raw + 3 * dx][column + 3 * dy] == w) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dy < 0) || (column + 3 * dy > 14))
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	// _?�����
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& ((board[raw + 4 * dx][column + 4 * dy] == w) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dy < 0) || (column + 4 * dy > 14))
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_four[direct_now] = true;
		if (forbid_four[other_direct1] || forbid_four[other_direct2] || forbid_four[other_direct3])
		{
			return 2;
		}
	}

	//���ⵣ�ģ�
	//X���_���_���X & X����_��_����X & X��_����_��X
	//ע���X��λ�㲻�����Լ����ӣ������Ǽ��������м�Ŀ�λ������������ֶ���������
	//ע������λ��ֻ���м䲿�֣����ϵ��Ǽ����Ӳ�Ҫ��
	//�ȼ��X���_���_���X
	//X���_?��_���X
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& ((board[raw + 5 * dx][column + 5 * dy] != b) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 4 * dx][column - 4 * dy] != b) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dx < 0) || (column - 4 * dx > 14))

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		return 2;
	}
	//X���_��?_���X
	if ((board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& ((board[raw + 4 * dx][column + 4 * dy] != b) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dx < 0) || (column + 4 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != b) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		return 2;
	}
	//���X����_��_����X
	//X����_?_����X
	if ((board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& ((board[raw + 5 * dx][column + 5 * dy] != b) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != b) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		return 2;
	}

	//���X��_����_��X
	//X��_?���_��X
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 4 * dx][column + 4 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& ((board[raw + 5 * dx][column + 5 * dy] != b) || (raw + 5 * dx < 0) || (raw + 5 * dx > 14) || (column + 5 * dx < 0) || (column + 5 * dx > 14))
		&& ((board[raw - 3 * dx][column - 3 * dy] != b) || (raw - 3 * dx < 0) || (raw - 3 * dx > 14) || (column - 3 * dx < 0) || (column - 3 * dx > 14))

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		return 2;
	}

	//X��_��?��_��X
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& ((board[raw + 4 * dx][column + 4 * dy] != b) || (raw + 4 * dx < 0) || (raw + 4 * dx > 14) || (column + 4 * dx < 0) || (column + 4 * dx > 14))
		&& ((board[raw - 4 * dx][column - 4 * dy] != b) || (raw - 4 * dx < 0) || (raw - 4 * dx > 14) || (column - 4 * dx < 0) || (column - 4 * dx > 14))

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		return 2;
	}

	//X��_���?_��X
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 4 * dx][column - 4 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)
		&& ((board[raw + 3 * dx][column + 3 * dy] != b) || (raw + 3 * dx < 0) || (raw + 3 * dx > 14) || (column + 3 * dx < 0) || (column + 3 * dx > 14))
		&& ((board[raw - 5 * dx][column - 5 * dy] != b) || (raw - 5 * dx < 0) || (raw - 5 * dx > 14) || (column - 5 * dx < 0) || (column - 5 * dx > 14))

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		return 2;
	}

	//���������Gapped_Three  _��_���_��_���_��_
		//Ҫ�ų�_��_���_��_�������
		//ˮƽ����
		//�ȼ��_��_���_
			//_?_���_
	if ((board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw + 4 * dx][column + 4 * dy] != b)
		&& (board[raw + 4 * dx][column + 4 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_��_?��_
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 3 * dx][column - 3 * dy] != b)
		&& (board[raw - 3 * dx][column - 3 * dy] != w)

		&& (raw - 3 * dx >= 0) && (raw - 3 * dx <= 14)
		&& (column - 3 * dy >= 0) && (column - 3 * dy <= 14)
		&& (raw + 2 * dx >= 0) && (raw + 2 * dx <= 14)
		&& (column + 2 * dy >= 0) && (column + 2 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_��_��?_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 4 * dx][column - 4 * dy] != b)
		&& (board[raw - 4 * dx][column - 4 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//�ټ��_���_��_
		//_���_?_
	if ((board[raw - 2 * dx][column - 2 * dy] == b)
		&& (board[raw - 3 * dx][column - 3 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw - 4 * dx][column - 4 * dy] != b)
		&& (board[raw - 4 * dx][column - 4 * dy] != w)

		&& (raw - 4 * dx >= 0) && (raw - 4 * dx <= 14)
		&& (column - 4 * dy >= 0) && (column - 4 * dy <= 14)
		&& (raw + 1 * dx >= 0) && (raw + 1 * dx <= 14)
		&& (column + 1 * dy >= 0) && (column + 1 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_��?_��_
	if ((board[raw - 1 * dx][column - 1 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] == b)
		&& (board[raw + 1 * dx][column + 1 * dy] != b)
		&& (board[raw + 1 * dx][column + 1 * dy] != w)
		&& (board[raw - 2 * dx][column - 2 * dy] != b)
		&& (board[raw - 2 * dx][column - 2 * dy] != w)
		&& (board[raw + 3 * dx][column + 3 * dy] != b)
		&& (board[raw + 3 * dx][column + 3 * dy] != w)

		&& (raw - 2 * dx >= 0) && (raw - 2 * dx <= 14)
		&& (column - 2 * dy >= 0) && (column - 2 * dy <= 14)
		&& (raw + 3 * dx >= 0) && (raw + 3 * dx <= 14)
		&& (column + 3 * dy >= 0) && (column + 3 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}

	//_?��_��_
	if ((board[raw + 1 * dx][column + 1 * dy] == b)
		&& (board[raw + 3 * dx][column + 3 * dy] == b)
		&& (board[raw + 2 * dx][column + 2 * dy] != b)
		&& (board[raw + 2 * dx][column + 2 * dy] != w)
		&& (board[raw - 1 * dx][column - 1 * dy] != b)
		&& (board[raw - 1 * dx][column - 1 * dy] != w)
		&& (board[raw + 4 * dx][column + 4 * dy] != b)
		&& (board[raw + 4 * dx][column + 4 * dy] != w)

		&& (raw - 1 * dx >= 0) && (raw - 1 * dx <= 14)
		&& (column - 1 * dy >= 0) && (column - 1 * dy <= 14)
		&& (raw + 4 * dx >= 0) && (raw + 4 * dx <= 14)
		&& (column + 4 * dy >= 0) && (column + 4 * dy <= 14))
	{
		forbid_three[direct_now] = true;
		if (forbid_three[other_direct1] || forbid_three[other_direct2] || forbid_three[other_direct3])
		{
			return 2;
		}
	}


	return 0;
}
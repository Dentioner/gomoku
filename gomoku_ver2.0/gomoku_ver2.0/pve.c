#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//����
extern int b;//����
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
//extern unsigned long long hashing_value2[depth_of_hashing][3];
extern unsigned long long hashing_value3[depth_of_hashing][4];
long int best_score_of_upper[11] = { -infinity , infinity , -infinity, infinity , -infinity, infinity, -infinity , infinity , -infinity, infinity, -infinity };//��minimax����ļ�֦�õ�
//ע����������������ı�����⡣floor�Ǵ�11��0�ݹ�ģ����Ҫ�������һ��Ԫ�ز��䡣
bool not_in_the_same_branch[11] = { true, true, true, true, true, true, true, true, true, true, true };
long int best_score_of_upper_ver2[12] = { infinity ,-infinity , infinity , -infinity, infinity , -infinity, infinity, -infinity , infinity , -infinity, infinity, -infinity };//��minimax����ļ�֦�õ�
long int value_for_board = 0;//�¼�
bool ai_first = false;//Ĭ�ϵ��Ժ���
long int empty_score_total_black[15][15] = { 0 };//���ں�����˵�Ŀ�λ���ܷ�
long int empty_score_total_white[15][15] = { 0 };//���ں�����˵�Ŀ�λ���ܷ�
extern int temp_point[2];

void pve(long int value)
{
	//PVE

	int ai_choice = 0;
	int floor = FLOOR;//��������
	int chess;
	int opponent_chess;
	int step_count = 0; //��Ϸ���˼����ӵļ���


	bool my_turn = true; //���������ȷ����һ������һ��������
	bool continue_playing = true; //ȷ����Ϸ�Ƿ����
	bool find_forbidden_step = false;//����ָ��

	initTable();
	
	ai_choice = offensive();

	if (ai_choice == 1)
	{
		ai_first = true;
	}
	else
	{
		ai_first = false;
	}

	if (ai_first)
	{
		my_turn = true;
		chess = b;
		opponent_chess = w;
		board[7][7] = chess;
		my_turn = false;
		step_count++;
	}
	else
	{
		my_turn = false;
		chess = w;
		opponent_chess = b;

	}
	DrawBoard(value, 2,  -1);
	//initialize_hashing_sheet(key);
	while (continue_playing)
	{
		find_forbidden_step = false;//����
		//ע���������轫my_turn���ˣ��ڦ��¼�֦�������Ѿ�����
		//ע�⣬����ɾ����priority���飬Ҫ���Ļ�ȥ1.0�汾
		//��ɾ����ɱ���õ��Ǽ�������
		
		if (my_turn)
		{
			double start_time = clock();
			double end_time, cost_time;
			if (step_count > 2)
			{
				init_best_score_of_upper();
				value = Minimax3(step_count, my_turn, floor);
				if ((coordinate[0] == 0) && (coordinate[1] == 0))
				{
					auto_play(chess, opponent_chess);
					chess_play_ver2(step_count);
					hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
					DrawBoard(value, 2, step_count);
					return_to_normal_chess(step_count);
				}
				else
				{
					chess_play_ver2(step_count);
					hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
					DrawBoard(value, 2, step_count);
					return_to_normal_chess(step_count);
				}

				//���ԣ���ӡ��ϣ���������Ƿ�����
				/*if (coordinate[0] == 8 && coordinate[1] == 7)
				{
					for (int ha1 = 0; ha1 < depth_of_hashing; ha1++)
					{
						if (hashing_value2[ha1][0] != 0)
						{


							printf("���̣�%llu���ҷ���%lld���Է���%lld\n", hashing_value2[ha1][0], hashing_value2[ha1][1], hashing_value2[ha1][2]);
							//�ڶ�ά�ȵ�[0]���������̵Ĺ�ϣֵ
							//[1]��[2]�Ǵ˹�ϣֵ��Ӧ���������֣�Ӧ�ö����ں�������;
						}
					}
					printf("������Ƿ����ϵ����õ�\n");
				}
				*/
			}
			else
			{
				//auto_play(chess, opponent_chess);
				open_base();
				chess_play_ver2(step_count);
				hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
				DrawBoard(value, 2, step_count);
				return_to_normal_chess(step_count);
			}
			end_time = clock();
			cost_time = (end_time - start_time) / CLK_TCK;
			printf("time=%fs.\n", cost_time);
			//��������ǽ����ӵĲ�λ��Ч���Ļ������������ҷ��Ǻ��ӻ��ǰ��ӣ��������鶼���õ���Ч������
			empty_score_total_black[coordinate[0]][coordinate[1]] = 0;
			empty_score_total_white[coordinate[0]][coordinate[1]] = 0;
			temp_point[0] = coordinate[0];
			temp_point[1] = coordinate[1];
			refresh_score(step_count, my_turn);
		}
		else
		{
			get_coordinate(step_count);
			//��value��chessplay����λ���ˣ���֪��������
			roaming = board[coordinate[0]][coordinate[1]];//��¼��һ����״̬
			if (step_count % 2 == 0)//���Ӳ�ִ���жϽ���
			{
				find_forbidden_step = detect_forbidden_step(coordinate[0], coordinate[1]);
				if (find_forbidden_step)
				{
					printf("����\n");
					system("pause");
				}
			}
			value = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
			chess_play_ver2(step_count);
			hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
			DrawBoard(value, 2, step_count);
			return_to_normal_chess(step_count);
			//�����ǻ�����룬���ܻ�������			
			printf("�Ƿ���Ҫ���壿��y���壬��������������������Ϸ.\n");
			char c_getback = ' ';
			c_getback = getchar();
			while (getchar() != '\n')
				continue;
			int i_getback = c_getback;
			if (i_getback == 89 || i_getback == 121)
			{
				board[coordinate[0]][coordinate[1]] = roaming;
				hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
				DrawBoard(value, 2, step_count);
				continue;
			}
			//��������ǽ����ӵĲ�λ��Ч���Ļ������������ҷ��Ǻ��ӻ��ǰ��ӣ��������鶼���õ���Ч������
			empty_score_total_black[coordinate[0]][coordinate[1]] = 0;
			empty_score_total_white[coordinate[0]][coordinate[1]] = 0;
			temp_point[0] = coordinate[0];
			temp_point[1] = coordinate[1];
			refresh_score(step_count, my_turn);
		}

		continue_playing = judgement(step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(value, 2, step_count);
	if (step_count % 2)
	{
		printf("���ӻ�ʤ");
	}
	else
	{
		printf("���ӻ�ʤ");
	}

	return;




}

int offensive()//ѡ��˭����˭����
{
	bool invalid_ai_choice = true;
	int ai_choice_index = 0;
	int ai_choice = 0;

	printf("�������ֻ��ǶԷ����֣�\n");
	printf("1.��������\t\t2.�Է�����\n");
	printf("************************************************\n");

	while (invalid_ai_choice)
	{
		ai_choice_index = scanf("%d", &ai_choice);
		while (getchar() != '\n')
			continue;
		if (ai_choice_index != 1)
		{
			printf("��Ч���룬������\n");

			continue;
		}
		if ((ai_choice != 1) && (ai_choice != 2))
		{
			printf("��Ч���룬������\n");

			continue;
		}

		invalid_ai_choice = false;
	}


	return ai_choice;
}

void auto_play(int chess, int opponent_chess)
{


	for (int p = 0; p < 15; p++)
	{
		for (int q = 0; q < 15; q++)
		{
			if (board[p][q] == opponent_chess)
			{
				if ((board[p + 1][q] != opponent_chess)
					&& (board[p + 1][q] != chess)
					&& (p + 1 <= 14))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q;
					
					return;
				}

				else if ((board[p][q + 1] != opponent_chess)
					&& (board[p][q + 1] != chess)
					&& (q + 1 <= 14))
				{
					coordinate[0] = p;
					coordinate[1] = q + 1;
					
					return;
				}
				else if ((board[p - 1][q] != opponent_chess)
					&& (board[p - 1][q] != chess)
					&& (p - 1 >= 0))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q;
					
					return;
				}
				else if ((board[p][q - 1] != opponent_chess)
					&& (board[p][q - 1] != chess)
					&& (q - 1 >= 0))
				{
					coordinate[0] = p;
					coordinate[1] = q - 1;
					//strncpy(board[p][q - 1], chess, 2);
					return;
				}
				else if ((board[p - 1][q - 1] != opponent_chess)
					&& (board[p - 1][q - 1] != chess)
					&& (p - 1 >= 0)
					&& (q - 1 >= 0))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q - 1;
					return;
				}
				else if ((board[p - 1][q + 1] != opponent_chess)
					&& (board[p - 1][q + 1] != chess)
					&& (p - 1 >= 0)
					&& (q + 1 <= 14))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q + 1;
					return;
				}
				else if ((board[p + 1][q + 1] != opponent_chess)
					&& (board[p + 1][q + 1] != chess)
					&& (p + 1 <= 14)
					&& (q + 1 <= 14))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q + 1;
					
					return;
				}
				else if ((board[p + 1][q - 1] != opponent_chess)
					&& (board[p + 1][q - 1] != chess)
					&& (p + 1 <= 14)
					&& (q - 1 >= 0))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q - 1;
					
					return;
				}

			}
		}
	}

}

void init_best_score_of_upper()
{
	//best_score_of_upper_ver2[12] = { infinity ,-infinity , infinity , -infinity, infinity , -infinity, infinity, -infinity , infinity , -infinity, infinity, -infinity };//��minimax����ļ�֦�õ�
	int i = 0;
	for (i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			best_score_of_upper_ver2[i] = infinity;
		}
		else
		{
			best_score_of_upper_ver2[i] = -infinity;
		}
	}
}
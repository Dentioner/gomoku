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
extern int w;//白棋
extern int b;//黑棋
extern bool BoardFull;
extern unsigned long long ZobristTable[15][15][2];//梅森旋转的哈希键值表
extern unsigned long long hashValue;//梅森旋转算法下，棋盘的哈希值
extern HE hashing_value4[depth_of_hashing];//注意上下这两个数组的编号问题。floor是从11往0递归的，因此要保持最后一个元素不变。
bool not_in_the_same_branch[11] = { true, true, true, true, true, true, true, true, true, true, true };
long int best_score_of_upper_ver2[12] = { infinity ,-infinity , infinity , -infinity, infinity , -infinity, infinity, -infinity , infinity , -infinity, infinity, -infinity };//给minimax里面的剪枝用的
long int value_for_board = 0;//新加
bool ai_first = false;//默认电脑后走
long int empty_score_total_black[15][15] = { 0 };//对于黑棋来说的空位的总分
long int empty_score_total_white[15][15] = { 0 };//对于黑棋来说的空位的总分
bool banned_point_sheet[15][15] = { false };//棋盘上禁手的空位 
extern int temp_point[2];
int times_of_finding_out_in_ZobTable = 0;//测试用，提交时删除，用于计数，看看查表查到了多少次


void pve(long int value)
{//PVE
	int ai_choice = 0;
	int floor = FLOOR;//搜索层数
	int chess;
	int opponent_chess;
	int step_count = 0; //游戏下了几个子的计数
	bool my_turn = true; //这个东西是确认这一步是哪一方下子了
	bool continue_playing = true; //确认游戏是否继续
	bool find_forbidden_step = false;//禁手指标

	initTable();
	ai_choice = offensive();

	if (ai_choice == 1)
		ai_first = true;
	else
		ai_first = false;
	if (ai_first)
	{
		my_turn = true;
		chess = b;
		opponent_chess = w;
		board[7][7] = chess;
		hashValue ^= ZobristTable[7][7][0];
		my_turn = false;
		step_count++;
	}
	else
	{
		my_turn = false;
		chess = w;
		opponent_chess = b;
	}
	DrawBoard(value, 2, -1);
	while (continue_playing)
	{
		find_forbidden_step = false;//重置		
		if (my_turn)
		{
			double start_time = clock();
			double end_time, cost_time;
			if (step_count > 2)
			{
				init_best_score_of_upper();
				value = iteration_search(step_count, my_turn);
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
			}
			else
			{
				open_base();
				chess_play_ver2(step_count);
				hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
				DrawBoard(value, 2, step_count);
				return_to_normal_chess(step_count);
			}
			end_time = clock();
			cost_time = (end_time - start_time) / CLK_TCK;
			//printf("time=%fs.\n", cost_time);
			empty_score_total_black[coordinate[0]][coordinate[1]] = 0;//如果仅仅是将落子的部位无效化的话，不用在意我方是黑子还是白子，两个数组都将该点无效化即可
			empty_score_total_white[coordinate[0]][coordinate[1]] = 0;
			temp_point[0] = coordinate[0];
			temp_point[1] = coordinate[1];
			refresh_banned_point_whole();
			refresh_score(step_count, my_turn);
		}
		else
		{
			char c_getback = ' ';
			int i_getback;
			int temp_cor[2];
			temp_cor[0] = coordinate[0];
			temp_cor[1] = coordinate[1];
			get_coordinate(step_count);
			roaming = board[coordinate[0]][coordinate[1]];//记录上一步的状态
			if (step_count % 2 == 0)//黑子才执行判断禁手
			{
				find_forbidden_step = detect_forbidden_step(coordinate[0], coordinate[1]);
				if (find_forbidden_step)
				{
					printf("禁手\n");
					system("pause");
				}
			}
			value = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
			chess_play_ver2(step_count);
			hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
			DrawBoard(value, 2, step_count);
			return_to_normal_chess(step_count);

			printf("是否想要悔棋？按y悔棋，按别的任意键正常继续游戏.\n");
			c_getback = getchar();
			while (getchar() != '\n')
				continue;
			i_getback = c_getback;
			if (i_getback == 89 || i_getback == 121)
			{
				board[coordinate[0]][coordinate[1]] = roaming;
				hashValue ^= ZobristTable[coordinate[0]][coordinate[1]][(step_count % 2)];
				coordinate[0] = temp_cor[0];
				coordinate[1] = temp_cor[1];
				DrawBoard(value, 2, step_count);
				continue;
			}
			empty_score_total_black[coordinate[0]][coordinate[1]] = 0;//如果仅仅是将落子的部位无效化的话，不用在意我方是黑子还是白子，两个数组都将该点无效化即可
			empty_score_total_white[coordinate[0]][coordinate[1]] = 0;
			temp_point[0] = coordinate[0];
			temp_point[1] = coordinate[1];
			refresh_banned_point_whole();
			refresh_score(step_count, my_turn);
		}

		continue_playing = judgement(step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(value, 2, step_count);
	if (BoardFull)
		printf("平局\n");
	else
	{
		if (step_count % 2)
			printf("黑子获胜");
		else
			printf("白子获胜");
	}
	return;
}

int offensive()//选择谁先手谁后手
{
	bool invalid_ai_choice = true;
	int ai_choice_index = 0;
	int ai_choice = 0;

	printf("电脑先手还是对方先手？\n");
	printf("1.电脑先手\t\t2.对方先手\n");
	printf("************************************************\n");

	while (invalid_ai_choice)
	{
		ai_choice_index = scanf("%d", &ai_choice);
		while (getchar() != '\n')
			continue;
		if (ai_choice_index != 1)
		{
			printf("无效输入，请重试\n");
			continue;
		}
		if ((ai_choice != 1) && (ai_choice != 2))
		{
			printf("无效输入，请重试\n");
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
				if ((board[p + 1][q] != opponent_chess) && (board[p + 1][q] != chess) && (p + 1 <= 14))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q;
					return;
				}

				else if ((board[p][q + 1] != opponent_chess) && (board[p][q + 1] != chess) && (q + 1 <= 14))
				{
					coordinate[0] = p;
					coordinate[1] = q + 1;
					return;
				}
				else if ((board[p - 1][q] != opponent_chess) && (board[p - 1][q] != chess) && (p - 1 >= 0))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q;
					return;
				}
				else if ((board[p][q - 1] != opponent_chess) && (board[p][q - 1] != chess) && (q - 1 >= 0))
				{
					coordinate[0] = p;
					coordinate[1] = q - 1;
					return;
				}
				else if ((board[p - 1][q - 1] != opponent_chess) && (board[p - 1][q - 1] != chess) && (p - 1 >= 0) && (q - 1 >= 0))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q - 1;
					return;
				}
				else if ((board[p - 1][q + 1] != opponent_chess) && (board[p - 1][q + 1] != chess) && (p - 1 >= 0) && (q + 1 <= 14))
				{
					coordinate[0] = p - 1;
					coordinate[1] = q + 1;
					return;
				}
				else if ((board[p + 1][q + 1] != opponent_chess) && (board[p + 1][q + 1] != chess) && (p + 1 <= 14) && (q + 1 <= 14))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q + 1;
					return;
				}
				else if ((board[p + 1][q - 1] != opponent_chess) && (board[p + 1][q - 1] != chess) && (p + 1 <= 14) && (q - 1 >= 0))
				{
					coordinate[0] = p + 1;
					coordinate[1] = q - 1;
					return;
				}
			}
		}
	}
}

void init_best_score_of_upper() {
	int i  = 0;
	for (i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
			best_score_of_upper_ver2[i] = infinity;
		else
			best_score_of_upper_ver2[i] = -infinity;
	}
}
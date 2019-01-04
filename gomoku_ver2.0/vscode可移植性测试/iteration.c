#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
#include<math.h>
#include<time.h>
#include<stdlib.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//白棋
extern int b;//黑棋
extern unsigned long long ZobristTable[15][15][2];//梅森旋转的哈希键值表
extern unsigned long long hashValue;//梅森旋转算法下，棋盘的哈希值
extern HE hashing_value4[depth_of_hashing];
extern long int best_score_of_upper[11];
extern bool not_in_the_same_branch[11];
extern long int value_for_board;//新加
extern long int best_score_of_upper_ver2[12];
extern bool ai_first;
int temp_point[2] = { 0,0 };//临时落子坐标，在minimax的里面迭代的时候落子的时候用
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
bool stop_searching = false;
rp RootBoard[15][15];//根节点棋盘
rp * be_searched_point;//目前正在被搜索的根节点的指针
static int Range;


long int iteration_search(int step_count, bool my_turn)
{
	//int MaxFloor = (step_count <= 4) ? 4 : FLOOR;//一开始少一点，后面再渐渐增加
	//int MaxFloor = (step_count <= 4) ? 4 : ((step_count <= 8) ? 6 : FLOOR);//一开始少一点，后面再渐渐增加
	int MaxFloor = FLOOR;//test
	stop_searching = false;//每次开始整个AI思考过程时，对这个参数初始化
	long int best_score;
	int floor;
	int raw, column;
	double start_time, end_time, cost_time;
	const double time_limit = 6;
	start_time = clock();
	for (floor = 2; floor <= MaxFloor && (!stop_searching); floor += 2)
	{
		be_searched_point = &RootBoard[coordinate[0]][coordinate[1]];//将被搜索的根节点指针指向 对方刚刚落子的那个空位  对应在根节点棋盘的位置
		be_searched_point->raw = coordinate[0];
		be_searched_point->column = coordinate[1];
		if (floor == 6)
			Range = 10;
		else if (floor == 8)
			Range = 6;
		else
			Range = MaxRange;
		best_score = Minimax4(step_count, true, floor, floor);
		end_time = clock();
		cost_time = (end_time - start_time) / CLK_TCK;
		if (cost_time > time_limit)
			stop_searching = true;//超过限定时间就停止思考
	}
	
	raw = RootBoard[coordinate[0]][coordinate[1]].best_leaf[0];//将最原始的那个根节点，也就是对方上一局落子的坐标 对应的那个根节点  的最佳坐标赋给coordinate
	column = RootBoard[coordinate[0]][coordinate[1]].best_leaf[1];
	coordinate[0] = raw;
	coordinate[1] = column;
	
	return best_score;
}

long int Minimax4(int step_count, bool my_turn, int floor, int top_floor)
{
	int temp_blank;//用这个来还原棋盘，相当于悔棋一样的
	int chess;
	int opponent_chess;
	//bool final_hit = false;
	int status = 0;//0表示当前棋局正常, 1表示当前棋局发现我方连五, 2表示当前棋局没有发现我方连五，但是发现对方连五
	int abs_distance = top_floor - floor;//这个参数用于衡量本层离最上层的距离，因为迭代加深的缘故，每一次迭代加深对于相同的棋局来说，都处于不同的floor数，只有这个参数能够保持不变
	long int best_score = 0;
	long int worst_score = 0;
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;
	rp *RootPoint_of_this_floor = be_searched_point;//另设一个指针来保存本层被搜索的根节点，因为在之后的递归的时候，等号右边的值会经常变
	if ((step_count % 2) == 0)
	{
		chess = b;
		opponent_chess = w;
		if (ai_first)
			my_turn = true;
		else
			my_turn = false;
	}
	else
	{
		chess = w;
		opponent_chess = b;
		if (ai_first)
			my_turn = false;
		else
			my_turn = true;
	}

	if (coordinate[0] == 8 && coordinate[1] == 11 && floor == top_floor)
		printf("\n");


	if (floor != 0)
	{
		if (my_turn)
		{
			status = before_evaluation_ver6(step_count);
			if (status != 0)
			{
				if (floor == top_floor)//这种情况是，如果刚开始搜就发现有连五点，那就只搜这一层就退出
				{
					shallowest2(step_count, my_turn);
					best_score = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
					stop_searching = true;
					return best_score;
				}
				else//这种情况是，在某一层（不是最外层）搜到了连五点，那就当做最底层开始搜				
					return infinity;
			}
			else//这种情况是，一般的情况
			{
				bool initialized = false;//false表示best_score还没有被赋值过
				for (int a = 0; a < Range; a++)
				{
					if (RootPoint_of_this_floor->LeafPoint[a][0] == RootPoint_of_this_floor->best_leaf[0] && RootPoint_of_this_floor->LeafPoint[a][1] == RootPoint_of_this_floor->best_leaf[1])
					{//交换一下，将上一轮迭代加深找到的本层最优点放在最前面搜索
						int temp_exchange[2];
						temp_exchange[0] = RootPoint_of_this_floor->LeafPoint[0][0];
						temp_exchange[1] = RootPoint_of_this_floor->LeafPoint[0][1];
						RootPoint_of_this_floor->LeafPoint[0][0] = RootPoint_of_this_floor->LeafPoint[a][0];
						RootPoint_of_this_floor->LeafPoint[0][1] = RootPoint_of_this_floor->LeafPoint[a][1];
						RootPoint_of_this_floor->LeafPoint[a][0] = temp_exchange[0];
						RootPoint_of_this_floor->LeafPoint[a][1] = temp_exchange[1];
						break;
					}
				}

				for (int a = 0; a < Range; a++)
				{
					not_in_the_same_branch[floor - 1] = true;//判断是否在同一分支中，以免误剪枝
					int raw = RootPoint_of_this_floor->LeafPoint[a][0];
					int column = RootPoint_of_this_floor->LeafPoint[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{//初始化剪枝的参数
							if (floor - 2 >= 0)
								best_score_of_upper_ver2[floor - 2] = infinity;
							temp_blank = board[raw][column];
							board[raw][column] = chess;
							temp_point[0] = raw;
							temp_point[1] = column;
							refresh_banned_point_whole();
							refresh_score(step_count, my_turn);
							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							temp_score = Searching_Hashing(step_count, my_turn, 0, false, floor);

							if (temp_score == 0)
							{
								be_searched_point = &RootBoard[raw][column];
								be_searched_point->raw = raw;
								be_searched_point->column = column;//在递归前，将待搜索的根节点指针指向那个要进行递归的空位
								temp_score = Minimax4(step_count + 1, !my_turn, floor - 1, top_floor);
							}

							if (!initialized)
							{
								best_score = temp_score;
								worst_score = temp_score;
								initialized = true;
								RootPoint_of_this_floor->best_leaf[0] = raw;
								RootPoint_of_this_floor->best_leaf[1] = column;
								if (abs_distance != 0)
								{
									if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//剪枝
									{
										temp_point[0] = raw;
										temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
										board[raw][column] = temp_blank;
										refresh_banned_point_whole();
										refresh_score(step_count, my_turn);
										hashValue ^= ZobristTable[raw][column][(step_count % 2)];
										return infinity;
									}
								}
							}
							else
							{
								if (temp_score > best_score)
								{
									best_score = temp_score;
									RootPoint_of_this_floor->best_leaf[0] = raw;
									RootPoint_of_this_floor->best_leaf[1] = column;
									if (abs_distance != 0)
									{
										if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//剪枝
										{
											temp_point[0] = raw;
											temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
											board[raw][column] = temp_blank;
											refresh_banned_point_whole();
											refresh_score(step_count, my_turn);
											hashValue ^= ZobristTable[raw][column][(step_count % 2)];
											return infinity;
										}
									}
								}
								if (temp_score < worst_score)
									worst_score = temp_score;
							}//复原
							board[raw][column] = temp_blank;
							temp_point[0] = raw;
							temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
							refresh_banned_point_whole();
							refresh_score(step_count, my_turn);//再刷新一次
							if ((temp_score != -infinity) && (temp_score != infinity))//不要把被剪枝的分数给录进去
								Searching_Hashing(step_count, my_turn, temp_score, true, floor);
							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
							}
							if (best_score == infinity)
								return best_score;
						}
					}
				}

				if ((abs_distance == 0) && (best_score == worst_score))//循环完了之后，检测是不是所有的路径都是必胜或必败
				{
					if (worst_score == infinity)//必胜
						stop_searching = true;
					else if (best_score == -infinity)//必败
						stop_searching = true;
				}
			}
		}
		else
		{
			status = before_evaluation_ver6(step_count);
			if (status != 0)//my_turn为假的时候不可能是最外层，因此少了一个if语句
				return -infinity;
			else
			{
				bool initialized = false;//false表示best_score还没有被赋值过
				for (int a = 0; a < Range; a++)
				{
					if (RootPoint_of_this_floor->LeafPoint[a][0] == RootPoint_of_this_floor->best_leaf[0] && RootPoint_of_this_floor->LeafPoint[a][1] == RootPoint_of_this_floor->best_leaf[1])
					{//交换一下，将上一轮迭代加深找到的本层最优点放在最前面搜索
						int temp_exchange[2];
						temp_exchange[0] = RootPoint_of_this_floor->LeafPoint[0][0];
						temp_exchange[1] = RootPoint_of_this_floor->LeafPoint[0][1];
						RootPoint_of_this_floor->LeafPoint[0][0] = RootPoint_of_this_floor->LeafPoint[a][0];
						RootPoint_of_this_floor->LeafPoint[0][1] = RootPoint_of_this_floor->LeafPoint[a][1];
						RootPoint_of_this_floor->LeafPoint[a][0] = temp_exchange[0];
						RootPoint_of_this_floor->LeafPoint[a][1] = temp_exchange[1];
						break;
					}
				}
				for (int a = 0; a < Range; a++)
				{
					not_in_the_same_branch[floor - 1] = true;
					int raw = RootPoint_of_this_floor->LeafPoint[a][0];
					int column = RootPoint_of_this_floor->LeafPoint[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess) && (board[raw][column] != opponent_chess))
						{//初始化剪枝的参数
							if (floor - 2 >= 0)
								best_score_of_upper_ver2[floor - 2] = -infinity;
							temp_blank = board[raw][column];
							board[raw][column] = chess;
							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							temp_score = Searching_Hashing(step_count, my_turn, 0, false, floor);
							temp_point[0] = raw;
							temp_point[1] = column;
							refresh_banned_point_whole();
							refresh_score(step_count, my_turn);
							if (temp_score == 0)
							{
								be_searched_point = &RootBoard[raw][column];
								be_searched_point->raw = raw;
								be_searched_point->column = column;//在递归前，将待搜索的根节点指针指向那个要进行递归的空位
								temp_score = Minimax4(step_count + 1, !my_turn, floor - 1, top_floor);
							}

							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;
								RootPoint_of_this_floor->best_leaf[0] = raw;
								RootPoint_of_this_floor->best_leaf[1] = column;
								if (abs_distance != 0)
								{
									if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//剪枝
									{
										temp_point[0] = raw;
										temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
										board[raw][column] = temp_blank;
										refresh_banned_point_whole();
										refresh_score(step_count, my_turn);
										hashValue ^= ZobristTable[raw][column][(step_count % 2)];
										return -infinity;
									}
								}
							}
							else
							{
								if (temp_score < best_score)
								{
									best_score = temp_score;
									RootPoint_of_this_floor->best_leaf[0] = raw;
									RootPoint_of_this_floor->best_leaf[1] = column;
									if (abs_distance != 0)
									{
										if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//剪枝
										{
											temp_point[0] = raw;
											temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
											board[raw][column] = temp_blank;
											refresh_banned_point_whole();
											refresh_score(step_count, my_turn);
											hashValue ^= ZobristTable[raw][column][(step_count % 2)];
											return -infinity;
										}
									}
								}
							}
							board[raw][column] = temp_blank;
							temp_point[0] = raw;
							temp_point[1] = column;//需要重新赋值一遍，因为更下一层的递归修改过这个全局变量
							refresh_banned_point_whole();
							refresh_score(step_count, my_turn);//再刷新一次
							if ((temp_score != -infinity) && (temp_score != infinity))//不要把被剪枝的分数给录进去
								Searching_Hashing(step_count, my_turn, temp_score, true, floor);
							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
							}
							if (best_score == -infinity)
								return best_score;
						}
					}
				}
			}
		}
	}

	else//最底层↓
		best_score = deepest(step_count, my_turn);

	return best_score;
}

long int deepest(int step_count, bool my_turn)//最底层搜索单独提取出来了
{
	long int temp_score;
	long int ai_score, p_score;
	int raw, column;
	long int board_score = 0;
	if (ai_first)
	{//这个for循环是一开始就有的，别把这个给删了
		for (raw = 0; raw < 15; raw++)
		{
			for (column = 0; column < 15; column++)
			{
				if ((board[raw][column] != b)
					&& (board[raw][column] != w))
				{
					if (!banned_point_sheet[raw][column])
					{
						ai_score = empty_score_total_black[raw][column];
						p_score = empty_score_total_white[raw][column];
						temp_score = ai_score * 1.1 - p_score * 0.9;
						board_score += temp_score;
					}
				}
			}
		}
	}
	else
	{
		for (raw = 0; raw < 15; raw++)
		{
			for (column = 0; column < 15; column++)
			{
				if ((board[raw][column] != b)
					&& (board[raw][column] != w))
				{
					ai_score = empty_score_total_white[raw][column];
					p_score = empty_score_total_black[raw][column];
					temp_score = ai_score * 1.1 - p_score * 0.9;
					board_score += temp_score;
				}
			}
		}
	}

	return board_score;
}

void shallowest2(int step_count, bool my_turn)//这个函数是用于只检索一层的情况
{
	long int temp_score1 = 0;
	long int temp_score2 = 0;
	bool initialized = false;
	long int temp_score = 0;
	long int best_score;
	int best_coordinate[2] = { 0,0 };
	for (int raw = 0; raw < 15; raw++)
	{
		for (int column = 0; column < 15; column++)
		{
			if ((board[raw][column] != w)
				&& (board[raw][column] != b))
			{
				if (ai_first && (!banned_point_sheet[raw][column]))//由于此函数只会在AI下子的时候用到，因此ai_first就代表了ai拿黑子，有禁手
				{
					temp_score1 = evaluation(step_count, my_turn, raw, column);
					temp_score2 = evaluation(step_count + 1, !my_turn, raw, column);
					temp_score1 = labs(temp_score1) * 1.1;
					temp_score2 = labs(temp_score2) * 0.9;
					temp_score = temp_score1 + temp_score2;
					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_coordinate[0] = raw;
						best_coordinate[1] = column;

					}
					else
					{
						if (temp_score > best_score)
						{//之所以不取等，是因为如果所有分支的分值都为0的话，就拿最开始出现的那个落点来下，因为最开始的落点是本层评分最高的
							best_score = temp_score;
							best_coordinate[0] = raw;
							best_coordinate[1] = column;
						}
					}
				}
				else if (!ai_first)
				{
					temp_score1 = evaluation(step_count, my_turn, raw, column);
					temp_score2 = evaluation(step_count + 1, !my_turn, raw, column);
					temp_score1 = labs(temp_score1) * 1.1;
					temp_score2 = labs(temp_score2) * 0.9;
					temp_score = temp_score1 + temp_score2;

					if (!initialized)
					{
						best_score = temp_score;
						initialized = true;
						best_coordinate[0] = raw;
						best_coordinate[1] = column;
					}
					else
					{
						if (temp_score > best_score)
						{//之所以不取等，是因为如果所有分支的分值都为0的话，就拿最开始出现的那个落点来下，因为最开始的落点是本层评分最高的						
							best_score = temp_score;
							best_coordinate[0] = raw;
							best_coordinate[1] = column;
						}
					}
				}
			}
		}
	}
	be_searched_point->best_leaf[0] = best_coordinate[0];
	be_searched_point->best_leaf[1] = best_coordinate[1];
}


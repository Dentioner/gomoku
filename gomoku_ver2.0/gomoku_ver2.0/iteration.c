#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
#include<math.h>

extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//����
extern int b;//����
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
//extern unsigned long long hashing_value2[depth_of_hashing][3];
//extern unsigned long long hashing_value3[depth_of_hashing][4];
extern HE hashing_value4[depth_of_hashing];
extern long int best_score_of_upper[11];
extern bool not_in_the_same_branch[11];
extern long int value_for_board;//�¼�
extern long int best_score_of_upper_ver2[12];
//bool show_me_the_array = false;//�����õĲ���ֵ
extern bool ai_first;
int temp_point[2] = { 0,0 };//��ʱ�������꣬��minimax�����������ʱ�����ӵ�ʱ����
//int temp_bestpoint[FLOOR][2] = { 0 };//��ʱ�������꣬���ڵ�������
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
bool stop_searching = false;
rp RootBoard[15][15];//���ڵ�����
rp * be_searched_point;//Ŀǰ���ڱ������ĸ��ڵ��ָ��

long int iteration_search(int step_count, bool my_turn)
{
	//int MaxFloor = (step_count <= 4) ? 4 : FLOOR;//һ��ʼ��һ�㣬�����ٽ�������
	//int MaxFloor = (step_count <= 4) ? 4 : ((step_count <= 8) ? 6 : FLOOR);//һ��ʼ��һ�㣬�����ٽ�������
	int MaxFloor = FLOOR;//test
	stop_searching = false;//ÿ�ο�ʼ����AI˼������ʱ�������������ʼ��
	long int best_score;
	int floor;
	int raw, column;
	for (floor = 2; floor <= MaxFloor && (!stop_searching); floor += 2)
	{
		be_searched_point = &RootBoard[coordinate[0]][coordinate[1]];//���������ĸ��ڵ�ָ��ָ�� �Է��ո����ӵ��Ǹ���λ  ��Ӧ�ڸ��ڵ����̵�λ��
		be_searched_point->raw = coordinate[0];
		be_searched_point->column = coordinate[1];
		//RootBoard[coordinate[0]][coordinate[1]] = be_searched_point;
		best_score = Minimax4(step_count, true, floor, floor);
	}
	raw = RootBoard[coordinate[0]][coordinate[1]].best_leaf[0];//����ԭʼ���Ǹ����ڵ㣬Ҳ���ǶԷ���һ�����ӵ����� ��Ӧ���Ǹ����ڵ�  ��������긳��coordinate
	column = RootBoard[coordinate[0]][coordinate[1]].best_leaf[1];
	coordinate[0] = raw;
	coordinate[1] = column;
	return best_score;
}



long int Minimax4(int step_count, bool my_turn, int floor, int top_floor)
{

	int temp_blank;//���������ԭ���̣��൱�ڻ���һ����
	int chess;
	int opponent_chess;
	//bool final_hit = false;
	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ�����
	//2��ʾ��ǰ���û�з����ҷ����壬���Ƿ��ֶԷ�����
	int abs_distance = top_floor - floor;//����������ں������������ϲ�ľ��룬��Ϊ���������Ե�ʣ�ÿһ�ε������������ͬ�������˵�������ڲ�ͬ��floor����ֻ����������ܹ����ֲ���
	long int best_score = 0;
	//po best_point;
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;
	//bool valid_coordinate = false;
	rp *RootPoint_of_this_floor = be_searched_point;//����һ��ָ�������汾�㱻�����ĸ��ڵ㣬��Ϊ��֮��ĵݹ��ʱ�򣬵Ⱥ��ұߵ�ֵ�ᾭ����
	//�������ڽ���ai���֡��غ����롰�Ƿ����ҷ��غϡ��Ĺ�ϵ

	//����������������������ϵ���е��������õģ�����������ʱ��Ҫע�͵�
	if (coordinate[0] == 9 && coordinate[1] == 8 && floor == top_floor)
	{
		printf("\n");
		//show_me_the_array = true;
	}

	if ((step_count % 2) == 0)
	{
		chess = b;
		opponent_chess = w;
		if (ai_first)
		{
			my_turn = true;
		}
		else
		{
			my_turn = false;
		}
	}
	else
	{
		chess = w;
		opponent_chess = b;
		if (ai_first)
		{
			my_turn = false;
		}
		else
		{
			my_turn = true;
		}

	}


	if (floor != 0)
	{
		if (my_turn)
		{
			//if (floor <= 2)//�������������㣬������һ�����ȶ�
				status = before_evaluation_ver6(step_count);
			//����Ҫע����ǣ�ÿһ�ε��������һ�ε�������õ���priority_ver2���黹�ܽ����ã�
			//���ֻ��Ҫ�����²����������Ӧ�ĸ����鼴��		
			if (status != 0)
			{
				if (floor == top_floor)//��������ǣ�����տ�ʼ�Ѿͷ���������㣬�Ǿ�ֻ����һ����˳�
				{
					shallowest2(step_count, my_turn);
					best_score = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
					stop_searching = true;
					return best_score; 
				}
				else//��������ǣ���ĳһ�㣨��������㣩�ѵ�������㣬�Ǿ͵�����ײ㿪ʼ��
				{
					//best_score = deepest(step_count, my_turn);
					stop_searching = true;
					return infinity;
				}
			}

			else//��������ǣ�һ������
			{
				
				for (int a = 0; a < Range; a++)
				{
					if (RootPoint_of_this_floor->LeafPoint[a][0] == RootPoint_of_this_floor->best_leaf[0] && RootPoint_of_this_floor->LeafPoint[a][1] == RootPoint_of_this_floor->best_leaf[1])
					{//����һ�£�����һ�ֵ��������ҵ��ı������ŵ������ǰ������
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
				

				bool initialized = false;//false��ʾbest_score��û�б���ֵ��

				for (int a = 0; a < Range; a++)
				{
					not_in_the_same_branch[floor - 1] = true;//�ж��Ƿ���ͬһ��֧�У��������֦
					int raw = RootPoint_of_this_floor->LeafPoint[a][0];
					int column = RootPoint_of_this_floor->LeafPoint[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//��ʼ����֦�Ĳ���
							if (floor - 2 >= 0)
							{
								best_score_of_upper_ver2[floor - 2] = infinity;

							}
							temp_blank = board[raw][column];
							board[raw][column] = chess;
							temp_point[0] = raw;
							temp_point[1] = column;
							refresh_score(step_count, my_turn);
							//�����ã���ӡZobristTable�������Ƿ�����
							/*
							for (int z1 = 0; z1 < 15; z1++)
							{
								for (int z2 = 0; z2 < 15; z2++)
								{
									printf("%llu, %llu\n", ZobristTable[z1][z2][0], ZobristTable[z1][z2][1]);
								}
							}
							*/


							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							//������һ�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��

							//�����⼸�����ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�

							//DrawBoard(board, 15, 0, 2, coordinate, step_count);


							temp_score = Searching_Hashing(step_count, my_turn, 0, false, floor);
							//������һ�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��
							/*
							if (floor >= 4 && show_me_the_array)//test
								DrawBoard(0, 2, step_count);
							*/
							if (temp_score == 0)
							{
								be_searched_point = &RootBoard[raw][column];
								be_searched_point->raw = raw;
								be_searched_point->column = column;//�ڵݹ�ǰ�����������ĸ��ڵ�ָ��ָ���Ǹ�Ҫ���еݹ�Ŀ�λ
								temp_score = Minimax4(step_count + 1, !my_turn, floor - 1, top_floor);
							}

							//�����������ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);


							//�����ǴӾ���������������


							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;
								//֮ǰ��ֻ��������¼���꣬���ڲ�������һ�㶼�ü�¼һ��
								RootPoint_of_this_floor->best_leaf[0] = raw;
								RootPoint_of_this_floor->best_leaf[1] = column;
								//�����֦���޸�
								if (abs_distance != 0)
								{
									if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//��֦
									{
										temp_point[0] = raw;
										temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
										board[raw][column] = temp_blank;
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

									//valid_coordinate = verify_coordinate(board, raw, column, chess, opponent_chess);
									//if ((floor == top_floor)&&valid_coordinate)
									//֮ǰ��ֻ��������¼���꣬���ڲ�������һ�㶼�ü�¼һ��
									RootPoint_of_this_floor->best_leaf[0] = raw;
									RootPoint_of_this_floor->best_leaf[1] = column;
									//�����֦���޸�

									if (abs_distance != 0)
									{
										if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//��֦
										{
											temp_point[0] = raw;
											temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
											board[raw][column] = temp_blank;
											refresh_score(step_count, my_turn);
											hashValue ^= ZobristTable[raw][column][(step_count % 2)];
											return infinity;
										}

									}
								}
								//��ԭ
							}
							board[raw][column] = temp_blank;
							temp_point[0] = raw;
							temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
							refresh_score(step_count, my_turn);//��ˢ��һ��
							if ((temp_score != -infinity) && (temp_score != infinity))//��Ҫ�ѱ���֦�ķ�����¼��ȥ
							{
								Searching_Hashing(step_count, my_turn, temp_score, true, floor);




							}
							//�����⼸�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��

							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							//������һ�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��
							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
							}
							if (best_score == infinity)
							{
								/*
								if (abs_distance == 0)
								{
									coordinate[0] = temp_bestpoint[abs_distance][0];
									coordinate[1] = temp_bestpoint[abs_distance][1];
								}
								*/
								return best_score;
							}

						}
					}




				}

			}
		}
		else
		{
			//best_score_of_upper_ver2[floor] = 0;
			//status = before_evaluation_ver4(priority_ver2, floor, step_count, my_turn);
			//final_hit = before_evaluation(board, priority, floor, step_count, my_turn);
			//if (floor <= 2)
				status = before_evaluation_ver6(step_count);

			if (status != 0)//my_turnΪ�ٵ�ʱ�򲻿���������㣬�������һ��if���
			{
				//best_score = deepest(step_count, my_turn);
				stop_searching = true;
				return -infinity;
			}

			else
			{
				
				for (int a = 0; a < Range; a++)
				{
					if (RootPoint_of_this_floor->LeafPoint[a][0] == RootPoint_of_this_floor->best_leaf[0] && RootPoint_of_this_floor->LeafPoint[a][1] == RootPoint_of_this_floor->best_leaf[1])
					{//����һ�£�����һ�ֵ��������ҵ��ı������ŵ������ǰ������
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
				
				bool initialized = false;//false��ʾbest_score��û�б���ֵ��

				for (int a = 0; a < Range; a++)
				{

					not_in_the_same_branch[floor - 1] = true;
					int raw = RootPoint_of_this_floor->LeafPoint[a][0];
					int column = RootPoint_of_this_floor->LeafPoint[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//��ʼ����֦�Ĳ���
							if (floor - 2 >= 0)
							{
								best_score_of_upper_ver2[floor - 2] = -infinity;
								//not_in_the_same_branch[floor - 2] = true;
							}
							temp_blank = board[raw][column];
							board[raw][column] = chess;
							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							temp_score = Searching_Hashing(step_count, my_turn, 0, false, floor);
							//������2�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��
							temp_point[0] = raw;
							temp_point[1] = column;
							
							
							if (raw == 7 && column == 9 && floor == 3)
								DrawBoard(0, 2, step_count);//test


							refresh_score(step_count, my_turn);
							//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);
							/*
							if (floor >= 4 && show_me_the_array)//test
								DrawBoard(0, 2, step_count);
							*/
							if (temp_score == 0)
							{
								be_searched_point = &RootBoard[raw][column];
								be_searched_point->raw = raw;
								be_searched_point->column = column;//�ڵݹ�ǰ�����������ĸ��ڵ�ָ��ָ���Ǹ�Ҫ���еݹ�Ŀ�λ
								temp_score = Minimax4(step_count + 1, !my_turn, floor - 1, top_floor);
							}



							//�����ǴӾ���������������
							//if ((temp_score != 0) && (best_score == 0))
		//֮���԰������temp_score != 0Ҳ��ȥ��������Ϊ������һ��֦��һ������0��������ô����ֱ�Ӹ���bestscore
		//������һ����ԽСԽ�ã����֮ǰ��0��֦����ȴ������ˣ��ǲ������
		//������������һ�����Ϊ0�ĵ㣬���һ���ѵ��˴��Ϊ100�ĵ㣬��ȻӦ������һ�㴫��0�ֵģ���������������߼��жϣ�����ȥ��100��
		//����ʲô����дҲ���У���Ϊ����и��֣��ڡ�������Сֵ�������������޷���Ϊ����ֵ
									//����Ӧ�ò���״̬���ķ�������������һ��ֵ��ʱ��֤�ḳ��bests
							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;

								//֮ǰ��ֻ��������¼���꣬���ڲ�������һ�㶼�ü�¼һ��
								RootPoint_of_this_floor->best_leaf[0] = raw;
								RootPoint_of_this_floor->best_leaf[1] = column;

								if (abs_distance != 0)
								{
									if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//��֦
									{
										temp_point[0] = raw;
										temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
										board[raw][column] = temp_blank;
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
									//����û���Ǹ�������ж�����Ķ�������Ϊ������ǲ����ܻ���ִ���min�������

									//֮ǰ��ֻ��������¼���꣬���ڲ�������һ�㶼�ü�¼һ��
									RootPoint_of_this_floor->best_leaf[0] = raw;
									RootPoint_of_this_floor->best_leaf[1] = column;

									if (abs_distance != 0)
									{
										if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//��֦
										{
											temp_point[0] = raw;
											temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
											board[raw][column] = temp_blank;
											refresh_score(step_count, my_turn);
											hashValue ^= ZobristTable[raw][column][(step_count % 2)];
											return -infinity;
										}
									}
								}
							}

							board[raw][column] = temp_blank;
							temp_point[0] = raw;
							temp_point[1] = column;//��Ҫ���¸�ֵһ�飬��Ϊ����һ��ĵݹ��޸Ĺ����ȫ�ֱ���
							refresh_score(step_count, my_turn);//��ˢ��һ��

							if ((temp_score != -infinity) && (temp_score != infinity))//��Ҫ�ѱ���֦�ķ�����¼��ȥ
							{
								Searching_Hashing(step_count, my_turn, temp_score, true, floor);


							}
							//�����⼸�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��

							hashValue ^= ZobristTable[raw][column][(step_count % 2)];
							//������һ�������ù�ϣ��������ʱ��Ҫ�õ���ǧ��Ҫɾ��
							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
							}
							if (best_score == -infinity)
							{
								return best_score;
							}

						}
					}

				}

			}
		}

	}
	//��ײ��
	else
	{
		best_score = deepest(step_count, my_turn);
	}

	//����㣬��Ҫ����һ�����վ�������������
	/*
	if (floor == top_floor)
	{
		*coordinate = *best_coordinate;
		*(coordinate + 1) = *(best_coordinate + 1);
		best_score = evaluation(step_count, my_turn, coordinate[0], coordinate[1]);
	}
	*/


	//strncpy(board[best_coordinate[0]][best_coordinate[1]], temp_blank, 2);


	return best_score;
}



void shallowest2(int step_count, bool my_turn)//�������������ֻ����һ������
{
	long int temp_score1 = 0;
	long int temp_score2 = 0;

	bool initialized = false;
	long int temp_score = 0;
	long int best_score;
	int best_coordinate[2] = { 0,0 };
	//���forѭ����һ��ʼ���еģ���������ɾ��
	for (int raw = 0; raw < 15; raw++)
	{
		for (int column = 0; column < 15; column++)
		{
			if ((board[raw][column] != w)
				&& (board[raw][column] != b))
			{
				//temp_score = evaluation(board, step_count, my_turn, raw, column);
				if (ai_first && (!detect_forbidden_step(raw, column)))//���ڴ˺���ֻ����AI���ӵ�ʱ���õ������ai_first�ʹ�����ai�ú��ӣ��н���
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
							//֮���Բ�ȡ�ȣ�����Ϊ������з�֧�ķ�ֵ��Ϊ0�Ļ��������ʼ���ֵ��Ǹ�������£���Ϊ�ʼ������Ǳ���������ߵ�
						{
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
							//֮���Բ�ȡ�ȣ�����Ϊ������з�֧�ķ�ֵ��Ϊ0�Ļ��������ʼ���ֵ��Ǹ�������£���Ϊ�ʼ������Ǳ���������ߵ�
						{
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


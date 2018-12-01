#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
#include<time.h>
#include<math.h>

//������ȥ���˹�ϣ
extern int board[15][15];
extern int coordinate[2];
extern int roaming;
extern int w;//����
extern int b;//����
extern unsigned long long ZobristTable[15][15][2];//÷ɭ��ת�Ĺ�ϣ��ֵ��
extern unsigned long long hashValue;//÷ɭ��ת�㷨�£����̵Ĺ�ϣֵ
extern unsigned long long hashing_value2[depth_of_hashing][3];
extern long int best_score_of_upper[11];
extern bool not_in_the_same_branch[11];
extern long int value_for_board;//�¼�
extern long int best_score_of_upper_ver2[12];
bool show_me_the_array =  false;//�����õĲ���ֵ
extern bool ai_first;

long int Minimax2(int step_count, bool my_turn, bool ai_first, int floor)
{

	int temp_blank;//���������ԭ���̣��൱�ڻ���һ����
	int chess;
	int opponent_chess;
	//bool final_hit = false;
	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ�����
	//2��ʾ��ǰ���û�з����ҷ����壬���Ƿ��ֶԷ�����
	int priority_ver2[10][2] = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };
	long int best_score = 0;
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;
	//bool valid_coordinate = false;
	//�������ڽ���ai���֡��غ����롰�Ƿ����ҷ��غϡ��Ĺ�ϵ

	//����������������������ϵ���е��������õģ�����������ʱ��Ҫע�͵�
	if (coordinate[0] == 11 && coordinate[1] == 6 && floor == FLOOR)
	{
		printf("\n");
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
			//best_score_of_upper[floor] = 0;
			//�Ƚ����ȵ���Щ���ҵ����ݹ�
			//�ɵ�����ʽ����
			//status = before_evaluation_ver2(board, priority, floor, step_count, my_turn);
			status = before_evaluation_ver4(priority_ver2, floor, step_count, my_turn);

			if (status != 0)
			{


				long int temp_score1 = 0;
				long int temp_score2 = 0;
				int best_raw = 0;
				int best_column = 1;
				bool initialized = false;

				//����ѵĵ�����ֵ

				temp_score = 0;
				
				//���forѭ����һ��ʼ���еģ���������ɾ��
				for (int raw = 0; raw < 15; raw++)
				{
					for (int column = 0; column < 15; column++)
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//temp_score = evaluation(board, step_count, my_turn, raw, column);

							temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
							temp_score2 = evaluation_ver2(step_count + 1, !my_turn, raw, column);

							temp_score1 = abs(temp_score1) * 1.5;
							temp_score2 = abs(temp_score2) * 0.75;
							temp_score = temp_score1 + temp_score2;

							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;
								best_raw = raw;
								best_column = column;

							}
							else
							{
								if (temp_score > best_score)
									//֮���Բ�ȡ�ȣ�����Ϊ������з�֧�ķ�ֵ��Ϊ0�Ļ��������ʼ���ֵ��Ǹ�������£���Ϊ�ʼ������Ǳ���������ߵ�
								{
									best_score = temp_score;
									if (floor == FLOOR)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
										best_raw = raw;
										best_column = column;

									}
								}
							}
						}
					}
				}







			}
			else
			{


				bool initialized = false;//false��ʾbest_score��û�б���ֵ��
				
				for (int a = 0; a < 10; a++)
				{
					not_in_the_same_branch[floor - 1] = true;//�ж��Ƿ���ͬһ��֧�У��������֦
					int raw = priority_ver2[a][0];
					int column = priority_ver2[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//��ʼ����֦�Ĳ���
							if (floor - 2 >= 0)
							{
								best_score_of_upper[floor - 2] = infinity;
								
							}
							temp_blank = board[raw][column];
							board[raw][column] = chess;
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

							temp_score = 0;
							//�����⼸�����ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�

							//DrawBoard(board, 15, 0, 2, coordinate, step_count);


							
							if (temp_score == 0)
							{
								temp_score = Minimax2(step_count + 1, !my_turn, ai_first, floor - 1);
							}

							//�����������ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);


							//�����ǴӾ���������������


							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;

								if (floor == FLOOR)
									//���������㣬��¼��ʱ����
								{
									best_coordinate[0] = raw;
									best_coordinate[1] = column;
								}
								//�����֦���޸�

								else
								{
									if ((best_score > best_score_of_upper[floor]) && (not_in_the_same_branch[floor]))//��֦
									{
										board[raw][column] = temp_blank;
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
									//if ((floor == FLOOR)&&valid_coordinate)
									if (floor == FLOOR)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}
									//�����֦���޸�

									else
									{
										if ((best_score > best_score_of_upper[floor]) && (not_in_the_same_branch[floor]))//��֦
										{
											board[raw][column] = temp_blank;
											return infinity;
										}

									}
								}
								//��ԭ
							}
							board[raw][column] = temp_blank;
							
							if (best_score > best_score_of_upper[floor - 1])
							{
								best_score_of_upper[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
							}
							if (best_score == infinity)
							{
								return best_score;
							}

						}
					}




				}

			}
		}
		else
		{
			//best_score_of_upper[floor] = 0;
			status = before_evaluation_ver4(priority_ver2, floor, step_count, my_turn);
			//final_hit = before_evaluation(board, priority, floor, step_count, my_turn);


			if (status != 0)
			{
				long int temp_score1 = 0;
				long int temp_score2 = 0;
				int best_raw = 0;
				int best_column = 0;
				bool initialized = false;

				//����ѵĵ�����ֵ


				temp_score = 0;






				//�������forѭ����ɾ��
				for (int raw = 0; raw < 15; raw++)
				{
					for (int column = 0; column < 15; column++)
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//temp_score = evaluation(board, step_count, my_turn, raw, column);
							temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
							temp_score2 = evaluation_ver2( step_count + 1, !my_turn, raw, column);
							temp_score1 = abs(temp_score1) * 1.5;
							temp_score2 = abs(temp_score2) * 0.75;
							temp_score = -(temp_score1 + temp_score2);

							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;
								best_raw = raw;
								best_column = column;

							}
							else
							{
								if (temp_score < best_score)
								{
									best_score = temp_score;
									if (floor == FLOOR)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
										best_raw = raw;
										best_column = column;

									}
								}
							}
						}

					}
				}



			}
			else
			{

				
				bool initialized = false;//false��ʾbest_score��û�б���ֵ��
				
				for (int a = 0; a < 10; a++)
				{

					not_in_the_same_branch[floor - 1] = true;
					int raw = priority_ver2[a][0];
					int column = priority_ver2[a][1];
					if ((raw != 0) || (column != 0))
					{
						if ((board[raw][column] != chess)
							&& (board[raw][column] != opponent_chess))
						{
							//��ʼ����֦�Ĳ���
							if (floor - 2 >= 0)
							{
								best_score_of_upper[floor - 2] = -infinity;
								//not_in_the_same_branch[floor - 2] = true;
							}
							temp_blank = board[raw][column];
							board[raw][column] = chess;
							temp_score = 0;
							//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);
							if (temp_score == 0)
							{
								temp_score = Minimax2(step_count + 1, !my_turn, ai_first, floor - 1);
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

								if (floor == FLOOR)
									//���������㣬��¼��ʱ����
								{
									best_coordinate[0] = raw;
									best_coordinate[1] = column;
								}

								else
								{
									if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
									{
										board[raw][column] = temp_blank;
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

									if (floor == FLOOR)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}

									else
									{
										if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
										{
											board[raw][column] = temp_blank;
											return -infinity;
										}
									}
								}
							}

							board[raw][column] = temp_blank;
							
							if (best_score > best_score_of_upper[floor - 1])
							{
								best_score_of_upper[floor - 1] = best_score;
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
		long int temp_score1 = 0;
		long int temp_score2 = 0;
		int best_raw = 0;
		int best_column = 1;
		bool initialized = false;

		//����ѵĵ�����ֵ
		if (my_turn)
		{
			temp_score = 0;
			//����ɾ��һ��ע�ͣ�Ҫ�ָ���ȥ����ĵط��浵��minimax�ļ�


					//���forѭ����һ��ʼ���еģ���������ɾ��
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 0; column < 15; column++)
				{
					if ((board[raw][column] != chess)
						&& (board[raw][column] != opponent_chess))
					{
						//temp_score = evaluation(board, step_count, my_turn, raw, column);

						temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
						temp_score2 = evaluation_ver2(step_count + 1, !my_turn, raw, column);

						temp_score1 = abs(temp_score1) * 1.5;
						temp_score2 = abs(temp_score2) * 0.75;
						temp_score = temp_score1 + temp_score2;
						if (!initialized)
						{
							best_score = temp_score;
							initialized = true;
							best_raw = raw;
							best_column = column;

						}
						else
						{
							if (temp_score > best_score)
							{
								best_score = temp_score;

							}
						}
						
					}
				}
			}

		}
		else
		{
			temp_score = 0;


			//�������forѭ����ɾ��
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 0; column < 15; column++)
				{
					if ((board[raw][column] != chess)
						&& (board[raw][column] != opponent_chess))
					{
						temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
						temp_score2 = evaluation_ver2(step_count + 1, !my_turn, raw, column);
						temp_score1 = abs(temp_score1) * 1.5;
						temp_score2 = abs(temp_score2) * 0.75;
						temp_score = -(temp_score1 + temp_score2);

						if (!initialized)
						{
							best_score = temp_score;
							initialized = true;
							best_raw = raw;
							best_column = column;

						}
						else
						{
							if (temp_score < best_score)
							{
								best_score = temp_score;

							}
						}
					
					}

				}
			}








		}
	}

	//����㣬��Ҫ����һ�����վ�������������
	if ((FLOOR - floor) == 0)
	{
		*coordinate = *best_coordinate;
		*(coordinate + 1) = *(best_coordinate + 1);
		best_score = evaluation_ver2(step_count, my_turn, coordinate[0], coordinate[1]);
	}



	//strncpy(board[best_coordinate[0]][best_coordinate[1]], temp_blank, 2);


	return best_score;
}

long int Minimax3(int step_count, bool my_turn, int floor)
{

	int temp_blank;//���������ԭ���̣��൱�ڻ���һ����
	int chess;
	int opponent_chess;
	//bool final_hit = false;
	int status = 0; 
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ�����
	//2��ʾ��ǰ���û�з����ҷ����壬���Ƿ��ֶԷ�����
	int priority_ver2[10][2] = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };
	long int best_score = 0;
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;
	//bool valid_coordinate = false;
	//�������ڽ���ai���֡��غ����롰�Ƿ����ҷ��غϡ��Ĺ�ϵ

	//����������������������ϵ���е��������õģ�����������ʱ��Ҫע�͵�
	if (coordinate[0] == 0 && coordinate[1] == 0 && floor == FLOOR2)
	{
		printf("\n");
		show_me_the_array = true;
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
			//best_score_of_upper[floor] = 0;
			//�Ƚ����ȵ���Щ���ҵ����ݹ�
			//�ɵ�����ʽ����
			//status = before_evaluation_ver2(board, priority, floor, step_count, my_turn);
			status = before_evaluation_ver4(priority_ver2, floor, step_count, my_turn);

			if (status != 0)
			{
				if (floor == FLOOR2)//��������ǣ�����տ�ʼ�Ѿͷ���������㣬�Ǿ�ֻ����һ����˳�
				{
					shallowest(step_count, my_turn);
					best_score = evaluation_ver2(step_count, my_turn, coordinate[0], coordinate[1]);
					return best_score;
				}
				else//��������ǣ���ĳһ�㣨��������㣩�ѵ�������㣬�Ǿ͵�����ײ㿪ʼ��
				{
					//best_score = deepest(step_count, my_turn);
					return infinity;
				}
			}
			else//��������ǣ�һ������
			{


				bool initialized = false;//false��ʾbest_score��û�б���ֵ��

				for (int a = 0; a < 10; a++)
				{
					not_in_the_same_branch[floor - 1] = true;//�ж��Ƿ���ͬһ��֧�У��������֦
					int raw = priority_ver2[a][0];
					int column = priority_ver2[a][1];
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

							temp_score = 0;
							//�����⼸�����ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�

							//DrawBoard(board, 15, 0, 2, coordinate, step_count);



							if (temp_score == 0)
							{
								temp_score = Minimax3(step_count + 1, !my_turn, floor - 1);
							}

							//�����������ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);


							//�����ǴӾ���������������


							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;

								if (floor == FLOOR2)
									//���������㣬��¼��ʱ����
								{
									best_coordinate[0] = raw;
									best_coordinate[1] = column;
								}
								//�����֦���޸�

								else
								{
									if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//��֦
									{
										board[raw][column] = temp_blank;
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
									//if ((floor == FLOOR)&&valid_coordinate)
									if (floor == FLOOR2)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}
									//�����֦���޸�

									else
									{
										if ((best_score > best_score_of_upper_ver2[floor]) && (not_in_the_same_branch[floor]))//��֦
										{
											board[raw][column] = temp_blank;
											return infinity;
										}

									}
								}
								//��ԭ
							}
							board[raw][column] = temp_blank;

							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
								if (best_score == 9375310)//������
									printf("\n");
							}
							if (best_score == infinity)
							{
								if (floor == FLOOR2)
								{
									coordinate[0] = best_coordinate[0];
									coordinate[1] = best_coordinate[1];
								}
								return best_score;
							}

						}
					}




				}

			}
		}
		else
		{
			//best_score_of_upper[floor] = 0;
			status = before_evaluation_ver4(priority_ver2, floor, step_count, my_turn);
			//final_hit = before_evaluation(board, priority, floor, step_count, my_turn);

			
			if (status != 0)//my_turnΪ�ٵ�ʱ�򲻿���������㣬�������һ��if���
			{
				//best_score = deepest(step_count, my_turn);
				return -infinity;
			}
			/*
			else
			{*/
			else
			{ 
				bool initialized = false;//false��ʾbest_score��û�б���ֵ��

				for (int a = 0; a < 10; a++)
				{

					not_in_the_same_branch[floor - 1] = true;
					int raw = priority_ver2[a][0];
					int column = priority_ver2[a][1];
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
							temp_score = 0;
							//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
							//DrawBoard(board, 15, 0, 2, coordinate, step_count);
							if (temp_score == 0)
							{
								temp_score = Minimax3(step_count + 1, !my_turn, floor - 1);
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

								if (floor == FLOOR2)
									//���������㣬��¼��ʱ����
								{
									best_coordinate[0] = raw;
									best_coordinate[1] = column;
								}

								else
								{
									if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//��֦
									{  
										board[raw][column] = temp_blank;
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

									if (floor == FLOOR2)
										//���������㣬��¼��ʱ����
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}

									else
									{
										if ((best_score < best_score_of_upper_ver2[floor]) && not_in_the_same_branch[floor])//��֦
										{
											board[raw][column] = temp_blank;
											return -infinity;
										}
									}
								}
							}

							board[raw][column] = temp_blank;

							if (best_score > best_score_of_upper_ver2[floor - 1])
							{
								best_score_of_upper_ver2[floor - 1] = best_score;
								not_in_the_same_branch[floor - 1] = false;
								if (best_score == 9375310)//������
									printf("\n");
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
	if ((FLOOR2 - floor) == 0)
	{
		*coordinate = *best_coordinate;
		*(coordinate + 1) = *(best_coordinate + 1);
		best_score = evaluation_ver2(step_count, my_turn, coordinate[0], coordinate[1]);
	}



	//strncpy(board[best_coordinate[0]][best_coordinate[1]], temp_blank, 2);

	
	return best_score;
}


long int deepest(int step_count, bool my_turn)//��ײ�����������ȡ������
{
	long int temp_score; 
	long int temp_score1, temp_score2;
	
	int raw, column;
	//����ɾ��һ��ע�ͣ�Ҫ�ָ���ȥ����ĵط��浵��minimax�ļ�
	long int board_score = 0;

			//���forѭ����һ��ʼ���еģ���������ɾ��
	for (raw = 0; raw < 15; raw++)
	{
		for (column = 0; column < 15; column++)
		{
			if ((board[raw][column] != b)
				&& (board[raw][column] != w))
			{
				//temp_score = evaluation(board, step_count, my_turn, raw, column);

				temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
				temp_score2 = evaluation_ver2(step_count + 1, !my_turn, raw, column);
				/*
				temp_score1 = abs(temp_score1) * 1.5;
				temp_score2 = abs(temp_score2) * 0.75;
				temp_score = temp_score1 + temp_score2;
				*/
				temp_score = temp_score1 * 1.1 + temp_score2 * 0.9;
				board_score += temp_score;
				/*
				if (!initialized)
				{
					best_score = temp_score;
					initialized = true;
					best_raw = raw;
					best_column = column;

				}
				else
				{
					if (temp_score > best_score)
					{
						best_score = temp_score;

					}
				}
				*/

			}
		}
	}
	 
	

	return board_score;
}

void shallowest(int step_count, bool my_turn)//�������������ֻ����һ������
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

				temp_score1 = evaluation_ver2(step_count, my_turn, raw, column);
				temp_score2 = evaluation_ver2(step_count + 1, !my_turn, raw, column);

				temp_score1 = abs(temp_score1) * 1.1;
				temp_score2 = abs(temp_score2) * 0.9;
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
	*coordinate = *best_coordinate;
	*(coordinate + 1) = *(best_coordinate + 1);
}
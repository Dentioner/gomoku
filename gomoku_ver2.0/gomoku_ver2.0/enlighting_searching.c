#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"
#include<stdlib.h>

extern int board[15][15];
extern int w;//����
extern int b;//����
extern int coordinate[2];
extern bool show_me_the_array;//������
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern int  temp_point[2];
//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js

int before_evaluation_ver4_5(int priority_ver2[][2], int step_count)
{
	long int temp_priority[255][3] = { 0 };//�Ƚ�255���������ȫ��������
	int my_raw = 0;
	int my_column = 0;

	int index = 0;
	int i = 0;
	long int my_value = 0;
	long int opponent_value = 0;
	long int temp_value = 0;
	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ����壬�������Է�����
	int array_size = 1;



	if (step_count % 2)//˵���ǰ��巽���ʴ˺���
	{
		for (my_raw = 0; my_raw < 15; my_raw++)
		{
			for (my_column = 0; my_column < 15; my_column++)
			{
				if ((board[my_raw][my_column] != b)
					&& (board[my_raw][my_column] != w))
				{
					//temp_value = empty_score_total[my_raw][my_column];
					my_value = empty_score_total_white[my_raw][my_column];
					//my_value = labs(my_value);
					opponent_value = empty_score_total_black[my_raw][my_column];
					//opponent_value = labs(opponent_value);
					temp_value = my_value + opponent_value;

					if (temp_value != 0)
					{
						if (my_value >= Consecutive_Five)//�����ҷ����壬����
						{
							status = 1;
							return status;
						}

						else//�������¼������
						{//����д������㷨
							temp_priority[index][0] = temp_value;
							temp_priority[index][1] = my_raw;
							temp_priority[index][2] = my_column;
							index++;


						}
					}
				}
			}
		}
	}

	else//˵���Ǻ��巽���ʵĴ˺���
	{
		for (my_raw = 0; my_raw < 15; my_raw++)
		{
			for (my_column = 0; my_column < 15; my_column++)
			{
				if ((board[my_raw][my_column] != b)
					&& (board[my_raw][my_column] != w))
				{
					//test
					//if (my_raw == 5 && my_column == 10)
						//printf("\n");

					//temp_value = empty_score_total[my_raw][my_column];
					my_value = empty_score_total_black[my_raw][my_column];
					//my_value = labs(my_value);
					opponent_value = empty_score_total_white[my_raw][my_column];
					//opponent_value = labs(opponent_value);
					temp_value = my_value + opponent_value;

					if (temp_value != 0)
					{
						if (my_value >= Consecutive_Five)//�����ҷ����壬����
						{
							status = 1;
							return status;
						}

						else//�������¼������
						{//����д������㷨
							temp_priority[index][0] = temp_value;
							temp_priority[index][1] = my_raw;
							temp_priority[index][2] = my_column;
							index++;
						}
					}
				}
			}
		}
	}
	quick_sort(temp_priority, 0, index - 1);//index��ֵ�ǵ�һ��0Ԫ�ص�λ��

	for (i = 0; (i < index) && (i < 10); i++)//��temp��ǰʮ������긳ֵ�������prioriy_ver2
	{
		priority_ver2[i][0] = temp_priority[i][1];
		priority_ver2[i][1] = temp_priority[i][2];
		/*
		if (temp != *chess_pointer)
		{
			printf(" ");
		}
		*/
	}


	if (show_me_the_array)
	{

		for (int ceshi = 0; ceshi < 10; ceshi++)
		{
			printf("���֣�%d�����꣺(%d, %d)\n", temp_priority[ceshi][0], temp_priority[ceshi][1], temp_priority[ceshi][2]);
		}
		//system("pause");
	}

	return status;
}

int before_evaluation_ver6(int priority_ver2[][2], int step_count)
{
	int my_raw, my_column;
	long int my_value, opponent_value;
	long int temp_value;
	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ����壬�������Է�����
	int node_number = 0;//��¼�γɵ�����ڵ���
	int index;
	Node * head = NULL;
	Node * prev, *current, *post;
	Node * insert_node;


	if (step_count % 2)//˵���ǰ��巽���ʴ˺���
	{
		for (my_raw = 0; my_raw < 15; my_raw++)
		{
			for (my_column = 0; my_column < 15; my_column++)
			{
				if ((board[my_raw][my_column] != b)
					&& (board[my_raw][my_column] != w))
				{
					my_value = empty_score_total_white[my_raw][my_column];
					opponent_value = empty_score_total_black[my_raw][my_column];
					temp_value = my_value + opponent_value;
					if (temp_value != 0)
					{
						if (my_value >= Consecutive_Five)//�����ҷ����壬����
						{
							status = 1;
							return status;
						}

						else//�������¼������
						{//����д������㷨

							insert_node = (Node *)malloc(sizeof(Node));
							insert_node->score = temp_value;
							insert_node->raw = my_raw;
							insert_node->column = my_column;
							insert_node->next = NULL;//������������һ��������Ľڵ�



							index = 0;//index��¼�����ڵ�Ĵ��������ͽڵ�Ƚ��˼���
							if (head == NULL)//��ʼ������������ʱһ���ڵ㶼û��
							{
								head = insert_node;
								node_number++;
							}
							else
							{
								current = head;//���Ƚ���һ���ڵ㵱����ǰ�ڵ�
								prev = NULL;
								post = head->next;//�������Ľڵ����head֮����Ǹ��ڵ�
								//�����������ǽ����Ƚϵ������ʼ��


								while (index < node_number && current != NULL)
								{//�����ǰ�ȽϵĴ����Ƚڵ�����С�����ҵ�ǰ�ڵ��ָ�벻�ǿ�ָ��
									if (insert_node->score >= current->score)
									{//���������Ľڵ�ķ�ֵ�ȵ�ǰ�ڵ�ķ�ֵ��
										if (index == 0)//���������Ľڵ�����߷�
										{
											insert_node->next = head;//������ͷ����һ����ַָ��ǰ��ͷ
											head = insert_node;//����ͷ�͸ĳɴ�����Ľڵ�
											node_number++;//�ڵ���+1
											break;
										}
										else
										{
											insert_node->next = current;//��������ڵ����һ����ַָ��ǰ�ڵ�
											prev->next = insert_node;//��ǰһ���ڵ����һ����ַָ�������ڵ�
											node_number++;//�ڵ���+1
											break;//����ѭ��
										}
									}
									else
									{//���������Ľڵ�ķ�ֵ�ȵ�ǰ�ڵ�ķ�ֵ��
										prev = current;//��ǰ�ڵ�ĵ�ַ����ǰһ���ڵ㣬��ǰ��һλ
										current = post;//��һ���ڵ�ĵ�ַ������ǰ�ڵ㣬��ǰ��һλ
										if (post != NULL)
											post = post->next;//��һ���ڵ�ָ��ĺ��һ���ڵ�ĵ�ַ������һ���ڵ㣬��ǰ��һλ
										index++;//�����������Ƚ��˼����ڵ���
									}
								}
								if (index == node_number)//����Ƚϴ������ڽڵ�����˵�������������С�ģ�Ӧ�÷����������
								{
									prev->next = insert_node;//����ǰ�ڵ������ַָ�������Ľڵ�
									node_number++;
								}
							}
						}
					}
				}
			}
		}
	}

	else//˵���Ǻ��巽���ʵĴ˺���
	{
		for (my_raw = 0; my_raw < 15; my_raw++)
		{
			for (my_column = 0; my_column < 15; my_column++)
			{
				if ((board[my_raw][my_column] != b)
					&& (board[my_raw][my_column] != w)
					&& (!detect_forbidden_step(my_raw, my_column)))
				{
					my_value = empty_score_total_black[my_raw][my_column];
					opponent_value = empty_score_total_white[my_raw][my_column];
					temp_value = my_value + opponent_value;
					if (temp_value != 0)
					{
						if (my_value >= Consecutive_Five)//�����ҷ����壬����
						{
							status = 1;
							return status;
						}

						else//�������¼������
						{//����д������㷨

							insert_node = (Node *)malloc(sizeof(Node));
							insert_node->score = temp_value;
							insert_node->raw = my_raw;
							insert_node->column = my_column;
							insert_node->next = NULL;//������������һ��������Ľڵ�



							index = 0;//index��¼�����ڵ�Ĵ��������ͽڵ�Ƚ��˼���
							if (head == NULL)//��ʼ������������ʱһ���ڵ㶼û��
							{
								head = insert_node;
								node_number++;
							}
							else
							{
								current = head;//���Ƚ���һ���ڵ㵱����ǰ�ڵ�
								prev = NULL;
								post = head->next;//�������Ľڵ����head֮����Ǹ��ڵ�
								//�����������ǽ����Ƚϵ������ʼ��

								while (index < node_number && current != NULL)
								{//�����ǰ�ȽϵĴ����Ƚڵ�����С�����ҵ�ǰ�ڵ��ָ�벻�ǿ�ָ��
									if (insert_node->score >= current->score)
									{//���������Ľڵ�ķ�ֵ�ȵ�ǰ�ڵ�ķ�ֵ��
										if (index == 0)//���������Ľڵ�����߷�
										{
											insert_node->next = head;//������ͷ����һ����ַָ��ǰ��ͷ
											head = insert_node;//����ͷ�͸ĳɴ�����Ľڵ�
											node_number++;//�ڵ���+1
											break;
										}
										else
										{
											insert_node->next = current;//��������ڵ����һ����ַָ��ǰ�ڵ�
											prev->next = insert_node;//��ǰһ���ڵ����һ����ַָ�������ڵ�
											node_number++;//�ڵ���+1
											break;//����ѭ��
										}
									}
									else
									{//���������Ľڵ�ķ�ֵ�ȵ�ǰ�ڵ�ķ�ֵ��
										prev = current;//��ǰ�ڵ�ĵ�ַ����ǰһ���ڵ㣬��ǰ��һλ
										current = post;//��һ���ڵ�ĵ�ַ������ǰ�ڵ㣬��ǰ��һλ
										if (post != NULL)
											post = post->next;//��һ���ڵ�ָ��ĺ��һ���ڵ�ĵ�ַ������һ���ڵ㣬��ǰ��һλ
										index++;//�����������Ƚ��˼����ڵ���
									}
								}
								if (index == node_number)//����Ƚϴ������ڽڵ�����˵�������������С�ģ�Ӧ�÷����������
								{
									prev->next = insert_node;//����ǰ�ڵ������ַָ�������Ľڵ�
									node_number++;
								}
							}
						}
					}
				}
			}
		}
	}

	current = head;
	for (index = 0; (current != NULL) && (index < 10); index++)//��temp��ǰʮ������긳ֵ�������prioriy_ver2
	{

		priority_ver2[index][0] = current->raw;
		priority_ver2[index][1] = current->column;
		current = current->next;
	}

	//�ͷ��ڴ�

	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
	return status;
}

void refresh_score(int step_count, bool my_turn)//����ˢ�¸����µ��ӵ��ĸ�������6����λ���ڵĿո�ķ���������ٶȹ��������޸�Ϊ4����λ���ڵĿո�
{

	int horizon[2] = { 0,1 };//ˮƽ����λʸ��
	int perpendicular[2] = { 1,0 };//��ֱ����λʸ��
	int up_right_down_left[2] = { -1,1 };//�������·���λʸ��
	int up_left_down_right[2] = { 1,1 };//�������·���λʸ��
	/*
	for (i = -6, j = -6; i < 6 && j < 6; i++, j++)
	{
		re_calculate(horizon, i, j, step_count, my_turn);//ˢ��ˮƽ����Ŀո�ķ���
		re_calculate(perpendicular, i, j, step_count, my_turn);//ˢ����ֱ����Ŀո�ķ���
		re_calculate(up_right_down_left, i, j, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
		re_calculate(up_left_down_right, i, j, step_count, my_turn);//ˢ���������·���Ŀո�ķ���

	}
	*/
	//if (temp_point[0] == 8 && temp_point[1] == 6)
		//DrawBoard(0, 2, step_count);

	re_calculate(horizon, step_count, my_turn);//ˢ��ˮƽ����Ŀո�ķ���
	re_calculate(perpendicular, step_count, my_turn);//ˢ����ֱ����Ŀո�ķ���
	re_calculate(up_right_down_left, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
	re_calculate(up_left_down_right, step_count, my_turn);//ˢ���������·���Ŀո�ķ���
}

void re_calculate(int vector[], int step_count, bool my_turn)
{
	/*
	int raw, column;
	long int value;
	raw = temp_point[0] + vector[0] * i;
	column = temp_point[1] + vector[1] * j;
	value = evaluation_ver2(step_count, my_turn, raw, column);
	empty_score_total[raw][column] = value;
	*/
	int i, j;
	int raw, column, point;
	long int white_value, black_value;
	for (i = -6, j = -6; i < 7 && j < 7; i++, j++)
	{
		raw = temp_point[0] + vector[0] * i;
		column = temp_point[1] + vector[1] * j;
		if (raw >= 0 && raw <= 14 && column >= 0 && column <= 14)
		{
			point = board[raw][column];
			if (point != w && point != b && (raw != temp_point[0] || column != temp_point[1]))
			{//�ж�����Ϊ���������ӣ��Ҳ��Ǹո�������Ǹ���
//֮������Ӻ����Ǹ���������Ϊ�ڳ������Ӳ������÷������ȥ��ʱ�򣬸ո�������Ǹ�λ��Ҳ�ᱻ������һ�飬����ʵ�����Ǹ�λ�ò�����
				black_value = evaluation(2, true, raw, column);//��step_countǿ����Ϊż��2����֤�Ǻ��ӵ÷֣�����my_turnǿ����Ϊtrue����֤����÷�Ϊ����
				white_value = evaluation(3, true, raw, column);//��step_countǿ����Ϊ����3����֤�ǰ��ӵ÷֣�����my_turnǿ����Ϊtrue����֤����÷�Ϊ����
				empty_score_total_black[raw][column] = black_value;
				empty_score_total_white[raw][column] = white_value;
				//if (empty_score_total_white[4][12] == 10000)
					//printf("test\n");
			}
		}

	}
}

void quick_sort(long int temp_priority[][3], int l, int r)//�Զ�ά������н���Ŀ�������
{//�˺����ο�https://blog.csdn.net/morewindows/article/details/6684558
	if (l < r)
	{

		int i = l, j = r;
		int x[3];
		x[0] = temp_priority[l][0];
		x[1] = temp_priority[l][1];
		x[2] = temp_priority[l][2];
		while (i < j)
		{
			while (i < j && temp_priority[j][0] < x[0])
				j--;
			if (i < j)
			{
				temp_priority[i][0] = temp_priority[j][0];
				temp_priority[i][1] = temp_priority[j][1];
				temp_priority[i][2] = temp_priority[j][2];

				//system("pause");
				i++;
			}


			while (i < j && temp_priority[i][0] >= x[0])
				i++;
			if (i < j)
			{
				temp_priority[j][0] = temp_priority[i][0];
				temp_priority[j][1] = temp_priority[i][1];
				temp_priority[j][2] = temp_priority[i][2];

				//system("pause");
				j--;
			}


		}
		temp_priority[i][0] = x[0];
		temp_priority[i][1] = x[1];
		temp_priority[i][2] = x[2];
		quick_sort(temp_priority, l, i - 1);
		quick_sort(temp_priority, i + 1, r);
	}
}

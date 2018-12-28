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
//extern bool show_me_the_array;//������
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
extern int  temp_point[2];
//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
extern rp RootBoard[15][15];
extern rp* be_searched_point;


int before_evaluation_ver6(int step_count)
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
					if (banned_point_sheet[my_raw][my_column])
						opponent_value = 0;
					else
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
					&& (!banned_point_sheet[my_raw][my_column]))
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
	for (index = 0; (current != NULL) && (index < Range); index++)//��temp��ǰʮ������긳ֵ�������prioriy_ver2
	{
		be_searched_point->LeafPoint[index][0] = current->raw;
		be_searched_point->LeafPoint[index][1] = current->column;
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

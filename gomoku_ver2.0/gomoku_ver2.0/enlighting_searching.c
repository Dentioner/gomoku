//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js

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
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
extern int  temp_point[2];
extern rp RootBoard[15][15];
extern rp* be_searched_point;

int before_evaluation_ver6(int step_count)
{
	int my_raw, my_column;
	long int *enemy_score_board;
	long int *my_score_board;
	long int my_value, opponent_value, temp_value;
	int status = 0;//0��ʾ��ǰ���������1��ʾ��ǰ��ַ����ҷ����壬�������Է�����
	int node_number = 0;//��¼�γɵ�����ڵ���
	int index;
	Node * head = NULL;
	Node * prev, *current, *post;
	Node * insert_node;
	if (step_count % 2)
	{
		enemy_score_board = &empty_score_total_black[0][0];
		my_score_board = &empty_score_total_white[0][0];
	}
	else
	{
		enemy_score_board = &empty_score_total_white[0][0];
		my_score_board = &empty_score_total_black[0][0];
	}
	for (my_raw = 0; my_raw < 15; my_raw++)
	{
		for (my_column = 0; my_column < 15; my_column++)
		{
			if (this_blank_is_useful(my_raw, my_column, step_count))
			{
				my_value = *(my_score_board + my_raw * 15 + my_column);
				opponent_value = *(enemy_score_board + my_raw * 15 + my_column);
				temp_value = my_value + opponent_value;
				if (temp_value != 0)
				{
					if (my_value >= Consecutive_Five)//�����ҷ����壬����
					{
						status = 1;
						return status;
					}
					else//�������¼������
					{
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
	current = head;
	for (index = 0; (current != NULL) && (index < MaxRange); index++)//��temp��ǰʮ������긳ֵ�������prioriy_ver2
	{
		be_searched_point->LeafPoint[index][0] = current->raw;
		be_searched_point->LeafPoint[index][1] = current->column;
		current = current->next;
	}

	while (head != NULL)//�ͷ��ڴ�
	{
		current = head;
		head    = current->next;
		free(current);
	}
	return status;
}

bool this_blank_is_useful(int raw, int column, int step_count)//��⵱ǰ�����Ƿ�Ϊ��Ч��λ
{
	if (step_count % 2)//����
		return (board[raw][column] != b) && (board[raw][column] != w);
	else
		return (board[raw][column] != b) && (board[raw][column] != w) && (!banned_point_sheet[raw][column]);
}
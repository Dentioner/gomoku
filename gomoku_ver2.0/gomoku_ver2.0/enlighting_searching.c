#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"
#include<stdlib.h>

extern int board[15][15];
extern int w;//白棋
extern int b;//黑棋
extern int coordinate[2];
//extern bool show_me_the_array;//测试用
extern bool ai_first;
extern long int empty_score_total_black[15][15];
extern long int empty_score_total_white[15][15];
extern bool banned_point_sheet[15][15];
extern int  temp_point[2];
//启发式搜索，按照优先级顺序，对分支进行排序，提高剪枝速度
//见https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
extern rp RootBoard[15][15];
extern rp* be_searched_point;


int before_evaluation_ver6(int step_count)
{
	int my_raw, my_column;
	long int my_value, opponent_value;
	long int temp_value;
	int status = 0;
	//0表示当前棋局正常
	//1表示当前棋局发现我方连五，不包括对方连五
	int node_number = 0;//记录形成的链表节点数
	int index;
	Node * head = NULL;
	Node * prev, *current, *post;
	Node * insert_node;
	

	if (step_count % 2)//说明是白棋方访问此函数
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
						if (my_value >= Consecutive_Five)//发现我方连五，返回
						{
							status = 1;
							return status;
						}

						else//否则继续录入数据
						{//这里写排序的算法

							insert_node = (Node *)malloc(sizeof(Node));
							insert_node->score = temp_value;
							insert_node->raw = my_raw;
							insert_node->column = my_column;
							insert_node->next = NULL;//这五行是制造一个待插入的节点



							index = 0;//index记录遍历节点的次数，即和节点比较了几次
							if (head == NULL)//初始化整个链表，此时一个节点都没有
							{
								head = insert_node;
								node_number++;
							}
							else
							{
								current = head;//首先将第一个节点当做当前节点
								prev = NULL;
								post = head->next;//紧随其后的节点就是head之后的那个节点
								//上面这三行是将待比较的链表初始化


								while (index < node_number && current != NULL)
								{//如果当前比较的次数比节点总数小，并且当前节点的指针不是空指针
									if (insert_node->score >= current->score)
									{//如果待插入的节点的分值比当前节点的分值高
										if (index == 0)//如果待插入的节点是最高分
										{
											insert_node->next = head;//将链表头的下一个地址指向当前表头
											head = insert_node;//链表头就改成待插入的节点
											node_number++;//节点数+1
											break;
										}
										else
										{
											insert_node->next = current;//将待插入节点的下一个地址指向当前节点
											prev->next = insert_node;//将前一个节点的下一个地址指向待插入节点
											node_number++;//节点数+1
											break;//跳出循环
										}
									}
									else
									{//如果待插入的节点的分值比当前节点的分值低
										prev = current;//当前节点的地址赋给前一个节点，即前移一位
										current = post;//后一个节点的地址赋给当前节点，即前移一位
										if (post != NULL)
											post = post->next;//后一个节点指向的后后一个节点的地址赋给后一个节点，即前移一位
										index++;//计数，看看比较了几个节点了
									}
								}
								if (index == node_number)//如果比较次数等于节点数，说明这个分数是最小的，应该放在链表最后
								{
									prev->next = insert_node;//将当前节点的最后地址指向待插入的节点
									node_number++;
								}
							}
						}
					}
				}
			}
		}
	}

	else//说明是黑棋方访问的此函数
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
						if (my_value >= Consecutive_Five)//发现我方连五，返回
						{
							status = 1;
							return status;
						}

						else//否则继续录入数据
						{//这里写排序的算法

							insert_node = (Node *)malloc(sizeof(Node));
							insert_node->score = temp_value;
							insert_node->raw = my_raw;
							insert_node->column = my_column;
							insert_node->next = NULL;//这五行是制造一个待插入的节点



							index = 0;//index记录遍历节点的次数，即和节点比较了几次
							if (head == NULL)//初始化整个链表，此时一个节点都没有
							{
								head = insert_node;
								node_number++;
							}
							else
							{
								current = head;//首先将第一个节点当做当前节点
								prev = NULL;
								post = head->next;//紧随其后的节点就是head之后的那个节点
								//上面这三行是将待比较的链表初始化

								while (index < node_number && current != NULL)
								{//如果当前比较的次数比节点总数小，并且当前节点的指针不是空指针
									if (insert_node->score >= current->score)
									{//如果待插入的节点的分值比当前节点的分值高
										if (index == 0)//如果待插入的节点是最高分
										{
											insert_node->next = head;//将链表头的下一个地址指向当前表头
											head = insert_node;//链表头就改成待插入的节点
											node_number++;//节点数+1
											break;
										}
										else
										{
											insert_node->next = current;//将待插入节点的下一个地址指向当前节点
											prev->next = insert_node;//将前一个节点的下一个地址指向待插入节点
											node_number++;//节点数+1
											break;//跳出循环
										}
									}
									else
									{//如果待插入的节点的分值比当前节点的分值低
										prev = current;//当前节点的地址赋给前一个节点，即前移一位
										current = post;//后一个节点的地址赋给当前节点，即前移一位
										if (post != NULL)
											post = post->next;//后一个节点指向的后后一个节点的地址赋给后一个节点，即前移一位
										index++;//计数，看看比较了几个节点了
									}
								}
								if (index == node_number)//如果比较次数等于节点数，说明这个分数是最小的，应该放在链表最后
								{
									prev->next = insert_node;//将当前节点的最后地址指向待插入的节点
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
	for (index = 0; (current != NULL) && (index < Range); index++)//将temp的前十大的坐标赋值给外面的prioriy_ver2
	{
		be_searched_point->LeafPoint[index][0] = current->raw;
		be_searched_point->LeafPoint[index][1] = current->column;
		current = current->next;
	}

	//释放内存

	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
	return status;
}


void quick_sort(long int temp_priority[][3], int l, int r)//对二维数组进行降序的快速排序
{//此函数参考https://blog.csdn.net/morewindows/article/details/6684558
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

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
extern unsigned long long ZobristTable[15][15][2];//梅森旋转的哈希键值表
extern unsigned long long hashValue;//梅森旋转算法下，棋盘的哈希值
//extern unsigned long long hashing_value2[depth_of_hashing][3];
//extern unsigned long long hashing_value3[depth_of_hashing][4];
extern HE hashing_value4[depth_of_hashing];

extern int times_of_finding_out_in_ZobTable;//test

long int Searching_Hashing(int step_count, bool my_turn, long temp_score, bool write, int floor)
{
	int black = 0;
	int white = 1;
	int chess;
	unsigned long long int location;
	if ((step_count % 2) == 0)
	{
		chess = black;
	}
	else
	{
		chess = white;
	}


	location = hashValue % depth_of_hashing;//生成一个特定的数组内的位置

	if (!write)//只读模式
	{
		
		if (hashing_value4[location].hash_value_of_board != 0)//如果这个哈希值不为0
		{
			/*
			if (hashing_value3[location][0] != hashValue && hashing_value3[location][0] != 0)
			//如果这个哈希值与外面的哈希值不等，说明取模运算将两个不同的哈希值转换成了相同的位置
			{
				printf("dismatch!\n");
			}	
			*/
			if (my_turn)
			{//目前[1]记录的是我方的得分
				if (hashing_value4[location].my_value != 0 && hashing_value4[location].floor >= floor)
				{
					times_of_finding_out_in_ZobTable++;
					return hashing_value4[location].my_value;
				}
			}
			else//[2]记录的是对方的得分
			{
				if (hashing_value4[location].opponent_value != 0 && hashing_value4[location].floor >= floor)
				{
					times_of_finding_out_in_ZobTable++;
					return hashing_value4[location].opponent_value;
				}

			}

			

		}

	

		return 0;

	}
	else//读写模式
	{
		/*
		if (hashing_value3[location][0] != hashValue && hashing_value3[location][0] != 0)
			//如果这个哈希值与外面的哈希值不等，说明取模运算将两个不同的哈希值转换成了相同的位置
		{
			printf("dismatch!\n");
		}
		*/
		if (my_turn)
		{
			if (temp_score != 0)//仅登记非0的得分
			{
				hashing_value4[location].hash_value_of_board = hashValue;
				hashing_value4[location].my_value = temp_score;
				hashing_value4[location].floor = floor;
			}
		}
		else
		{
			if (temp_score != 0)

			{
				hashing_value4[location].hash_value_of_board = hashValue;
				hashing_value4[location].opponent_value = temp_score;
				hashing_value4[location].floor = floor;
			}
		}


		return 0; //这个操作也只能执行一次，如果执行了，就必须跳出循环
		

		



	}


}
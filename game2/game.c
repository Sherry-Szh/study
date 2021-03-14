#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand()%row+1;//0-8 +1 -> 1-9
		int y = rand()%col+1;
		if (board[x][y] == '0')//用字符0能与初始化的值0有所区分
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//区间遍历是可行的，但这里用另一种方法：
	//把区间内的0和1都加起来，是几就有几个雷，但问题是存的是字符0和字符1
	//然而'1'-'0'=1  '3'-'0'=3  '0'-'0'=0
	//所以可以都减去'0'转换成数字之后再统计
	return mine[x - 1][y] + 
	mine[x-1][y-1] +
	mine[x][y-1] +
	mine[x+1][y-1] +
	mine[x+1][y] +
	mine[x+1][y+1] +
	mine[x][y+1] +
	mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了");
				DisplayBoard(mine, row, col);
				break;
			}
			else//2.不是雷
			{
				//计算x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//将数字转换成字符
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("输入坐标非法，请重新输入！\n");
	}
	if (win=row*col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, ROW, COL);
	}
}
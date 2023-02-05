#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<stdio.h>

#define H 3
#define L 3
#include"game.h"

int pj(char add[H][L], int h, int l)//三子棋
{
	int i = 0;
	int j = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; i < l; j++)
		{
			if (add[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char pd(char add[H][L], int h, int l)
{
	int i = 0;
	for (i = 0; i < h; i++)
	{
		if (add[i][0] == add[i][1] && add[i][1] == add[i][2] && add[i][1] != ' ')
		{
			return add[i][1];
		}
	}
	for (i = 0; i < l; i++)
	{
		if (add[0][i] == add[1][i] && add[1][i] == add[2][i] && add[1][i] != ' ')
		{
			return add[1][i];
		}
	}
	if (add[0][0] == add[1][1] && add[1][1] == add[2][2] && add[1][1] != ' ')
	{
		return add[1][1];
	}
	if (add[2][0] == add[1][1] && add[1][1] == add[0][2] && add[1][1] != ' ')
	{
		return add[1][1];
	}
	if (1 == pj(add, H, L))
	{
		return 'Q';
	}
	return 'C';
}
void dn(char add[H][L], int h, int l)
{
	int x = 0;
	int y = 0;
	printf("电脑回合\n");
	while (1)
	{
		x = rand() % h;
		y = rand() % l;
		if (add[x][y] == ' ')
		{
			add[x][y] = '#';
			break;
		}
	}
}
void wj(char add[H][L], int h, int l)
{
	int x = 0;
	int y = 0;
	printf("玩家回合:\n");
	while (1)
	{
		printf("请输入坐标:\n");
		scanf("%d%d", &x, &y);
		if (x >= 0 && x <= h && y >= 0 && y <= l)
		{
			if (add[x - 1][y - 1] == ' ')
			{
				add[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
		}
	}
}
void csh(char add[H][L], int h, int l)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			add[i][j] = ' ';
		}
	}
}
void dy(char add[H][L], int h, int l)
{
	int a = 0;
	for (a = 0; a < h; a++)
	{
		int b = 0;
		for (b = 0; b < l; b++)
		{
			printf(" %c ", add[a][b]);
			if (b < l - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (a < h - 1)
		{
			for (b = 0; b < l; b++)
			{
				printf("---");
				if (b < l - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void game()
{
	int ret = 0;
	char add[H][L] = { 0 };
	csh(add, H, L);
	dy(add, H, L);
	while (1)
	{
		wj(add, H, L);
		dy(add, H, L);
		ret=pd(add, H, L);
		if (ret != 'C')
		{
			break;
		}
		dn(add, H, L);
		dy(add, H, L);
		ret = pd(add, H, L);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利！\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利！\n");
	}
	else
	{
		printf("平局！\n");
	}
}
void b()
{
	printf("###########################\n");
	printf("##1.开始游戏   0.退出游戏##\n");
	printf("###########################\n");
}
void a()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do
	{
		b();
		printf("请选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("开始！\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (i);
}
int main()
{
	a();
	return 0;
}
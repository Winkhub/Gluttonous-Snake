#pragma warning(disable: 4996)
#include"UI.h"
#include"Game.h"
#include"Rank.h"
enum Color
{
	black, blue, green, lakeBlue, red, purple, yellow, white, gray, lightBlue, lightGreen, lightSimpleGreen, lightRed, lightPurple, lightYellow, brightWhite
};
void setColor(unsigned short textColor)
{
	char command[9] = "color 07";
	command[7] = '8' + textColor;
	system(command);
}
void MainMenu()
{
	system("cls");
	printf("--------------------------------------------------------------\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                       贪吃蛇小游戏1.2                      |\n");
	printf("|                                                            |\n");
	printf("|                                    ___                     |\n");
	printf("|          _________________________/O \\___/                 |\n");
	printf("|          <888888888888888888888888_____/ \\                 |\n");
	printf("|                                                            |\n");
	printf("|                       1、开始游戏                          |\n");
	printf("|                       2、排行榜                            |\n");
	printf("|                       3、操作介绍                          |\n");
	printf("|                       4、退出                              |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
}
void StartGame()
{
	system("cls");
	printf("\t\t\t\t贪吃蛇\n");
	printf("分数:000 速度:01\n");
	printf("______________________________________________________________\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                    按任意键开始游戏                        |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	_getch();
	Location(21, 11);
	printf("                          ");
	GamePlay();
}
void Ranking()
{
	int i = 0;
	Score aScore[N];
	memset(aScore, NULL, sizeof(Score) * N);
	system("cls");
	printf("\t\t\t排行榜\n");
	printf("--------------------------------------------------------------\n");
	printf("|名次  段位     玩家姓名\t\t            分数\t|\n");
	printf("|                                                            |\n");
	ReadScore(aScore);
	for (i = 0; i < N-9; i++)
	{
		printf("|%02d  最强王者   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null"):(aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 1; i < N - 7; i++)
	{
		printf("|%02d  至尊星耀   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 3; i < N - 4; i++)
	{
		printf("|%02d  永恒钻石   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 6; i < N; i++)
	{
		printf("|%02d  尊贵铂金   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
		if (i < N - 1)
		{
			printf("|                                                            |\n");
		}
	}
	printf("--------------------------------------------------------------\n");
	_getch();
}
void Introduce()
{
	system("cls");
	printf("\t\t\t操作介绍\n");
	printf("\t----------------\n");
	printf("\t按键操作说明\n");
	printf("\t1、按a或A向左移动\n");
	printf("\t2、按d或D向右移动\n");
	printf("\t3、按w或W向上移动\n");
	printf("\t4、按s或S向下移动\n");
	printf("\t----------------\n");
	printf("\t游戏注意事项\n");
	printf("\t1、没有设置通关分数\n");
	printf("\t2、最高分没有上限\n");
	printf("\t----------------\n");
	printf("\t排行榜说明\n");
	printf("\t1、游戏只收录了分数排行榜前十名\n");
	printf("\t2、只有当玩家分数最少高于第十名时才能进入榜单\n");
	printf("\t3、当有玩家进入排行榜前十名，最后一名自动掉出榜单\n");
	printf("\t----------------\n");
	printf("\t游戏结束说明\n");
	printf("\t1、贪吃蛇撞上四周的墙壁时，结束游戏\n");
	printf("\t2、贪吃蛇咬到自身时，结束游戏\n");
	printf("\n\n按任意键返回主菜单\n");
	_getch();
}
void SwitchCursor(BOOL bVisible)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = 1;
	cursor_info.bVisible = bVisible;
	SetConsoleCursorInfo(hOut, &cursor_info);
}
void Location(int iX, int iY)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = iX;
	pos.Y = iY;
	SetConsoleCursorPosition(hOut, pos);
}
void DrawSnake(Snake* pSnake)
{
	Body* pNode = pSnake->pHead;
	Location(pNode->iX * 2 + 1, pNode->iY + 3);
	printf("■");
	while (pNode->next != NULL)
	{
		pNode = pNode->next;
		Location(pNode->iX * 2 + 1, pNode->iY + 3);
		printf("□");
	}
}
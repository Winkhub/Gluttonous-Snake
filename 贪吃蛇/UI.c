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
	printf("|                       ̰����С��Ϸ1.2                      |\n");
	printf("|                                                            |\n");
	printf("|                                    ___                     |\n");
	printf("|          _________________________/O \\___/                 |\n");
	printf("|          <888888888888888888888888_____/ \\                 |\n");
	printf("|                                                            |\n");
	printf("|                       1����ʼ��Ϸ                          |\n");
	printf("|                       2�����а�                            |\n");
	printf("|                       3����������                          |\n");
	printf("|                       4���˳�                              |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("��������������������������������������������������������������\n");
}
void StartGame()
{
	system("cls");
	printf("\t\t\t\t̰����\n");
	printf("����:000 �ٶ�:01\n");
	printf("______________________________________________________________\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                                                            |\n");
	printf("|                    ���������ʼ��Ϸ                        |\n");
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
	printf("��������������������������������������������������������������\n");
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
	printf("\t\t\t���а�\n");
	printf("--------------------------------------------------------------\n");
	printf("|����  ��λ     �������\t\t            ����\t|\n");
	printf("|                                                            |\n");
	ReadScore(aScore);
	for (i = 0; i < N-9; i++)
	{
		printf("|%02d  ��ǿ����   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null"):(aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 1; i < N - 7; i++)
	{
		printf("|%02d  ������ҫ   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 3; i < N - 4; i++)
	{
		printf("|%02d  ������ʯ   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
		printf("|                                                            |\n");
	}
	for (i = 6; i < N; i++)
	{
		printf("|%02d  ��󲬽�   name:%-20s           score:%03d|\n", i + 1, strlen(aScore[i].aName) == 0 ? ("null") : (aScore[i].aName), aScore[i].iScore);
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
	printf("\t\t\t��������\n");
	printf("\t----------------\n");
	printf("\t��������˵��\n");
	printf("\t1����a��A�����ƶ�\n");
	printf("\t2����d��D�����ƶ�\n");
	printf("\t3����w��W�����ƶ�\n");
	printf("\t4����s��S�����ƶ�\n");
	printf("\t----------------\n");
	printf("\t��Ϸע������\n");
	printf("\t1��û������ͨ�ط���\n");
	printf("\t2����߷�û������\n");
	printf("\t----------------\n");
	printf("\t���а�˵��\n");
	printf("\t1����Ϸֻ��¼�˷������а�ǰʮ��\n");
	printf("\t2��ֻ�е���ҷ������ٸ��ڵ�ʮ��ʱ���ܽ����\n");
	printf("\t3��������ҽ������а�ǰʮ�������һ���Զ�������\n");
	printf("\t----------------\n");
	printf("\t��Ϸ����˵��\n");
	printf("\t1��̰����ײ�����ܵ�ǽ��ʱ��������Ϸ\n");
	printf("\t2��̰����ҧ������ʱ��������Ϸ\n");
	printf("\n\n��������������˵�\n");
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
	printf("��");
	while (pNode->next != NULL)
	{
		pNode = pNode->next;
		Location(pNode->iX * 2 + 1, pNode->iY + 3);
		printf("��");
	}
}
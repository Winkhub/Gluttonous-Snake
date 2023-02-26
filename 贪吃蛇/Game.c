#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"UI.h"
#include"Game.h"
#include"Rank.h"
void GamePlay()
{
	BOOL bRunning = TRUE;
	Snake* pSnake = (Snake*)malloc(sizeof(Snake));
	Food* pFood = (Food*)malloc(sizeof(Food));
	Score aScore[N];
	int iX, iY, i, j;
	int iScore = 0;
	int iSpeed = 200;
	memset(aScore, NULL, sizeof(Score) * N);
	InitSnake(pSnake);
	DrawSnake(pSnake);
	Sleep(iSpeed);
	MakeFood(pFood, pSnake);
	while (bRunning)
	{
		KeyPress(pSnake);
		Move(pSnake);
		iX = pSnake->pHead->iX;
		iY = pSnake->pHead->iY;
		if (iX < 0 || iY < 0 || iX > WIDTH - 1 || iY > HEIGHT - 1 || CheckBody(iX, iY, pSnake))
		{
			bRunning = FALSE;
			Location(22, 10);
			printf("ÓÎÏ·½áÊø");
		}
		else
		{
			if (iX == pFood->iX && iY == pFood->iY)
			{
				MakeFood(pFood, pSnake);
				Location(5, 1);
				printf("%03d", ++iScore);
				if (iScore % 10 == 0)
				{
					Location(14, 1);
					iSpeed -= 20;
					printf("%02d", (220 - iSpeed) / 20);
				}
			}
			else
			{
				RemoveNode(pSnake);
			}
			DrawSnake(pSnake);
		}
		Sleep(iSpeed);
	}
	EndGame(pSnake);
	_getch();
	ReadScore(aScore);
	for (i = 0; i < N; i++)
	{
		if (iScore > aScore[i].iScore)
		{
			for (j = N - 2; j >= i; j--)
			{
				strcpy(aScore[i + 1].aName, aScore[i].aName);
				aScore[i + 1].iScore = aScore[i].iScore;
			}
			system("cls");
			SwitchCursor(TRUE);
			printf("ÇëÊäÈëÄúµÄêÇ³Æ£º\n");
			gets(aScore[i].aName);
			aScore[i].iScore = iScore;
			SwitchCursor(FALSE);
			break;
		}
	}
	WriteScore(aScore);
}
void InitSnake(Snake* pSnake)
{
	int i;
	pSnake->eDir = RIGHT;
	pSnake->iLen = LEN;
	pSnake->pHead = NULL;
	for (i = 0; i < LEN; i++)
	{
		AddNode(i + 3, 3, pSnake);
	}
}
void AddNode(int iX, int iY, Snake* pSnake)
{
	Body* pNode = (Body*)malloc(sizeof(Body));
	pNode->iX=iX;
	pNode->iY=iY;
	pNode->next = pSnake->pHead;
	pSnake->pHead = pNode;
}
void EndGame(Snake* pSnake)
{
	Body* pNode;
	while (pSnake->pHead != NULL)
	{
		pNode = pSnake->pHead;
		pSnake->pHead = pSnake->pHead->next;
		free(pNode);
	}
	free(pSnake);
}
void Move(Snake* pSnake)
{
	int iX = pSnake->pHead->iX;
	int iY = pSnake->pHead->iY;
	switch (pSnake->eDir)
	{
		case UP   :AddNode(iX, iY - 1, pSnake); break;
		case DOWN :AddNode(iX, iY + 1, pSnake); break;
		case LEFT :AddNode(iX - 1, iY, pSnake); break;
		case RIGHT:AddNode(iX + 1, iY, pSnake); break;
	}
}
void RemoveNode(Snake* pSnake)
{
	Body* pNode = pSnake->pHead;
	Body* pTempNode = NULL;
	while (pNode->next != NULL)
	{
		pTempNode = pNode;
		pNode = pNode->next;
	}
	Location(pNode->iX * 2 + 1, pNode->iY + 3);
	printf("  ");
	pTempNode->next = NULL;
	free(pNode);
}
void KeyPress(Snake* pSnake)
{
	int iInput = 0;
	if (_kbhit())
	{
		iInput = _getch();
		switch (iInput)
		{
			case 'a':
			case 'A':if (pSnake->eDir != RIGHT) pSnake->eDir = LEFT; break;
			case 'd':
			case 'D':if (pSnake->eDir != LEFT) pSnake->eDir = RIGHT; break;
			case 'w':
			case 'W':if (pSnake->eDir != DOWN) pSnake->eDir = UP; break;
			case 's':
			case 'S':if (pSnake->eDir != UP) pSnake->eDir = DOWN; break;
			case ' ':system("pause>>null"); break;
		}
	}
}
void MakeFood(Food* pFood, Snake* pSnake)
{
	int iX = rand() % WIDTH;
	int iY = rand() % HEIGHT;
	while (CheckBody(iX, iY, pSnake))
	{
		iX = rand() % WIDTH;
		iY = rand() % HEIGHT;
	}
	pFood->iX = iX;
	pFood->iY = iY;
	Location(pFood->iX * 2 + 1, pFood->iY + 3);
	printf("¡õ");
}
BOOL CheckBody(int iX, int iY, Snake* pSnake)
{
	Body* pNode = pSnake->pHead->next;
	while (pNode != NULL)
	{
		if (pNode->iX == iX && pNode->iY == iY)
		{
			return TRUE;
		}
		pNode = pNode->next;
	}
	return FALSE;
}
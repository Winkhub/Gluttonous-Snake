#ifndef GAME_H
#define GAME_H
#include<stdio.h>
#define LEN 3
#define WIDTH 30
#define HEIGHT 20
typedef enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}eDIR;
typedef struct SNAKEBODY
{
	int iX;
	int iY;
	struct SNAKEBODY* next;
}Body;
typedef struct SNAKE
{
	int iLen;
	eDIR eDir;
	Body *pHead;
}Snake;
typedef struct FOOD
{
	int iX;
	int iY;
}Food;
void GamePlay();
void InitSnake(Snake* pSnake);
void AddNode(int iX, int iY, Snake* pSnake);
void EndGame(Snake* pSnake);
void Move(Snake* pSnake);
void RemoveNode(Snake* pSnake);
void KeyPress(Snake* pSnake);
void MakeFood(Food* pFood, Snake* pSnake);
BOOL CheckBody(int iX, int iY, Snake* pSnake);
#endif
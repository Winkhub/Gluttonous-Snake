#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Rank.h"
void ReadScore(Score* aScore)
{
	FILE* fp = fopen("score.dat", "rb");
	if (fp == NULL)
	{
		return;
	}
	if (fread(aScore, sizeof(Score), N, fp) == 0)
	{
		return;
	}
	fclose(fp);
	fp = NULL;
}
void WriteScore(Score* aScore)
{
	FILE* fp = fopen("score.dat", "wb");
	if (fp == NULL)
	{
		return;
	}
	if (fwrite(aScore, sizeof(Score), N, fp) == 0)
	{
		return;
	}
	fclose(fp);
	fp = NULL;
}
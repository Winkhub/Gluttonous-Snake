#define N 10
typedef struct SCORE
{
	char aName[20];
	int iScore;
}Score;
void ReadScore(Score* aScore);
void WriteScore(Score* aScore);
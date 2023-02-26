#include"UI.h"
int main()
{
	system("mode con cols=62 lines=25");
	setColor(1, 2);
	system("COLOR 17");
	int iKey = 0;
	do {
		SwitchCursor(0);
		MainMenu();
		iKey = _getch();
		switch (iKey)
		{
			case '1':StartGame(); break;
			case '2':Ranking(); break;
			case '3':Introduce(); break;
			default :iKey = 0; break;
		}
	} while (iKey);
	return 0;
}
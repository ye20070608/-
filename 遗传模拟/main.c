#include <stdio.h>
#include"mode.h"

int main() 
{
	int ch;
	while ((ch = get_choice()) != 'q') 
	{
		switch (ch)
		{
		case 'a':mode_1();
			break;
		default:
			break;
		}
		while (getchar() != '\n')
			continue;
	}
}




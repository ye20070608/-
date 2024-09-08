#include"mode.h"

char get_choice(void)
{
	int ch;
	while (1)
	{
		printf("请输入对应功能字母：\r\n");
		printf("a.固定基因型求F1    q.退出\r\n");
		ch = getchar();
		while ((ch < 'a' || ch>'a') && ch != 'q')
		{
			printf("请您输入正确字母呢\r\n");
			while (getchar() != '\n')
				continue;
			ch = getchar();
		}
		return ch;
	}
}
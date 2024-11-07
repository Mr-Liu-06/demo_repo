#include"AddressBook.h"

int main()
{
	int input;
	AddB con;
	IniAddB(&con);
	do
	{
		menu();
		printf("请输入对应选项:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddCon(&con);
			break;
		case DEL:
			DelCon(&con);
			break;
		case MOD:
			ModCon(&con);
			break;
		case FIND:
			FindCon(&con);
			break;
		case SORT:
			SortCon(&con);
			break;
		case SHOW:
			ShowCon(&con);
			break;
		case EXIT:
			printf("已退出通讯录:>");
			break;
		default:
			printf("输入错误，请重新输入:>\n");
		}
	} while (input);
	return 0;
}
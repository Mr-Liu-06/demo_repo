#include"AddressBook.h"

int main()
{
	int input;
	AddB con;
	IniAddB(&con);
	do
	{
		menu();
		printf("�������Ӧѡ��:>\n");
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
			printf("���˳�ͨѶ¼:>");
			break;
		default:
			printf("�����������������:>\n");
		}
	} while (input);
	return 0;
}
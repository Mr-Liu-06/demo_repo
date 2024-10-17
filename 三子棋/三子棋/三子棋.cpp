#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("****************************************\n");
	printf("*********        ������        *********\n");
	printf("*********      1.��ʼ��Ϸ      *********\n");
	printf("*********      0.�˳���Ϸ      *********\n");
	printf("****************************************\n");
}

void InitBoard(char arr[3][3])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr[i][j] = ' ';
		}
	}

}

void DisplayBoard(char arr[3][3])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
		if (i < 2)
		{
			printf("---|---|---\n");
		}
	}
}

char Is_win(char arr[3][3])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	if (arr[1][1] == arr[0][0] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (arr[1][1] == arr[0][2] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];

	int j = 0;
	int k = 0;
	int ret = 0;
	for (j = 0; j < 2; j++)
	{
		for (k = 0; k < 2; k++)
		{
			ret = (arr[j][k] == ' ') ? 1 : 0;
			if (ret == 1)
				return ' ';
		}
	}
	return '0';

}
void PlayerMove(char arr[3][3])
{
	printf("�����:>\n�������Ӧ����:>\n");
	int x=0;
	int y=0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 4 && y>0 && y < 4)
		{
			if (arr[x - 1][y - 1] != ' ')
				printf("�������ѱ�ռ��,����������:>\n");
			else
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("�����겻��������,����������:>\n");
	}
}

void ComputerMove(char arr[3][3])
{
	printf("�����:>\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

void game()
{
	char board[3][3];
	InitBoard(board);
	DisplayBoard(board);
	while (1)
	{
		if (Is_win(board) == '0')
		{
			printf("ƽ��,���ٴγ�����:>\n");
			break;
		}
		PlayerMove(board);
		DisplayBoard(board);
		if (Is_win(board) == '*')
		{
			printf("���ʤ:>\n");
			break;
		}
		ComputerMove(board);
		DisplayBoard(board);
		if (Is_win(board) == '#')
		{
			printf("����ʤ,�ٽ�����:>\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("��ѡ�� �������Ӧѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ:>\n");
			game();
			break;
		case 0:
			printf("��Ϸ����:>\n");
			break;
		default:
			printf("������� ����������:>\n");
			break;
		}
	} while (input);





	return 0;
}
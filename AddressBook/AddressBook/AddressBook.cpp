#include"AddressBook.h"

void menu()
{
	printf("**************************************\n");
	printf("******          ͨѶ¼          ******\n");
	printf("***   1.�����ϵ��  2.ɾ����ϵ��   ***\n");
	printf("***   3.������ϵ��  4.��ѯ��ϵ��   ***\n");
	printf("***   5.������ϵ��  6.�鿴ͨѶ¼   ***\n");
	printf("******       0.�˳�ͨѶ¼       ******\n");
	printf("**************************************\n");
}

void IniAddB(AddB* p)
{
	p->dt = (data*)malloc(DEFAULT_SZ * sizeof(data));
	if (p->dt == NULL)
	{
		perror("IniAddB");
		return;
	}
	for (int i = 0; i < p->tot_sz; i++)
	{
		(p->dt)[i] = { 0 };
	}
	p->mem_sz = 0;
	p->tot_sz = DEFAULT_SZ;
}
void AddCon(AddB* p)
{
	if (p->mem_sz == p->tot_sz)
	{
		data* ptr = (data*)realloc(p->dt, (p->tot_sz + INC_SZ) * sizeof(data));
		if (ptr == NULL)
		{
			perror("AddCon");
			printf("�����ϵ��ʧ��:<\n");
			return;
		}
		p->dt = ptr;
		ptr == NULL;
	}
	printf("�������������ϵ�˵�����:>");
	scanf("%s", p->dt[p->mem_sz].name);
	printf("�������������ϵ�˵��Ա�:>");
	scanf("%s", p->dt[p->mem_sz].sex);
	printf("�������������ϵ�˵�����:>");
	scanf("%d", &(p->dt[p->mem_sz].age));
	printf("�������������ϵ�˵ĵ绰:>");
	scanf("%s", p->dt[p->mem_sz].tele);
	printf("�������������ϵ�˵ĵ�ַ:>");
	scanf("%s", p->dt[p->mem_sz].addr);
	printf("��ӳɹ�:>\n");
	p->mem_sz++;
}

void ShowCon(const AddB* p)
{
	printf("%-15s\t%-10s\t%-10s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < p->mem_sz; i++)
	{
		printf("%-15s\t%-10s\t%-10d\t%-20s\t%-30s\n", p->dt[i].name, p->dt[i].sex, p->dt[i].age, p->dt[i].tele, p->dt[i].addr);
	}
}

int FindByNameTele(AddB* p)
{
	char a[TELE_MAX];
	printf("������ҪĿ���������绰:>\n");
	scanf("%s", a);
	for (int i = 0; i < p->mem_sz; i++)
	{
		if (strcmp(a, p->dt[i].name) * strcmp(a, p->dt[i].tele) == 0)
			return i;
	}
	return 0;
}

void FindCon(AddB* p)
{
	int ret = FindByNameTele(p);
	if (ret + 1)
	{
		printf("�ҵ�����ϵ��\n");
		printf("%-15s\t%-10s\t%-10s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-15s\t%-10s\t%-10d\t%-20s\t%-30s\n", p->dt[ret].name, p->dt[ret].sex, p->dt[ret].age, p->dt[ret].tele, p->dt[ret].addr);
	}
	else
		printf("δ�ҵ�����ϵ��:<\n");
}

void DelCon(AddB* p)
{
	if (p->mem_sz == 0)
	{
		printf("ͨѶ¼Ϊ�� �޷�ɾ��:<\n");
		return;
	}
	int ret = FindByNameTele(p);
	if (ret + 1)
	{
		for (int i = 0; i < p->mem_sz - ret - 1; i++)
		{
			p->dt[ret + i] = p->dt[ret + i + 1];
		}
		p->mem_sz--;
		printf("ɾ���ɹ�:>\n");
		return;
	}
	else
		printf("δ�ҵ�����ϵ��:<\n");
}

void ModCon(AddB* p)
{
	if (p->mem_sz == 0)
	{
		printf("ͨѶ¼Ϊ�� �޷��޸�:<\n");
		return;
	}
	int ret = FindByNameTele(p);
	printf("�������޸ĺ���ϵ�˵�����:>");
	scanf("%s", p->dt[ret].name);
	printf("�������޸ĺ���ϵ�˵��Ա�:>");
	scanf("%s", p->dt[ret].sex);
	printf("�������޸ĺ���ϵ�˵�����:>");
	scanf("%d", &(p->dt[ret].age));
	printf("�������޸ĺ���ϵ�˵ĵ绰:>");
	scanf("%s", p->dt[ret].tele);
	printf("�������޸ĺ���ϵ�˵ĵ�ַ:>");
	scanf("%s", p->dt[ret].addr);
	printf("�޸ĳɹ�:>\n");
}

int cmp(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
void SortCon(AddB* p)
{
	qsort(&(p->dt->name), p->mem_sz, sizeof(data), cmp);
	printf("������������ɹ�:>\n");
}
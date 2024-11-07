#include"AddressBook.h"

void menu()
{
	printf("**************************************\n");
	printf("******          通讯录          ******\n");
	printf("***   1.添加联系人  2.删除联系人   ***\n");
	printf("***   3.更改联系人  4.查询联系人   ***\n");
	printf("***   5.排序联系人  6.查看通讯录   ***\n");
	printf("******       0.退出通讯录       ******\n");
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
			printf("添加联系人失败:<\n");
			return;
		}
		p->dt = ptr;
		ptr == NULL;
	}
	printf("请输入所添加联系人的姓名:>");
	scanf("%s", p->dt[p->mem_sz].name);
	printf("请输入所添加联系人的性别:>");
	scanf("%s", p->dt[p->mem_sz].sex);
	printf("请输入所添加联系人的年龄:>");
	scanf("%d", &(p->dt[p->mem_sz].age));
	printf("请输入所添加联系人的电话:>");
	scanf("%s", p->dt[p->mem_sz].tele);
	printf("请输入所添加联系人的地址:>");
	scanf("%s", p->dt[p->mem_sz].addr);
	printf("添加成功:>\n");
	p->mem_sz++;
}

void ShowCon(const AddB* p)
{
	printf("%-15s\t%-10s\t%-10s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < p->mem_sz; i++)
	{
		printf("%-15s\t%-10s\t%-10d\t%-20s\t%-30s\n", p->dt[i].name, p->dt[i].sex, p->dt[i].age, p->dt[i].tele, p->dt[i].addr);
	}
}

int FindByNameTele(AddB* p)
{
	char a[TELE_MAX];
	printf("请输入要目标的姓名或电话:>\n");
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
		printf("找到了联系人\n");
		printf("%-15s\t%-10s\t%-10s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-15s\t%-10s\t%-10d\t%-20s\t%-30s\n", p->dt[ret].name, p->dt[ret].sex, p->dt[ret].age, p->dt[ret].tele, p->dt[ret].addr);
	}
	else
		printf("未找到该联系人:<\n");
}

void DelCon(AddB* p)
{
	if (p->mem_sz == 0)
	{
		printf("通讯录为空 无法删除:<\n");
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
		printf("删除成功:>\n");
		return;
	}
	else
		printf("未找到该联系人:<\n");
}

void ModCon(AddB* p)
{
	if (p->mem_sz == 0)
	{
		printf("通讯录为空 无法修改:<\n");
		return;
	}
	int ret = FindByNameTele(p);
	printf("请输入修改后联系人的姓名:>");
	scanf("%s", p->dt[ret].name);
	printf("请输入修改后联系人的性别:>");
	scanf("%s", p->dt[ret].sex);
	printf("请输入修改后联系人的年龄:>");
	scanf("%d", &(p->dt[ret].age));
	printf("请输入修改后联系人的电话:>");
	scanf("%s", p->dt[ret].tele);
	printf("请输入修改后联系人的地址:>");
	scanf("%s", p->dt[ret].addr);
	printf("修改成功:>\n");
}

int cmp(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
void SortCon(AddB* p)
{
	qsort(&(p->dt->name), p->mem_sz, sizeof(data), cmp);
	printf("按照名字排序成功:>\n");
}
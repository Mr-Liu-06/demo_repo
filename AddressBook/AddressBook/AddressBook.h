#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 10
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDR_MAX 20
#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct data
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}data;

typedef struct AddB
{
	data* dt;
	int mem_sz;
	int tot_sz;
}AddB;

enum
{
	EXIT,
	ADD,
	DEL,
	MOD,
	FIND,
	SORT,
	SHOW
};

void menu();

void IniAddB(AddB*);

void AddCon(AddB*);

void ShowCon(const AddB*);

int FindByNameTele(AddB*);

void FindCon(AddB*);

void DelCon(AddB*);

void ModCon(AddB*);

int cmp(const void*, const void*);

void SortCon(AddB*);
// stdafx.cpp : 只包括标准包含文件的源文件
// Insert algoritham.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
 vector<List_insert*>Sequence;
 vector<vector<int> >City_color;
 vector<int >City;
 vector<int >Sale;
 hash_map<int, int>hash_notes;
 vector<int>Cross_notes;
 vector<vector<double> >Distance;
 int Citynum;
 int Salesnum;
 vector<int >dopt;
 int local_num=0;
int rand_int(int min, int max)
{
	int a = max - min;
	int b = min + rand() % a;
	return b;
}
double rand_01()
{
	double s = rand();
	double x = s / (RAND_MAX + 1);
	return x;
}
double Get_fitness(List_insert*list)
{
	List_insert*l = list;
	double fitness = 0;
	while (list->next != NULL)
	{
		fitness = fitness + Distance[list->val][list->next->val];
		list = list->next;
	}
	fitness = fitness + Distance[list->val][l->val];
	return fitness;
}
double insert_note_fitness(List_insert*list, int index, int val,int color)
{
	List_insert*l = list;
	int number = 1;
	double fitness = 0;
	int flag = 0;
	while (list->next != NULL)
	{
		if (index == number)
		{
			fitness = fitness + Distance[list->val][val] + Distance[val][list->next->val];
			flag = 1;
		}
		else
		   fitness = fitness + Distance[list->val][list->next->val];
		number++;
		list = list->next;
	}
	if (flag == 0) 
		fitness = fitness + Distance[list->val][val] + Distance[val][l->val];
	else fitness = fitness + Distance[list->val][l->val];

	int i = 0; int num = City_color[val].size();
	while (i < num)
	{
		int val_out_color = City_color[val][i] - 1;
		if (val_out_color != color)
			fitness = fitness + Get_fitness(Sequence[val_out_color]);
		i++;
	}
	return fitness;
}
double insert_note_fit_sctsp(List_insert*list, int index, int val)
{
	List_insert*l = list;
	int number = 1;
	double fitness = 0;
	int flag = 0;
	while (list->next != NULL)
	{
		if (index == number)
		{
			fitness = fitness + Distance[list->val][val] + Distance[val][list->next->val];
			flag = 1;
		}
		else
			fitness = fitness + Distance[list->val][list->next->val];
		number++;
		list = list->next;
	}
	if (flag == 0)
		fitness = fitness + Distance[list->val][val] + Distance[val][l->val];
	else fitness = fitness + Distance[list->val][l->val];	
	return fitness;
}

List_insert* reverseBetween(List_insert* head, int m, int n) {
	List_insert* new_head = new List_insert(0);
	new_head->next = head;
	List_insert* pre = new_head;
	for (int i = 0; i < m - 1; i++)
		pre = pre->next;
	List_insert* cur = pre->next;
	for (int i = 0; i < n - m; i++) {
		List_insert* move = cur->next;
		cur->next = move->next;
		move->next = pre->next;
		pre->next = move;
	}
	return new_head->next;
}

void destroy_list(List_insert* list)
{
	while (list)
	{
		List_insert *p = list->next;
		free(list);
		list = p;
	}
}
// TODO:  在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用

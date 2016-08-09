
#include "stdafx.h"
int rand_int(int min, int max)
{
	int a = max - min + 1;
	int b = min + rand() % a;
	return b;
}
void Get_Sequence()
{
	vector<int >City;
	vector<int >Sale;
	vector<int >temp(Citynum,0);
	for (int i = 0; i < Citynum; i++)
	{
		int random_city = rand_int(0, Citynum);
		while (temp[random_city] == 1)
		{
			random_city = rand_int(1, Citynum);
		}
		temp[random_city] = 1;
		City.push_back(random_city);
	}
	for (int i = 0; i < Citynum; i++)
	{
		cout<<City[i]<<"   ";
	}

}

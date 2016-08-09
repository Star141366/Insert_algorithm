
#include"stdafx.h"


void Get_randomCity()
{
	
	vector<int >temp(Citynum + 1, 0);
	for (int i = 0; i < Citynum; i++)
	{
		int random_city = rand_int(0, Citynum);
		while (temp[random_city] == 1 )
		{
			random_city = rand_int(0, Citynum);
		}
		temp[random_city] = 1;
		City.push_back(random_city);
	}
	/*for (int i = 0; i < Citynum; i++)
	{
	cout << City[i] << "   ";
	}*/
}
void Get_Sequence()
{
	for (int i = 0; i < Citynum; i++)
	{
		//if(City_color[City[i]].size()==1)
		int k = 0;
		//cout << City[i] << " ";
		for (int j = 0; j < Salesnum; j++)
		{
			if (City[i] == dopt[j])
			{
				Sale.push_back(j + 1);
				k = 1;
				break;
			}
		}
		int aa = rand_int(0, City_color[City[i]].size());
		if (k == 0)
		{
			Sale.push_back(City_color[City[i]][aa]);
		}
		//cout << Sale[i] << endl;
		//int nnn = 0;
	}
	/*for (int i = 0; i < Citynum; i++)
	{
		cout << City[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < Citynum; i++)
	{
		cout << Sale[i] << "  ";
	}
	cout << endl;*/
	/*for (int i = 0; i < Citynum; i++)
	{
		for (int j = 0; j < City_color[i].size(); j++)
			cout << City_color[i][j] << "    ";
		cout << endl;
	}*/
	/*for (int i = 0; i <Salesnum; i++)
	{
		List_insert*p = new List_insert(0);
		Sequence[i]= p;
	}
	    vector<List_insert*>ivec(Salesnum);*/
	vector<int >sort_sequence;
	for (int i = 0; i < Salesnum; i++)
	{
		sort_sequence.push_back(dopt[i]);
		for (int j = 0; j < Citynum; j++)
		{
			if (Sale[j] == i + 1 && City[j] != dopt[i])
			{
				sort_sequence.push_back(City[j]);
			}
		}
	}
	
	/*for (int j = 0; j < Citynum; j++)
	{
		
			cout<<sort_sequence[j]<<" ";	
	}
	cout << endl;*/
	if(local_num==5)greedy_opt(sort_sequence);
	/*for (int j = 0; j < Citynum; j++)
	{

		cout << sort_sequence[j] << " ";
	}
	cout << endl;*/
	int num = 0;
	for (int i = 0; i < Salesnum; i++)
	{
		List_insert*list = new List_insert(dopt[i]);
		List_insert*q = list;
		num++;
		while (i == Salesnum - 1 || (i<Salesnum - 1 && sort_sequence[num] != dopt[i + 1]))
		{
			
			List_insert*p = new List_insert(sort_sequence[num]);
			q->next = p;
			q = p;
			num++;
			if (num == Citynum) break;
		}
		Sequence.push_back(list);
	}

	/*for (int i = 0; i < Salesnum; i++)
	{
		List_insert*list = new List_insert(dopt[i]);
		List_insert*q = list;
		for (int j = 0; j < Citynum; j++)
		{
			if (Sale[j] == i + 1&&City[j]!=dopt[i])
			{
				List_insert*p = new List_insert(City[j]);
				q->next = p;
				q = p;
			}
		}
		Sequence.push_back(list);
	}*/
	/*	for (int i = 0; i < Salesnum; i++)
		{
			while (Sequence[i]!= NULL)
			{
				cout << Sequence[i]->val << "   ";
				Sequence[i] = Sequence[i]->next;
			}
			cout << endl;
		}
		int aaa = 0;*/
}

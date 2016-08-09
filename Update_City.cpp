
#include"stdafx.h"

void update_city()
{
	vector<List_insert*>ivec(Sequence);
	/*for (int i = 0; i < Citynum; i++)
	{
		cout << City[i] << "   " << Sale[i] << endl;
	}
	for (int i = 0; i < Salesnum; i++)
	{
		while (Sequence[i] != NULL)
		{
			cout << Sequence[i]->val << "   ";
			Sequence[i] = Sequence[i]->next;
		}
		cout << endl;
	}*/
	int k = 0;
	for (int i = 0; i < Salesnum; i++)
	{
		if (i != 0) ivec[i] = ivec[i]->next;
		while (ivec[i] != NULL)
		{
			City[k] = ivec[i]->val;
			ivec[i] = ivec[i]->next;
			Sale[k] = i + 1;
			k++;
		}
	}
	/*for (int i = 0; i < Citynum; i++)
	{
		cout << City[i] << "   "<<Sale[i]<<endl;
	}
	int nn = 0;*/
}
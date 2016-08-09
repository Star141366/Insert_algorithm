

#include"stdafx.h"

void init_popsize(vector<pair<vector<List_insert*>, multimap<double, int>>>&mappopulation)
{
	
	for (int j = 0; j <20; j++)
	{
		Get_randomCity();
		Get_Sequence();
		//double fit_ness = INT_MIN;
		multimap<double, int>imap;
		for (int i = 0; i < Sequence.size(); i++)
		{
			double fit = Get_fitness(Sequence[i]);
			imap.insert(make_pair(fit, i));
		}
		mappopulation.push_back(make_pair(Sequence, imap));
		City.clear();
		Sale.clear();
		Sequence.clear();
		imap.clear();
	}
}
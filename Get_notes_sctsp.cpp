

#include"stdafx.h"
int Get_list_length(List_insert*list)
{
	int length = 0;
	while (list != NULL)
	{
		list = list->next;
		length++;
	}
	return length;
}
void Get_notes_sctsp(vector<pair<vector<List_insert*>, multimap<double, int>>>&mappopulation, vector<vector<int >>&Cross_node_pop)
{
	
	for (auto& it : mappopulation)
	{
		vector<int >iv;
		vector<List_insert*>ivec = it.first;
		multimap<double, int>imap = it.second;
		multimap<double, int>::reverse_iterator iter = imap.rbegin();
		//cout << iter->second << endl;
		List_insert*list = ivec[iter->second];
		double prob = 0.3;
		int len = Get_list_length(list);
		vector<int >temp(len+1, 0);
		for (int j = 0; j < len*prob; j++)
		{
			int a = rand_int(1, len);
			if (temp[a] == 0)
			{
				iv.push_back(a);
				temp[a] = 1;
			}
			else j--;
		}
		sort(iv.begin(), iv.end());
		vector<int >res;
		int n = 0; int k = 0;
		while (list != NULL)
		{
			if (n == iv[k])
			{
				res.push_back(list->val);
				k++;
				if (k == iv.size())
					break;
			}
			list = list->next;
			n++;
		}
		Cross_node_pop.push_back(res);
		iv.clear();
		temp.clear();
		res.clear();
	}
}
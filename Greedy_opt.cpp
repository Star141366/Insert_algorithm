

#include"stdafx.h"
void greedy_opt(vector<int>&g_opt)
{
	vector<int> ivec(g_opt);
	dopt.push_back(-1);
	ivec.push_back(10000);//判断用于最后一个商人结束的标志
	vector<int>::iterator iter = ivec.begin();
	int precity = *iter;
	double mindistance = 10000000;
	int nextcity = 0;
	int j = 0;
	vector<int> ioptimizationsequence;//存储优化后的数据
	ioptimizationsequence.push_back(*iter);
	if (iter != ivec.end())
	{
		iter = ivec.erase(iter);//删除第一个城市0，其值保存在precity中
	}
	for (iter; iter != ivec.end();)
	{
		if ((*iter) != dopt[j + 1] && (*iter) != 10000)//等于说明已经到了下一个商人&& (*iter) != depot[2]
		{
			if (Distance[precity][*iter] < mindistance)//求取此时起点城市到该商人所有城市的距离最小值
			{
				mindistance = Distance[precity][*iter];
				nextcity = *iter;
			}
			++iter;

		}
		else
		{
			ioptimizationsequence.push_back(nextcity);
			//把此时的城市放进优化序列中
			vector<int>::iterator itertemp = find(ivec.begin(), ivec.end(), nextcity);//在原来的序列中删除这个城市
			if (itertemp != ivec.end())
			{
				ivec.erase(itertemp);
			}
			precity = nextcity;
			mindistance = 10000000;//下次比较，将mindistance设为一个大数
			iter = ivec.begin();
			if (*iter == dopt[j + 1] || (*iter) == 10000)//说明已经到了下一个旅行商|| (*iter) == depot[2]
			{
				//ioptimizationsequence.push_back(dopt[j]);
				if ((*iter) != 10000)
				{
					ioptimizationsequence.push_back(*iter);
				}
				precity = *iter;
				iter = ivec.erase(iter);
				nextcity = 0;
				if (ivec.empty())
				{
					break;//优化结束

				}
				++j;
			}
		}

	}
	g_opt = ioptimizationsequence;
	ioptimizationsequence.clear();
	ivec.clear();
	
}
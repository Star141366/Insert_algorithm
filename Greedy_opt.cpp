

#include"stdafx.h"
void greedy_opt(vector<int>&g_opt)
{
	vector<int> ivec(g_opt);
	dopt.push_back(-1);
	ivec.push_back(10000);//�ж��������һ�����˽����ı�־
	vector<int>::iterator iter = ivec.begin();
	int precity = *iter;
	double mindistance = 10000000;
	int nextcity = 0;
	int j = 0;
	vector<int> ioptimizationsequence;//�洢�Ż��������
	ioptimizationsequence.push_back(*iter);
	if (iter != ivec.end())
	{
		iter = ivec.erase(iter);//ɾ����һ������0����ֵ������precity��
	}
	for (iter; iter != ivec.end();)
	{
		if ((*iter) != dopt[j + 1] && (*iter) != 10000)//����˵���Ѿ�������һ������&& (*iter) != depot[2]
		{
			if (Distance[precity][*iter] < mindistance)//��ȡ��ʱ�����е����������г��еľ�����Сֵ
			{
				mindistance = Distance[precity][*iter];
				nextcity = *iter;
			}
			++iter;

		}
		else
		{
			ioptimizationsequence.push_back(nextcity);
			//�Ѵ�ʱ�ĳ��зŽ��Ż�������
			vector<int>::iterator itertemp = find(ivec.begin(), ivec.end(), nextcity);//��ԭ����������ɾ���������
			if (itertemp != ivec.end())
			{
				ivec.erase(itertemp);
			}
			precity = nextcity;
			mindistance = 10000000;//�´αȽϣ���mindistance��Ϊһ������
			iter = ivec.begin();
			if (*iter == dopt[j + 1] || (*iter) == 10000)//˵���Ѿ�������һ��������|| (*iter) == depot[2]
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
					break;//�Ż�����

				}
				++j;
			}
		}

	}
	g_opt = ioptimizationsequence;
	ioptimizationsequence.clear();
	ivec.clear();
	
}
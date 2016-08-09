
#include"stdafx.h"
#include<fstream>
#include<string>
void  ReadCitiesDistance()
{
	vector<vector<double> >distance(Citynum, vector<double>(Citynum, 0));
	int* bianhao = new int[Citynum];
	double* cityzuobiaox = new double[Citynum];
	double* cityzuobiaoy = new double[Citynum];
	ifstream IniMatrixCitiesDistance;
	IniMatrixCitiesDistance.open("C:\\Users\\dell\\Desktop\\城市分配\\" + to_string(Citynum) + ".txt");
	while (!IniMatrixCitiesDistance.eof())
	{
		for (int i = 0; i<Citynum; i++)
		{
			//IniMatrixCitiesDistance >> bianhao[i];
			IniMatrixCitiesDistance >> cityzuobiaox[i];
			IniMatrixCitiesDistance >> cityzuobiaoy[i];
		}
	}

	for (int i = 0; i<Citynum; i++)
	{
		for (int j = 0; j<Citynum; j++)
		{
			distance[i][j] = sqrt(pow((double)(cityzuobiaox[i] - cityzuobiaox[j]), 2) + pow((double)(cityzuobiaoy[i] - cityzuobiaoy[j]), 2));
		}
	}
	Distance = distance;
	//for (int i = 0; i<Citynum; i++)
	//{
	//	for (int j = 0; j<Citynum; j++)
	//	{
	//		cout << Distance[i][j] << "  ";// = sqrt(pow((double)(cityzuobiaox[i] - cityzuobiaox[j]), 2) + pow((double)(cityzuobiaoy[i] - cityzuobiaoy[j]), 2));
	//	}
	//	cout << endl;
	//}
	//cout << "城市坐标及距离录入成功!" << endl;
	delete[]bianhao;
	delete[]cityzuobiaox;
	delete[]cityzuobiaoy;

}
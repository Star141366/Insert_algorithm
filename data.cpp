

#include"stdafx.h"
#include<fstream>
#include<string>
void data_input_sctsp()
{
	ifstream file_read("C:\\Users\\dell\\Desktop\\���з���_MIN_MAX\\prama.txt");
	//while (!file_read.eof())
	//{
		cout << "������Ŀ��   ";
		file_read >> Salesnum;
		cout << "������Ŀ��   ";
		file_read >> Citynum;
		cout << endl;
		vector<int >Private(Salesnum);
		vector<int >Share(Salesnum - 1);
		//vector<vector<int >>temp_color(Sales_num + 1, vector<int >(City_num, 0));

		ofstream file_name("C:\\Users\\dell\\Desktop\\���з���_MIN_MAX\\" + to_string(Citynum) + "_" + to_string(Salesnum) + ".txt");
		//ofstream file_dopt("C:\\Users\\dell\\Desktop\\���з���_MIN_MAX\\" + to_string(City_num) + "_" + to_string(Sales_num) + "_dopt.txt");
		//ofstream file_name("aa.txt");
		int sumcities = 0;
		vector<int >color_index;
		for (int i = 0; i < Salesnum; i++)
		{
			cout << "�������" << i + 1 << "�������̵�ר�����м��ĳ�����Ŀ�� ";
			file_read >> Private[i];
			sumcities += Private[i];
			color_index.push_back(sumcities);
			if (i < Salesnum - 1)
			{
				cout << "�������" << i + 1 << "��" << i + 2 << "�������̵Ĺ�����м��ĳ�����Ŀ�� ";
				file_read >> Share[i];
				sumcities += Share[i];
				color_index.push_back(sumcities);
			}
		}
		if (sumcities != Citynum)
		{
			cout << "��������ĸ�������ר����е���Ŀ��������ר����м�������Ŀ��ͬ,���������" << endl;
			return;
		}
		for (int i = 0; i < Salesnum; i++)
		{
			int a;
			file_read >> a;
			dopt.push_back(a - 1);
		}
		vector<vector<int >>temp_color;
		int sales_index = 0;
		for (int i = 0; i < Citynum; i++)
		{
			vector<int >iv;
			if (i < color_index[sales_index])
			{
				if (sales_index % 2 == 0) iv.push_back(sales_index / 2 + 1);
				else {
					iv.push_back((sales_index + 1) / 2);
					iv.push_back((sales_index + 1) / 2 + 1);
				}
				temp_color.push_back(iv);
				iv.clear();
			}
			else {
				sales_index++;
				if (sales_index == color_index.size())
					break;
				i--;
			}

		}
		City_color = temp_color;
		//temp_color.clear();
		for (int i = 0; i < Citynum; i++)
		{
			for (int j = 0; j < temp_color[i].size(); j++)
				file_name << temp_color[i][j] << " ";
			file_name << endl;
		}
		int aaaa = 0;
	
}

void data_input_sctsp_1()
{
	int City_num, Sales_num;
	cout << "������Ŀ��   " ;
	std::cin >> City_num;
	cout << "������Ŀ��   " ;
	cin >> Sales_num;
	cout << endl;
	vector<int >Private(Sales_num);
	vector<int >Share(Sales_num-1);
	//vector<vector<int >>temp_color(Sales_num + 1, vector<int >(City_num, 0));
	ofstream file_name("C:\\Users\\dell\\Desktop\\���з���_MIN_MAX\\" + to_string(City_num) + "_" + to_string(Sales_num) + ".txt");
	//ofstream file_name("aa.txt");
	int sumcities = 0;
	vector<int >color_index;
	for (int i = 0; i<Sales_num; i++)
	{
		cout << "�������" << i + 1 << "�������̵�ר�����м��ĳ�����Ŀ�� ";
		cin >> Private[i];
		sumcities += Private[i];
		color_index.push_back(sumcities);
		if (i < Sales_num - 1)
		{
			cout << "�������" << i + 1 << "��" << i + 2 << "�������̵Ĺ�����м��ĳ�����Ŀ�� ";
			cin >> Share[i];
			sumcities += Share[i];
			color_index.push_back(sumcities);
		}
	}
	if (sumcities != City_num)
	{
		cout << "��������ĸ�������ר����е���Ŀ��������ר����м�������Ŀ��ͬ,���������" << endl;
		return ;
	}
	vector<vector<int >>temp_color;
	int sales_index = 0;
	for (int i = 0; i < City_num; i++)
	{
		vector<int >iv;
		if (i < color_index[sales_index])
		{
			if (sales_index % 2 == 0) iv.push_back(sales_index/2+1);
			else {
				iv.push_back((sales_index+1) / 2);
				iv.push_back((sales_index + 1) / 2 + 1);
			}
			temp_color.push_back(iv);
			iv.clear();
		}
		else {
             sales_index++; 
			 if (sales_index==color_index.size())
			      break; 
			 i--;
		}

	}
	for (int i = 0; i < City_num; i++)
	{
		for (int j = 0; j < temp_color[i].size(); j++)
			file_name << temp_color[i][j] << " ";
		file_name << endl;
	}
	int aaaa = 0;
}





void data_input()
{
	
	int City_num, Sales_num;
	cout << "������Ŀ��" << endl;
	std::cin >> City_num;
	cout << "������Ŀ��" << endl;
	cin >> Sales_num;
	vector<int >data_number(Sales_num);
	int city_sum = 0;
	vector<vector<int >>temp_color(Sales_num + 1, vector<int >(City_num,0));
	ofstream file_name("C:\\Users\\dell\\Desktop\\���з���\\" + to_string(City_num) + "_" + to_string(Sales_num)+".txt");
	for (int i = 0; i < Sales_num; i++)
	{
		cout << "����" << i + 1 << "��ר����Ŀ��" << endl;
		cin >> data_number[i];
		city_sum = city_sum + data_number[i];
	}
	data_number.push_back(City_num - city_sum-1);
	vector<vector<int >>temp_color_1(City_num);
	int m = 0;
	for (int i = 0; i < City_num; )
	{
		while (data_number[m]>0)
		{
			if (i == 0||m==data_number.size()-1){
				for (int j = 0; j < Sales_num; j++)
					temp_color_1[i].push_back(j + 1);
				if (i != 0) data_number[m]--;
			}
			else {
				temp_color_1[i].push_back(m + 1);
				data_number[m]--;
			}
			i++;
		}
		m++;
	}
	for (int i = 0; i < City_num;i++)
	{
		for (int j = 0; j < temp_color_1[i].size();j++)
		  cout << temp_color_1[i][j] << " ";
		cout << endl;
	}

	//int k = 1;
	//for (int i = 0; i < Sales_num+1; i++)
	//{
	//	if (i == 0) temp_color[i][0] = Sales_num;
	//	else temp_color[i][0] = 1;
	//}
	//for (int i = 0; i < Sales_num; i++)
	//{
	//	while (data_number[i]>0)
	//	{
	//		temp_color[0][k] = 1;
	//		temp_color[i + 1][k] = 1;
	//		data_number[i]--;
	//		k++;
	//	}
	//}
	//while (k < City_num)
	//{
	//	for (int i = 0; i < Sales_num+1; i++)
	//	{
	//		if (i == 0)temp_color[i][k] = Sales_num;
	//		else temp_color[i][k] = 1;
	//	}
	//	k++;
	//}
	for (int i = 0; i < Sales_num + 1; i++)
	{
		for (int j = 0; j < City_num; j++)
		{
			file_name << temp_color[i][j] << " ";
			cout << temp_color[i][j] << " ";
		}
		file_name << endl;
		cout << endl;
	}
	/*ifstream file_data("C:\\Users\\dell\\Desktop\\���з���\\" + to_string(City_num) + "--" + to_string(Sales_num) + ".txt");
	ofstream file_d("C:\\Users\\dell\\Desktop\\���з���\\" + to_string(City_num) + " " + to_string(Sales_num) + ".txt");
	int colod;
	while (!file_data.eof())
	{
		for (int i = 0; i < Sales_num + 1; i++)
		{
			for (int j = 0; j < City_num; j++)
			{
				file_data >> colod;
				cout << colod << " ";
				file_d << colod << " ";
			}
			file_d << endl;
			cout << endl;
		}
	}*/

}
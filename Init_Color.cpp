
#include"stdafx.h"
#include<fstream>
#include<string>
//void Init_Color_sctsp()
//{
//	ifstream file_read("C:\\Users\\dell\\Desktop\\城市分配_MIN_MAX\\prama.txt");
//	while (!file_read.eof()){
//		file_read >> Salesnum;
//		file_read >> Citynum;
//		ifstream file_name("C:\\Users\\dell\\Desktop\\城市分配_MIN_MAX\\" + to_string(Citynum) + "_" + to_string(Salesnum) + ".txt");
//		ifstream file_dopt("C:\\Users\\dell\\Desktop\\城市分配_MIN_MAX\\" + to_string(Citynum) + "_" + to_string(Salesnum) + "_dopt.txt");
//		while (!file_name.eof())
//		{
//			vector<int >temp;
//
//
//		}
//	}
//}
void Init_Color()
{
	for (int i = 0; i < Citynum; i++)
	{
		vector<int >temp;
		/*int random_a = rand_int(1, 4);
		int random_b = rand_int(1, 4);
		if (random_a >= random_b)
			temp.push_back(random_a);
		else
		{
			temp.push_back(random_a);
			temp.push_back(random_b);
		}*/
		if (i <20) {
			temp.push_back(1); //temp.push_back(3);
		}
		else if (i < 40){
			temp.push_back(1); temp.push_back(2);
		}
		else {
			if (i <61){ temp.push_back(2); }
			else if (i < 81){
				temp.push_back(2); temp.push_back(3);	
			}
			else  temp.push_back(3);	
		}
		
		
		//else temp.push_back(3);
		City_color.push_back(temp);
		temp.clear();
	}/*int k = 0;
	for (int i = 0; i < Citynum; i++,k++)
	{
		
		for (int j = 0; j < City_color[i].size(); j++)
			cout << City_color[i][j] << "    ";
		cout << k <<endl;
	}
	int m = 0;*/
}
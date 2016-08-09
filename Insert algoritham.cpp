// Insert algoritham.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"标头.h"
#include<string>
#include<fstream>

void insert_note(List_insert*list, int n,int val)
{
	List_insert*node = new List_insert(val);
	while (n>1)
	{
		list = list->next;
		n--;
	}
	List_insert*q = list->next;
	node->next = q;
	list->next = node;
}
int list_length(List_insert*list)
{
	int length = 0;
	while (list != NULL)
	{
		list = list->next;
		length++;
	}
	return length;
}
void delete_note(List_insert*list, int note)
{
	List_insert *pre=(List_insert*)malloc(sizeof(List_insert*));
	while (list != NULL)
	{
		if (list->val ==note)
		{
			if (list->next == NULL)
			{
				pre->next = NULL;
				list = NULL;
			}
			else {
				list->val = list->next->val;
				list->next = list->next->next;
			}
			break;
		}
		pre = list;
		list = list->next;
	}
}
void insert_algoritham()
{
	double best_fit; vector<List_insert*>ivec; 
	for (int i = 0; i < Notenum; i++)
	{
		int note_index = hash_notes[Cross_notes[i]];
		vector<int >note_color = City_color[Cross_notes[i]];
		//vector<List_insert* >list;
		List_insert*temp = Sequence[note_index - 1];
		delete_note(temp, Cross_notes[i]);
		double best_fitness = INT_MAX;
		int location = 0;
		int sales_index = 0; //int getbest_flag = 0;
		for (int j = 0; j < note_color.size();j++)
		{
			    List_insert*list_cross = Sequence[note_color[j]-1];				
				int length = list_length(list_cross);
				//cout <<"changdu" <<length << endl;
				for (int cross_index = 1; cross_index <= length; cross_index++)
				 {
					double note_fitness = insert_note_fitness(list_cross, cross_index, Cross_notes[i], note_color[j] - 1);
					//cout << note_fitness << endl;
					if (note_fitness <= best_fitness)
					{
						best_fitness = note_fitness;
						//cout << "jdlfjdkjkl" << best_fitness << endl;
						location = cross_index;
						sales_index = note_color[j] - 1;
						//getbest_flag = 1;
						best_fit = best_fitness;
					}

				 }
		}
		//cout << best_fit << endl;
		insert_note(Sequence[sales_index], location, Cross_notes[i]);
		//ivec = Sequence; 
		/*double fit_ness = 0;
		for (int i = 0; i < Salesnum; i++)
		{
			fit_ness = fit_ness + Get_fitness(Sequence[i]);
		}
		cout << fit_ness << endl;
		for (int i = 0; i < Salesnum; i++)
		{
			while (ivec[i] != NULL)
			{
				cout << ivec[i]->val << "   ";
				ivec[i] = ivec[i]->next;
			}
			cout << endl;
		}*/
	}
	/*cout << best_fit << endl;
	for (int i = 0; i < Salesnum; i++)
	{
	      while (ivec[i] != NULL)
	     {
	       cout << ivec[i]->val << "   ";
	       ivec[i] = ivec[i]->next;
	     }
	cout << endl;
	}*/
	int nnn = 0;
}
void insert_result(List_insert* list, vector<int >&Cross_note)
{

	for (int cross_d = 0; cross_d < Cross_note.size(); cross_d++)
	{
		List_insert*temp = list;
		delete_note(temp, Cross_note[cross_d]);
		double best_fitness = INT_MAX;
		int location = 0;
		int sales_index = 0;
		int length = list_length(temp);
		for (int cross_index = 1; cross_index <= length; cross_index++)
		{
			double note_fitness = insert_note_fit_sctsp(list, cross_index, Cross_note[cross_d]);
			//cout << note_fitness << endl;
			if (note_fitness <= best_fitness)
			{
				best_fitness = note_fitness;
				location = cross_index;
			}
		}
		insert_note(list, location, Cross_note[cross_d]);
	}
		//cout << best_fit << endl;
		
		
	
}
void opt_2(List_insert* list)
{
	List_insert* head =list;
	int len = list_length(head);
	for (int i = 0; i < 50; i++)
	{
		int aa_1 = rand_int(2, len);
		int bb_1 = rand_int(2, len);
		while (aa_1 == bb_1)
		{
			bb_1 = rand_int(3, len);
		}
		int m = min(aa_1, bb_1);
		int n = max(aa_1, bb_1);
		double pre_rever = Get_fitness(head);
		List_insert* head_2 = reverseBetween(head, m, n);
		double next_rever = Get_fitness(head_2);
		if (next_rever > pre_rever)
		{
			reverseBetween(head, m, n);
		}
	}

}
List_insert* SA_algoritham_SCTSP(List_insert* list,ofstream &file_name)
{
	int length = list_length(list); 
	double prefit = Get_fitness(list);
	double best_fit = prefit;
	List_insert*best_list = Copy_List(list);
	//file_name << best_fit ;
	double tep = 100;
	for (int i = 0; i < iSANum; i++)
	{ 
		int diedai = 0;
		while (diedai < SAdiedai)
		{
			operator_num--;
			//file_name <<"   " <<operator_num << endl;
			int aa = rand_int(1, length - 1);
			int bb = rand_int(1, length - 1);
			while (aa == bb)
			{
				bb = rand_int(1, length - 1);
			}
			int pa = min(aa, bb);
			int pb = max(aa, bb);
			Swap_list(list, pa, pb);
			double nextfit = Get_fitness(list);
			if (nextfit<best_fit)
			{
				destroy_list(best_list);
				best_list = Copy_List(list);
				best_fit = nextfit;
			}
			if (nextfit > prefit)
			{
				double randnum = rand_01(); 
				//cout << randnum << "         " << exp((prefit - nextfit) / tep)<<endl;
				if (exp((prefit - nextfit) / tep) > randnum)
				{
					prefit = nextfit;
				}
				else Swap_list(list, pa, pb);
			}
			else{
				prefit = nextfit;
			}
			diedai++;
			//file_name << best_fit << endl;;
		}
		tep = tep*0.9;
	}
	destroy_list(list);
	return best_list;
}
void climb_algoritham_SCTSP(List_insert* list)
{
	int length = list_length(list);
	double prefit = Get_fitness(list);
	for (int i = 0; i < iClimbNum; i++)
	{		
		int aa = rand_int(1, length - 1);
		int bb = rand_int(1, length - 1);
		while (aa == bb)
		{
			bb = rand_int(1, length - 1);
		}
		int pa = min(aa, bb);
		int pb = max(aa, bb);
		Swap_list(list, pa, pb);
		/*List_insert *temp = list;
		List_insert *t = list;
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
		t=reverseList(t);
		while (t != NULL)
		{
			cout << t->val << " ";
			t = t->next;
		}
		cout << endl;
		destroy_list(t);*/
		double nextfit = Get_fitness(list);
		if (nextfit > prefit)
		{
			Swap_list(list, pa, pb);
		}
		else{
			prefit = nextfit;
		}
	}
}
void insert_algoritham_SCTSP(vector<pair<vector<List_insert*>, multimap<double, int>>>&mappopulation, vector<vector<int >>&Cross_node_pop, string&Filename)
{
	int k = 0; vector<pair<vector<List_insert*>, multimap<double, int>>>maptemp;
	int num = 1;
	for (auto& it : mappopulation)
	{
		string s = Filename + "\\" + to_string(num) + ".txt";
		ofstream file_name(s);
		vector<List_insert*>ivec = it.first;
		multimap<double, int>imap = it.second;
		multimap<double, int>::reverse_iterator iter = imap.rbegin();
		List_insert*list = ivec[iter->second];
		int index = iter->second;
		imap.erase(iter->first);
		vector<int >Cross_note = Cross_node_pop[k++];
		
		opt_2(list);
		if (local_num == 2) insert_result(list, Cross_note);
		if (local_num == 3) climb_algoritham_SCTSP(list);
		if (local_num == 4) list = SA_algoritham_SCTSP(list, file_name);;

		//insert_result(list, Cross_note,file_name);
		//opt_2(list,file_name);
		//climb_algoritham_SCTSP(list,file_name);
		//list = SA_algoritham_SCTSP(list, file_name);
		ivec[index] = list;
		double fit = Get_fitness(list);
		imap.insert(make_pair(fit, index));
		maptemp.push_back(make_pair(ivec, imap));
		num++;
	}
	mappopulation.clear();
	mappopulation = maptemp;
}

int main()
{
	    data_input_sctsp();
		ReadCitiesDistance();
		vector<pair<vector<List_insert*>, multimap<double, int>>>mappopulation;

		srand(GetTickCount());
		string local_algorithm = "";
		int Is_local = 0;
		cout << "是不是需要选择局部搜索算法，是的话输入1，否则输入0：" << endl;
		cin >> Is_local;
		if (Is_local)
		{

			cout << "选择需要的局部搜索算法:2-0pt--1    ";
			cout << "插入搜索算法----2    爬山算法----3    模拟退火算法----4   贪婪初始化----5：" << endl;
			cout << "请输入算法编号：";
			cin >> local_num;
			if (local_num == 1) local_algorithm = " 2-0pt";
			if (local_num == 2) local_algorithm = " 插入搜索算法";
			if (local_num == 3) local_algorithm = " 爬山算法";
			if (local_num == 4) local_algorithm = " 模拟退火算法";
			if (local_num == 5) local_algorithm = " 贪婪初始化";

		}
		string Flname = "C:\\Users\\dell\\Desktop\\城市分配_MIN_MAX\\萤火虫-result\\" + to_string(Citynum) + "-" + to_string(Salesnum) + "\\数据每次结果\\";
		MakeSureDirectoryPathExists(Flname.c_str());
		ofstream result_file(Flname + to_string(Citynum) + "-" + to_string(Salesnum) + local_algorithm + ".txt");

		init_popsize(mappopulation);
		
		double t1 = GetTickCount();
		string Filename = "C:\\Users\\dell\\Desktop\\城市分配\\" + to_string(Citynum) + "-" + to_string(Salesnum) + "\\数据每次结果\\";
		int k = 2000;
		multimap<double, int>re;
		while (k--)
		{
			vector<vector<int >>Cross_node_pop;
			Get_notes_sctsp(mappopulation,Cross_node_pop);
			insert_algoritham_SCTSP(mappopulation, Cross_node_pop,Filename);
			multimap<double, int>result;
			for (auto& it : mappopulation)
			{
				vector<List_insert*>ivec = it.first;
				multimap<double, int>imap = it.second;
				multimap<double, int>::reverse_iterator it = imap.rbegin();
				result.insert(make_pair(it->first, 1));
			}
			if(k==0) re = result;
			multimap<double, int>::iterator it = result.begin();
			result_file << it->first << endl;
			result.clear();
		}
		//for (auto& it : mappopulation)
		//{
		//	vector<List_insert*>ivec = it.first;
		//	multimap<double, int>imap = it.second;
		//	multimap<double, int>::reverse_iterator it = imap.rbegin();
		//	//List_insert*res = ivec[it->second];
		//	result.insert(make_pair(it->first, 1));
		//}
		double t2 = GetTickCount();
		double time = t2 - t1;
		ofstream res("C:\\Users\\dell\\Desktop\\城市分配_MIN_MAX\\萤火虫-result\\" + to_string(Citynum) + "-" + to_string(Salesnum) + "\\"+local_algorithm + ".txt", ios::app);
		for (auto& iter : re)
		{
			res << iter.first <<"     "<<time<< endl;
			break;
		}
		////res << "运行时间："<<time/1000 << endl;
		//int bb = 0;
		//int aa = 0;
}



//int main()
//{
//	/*mycalss *p = (mycalss*)malloc(sizeof(mycalss));
//	cout << p->a << endl;*/
//	//data_input();
//	int k = 100;
//	double bestfitness = INT_MAX;
//	srand(GetTickCount());
//	ReadCitiesDistance();
//	Init_Color();
//	//init_popsize();
//	vector<List_insert*>best_sequence;
//	Get_randomCity();
//	Get_Sequence();
//	while (k--){
//		Get_notes();//更新城市所在的商人序列的信息
//		insert_algoritham();
//		double fitness = 0;
//		for (int i = 0; i < Salesnum; i++)
//		{
//			fitness = fitness + Get_fitness(Sequence[i]);
//		}
//		if (fitness < bestfitness)
//		{
//			bestfitness = fitness;
//			best_sequence = Sequence;
//			cout << "kl;gskglkgk" << bestfitness << endl;
//		}
//		hash_notes.clear();
//		Cross_notes.clear();
//		update_city();
//		//City.clear();
//		//Sale.clear();
//		//Sequence.clear();
//	}
//	for (int i = 0; i < Salesnum; i++)
//	{
//		while (best_sequence[i] != NULL)
//	  {
//			cout << best_sequence[i]->val << "   ";
//			best_sequence[i] = best_sequence[i]->next;
//	   }
//	    cout << endl;
//	}
//	system("pause");
//	int b = 0;
//	return 0;
//}


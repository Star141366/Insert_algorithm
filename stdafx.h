// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//


#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<hash_map>
#include<map>
#include<windows.h>
#include<algorithm>
#include "List_insert.h"
#include "imagehlp.h"
#pragma comment(lib,"imagehlp.lib")
using namespace std;
extern int Citynum;
extern int Salesnum;
const int Notenum = 10;
const int iClimbNum = 50;
const int iSANum = 5;
const int SAdiedai = 10;
static int operator_num = 15000;
extern int local_num;

extern vector<int >dopt;
extern vector<int >City;
extern vector<int >Sale;
extern hash_map<int,int>hash_notes;
extern vector<int>Cross_notes;
extern vector<List_insert*>Sequence;
extern vector<vector<int> >City_color;
extern vector<vector<double> >Distance;
const int Popsize=30;
int rand_int(int min, int max); 
double rand_01();
void Init_Color();
void Get_Sequence();
void Get_randomCity();
void Get_notes();
double Get_fitness(List_insert*list);
double insert_note_fitness(List_insert*list, int index, int val,int color);
void  ReadCitiesDistance();
void update_city();
void data_input();
//void init_popsize(multimap<vector<List_insert*>, multimap<double, int>>&mappopulation);
void init_popsize(vector<pair<vector<List_insert*>, multimap<double, int>>>&mappopulation);
//void Get_notes_sctsp(multimap<vector<List_insert*>, multimap<double, int>>&mappopulation, vector<vector<int >>&Cross_node_pop);
void Get_notes_sctsp(vector<pair<vector<List_insert*>, multimap<double, int>>>&mappopulation, vector<vector<int >>&Cross_node_pop);
double insert_note_fit_sctsp(List_insert*list, int index, int val);
List_insert* reverseBetween(List_insert* head, int m, int n);
void greedy_opt(vector<int>&g_opt);
void data_input_sctsp();
void Swap_list(List_insert* list, int px, int py);
List_insert* Copy_List(List_insert* head);
void destroy_list(List_insert* list);
// TODO:  在此处引用程序需要的其他头文件



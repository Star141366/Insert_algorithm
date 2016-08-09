

#include"stdafx.h"
void Swap_list(List_insert* list,int px, int py)
{
	/*List_insert *temp = list;
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;*/
	List_insert *pa = NULL, *pb = NULL;
	int k = 0;
	while (list != NULL)
	{
		list = list->next;
		k++;
		if (k == px) pa = list;
		if (k == py){
			pb = list; break;
		}
	}
	int a = pa->val;
	pa->val = pb->val;
	pb->val = a;
}
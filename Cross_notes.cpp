

#include"stdafx.h"
void Get_notes()
{
	for (int i = 0; i < Notenum; i++)
	{
		int rand_note = rand_int(1, Citynum);
		while (hash_notes.find(City[rand_note]) != hash_notes.end() || City[rand_note]==0)
			   rand_note = rand_int(1, Citynum);
		//cout << rand_note << endl;
		hash_notes[City[rand_note]] = Sale[rand_note];
		Cross_notes.push_back(City[rand_note]);	
	}
	/*for (int i = 0; i < Notenum; i++)
	{
		cout << hash_notes[Cross_notes[i]] << "   ";
	}*/
}
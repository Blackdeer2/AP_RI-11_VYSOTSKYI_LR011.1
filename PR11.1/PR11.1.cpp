#include <iostream>
#include<windows.h>
#include<fstream>
#include <string>

using namespace std;

void CreateBIN(char* fname);
void PrintBIN(char* fname);
void ProcessBIN1(char* fname1, char* fname2);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname1[100];                  
	wcout << "enter file name 1: "; cin >> fname1;
	CreateBIN(fname1);
	PrintBIN(fname1);

	char fname2[100];
	wcout << "enter file name 2: "; cin >> fname2;

	ProcessBIN1(fname1, fname2);
	PrintBIN(fname2);


	return 0;
}
void CreateBIN(char* fname) {

	ofstream fout(fname, ios::binary);
	string s;
	char ch = 0;
	do {
		cin.get();
		cin.sync();
		wcout << "input line: "; getline(cin, s);
		for (unsigned i = 0; i < s.length(); i++)
			fout.write((char*)&s[i], sizeof(s[i]));
		wcout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	wcout << endl;
}
void PrintBIN(char* fname) {
	ifstream fin(fname, ios::binary);
	char c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c;
	}
	cout << endl;
}
void ProcessBIN1(char* fname1, char* fname2)
{
	ifstream f(fname1, ios::binary);
	ofstream g(fname2, ios::binary);
	char  c = 0;
	//char arr[] = { 'i','н','ф','о','р','м','а','т','и','к' };
	while (f.read((char*)&c, sizeof(c)))
	{
		if (c == 'i' || c == 'н' || c == 'ф' || c == 'о' || c == 'р' || c == 'м' || c == 'а' || c == 'т' || c == 'и' || c == 'к')
			g.write((char*)&c, sizeof(c));
	}
}
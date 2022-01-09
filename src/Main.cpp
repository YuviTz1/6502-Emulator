#include<iostream>
#include"cpu.h"
using namespace std;

int main()
{

	cpu CPU;

	cout << "Enter path to ROM file" << endl;
	string filename;
	cin >> filename;

	cout << "Enter number of instructions" << endl;
	int n; cin >> n;

	CPU.loadRom(filename);
	for (int i = 0; i < n; i++)
	{
		CPU.cycle();
	}
	CPU.status();
}

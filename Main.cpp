#include<iostream>
#include"cpu.h"
using namespace std;

int main()
{

	cpu CPU;

	string filename = "test.bin";

	//number of instructions
	int n; cin >> n;

	CPU.loadRom(filename);
	for (int i = 0; i < n; i++)
	{
		CPU.cycle();
		CPU.cycle();
	}
	CPU.status();
}
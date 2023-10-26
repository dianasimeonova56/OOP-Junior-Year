
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string namefile = "d:\data\\text.txt";
	fstream fp;
	fp.open(namefile, ios::in);
	string line, toPrint;
	while (!fp.eof()) {
		getline(fp, line);
		if (fp.eof()) {
			toPrint += line + ".";
		}
		else {
			toPrint += line + " ";
		}
	}
	cout << toPrint;
	fp.close()
}

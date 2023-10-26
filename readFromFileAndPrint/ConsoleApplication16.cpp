
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream fp;
	fp.open("d:\data\\text2.txt", ios::out);
	string text, word, toPrint;
	getline(cin, text);
	int wordCount = 1;

	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			word += text[i];
		}
		else if (wordCount != 3) {
			wordCount++;
			toPrint += word + " ";
			word = "";
		}
		else if (wordCount == 3) {
			toPrint += word + "\n";
			cout << toPrint;
			fp << toPrint;
			toPrint = "";
			word = "";
			wordCount = 1;
		}
	}
	if (wordCount < 3) {
		toPrint += word;
		cout << toPrint;
		fp << toPrint;
	}
	fp.close();
}

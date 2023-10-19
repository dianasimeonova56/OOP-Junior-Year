#include <iostream>
#include <string>
using namespace std;

int main()
{
	string words, currWord, prevWord;
	getline(cin, words);
	size_t nachalo, krai = 0;
	string mask = ".,!?:=;\"0123456789 ";
	string longest;
	while ((nachalo = words.find_first_not_of(mask, krai)) != string::npos) {
		prevWord = currWord;
		krai = words.find_first_of(mask, nachalo);
		currWord = words.substr(nachalo, krai - nachalo);
		if (currWord.length() > prevWord.length()) {
			longest = currWord;
		}
		else if (currWord.length() < prevWord.length()) {
			longest = prevWord;
		}
		else if (currWord.length() == prevWord.length()) {
			longest = currWord;
		}
	}
	cout << longest;


}
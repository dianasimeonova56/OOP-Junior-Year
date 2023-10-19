#include <iostream>
#include <string>
using namespace std;

int main()
{
	string words;
	getline(cin, words);
	size_t p = -1;

	while ((p = words.find_first_of("0123456789", p + 1)) != string::npos) {
		words[p] = '*';
	}
	size_t pos;
	while ((pos = words.find("**")) != string::npos) {
		words.replace(pos, 2, "*");
	}
	cout << words << endl;

}
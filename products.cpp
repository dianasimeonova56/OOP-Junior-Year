#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	fstream fp, fp2;
	fp.open("d:\\data\\store.txt", ios::in);
	fp2.open("d:\\data\\store-sorted.txt", ios::out);
	if (!fp.is_open()) {
		cout << "Error!";
		return -1;
	}

	vector<pair<string, double>> store;

	string product, line; int amount = 0; double price = 0, final = 0;
	//fp.ignore('\n');
	size_t p;

	while (!fp.eof()) {
		getline(fp, product, '\t');
		fp >> amount >> price;
		final += (amount * price);
		if (p = product.find_first_of('\n') != string::npos) {
			p = product.find_first_not_of('\n');
			product = product.substr(p, product.length());
		}
		
		int i = 0;
		while (i < store.size() && product != store[i].first) i++;
		if (i == store.size()) store.push_back(make_pair(product, final));
		else store[i].second += final;
		final = 0;
	}

	for (int i = 0; i < store.size(); i++) {
		cout << store[i].first << "\t" << store[i].second << endl;
	}

	vector<pair<string, double>> sorted;

	for (int i = 0; i < store.size(); i++) {
		int p = 0;
		while (p < sorted.size() && store[i].second < sorted[p].second) p++;
		if (p == sorted.size()) sorted.push_back(store[i]);
		else sorted.insert(sorted.begin() + p, store[i]);
	}

	for (int i = 0; i < sorted.size(); i++) {
		fp2 << sorted[i].first << "\t" << sorted[i].second << endl;
	}

	fp.close(), fp2.close();
}

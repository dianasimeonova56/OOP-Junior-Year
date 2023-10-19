
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string url;
	cout << "Enter url: " << endl;
	cin >> url;

	size_t findFirstSlash = url.find("://");

	string protocol = url.substr(0, findFirstSlash);

	size_t findNextSlash = url.find("/", findFirstSlash + 3);

	string host;
	for (int i = findFirstSlash + 3; i < findNextSlash; i++) {
		host += url[i];
	}

	size_t lastSlash = url.rfind("/");
	string path;
	for (int i = findNextSlash + 1; i < lastSlash; i++) {
		path += url[i];
	}

	string file;
	for (int i = lastSlash + 1; i < url.length(); i++) {
		file += url[i];
	}

	cout << "Protocol: " << protocol << endl;
	cout << "Host: " << host << endl;
	cout << "Path: " << path << endl;
	cout << "File: " << file << endl;

}



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	//read from a file that contains the following format:
	/*12.10.2023*124
	13.11.2023*50
	15.10.2023*200*/
	//the first part is a date, the second the number of passengers of a flight
	//calculate the average amount of passengers for all flies
	fstream fp3;
	fp3.open("d:\data\\bileti.txt", ios::in);
	if (!fp3.is_open()) {
		cout << "Error while opening file" << endl;
		return -1;
	}

	/*12.10.2023*124
	13.11.2023*50
	15.10.2023*200*/

	string line, passengers;
	int count = 0;
	double toAdd, average = 0, total = 0;

	while (!fp3.eof()) {
		getline(fp3, line);
		count++;

		size_t findAstericks = line.find("*");
		if (findAstericks != string::npos) {
			for (int i = findAstericks + 1; i < line.length(); i++) {
				passengers += line[i];
			}
		}
		else {
			cout << "Not found";
		}
		stringstream add(passengers);
		//add << passengers;
		add >> toAdd;
		total += toAdd;
		passengers = "";
	}
	cout << total << " " << count << endl;
	//average = static_cast<double>(total) / count;
	if (count > 0 && total > 0) {
		average = total / count;
		cout << average;
	}
	else {
		cout << "No data found";
	}
	fp3.close();
}
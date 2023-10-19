#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email;
    cout << "Enter e-mail: " << endl;
    cin >> email;
    string userName;
    size_t findUN = email.find("@");
    string server;

    for (int i = 0; i < findUN; i++) {
        userName += email[i];
    }
    cout << "User name: " << userName << endl;
    for (int i = findUN + 1; i < email.length(); i++) {
        server += email[i];
    }
    cout << "E-mail server: " << server << endl;
    size_t nationality = server.find("bg");
    if (nationality != string::npos) {
        cout << "Nationality: bulgarian";
    }
    else {
        cout << "Nationality: not bulgarian";
    }
}

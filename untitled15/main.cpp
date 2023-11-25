#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, int> rejestry;
vector<string> command;
vector<int> valueForCommand;


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N >= 1 && N <= 500000){
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            command.push_back(s);
            int n;
            cin >> n;
            if (n >= -15000 && n <= 15000) {
                valueForCommand.push_back(n);
            } else {
                exit(1);
            }
        }
    } else {
        exit(1);
    }
    for (int i = 0; i < 16; ++i) {
        rejestry[char(97 + i)] = 1;
    }

    for (int i = 0; i < command.size(); ++i) {
        if (command[i].find("mod") != string::npos){
            string kurwamac = command[i];
            if (int(kurwamac.at(3)) > 113 || int(kurwamac.at(3)) < 97){
                exit(1);
            }
            int Value = rejestry[kurwamac.at(3)];
            int n = valueForCommand[i];
            Value += n;
            rejestry[kurwamac.at(3)] = Value;
        }
        if (command[i].find("clr") != string::npos){
            string kurwamac = command[i];
            if (int(kurwamac.at(3)) > 113 || int(kurwamac.at(3)) < 97){
                exit(1);
            }
            int Value = valueForCommand[i];
            rejestry[kurwamac.at(3)] = Value;
        }
        if (command[i].find("gogo") != string::npos) {
            int Value = valueForCommand[i];
            if (Value == -1) {
                break;
            }
            if (Value == 1) {
                continue;
            }
            if (Value == 0) {
                break;
            } else {
                valueForCommand[i] = 0;
                i += Value - 1;
                if (i < 0){
                    i = 0;
                }
            }
            continue;
        }
        if (command[i].find("mod") == string::npos && command[i].find("clr") == string::npos && command[i].find("gogo") == string::npos && command[i].find("nope") == string::npos || command[i].length() != 4){
            exit(1);
        }
    }

    for (auto rejestr : rejestry) {
        cout << rejestr.first << ": " << rejestr.second << "\n";
    }
    return 0;
}
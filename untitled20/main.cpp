#include<bits/stdc++.h>
#include <vector>
using namespace std;


int main() {

    vector<int> liczby;
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int k;
        cin >> k;
        liczby.push_back(k);
    }

    for(int l = 0; l < p; l++) {
        vector<int> F;
        F.push_back(1);
        F.push_back(1);
        int i = 2;
        while (true) {
            int k = F[i - 1] + F[i - 2];
            F.push_back(k);
            if (F[i] > liczby[l]) {
                break;
            }
            i++;
        }
        F.pop_back();
        int count = 0;
        int sum = liczby[l];
        for (int q = F.size() - 1; q >= 0; q--) {
            if (sum - F[q] >= 0) {
                while (sum - F[q] >= 0) {
                    sum -= F[q];
                    count++;
                }
            }
        }


        cout << count << "\n";
    }

    return 0;
}



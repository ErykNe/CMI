#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
    unsigned long long N;
    unsigned long long count = 0;
    cin >> N;
    unordered_map<unsigned long long, unsigned long long> mods;

    if (N >= 3 && N <= 1000000) {
        for (int i = 0; i < N; ++i) {
            unsigned long long bouquet;
            cin >> bouquet;

            if (bouquet >= 2 && bouquet <= 100) {
                mods[bouquet % 3]++;
            } else {
                exit(1);
            }
        }
    } else {
        exit(1);
    }

    count = (mods[0] * (mods[0] - 1) / 2) + (mods[1] * mods[2]);
    cout << count;

    return 0;
}

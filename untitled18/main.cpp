#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isAnagram(const string& word1, const string& word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    int numWildcards = 0;

    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] == '?') {
            numWildcards++;
        } else {
            count1[word1[i] - 'a']++;
        }

        if (word2[i] == '?') {
            numWildcards++;
        } else {
            count2[word2[i] - 'a']++;
        }
    }

    if (numWildcards == word1.length()) {
        return true;
    }

    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            if (numWildcards == 0) {
                return false;
            } else {
                numWildcards -= abs(count1[i] - count2[i]);
                if (numWildcards < 0) {
                    return false;
                }
            }
        }
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<string, string>> slowa(N);
    for (auto& slowo : slowa) {
        cin >> slowo.first >> slowo.second;
    }
    for (const auto& slowo : slowa) {
        if (isAnagram(slowo.first, slowo.second)) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    return 0;
}
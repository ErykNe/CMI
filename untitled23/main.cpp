#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;



int main() {
    vector<int> nawiewy;
    int klapy = 2;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int Moc;
        cin >> Moc;
        nawiewy.push_back(Moc);
    }
    int temperatura = accumulate(nawiewy.begin(), nawiewy.end(), 0);
    int firstLoop = 1;
    while (1 == 1) {
        if(nawiewy.size() < 3){
            if(temperatura > 0){
                cout << temperatura;
                exit(0);
            } else {
                cout << 0;
                exit(0);
            }
        }
        auto min_it = min_element(nawiewy.begin(), nawiewy.end() - 2);
        auto min_index = distance(nawiewy.begin(), min_it);
        auto max_it = max_element(nawiewy.begin(), nawiewy.end() - 2);
        auto max_index = distance(nawiewy.begin(), max_it);
        if(firstLoop == 0){
             min_it = min_element(nawiewy.begin(), nawiewy.end());
             max_it = max_element(nawiewy.begin(), nawiewy.end());
             min_index = distance(nawiewy.begin(), min_it);
             max_index = distance(nawiewy.begin(), max_it);
        }
        firstLoop = 0;
        int min = (int) min_index;
        int max = (int) max_index;
        if ((min + 1 == max || min + 2 == max) && (nawiewy[min + 1] + nawiewy[max] > 0 || nawiewy[min + 2] + nawiewy[max] > 0)) {

            min_it = min_element(nawiewy.begin() + min + 1, nawiewy.end());
            min_index = distance(nawiewy.begin(), min_it);
            min = (int) min_index;

        }
        nawiewy.erase(nawiewy.begin() + min, nawiewy.end());
        klapy--;
        int TerazTemperatura = accumulate(nawiewy.begin(), nawiewy.end(), 0);
        if(TerazTemperatura > temperatura){
            temperatura = TerazTemperatura;
        } else {
            break;
        }
        if(klapy == 0){
            break;
        }
        if(nawiewy.empty()){
            cout << 0;
            exit(0);
        }
    }

    cout << temperatura;

    return 0;
}

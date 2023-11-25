#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    std::ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> arr;
    if (N >= 3 && N <= 100000) {
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            if (a < 1000000000) {
                arr.push_back(a);
            } else {
                exit(1);
            }
        }
    } else {
        exit(1);
    }

    sort(arr.begin(), arr.end());


    unsigned long long shortestDistance = 100000000000000000;


    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = arr[j] - arr[i];
            if (dist < shortestDistance) {
                shortestDistance = dist;
            }
        }
    }

    int count = 0;
    int a = 0;

    while ((arr[0] + a * shortestDistance) != arr[arr.size() - 1]) {

        if (find(arr.begin(), arr.end(), arr[0] + a * shortestDistance) == arr.end()){
            count++;
        }
        a++;

    }

    cout << count << endl;

    return 0;
}


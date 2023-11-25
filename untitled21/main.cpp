#include <iostream>
using namespace std;

const int MAXN = 1000;

unsigned long long n;
unsigned long long mapa[MAXN][MAXN];
unsigned long long horizontal[MAXN][MAXN];
unsigned long long vertical[MAXN][MAXN];

unsigned long long check_direction(int row, int col, int drow) {
    unsigned long long res = 0;
    unsigned long long length1 = 0, length2 = 0;
    if (drow == 0) {
        if (horizontal[row][col] != 0) {
            return horizontal[row][col];
        }
        for (int j = col; j < n && mapa[row][j] == mapa[row][col]; j++) {
            length1++;
        }
        for (int j = col - 1; j >= 0 && mapa[row][j] == mapa[row][col]; j--) {
            length2++;
        }
        res = length1 + length2;
        horizontal[row][col] = res;
    } else {
        if (vertical[row][col] != 0) {
            return vertical[row][col];
        }
        for (int i = row; i < n && mapa[i][col] == mapa[row][col]; i++) {
            length1++;
        }
        for (int i = row - 1; i >= 0 && mapa[i][col] == mapa[row][col]; i--) {
            length2++;
        }
        res = length1 + length2;
        vertical[row][col] = res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mapa[i][j];
        }
    }
    unsigned long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            unsigned long long horizontal = check_direction(i, j, 0);
            unsigned long long vertical = check_direction(i, j, 1);
            result = max(result, horizontal + vertical);
        }
    }
    cout << result << "\n";
    return 0;
}
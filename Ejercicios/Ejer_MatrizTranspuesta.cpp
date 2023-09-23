#include <iostream>
using namespace std;

void CalcTrans(int(*p)[4]) {

    int temp;

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            temp = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + j) + i);
            *(*(p + j) + i) = temp;
        }
    }
}

int main() {
    int matrizA[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    // Matriz original
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrizA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n";

    // Matriz Transpuesta
    CalcTrans(matrizA);

    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
            cout << matrizA[a][b] << " ";
        }
        cout << endl;
    }

    return 0;
}

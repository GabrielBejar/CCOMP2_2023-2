#include <iostream>
using namespace std;

void camb(int* p, int* q) {

    int temp = *p;
    *p = *q;
    *q = temp;
}

void cocktail(int* ini, int* fin) {

    bool cambiado = true ;

    while (cambiado && ini < fin) {

        int x = 0;

        for (int* i = ini; i < fin; i++) {
            if (*i > *(i + 1)) {
                camb(i, i + 1);
                x++;
            }
            else {
                continue;
            }
        }
        fin--;

        for (int* j = fin; j > ini; j--) {
            if (*j < *(j - 1)) {
                camb(j, j - 1);
                x++;
            }
            else {
                continue;
            }
        }
        ini++;

        if (x == 0) {
            cambiado = false;
        }
        else {
            cambiado = true;
        }
    }
}

int main()
{
    int mA[] = { 13, 17, 8, 2, 1, 30, 21, 64 };
    int t{ sizeof(mA) / 4 };

    cocktail(mA, mA + t - 1);

    for (int* h = mA; h < mA + t; h++) {
        cout << *h << " ";
    }
}



#include <iostream>
using namespace std;


void camb(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


void ordenar(int* ini, int* mid) {

    int* fin = { mid + (mid - ini) };

    while (ini < mid && mid < fin) {
        if (*ini > *mid) {
            for (int* temp = ini; temp < mid; temp++) {
                camb(temp, mid);
            }
            mid++;
        }
        else {
            ini++;
        }
    }
}

int main()
{
    int A[] = { 1, 5, 8 ,9, 11, 15, 3, 2, 7, 12, 26, 30 };
    int t{ sizeof(A) / 4 };

    ordenar(A, A + t / 2);

    for (int* p = A; p < A + t; p++) {
        cout << *p << " ";
    }
}



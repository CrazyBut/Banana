#include <iostream>
#include <ctime>
#include "string.h"

using namespace std;


class Sort {
public:
    virtual void sort(int *mas, int n) = 0;
};

class Quick : public Sort {
public:

void sort(int *mas, int n) {
    int f = 0;
    int l = n - 1;
    int mid = mas[n / 2];
    do {
        while (mas[f] < mid) {
            f++;
        }
        while (mas[l] > mid) {
            l--;
        }
        if (f <= l)
        {
            int count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }

    } while (f <= l);

    if (l > 0) {
        sort(mas, l + 1);
    }
    if (f < n) {
        sort (&mas[f], n - f);
    }
}
};

void printSortedArray(Sort &sort, int *mas, int n){
    int *res = new int[n];
    memcpy(res, mas, n * sizeof(int));
    cout << "Using " << " sort :" << endl;
    sort.sort(res, n);
    for (int i = 0; i < n; i++)
        cout << " " << res[i];
    cout << endl;
}

int main() {
    Quick quick;

    int n;
    cout << "Vvedite razmernost' massiva : " << endl;
    cin >> n;
    cout << "Nachalnii massiv : " << endl;
    int *userArray = new int[n];
    for(size_t i = 0; i < n; i++){
        userArray[i] = rand() % 100;
        cout << userArray[i] << " ";
    }

    cout << endl;
    printSortedArray(quick, userArray, n);
}
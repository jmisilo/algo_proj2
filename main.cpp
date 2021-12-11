#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int const MAX_VALUE = 200;

// generate n el. vector
vector<int> generateVector(int n) {
    vector<int> new_vect;

    for(int i = 0; i < n; i++) {
        new_vect.push_back(rand() % MAX_VALUE);
    }

    return new_vect;
}

vector<int> generateSequence(int n) {
    vector<int> new_vect;

    for(int i = 1; i <= n; i++) new_vect.push_back(i);

    return new_vect;
}

// write vector to file
vector<int> toFile(vector<int> vect) {
    fstream out;
    out.open("output.txt", ios::out);

    for (int i = 0; i<vect.size(); i++){
        out << vect[i] << " ";
    }

    out.close();
}

////////////////////////////////////////////
// QUICK SORT
int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];

    int i = left, j = right;

    int temp;

    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;

            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}
////////////////////////////////////////////

void executionTime(vector<int> vect, bool sortType) {
    // sortType - if True - quicksort, else insertation sort
    string sortName;
    clock_t t = clock();

    if (sortType) {
        quicksort(vect, 0, vect.size()-1); // funkcja wykonujaca dane zadanie
        sortName = "Quicksort";
    } else if (!sortType) {
        insertion_sort(vect);
        sortName = "Insertation sort";
    }

    t = clock() - t;

    long double fullTime = (float)t/CLOCKS_PER_SEC;

    fstream res;
    res.open("results.csv", ios::app);
    //res << "n elements, algorithm, execution time" << endl;
    res << vect.size() << ", " << sortName << ", " << fullTime << endl;

    res.close();

}
////////////////////////////////////////////
int main()
{
    
    return 0;
}

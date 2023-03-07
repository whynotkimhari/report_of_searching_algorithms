#include <bits/stdc++.h>
using namespace std;

void heapify(vector<double> &array, int n, int i);
void HeapSort(vector<double> &array, int n);

int main() {
    ifstream fi;
    ofstream fo;
    int cnt = 1;
    string fo_path = "speed_rate/HeapSort.txt";
    fo.open(fo_path);
    while(cnt < 11) {
        srand(time(NULL));
        clock_t start, end;
        double running_time;
        //File processing
        string fi_path = "data/data" + to_string(cnt) + ".txt";
        fi.open(fi_path);

        vector<double> array(1000000);
        for(int i = 0; i < 1000000; i++) fi >> array[i];
    
        start = clock();
        HeapSort(array, 1000000);
        end = clock();

        running_time = (double)(end - start)/ CLOCKS_PER_SEC;
        // for(int i = 0; i < 1000000; i++) fo << array[i] << " ";
        fo << "Running time " << cnt << ": " << running_time << endl;
        ++cnt;
    }
}

void heapify(vector<double> &array, int n, int i) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;

    if(l < n && array[l] > array[largest]) largest = l;
    if(r < n && array[r] > array[largest]) largest = r;

    if(largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void HeapSort(vector<double> &array, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) heapify(array, n, i);
    for(int i = n - 1; i >= 0; i--) {
        swap(array[i], array[0]);
        heapify(array, i, 0);
    }
}
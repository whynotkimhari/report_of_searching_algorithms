#include <bits/stdc++.h>
using namespace std;

void merge(vector<double> &array, int l, int m, int r);
void MergeSort(vector<double> &array, int l,int r);

int main() {
    ifstream fi;
    ofstream fo;
    int cnt = 1;
    string fo_path = "speed_rate/MergeSort.txt";
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
        
        //MergeSort
        start = clock();
        MergeSort(array, 0, 1000000 - 1);
        end = clock();

        running_time = (double)(end - start)/ CLOCKS_PER_SEC;
        // for(int i = 0; i < 1000000; i++) fo << array[i] << " ";
        fo << "Running time " << cnt << ": " << running_time << endl;
        ++cnt;
    }
}

void merge(vector<double> &array, int l, int m, int r) {
    vector<double> one(array.begin() + l, array.begin() + m + 1);
    vector<double> two(array.begin() + m + 1, array.begin() + r + 1);
    int i = 0, j = 0;
    while(i < one.size() && j < two.size()) {
        if(one[i] <= two[j]) {
            array[l] = one[i];
            ++l; ++i;
        }
        else{
            array[l] = two[j];
            ++l; ++j;
        }
    }

    while(i < one.size()) {
        array[l] = one[i];
        ++l; ++i;
    }

    while(j < two.size()) {
        array[l] = two[j];
        ++l; ++j;
    }
}

void MergeSort(vector<double> &array, int l,int r) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    MergeSort(array, l, mid);
    MergeSort(array, mid + 1, r);
    merge(array, l, mid, r);
}
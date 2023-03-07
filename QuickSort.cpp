#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<double>& array, int l, int r);
int Partition(vector<double>& array, int Left, int Right);

int main() {
    ifstream fi;
    ofstream fo;
    int cnt = 1;
    string fo_path = "speed_rate/QuickSort.txt";
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
        
        //QuickSort
        start = clock();
        QuickSort(array, 0, 1000000 - 1);
        end = clock();

        running_time = (double)(end - start)/ CLOCKS_PER_SEC;
        // for(int i = 0; i < 1000000; i++) fo << array[i] << " ";
        fo << "Running time " << cnt << ": " << running_time << endl;
        ++cnt;
    }
}

void QuickSort(vector<double>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition(array, l, r);
    QuickSort(array, l, p);
    QuickSort(array, p + 1, r);
}

int Partition(vector<double>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    double pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i] < pivot);

        do{
            --j;
        }while(array[j] > pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

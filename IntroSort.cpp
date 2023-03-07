#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fi;
    ofstream fo;
    int cnt = 1;
    string fo_path = "speed_rate/IntroSort.txt";
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
        sort(array.begin(), array.end());
        end = clock();

        running_time = (double)(end - start)/ CLOCKS_PER_SEC;
        // for(int i = 0; i < 1000000; i++) fo << array[i] << " ";
        fo << "Running time " << cnt << ": " << running_time << endl;
        ++cnt;
    }
}
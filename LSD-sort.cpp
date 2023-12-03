#include <fstream> 
#include <string> 
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <ctime>


using namespace std;

void LSD_sort(vector <int> arr, int size_array, int size_radix) {
    vector <int> B(size_array);
    for (int i = 0; i < size_radix; i++) {
        int C[10], d;
        for (int j = 0; j < 10; j++)
            C[j] = 0;
        for (int j = 0; j < size_array; j++) { // кол-во букв в слове
            d = int(arr[j] / int(pow(10, i))) % 10; // word - слово (baa) 
            C[d]++;
        }
        int count = 0;
        for (int j = 0; j < 10; j++) {
            int tmp = C[j];
            C[j] = count;
            count += tmp;
        }
        for (int j = 0; j < size_array; j++) {
            d = int(arr[j] / int(pow(10, i))) % 10;
            B[C[d]] = arr[j]; //j;
            C[d]++;
        }
        for (int ii = 0; ii < size_array; ii++)
        {
            arr[ii] = B[ii];
        }
    }
}

int main() {
    string output = "output2k.txt";

    ofstream outFile;
    outFile.open(output);
    int size_radix = 3, size_array = 10, radix = int(pow(10, size_radix - 1));

    for (size_array; size_array <= 500; size_array += 10) {    
        
        vector <int> arr(size_array), B(size_array);     
        
        srand(time(NULL)); 

        for (int i = 0; i < size_array; i++)
        {
            arr[i] = (rand() + radix) % (radix * 10);
            cout << arr[i] << ' ';
        }

        srand(time(0)); 

        LSD_sort(arr, size_array, size_radix);

        seconds = clock() / 1000.0;
        outFile << "n: " << size_array << "   " << "runtime: " << seconds << endl;
    }
    outFile.close();
    return 0;
}

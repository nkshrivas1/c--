#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;


int main(){
    // cout << "Enter the input: ";
    // int arr[5];
    // for(int i = 0; i < 5; i++) {
    //     cin >> arr[i];
    // }
    // ofstream fout;
    // fout.open("output.txt");
    // fout << "Original data: "<<endl;

    // for(int i = 0; i < 5; i++) {
    //     fout << arr[i] << " ";
    // }
    // fout << endl;
    // fout << "Sorted data: "<<endl;
    // // Simple bubble sort for demonstration
    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 5 - i - 1; j++) {
    //         if(arr[j] > arr[j + 1]) {
    //             swap(arr[j], arr[j + 1]);
    //         }
    //     }
    // }
    // for(int i = 0; i < 5; i++) {
    //     fout << arr[i] << " ";
    // }
    // // fout << "Hello, World!" << endl;
    // fout.close();

    // ifstream fin;
    // fin.open("output.txt");
    // string line;
    // // getline(fin, line);
    // // cout << line << endl;
    // // while(getline(fin, line)) {
    // //     cout << line << endl;
    // // }
    // char ch;
    // // while(fin.get(ch)) {
    // //     cout << ch;
    // // }
    // ch = fin.get();
    // while (!fin.eof()) {
    //     cout << ch;
    //     ch = fin.get();
    // }
    // fin.close();

    // write a program to read input from file and write sum of each row 
    // to new file. Each row contains 5 integers.
    //  The output file should contain the sum of each row in a new line.
    // ofstream inputFile("input.txt");
    // inputFile << "1 2 3 4 5\n";
    // inputFile << "6 7 8 9 10\n";
    // inputFile << "11 12 13 14 15\n";
    // inputFile.close();

    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    // int sum;
    // while (!fin.eof()) {
    //     sum = 0;
    //     for (int i = 0; i < 5; i++) {
    //         int num;
    //         fin >> num;
    //         sum += num;
    //     }

    //     fout << "Sum: " << sum << endl;
    // }
    // fin.close();
    // fout.close();
    // ios::in - read from file.if file does not exist,
    //  failbit is set.
    // ios::out - write to file. if file does not exist,
    //  it will be created.
    fstream inputFile("input.txt", ios::in );
    if(!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }
     // add sum at the end of the each line for 
    //  each row of integers in the same file
    vector<string> lines;
    string line;
    while(getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    ofstream outputFile("input.txt", ios::out | ios::trunc);
    for (const auto& l : lines) {
        istringstream iss(l);
        int sum = 0, num;
        while (iss >> num) {
            sum += num;
        }
        outputFile << l << " Sum: " << sum << endl;
    }
    outputFile.close();





    return 0;

}
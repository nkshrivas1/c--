#include<iostream>
#include<fstream>
using namespace std;

int main(){  
    // file opening modes
    //ios::in - read from file.if file does not exist,
    //  failbit is set.
    // ios::out - write to file. if file does not exist,
    //  it will be created.
    //ios:binary - binary mode. used to read/write binary
    //  files.
    // ios::trunc - if file exists, discard the contents
    //  and start fresh.
    // ifstream is used to read from a file
//    ox

   ifstream inputFile("test.txt",ios::in);
   string line;
//    inputFile >> line;
//   getline(inputFile,line);
while(getline(inputFile,line)){
   cout << line << endl;
}
   inputFile.close();

    return 0;
}
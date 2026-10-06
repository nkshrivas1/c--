#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // write to a text
    // random access


    //1. tellg() - tells us the current read/get position
    //2. seekg() - moves the get/read pointer
                // modes in seekg- ios::beg ,ios::cur,ios::end
     string line;
     char ch;
    fstream file("example.txt",ios::in);
    if(file){
// some example data
// This is another test line appended to file
// some example data again
        // cout << "Position: "<< file.tellg()<< endl;
        // // getline(file,line);
        // file.seekg(-10,ios::end);

        // file.get(ch);
        // file.seekg(1,ios::cur);

        // cout << "Character: "<< ch << endl;
        // cout << "Position: "<< file.tellg()<< endl;
        file.close();
    }else{
        cout << "Unable to open file"<<endl;
        return 1;
    }
    file.open("example.txt",ios::out);
    if(file){
// some example data
// This is another test line appended to file
// some example data again
        cout << "Position: "<< file.tellp()<< endl;
        // getline(file,line);
        file << "some example data" << endl;
        file << "This is another test line appended to file" << endl;
        file << "some example data again" << endl;

        file.seekp(-4,ios::end);
        file << " New data ";
        cout << "Character: "<< ch << endl;
        cout << "Position: "<< file.tellg()<< endl;
        file.close();
    }else{
        cout << "Unable to open file"<<endl;
        return 1;
    }

    // write mode :
        // tellp()
        //seekp()
        //put pointers
    
    
    
    
    
    
    
    // ?? modes in file handeling
    // fstream my_file("example.txt",ios::app);
    // if(my_file){
    //     my_file << "some example data" << endl;
    //     my_file.close();
    // }else{
    //     cout << "Unable to open file"<<endl;
    //     return 1;
    // }
    // string line;
    // my_file.open("example.txt",ios::in);
    // if(my_file){
    //     while(!my_file.eof()){
    //         getline(my_file,line);
    //         cout << line << endl;
    //     }
    //     my_file.close();
    // }else{
    //     cout << "Unable to open file"<<endl;
    //     return 1;
    // }


    //3. append data
    // my_file.open("example.txt",ios::app);
    // if(my_file){
    //     my_file << "This is another test line appended to file"<<endl;
    //     my_file.close();
    // }else{
    //     cout << "Unable to open file"<<endl;
    //     return 1;
    // }

    // my_file.open("example.txt",ios::out | ios::app);
    // if(my_file){
    //     my_file << "some example data again" << endl;
    //     my_file.close();
    // }else{
    //     cout << "Unable to open file"<<endl;
    //     return 1;
    // }
}
// player 1 - alex
// player 2 -> rahul
// player 3 -> aman
// ....
// player 8500 -> rohit

// sequential access 
// start from beginning
// read in order
// good for processing all records
// similar to linear traversal

// random access
// can jump to any position
// read desired location
// good for specific records
//can directly access known position
// smilar to direct indexing
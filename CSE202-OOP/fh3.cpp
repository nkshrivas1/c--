#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct player{
    string name;
    int score;
};

int main(){
   
   
     // add sum at the end of the each line for 
    //  each row of integers in the same file
    //Sequential file processing: read each line, calculate sum, write back
    //  to file
  // 10 20  30 40 50
  // create a file and isert that data 
  // and using inputFile read the data and calculate sum of each row
//    and write it back to the new file
// g++ fh3.cpp -o fh3
//fh3
//  fstream out("input.txt", ios::out );
//     if(!out) {
//         cout << "Error opening file!" << endl;
//         return 1;
//     }
//     out << "1 2 3 4 5\n";
//     out << "6 7 8 9 10\n";
//     out.close();

//     fstream in("input.txt", ios::in);
//     if(!in) {
//         cout << "Error opening file!" << endl;
//         return 1;
//     }
//     fstream out2("output.txt", ios::out);
   
    // string line;
    // while(getline(in, line)) {
    //     // creating a string stream from the line
    //     istringstream iss(line);
    //     int sum = 0, num;
    //     // reading integers from the string stream and calculating sum
    //     while (iss >> num) {
    //         sum += num;
    //     }
    //     out2 << line << " Sum: " << sum << endl;
    // }
    // in.close();
    // out2.close();
 // create struct player with name and score
    // /./ create 5 players by taking user input and write to file
    player players[5];
    fstream out("players.txt", ios::out );
    if(!out) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for(int i=0;i<2;i++){
        cout << "Enter name and score for player " << i+1 << ": ";
        cin >> players[i].name >> players[i].score;
        out << players[i].name << " " << players[i].score << endl;
    }
    out.close();

    // ifstream in("players.txt", ios::in);
    player p;
    // cout << in.eof() << endl;
    // //Keep going as long as reading the next record succeeds
    // while(!in.eof()) {
    //     in >> p.name >> p.score;
    //     cout << "Player: " << p.name << ", Score: " << p.score << endl;
    // }
    // cout << in.eof() << endl;

    // end of file eof() is set when the end of file is reached.
    // find and print the average score of players
    // in.close();
    fstream if2("input.txt",ios::in);
    int sum =0;
    int count =0;
    while(!if2.eof()){
        if2 >> p.name >> p.score;
        sum+= p.score;
        cout << p.score << " " << sum  << endl;
        count++;
    }
    cout<< "average score : " << sum/count;
    if2.close();



    return 0;

}
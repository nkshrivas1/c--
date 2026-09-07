#include<iostream>
using namespace std;

int main(){
    //suppose a class has 4 students
    // each student has marks in 3 subjects
    int students[4][3] = {
        {80,50,70},
        {90,60,80},
        {80,80,70},
        {96,80,90}
    };
    //get the total score of each student from this array
    for(int i =0;i<4;i++){
        int sum =0;
        for(int j=0;j<3;j++){
            sum+=students[i][j];
        }
        cout << "Total marks of student "<< i << " "<< sum << endl;
    }
    // find the diagonal sum of this matriux]
        int sum =0;
        for(int i =0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==j)
                    sum+=students[i][j];
            }
        }
        cout << "Total marks of student "<< sum << endl;



    return 0;
}
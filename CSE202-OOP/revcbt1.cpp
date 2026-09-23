#include<iostream>
#include<iomanip>
using namespace std;

class Student{
    private:
        string name;
        int marks;

        public:
        Student(string n,int m): name(n),marks(m){}
        Student(string name){
            this->name = name;
        }
};
    int x = 10;
 inline int square(int x){
        return x*x;
    }
    void modifyValue( int &x){
        x = x+10;
        cout << "Inside function : " << x << endl;//30
    }
int main(){
    int x = 10;
    int *p = &x;
    int **q=&p;
    *p=20;
    p=nullptr;
    cout << x;


}
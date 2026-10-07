#include<iostream>
#include<fstream>
using namespace std;
class Student{
    public:
        int roll;
        string name;
        // vector<int> marks = {1,2,3,4,5};
        void read(){
            cout << "enter roll: ";
            cin >> roll;
             cout << "enter name: ";
            cin >> name;
        }
        void display(){
            cout << "Roll: "<< roll << endl;
            cout << "Name: "<< name << endl;
        }
        void writeToFile(fstream& out){
            out.write((char*)&roll, sizeof(roll));
            int len = name.size();
            out.write((char*)&len,sizeof(len));
            out.write(name.c_str(),len);
        }
        void readFromFile(fstream& in){
            in.read((char*)&roll,sizeof(roll));
            int len = name.size();
            in.read((char*)&len,sizeof(len));
            name.resize(len);
            in.read(&name[0],len);
        }
};
int main(){

    Student s;
    // insert multiple object data in binary file
    int T;
    cout << "enter total records: ";
    cin >> T;
    

    // binary mode : data is handeled as bytes
    // advantages
        // faster for suitable structured data
        // can be more compact
        // preserves the byte representation
        
    fstream obj;
    obj.open("Today.dat", ios::binary | ios::out);
        // for(int i=0;i<T;i++){
        //     Student s;
        //     s.read();
        //     obj.write((char*)&s,sizeof(s));
        // }
        s.read();
        s.writeToFile(obj);
        // binary mode + output mode
        obj.close();

    // // why convert it to char*?
    // //Because write() works with a sequence of bytes
    // //write( 
    //     // address of data,
    //     // number of bytes
    // // )
    // // (char*)&s - treat the memory occupied by s as a sequence of bytes
    // //read( 
    //     // address of data,
    //     // number of bytes
    // // )
   
    // ifstream in("Today.dat" ,ios::binary | ios::in);
    // in.read(
    //     (char*)&s,sizeof(s)
    // );
    // s.display();
    // in.close();

    obj.open("Today.dat", ios::binary | ios::in );
    // for(int i=0;i<T;i++){
    //     Student s;
    //     obj.read((char*)&s,sizeof(s));
    //     s.display();
    // }
    // while(obj.read((char*)&s,sizeof(s))){
    //     s.display();
    // }
    s.readFromFile(obj);
    s.display();
    obj.close();
    //can i do this for every calss
    //No
    //works reasonably for classes containing simple/trivally
    //copyable data such as: int , float, char,char[]

    //Serialization - coverting an object's data into a format that can be safely 
    //stored in a file, and later reconstructing the object from that stored data.
    
    //until now what are we doing :?
    // object -> copy raw memory -> file

    // we do now -
    //object -> extract individual data members ->convert/store them -> Binary file
    // while reading
    // binary file -> read individual data -> assign to object member -> object

    return 0;
}
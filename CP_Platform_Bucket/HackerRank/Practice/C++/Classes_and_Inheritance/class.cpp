#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    int age,standard;
    string first_name,last_name;
    public:
        void set_age(int x){
            age=x;
        }
        void set_first_name(string x){
            first_name=x;
        }
        void set_last_name(string x){
            last_name=x;
        }
        void set_standard(int x){
            standard=x;
        }

        int get_age(){
            return age;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        int get_standard(){
            return standard;
        }
        string to_string(){
            stringstream a;
            char c=',';
            a<<age<<c<<first_name<<c<<last_name<<c<<standard;
            return a.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
      
    return 0;
}


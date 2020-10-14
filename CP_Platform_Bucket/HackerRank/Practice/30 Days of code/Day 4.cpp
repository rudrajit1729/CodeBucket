using namespace std;
#include <iostream>
int c=1;
class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        if(initialAge<0){
            age=0;
             cout<<"Age is not valid, setting age to 0.\n";
        }
        else
            age=initialAge;
    }

    void Person::amIOld(){
        if(c==1){
            if(age<13){ cout<<"You are young.";}
            else if(age>=13 && age<18) cout<<"You are a teenager.";
            else cout<<"You are old.";
        }
        else{
            if(age<13){ cout<<"\nYou are young.";}
            else if(age>=13 && age<18) cout<<"\nYou are a teenager.";
            else cout<<"\nYou are old.";
        }
        c++;
    }   

    void Person::yearPasses(){
        age++;
    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}

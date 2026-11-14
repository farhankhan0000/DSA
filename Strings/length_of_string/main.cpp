#include <iostream>
using namespace std;

class String{
    private:
        char* a;
        int length;
        int size;

    public:
        String(int size){
            this->size = size;
            a = new char[size]; 
        }

        void initialize(){
            
        }

        void find_length(){
            int i;
            for(i=0; a[i] != '\0'; i++){

            }
            cout<<"i";
        }
};

int main(){
    String s(15);
}
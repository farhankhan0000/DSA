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
            length = 0;
            a = new char[size]; 
            a[0] = '\0';
        }

        void initialize(const char* str){
            int i;
            for(i = 0; str[i] != '\0'; i++){
                a[i] = str[i];
            }
            a[i] = '\0';
            length = i;
        }

        int find_length(){
            return length;
        }
};

int main(){
    String s(15);
    s.initialize("Hello");
    cout<<s.find_length()<<endl;
}
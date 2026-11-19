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

        void change(){
            char temp;
            for (int i = 0; i < length/2; i++)
            {
                temp = a[i];
                a[i] = a[length-i-1];
                a[length-i-1] = temp;
            }
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<a[i];
            }
            
        }
};

int main(){
    String s(20);
    s.initialize("Python");
    s.change();
    s.show();
}

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

        void change() {
            for (int i = 0; i < length; i++)
            {
                if(a[i] >= 65 && a[i] <= 90){
                    a[i] = a[i] + 32;
                }
                else if(a[i] >= 97 && a[i] <= 122){
                    a[i] = a[i] - 32;
                }
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
    String s(15);
    s.initialize("WelcOMe");
    s.change();
    s.show();
}
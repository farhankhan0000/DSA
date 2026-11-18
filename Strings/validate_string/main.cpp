#include <iostream>
using namespace std;

class String{
    private:
        char* A;
        int length;
        int size;

    public:
        String(int size){
            this->size = size;
            A = new char[size];
            length = 0;
        }

        void initialize(const char* str){
            int i;
            for (i = 0; str[i] != '\0'; i++)
            {
                A[i] = str[i];
            }
            length = i;
            A[i] = '\0';
        }

        bool check(){
            bool valid = true;
            for (int i = 0; i < length; i++)
            {
                if(!((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '1' && A[i] <= '9'))){
                    valid = false;
                    break;
                }
            }
            return valid; 
        }
};

int main(){
    String s(20);
    s.initialize("womaniya89");
    cout<<s.check()<<endl;
}
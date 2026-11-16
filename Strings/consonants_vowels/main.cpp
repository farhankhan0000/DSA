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
            A[0] = '\0';
        }

        void initialize(const char* str){
            int i = 0;
            while (str[i] != '\0')
            {
                A[i] = str[i];
                i++;
            }
            i = length;
        }

        void consonant_vowel_count(){
            int cons = 0;
            int vow = 0;
            for (int i = 0; i < length; i++)
            {
                if(A[i] == 'a', A[i] == 'A', A[i] == 'e', A[i] == 'E', A[i] == 'i', A[i] == 'I',
                A[i] == 'o', A[i] == 'O', A[i] == 'u', A[i] == 'U'){
                    vow++;
                }
                else if((A[i] >= 97 && A[i] <= 122) || A[i] >= 65 && A[i] <= 90){
                    cons++;
                }
            }
            cout<<"no of vowels = "<<vow<<" no of consonants "<<cons<<endl;
            
        }
};

int main(){
    String s(30);
    s.initialize("How are you Doing");
}
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

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<a[i];
            }
            
        }

        void compare(const char* str){
            int i;
            int j;
            for(i=0,j=0; a[i] != '\0' && str[j] != '\0'; i++,j++){
                char c1 = a[i];
                char c2 = str[j];
                if(c1 >= 97 && c1 <= 122){
                    
                }
                else if(c1 >= 65 && c1 <= 90){
                    c1 = c1 + 32;
                }

                if(c2 >= 97 && c2 <= 122){
                    
                }
                else if(c2 >= 65 && c2 <= 90){
                    c2 = c2 + 32;
                }

                if(c1 != c2){
                    break;
                }
            }
            if(a[i] == str[j]){
                cout<<"equal";
            }
            else if(a[i] < str[j]){
                cout<<"smaller";
            }
            else{
                cout<<"greater";
            }
            
        }

        string check_palindrome(){
            int i = 0;
            int j = length-1;
            while(i <= j){
                if(a[i] != a[j]){
                   return "not Palindrome"; 
                }
                i++;
                j--;
            }
            return "Palindrome";
        }
};

int main(){
    String s(25);
    s.initialize("madam");
    s.show();
    cout<<s.check_palindrome();
}
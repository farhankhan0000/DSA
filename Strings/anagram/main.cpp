#include <iostream>
using namespace std;

class String{
    private:
        char* a;
        int size;
        int length;

    public:
        String(int size){
            this->size = size;
            a = new char[size];
            length = 0;
        }

        void initialize(const char* str){
            int i;
            for(i = 0; str[i] != '\0'; i++){
                a[i]  = str[i]; 
            }
            a[i] = '\0';
            length = i;
        }

        bool check_angram(const char* b, int arr_size){
            int* d = new int[arr_size]();
            for (int i = 0; i < length; i++)
            {
                d[a[i]-97]++;
            }
            for (int i = 0; i < length; i++){
                if(d[b[i]-97] > 0){
                    d[b[i]-97]--;
                }
                else{
                    delete []d;
                    return false;
                }
            }
            delete []d;
            return true;
            
        }
};


int main(){
    String s(30);
    s.initialize("silent");
    cout<<s.check_angram("listem", 26)<<endl;
    return 0;
}
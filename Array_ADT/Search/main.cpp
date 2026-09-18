#include <iostream>
using namespace std;

class Array{
    private:
        int* A;
        int size;
        int length;

    public:
        Array(int size){
            this->size = size;
            length = 0;
            A = new int[size];
        }

        void initialization(int length){
            this->length = length;
            cout<<"Enter the elements in the Array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        int linearSearch(int num){
            for (int i = 0; i < length; i++)
            {
                if(A[i] == num){
                    return i;
                }
            }
            return -1;
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
            
        }
};

int main(){
    Array arr(10);
    arr.initialization(5);
    arr.show();
    cout<<arr.linearSearch(30);
    return 0;
}
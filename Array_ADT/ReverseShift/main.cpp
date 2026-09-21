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
            A = new int[size];
            length = 0;
        }

        void initialize(){
            length = 10;
            cout<<"Enter the elements in Array \n";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
            
        }

        void reverse(){
            int temp = 0;
            for (int i = 0; i < length/2; i++)
            {
                temp = A[i];
                A[i] = A[length-i-1];
                A[length-i-1] = temp;
            }
        }
};

int main(){
    Array arr(10);
    arr.initialize();
    arr.show();
    cout<<"\n";
    arr.reverse();
    arr.show();
}
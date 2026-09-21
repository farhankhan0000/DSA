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

        void reverse2(Array& arr2){
            int j = length - 1;
            for (int i = 0; i < length; i++)
            {
                arr2.A[i] = A[j];
                j--;
            }

            for (int i = 0; i < length; i++)
            {
                A[i] = arr2.A[i];
            }  
        }
};



int main(){
    Array arr1(10);
    Array arr2(10);
    arr1.initialize();
    cout<<"\n";
    arr2.initialize();
    arr1.show();
    cout<<"\n";
    arr2.show();
    arr1.reverse2(arr2);
    cout<<"\n";
    arr1.show();
}
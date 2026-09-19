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

        int binarySearch(int num){
            int i = 0;
            int j = length-1;
            while(i <= j){
                int middle = (i+j)/2;
                if(A[middle] == num){
                    return num;
                }
                else if(A[middle] < num){
                    i = middle + 1;
                }
                else if(A[middle] > num){
                    j = middle - 1;
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
    arr.initialization(10);
    arr.show();
    cout<<arr.binarySearch(30);
    return 0;
}
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

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in Array\n ";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }  
        }

        void unionUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                arr3.A[k] = A[i];
                k++;
            }
            for (int j = 0; j < length; j++)
            {
                bool isPresent = false;
                for (int i = 0; i < length; i++)
                {
                    if(arr2.A[j] == A[i]){
                        isPresent = true;
                        break;
                    }
                }
                if(!isPresent){
                    arr3.A[k] = arr2.A[j];
                    k++;
                }
                
            }
            arr3.length = k;
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
        }
};


int main(){
    Array arr1(5);
    Array arr2(5);
    Array arr3(10);

    arr1.initialize(5);
    arr2.initialize(5);
    
    arr1.unionUnsorted(arr2, arr3);

    arr3.show();

    return 0;
}
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
            A  = new int[size];
            length = 0;
        }

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in Array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void mergeArray(Array &arr2, Array &arr3){
            int arr3_lenght = 0;
            int i = 0;
            int j = 0;
            int k = 0;
            while(i < length && j < length){
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    k++;
                    i++;
                    arr3_lenght++;
                }
                else if(arr2.A[j] < A[i]){
                    arr3.A[k] = arr2.A[j];
                    k++;
                    j++;
                    arr3_lenght++;
                }
                else{
                    i++;
                    j++;
                }
            }

            while(i < length){
                arr3.A[k] = A[i];
                k++;
                i++;
                arr3_lenght++;
            }

            while(j < length){
                arr3.A[k] = arr2.A[j];
                j++;
                k++;
                arr3_lenght++;
            }
            arr3.length = arr3_lenght;
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
        }
};

int main(){
    Array arr1(10);
    Array arr2(10);
    Array arr3(10);
    arr1.initialize(5);
    arr2.initialize(5);
    arr1.mergeArray(arr2, arr3);
    arr3.show();
    return 0;
}
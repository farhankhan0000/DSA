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

        void reverseArray(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;
            while(i < length && j < length){
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    k++;
                    i++;
                }
                else if(arr2.A[j] < A[i]){
                    arr3.A[k] = arr2.A[j];
                    k++;
                    j++;
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
            }

            while(j < length){
                arr3.A[k] = arr2.A[j];
                j++;
                k++;
            }
        }
};

int main(){

    return 0;
}
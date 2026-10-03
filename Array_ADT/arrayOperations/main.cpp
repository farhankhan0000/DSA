#include <iostream>
using namespace std;


class Array{
    private:
        int* A;
        int size;
        int lenght;

    public:
        Array(int size){
            this->size = size;
            A = new int[size];
            lenght = 0;
        }

        void initialize(int length){
            this->lenght = lenght;
            cout<<"Enter the elements in Array\n ";
            for (int i = 0; i < lenght; i++)
            {
                cin>>A[i];
            }  
        }

        void unionUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            bool isPresent = false;
            for (int i = 0; i < lenght; i++)
            {
                arr3.A[k] = A[i];
                k++;
            }
            for (int j = 0; j < lenght; j++)
            {
                for (int i = 0; i < lenght; i++)
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
            arr3.lenght = k+1;
        }
};
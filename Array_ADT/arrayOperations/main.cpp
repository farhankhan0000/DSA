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

        void unionSorted(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < length && j < length)
            {
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    i++;
                    k++;
                }
                else if(arr2.A[j] < A[i]){
                    arr3.A[k] = arr2.A[j];
                    j++;
                    k++;
                }
                else{
                    arr3.A[k] = A[i];
                    i++;
                    k++;
                    j++;
                }
            }

            while(i < length){
                arr3.A[k] = A[i];
                i++;
                k++;
            }

            while(j < length){
                arr3.A[k] = arr2.A[j];
                j++;
                k++;
            }
            arr3.length = k;
        }

        void intersectionUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < arr2.length; j++)
                {
                    if(A[i] == arr2.A[j]){
                        arr3.A[k] = A[i];
                        k++;
                        break;
                    }
                }
                
            }
            arr3.length = k;
            
        }

        void intersectionSorted(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;

            while(i < length && j < length){
                if(A[i] < arr2.A[j]){
                    i++;
                }
                else if(arr2.A[j] < A[i]){
                    j++;
                }
                else{
                    arr3.A[k] = A[i];
                    i++;
                    j++;
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
    // arr1.unionSorted(arr2, arr3);

    arr1.intersectionSorted(arr2,arr3);

    arr3.show();

    return 0;
}
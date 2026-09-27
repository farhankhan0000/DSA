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

        void setArray(int length){
            this->length = length;
            cout<<"Enter the elements in array\n";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void checkSort(){
            bool sorted = true;
            for (int i = 0; i < length-1; i++)
            {
                if(A[i] > A[i+1]){
                    sorted = false;
                }
            }
            if(sorted){
                cout<<"Sorted";
            }
            else{
                cout<<"Not sorted";
            }
            
        }

        void insertInSortedAsc(int number){
            for (int i = 0; i < length; i++)
            {
                if(number < A[i]){
                    for (int j = length; j > i; j--)
                    {
                        A[j] = A[j-1];
                    }
                    A[i] = number;
                    length++;
                    return;
                }
                
            }
            A[length] = number;
            length++;
        }

        void insertInSortedDesc(int number){
            for (int i = 0; i < length; i++)
            {
                if(number > A[i]){
                    for (int j = length; j > i; j--)
                    {
                        A[j] = A[j-1];
                    }
                    A[i] = number;
                    length++;
                    return;
                }
                
            }
            A[0] = number;
            length++;
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"    ";
            }
            
        }
};

int main(){
    Array arr(10);
    arr.setArray(5);
    arr.checkSort();
    arr.insertInSortedDesc(10);
    arr.show();
    return 0;
}
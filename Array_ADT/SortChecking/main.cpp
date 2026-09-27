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
            int lowest = A[0];
            for (int i = 0; i < length; i++)
            {
                if(lowest < A[i+1]){
                    lowest = A[i+1];
                }
                else{
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
};

int main(){
    Array arr(10);
    arr.setArray(5);
    arr.checkSort();
    return 0;
}
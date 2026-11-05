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
            cout<<"Enter the elements in array\n";
            for(int i = 0; i < length; i++){
                cin>>A[i];
            }
        }

        void  min_max(){
            int min = A[0];
            int max = A[0];
            for (int i = 1; i < length; i++)
            {
                if(A[i] < min){
                    min = A[i];
                }
                else if(A[i] > max){
                    max = A[i];
                }
            }
            cout<<min<<" "<<max;
        }
};

int main(){
    Array arr(10);
    arr.initialize(10);
    arr.min_max();
}
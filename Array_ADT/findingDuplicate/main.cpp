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
            cout<<"Enter the elements in Array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void finding_duplicates(){
            int duplicate = 0;
            for (int i = 0; i < length; i++)
            {
                if(A[i] == A[i+1] && A[i] != duplicate){
                    cout<<A[i]<<" ";
                    duplicate = A[i];
                }
            }
            
        }
        
};

int main(){
    Array arr1(10);
    arr1.initialize(10);
    arr1.finding_duplicates();
    return 0;
}
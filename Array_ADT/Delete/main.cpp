#include <iostream>
using namespace std;

class Array{
    private:
        int * A;
        int size;
        int length;

    public:
        Array(int size){
            this->size = size;
            length = 0;
            A = new int[size];
        }

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in array\n";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void deleteElement(int index){
            if(index < length && index >= 0){
                for (int i = index; i < length-1; i++)
                {
                    A[i] = A[i+1];
                }
                length--; 
            }
        }

        void show(){
        for(int i = 0; i < length; i++){
            cout<<A[i]<<"  ";
        }
    }
};

int main(){
    Array arr(10);
    arr.initialize(5);
    arr.show();
    arr.deleteElement(4);
    cout<<"\n";
    arr.show();
    return 0;
}
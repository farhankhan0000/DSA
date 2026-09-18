#include <iostream>
using namespace std;

class Array{
    private:
        int * A;
        int length;
        int size;

    public:
        Array(int size){
            this->size = size;
            A = new int[size];
            length = 0;
        }

    void insert(int index, int num){
        if(index >= 0 && length < size && index <= length){
            for(int i = length; i > index; i--){
                A[i] = A[i-1];
            }
            A[index] = num;
            length++;
        }
    }

    void show(){
        for(int i = 0; i < length; i++){
            cout<<A[i]<<"\n";
        }
    }

};

int main(){
    Array arr(10);
    arr.insert(0,10);
    arr.show();
}
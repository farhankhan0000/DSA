#include <iostream>
using namespace std;

class Array{
    private:
        int* A;
        int size;
        int length;

    public:
        Array(){
            size = 10;
            A = new int[size];
            length = 0;
        }

        Array(int size){
            this->size = size;
            A = new int[size];
            length = 0;
        }

        ~Array(){
            delete []A;
        }

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in Array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void find_missing_element(){
            int diff = A[0] - 0;
            int missing_element;
            for (int i = 0; i < length; i++)
            {
                if(A[i] - i != diff){
                    missing_element=i+diff;
                    break;
                }
            }

            cout<<missing_element<<" "<<endl;
            
        }

        void display(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
            
        }
};

int main(){
    Array arr1;
    arr1.initialize(10);
    arr1.display();
    arr1.find_missing_element();
}
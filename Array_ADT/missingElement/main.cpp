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

        void find_multiple_missing_element(){
            int diff = A[0] - 0;
            int missing_element;
            for (int i = 0; i < length; i++)
            {
                if(A[i] - i != diff){
                    while(diff < A[i] - i){
                        missing_element = i+diff;
                        cout<<missing_element<<"  ";
                        diff++;
                    }
                }
            }
        }

        void find_missing_element_unsorted(Array &arr1){
            for (int i = 0; i < length; i++)
            {
                arr1.A[A[i]]++;
            }

            cout<<"Missing elements are\n";

            for (int i = 1; i < arr1.length; i++)
            {
                if(arr1.A[i]  == 0){
                    cout<<i<<"  ";
                    
                }
            }
            
            
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
    Array arr2(13);
    arr2.initialize(13);
    arr1.initialize(10);
    arr1.display();
    arr2.display();
    arr1.find_missing_element_unsorted(arr2);
}
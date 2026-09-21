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

        void initialization(){
            cout<<"Enter the elements in array";
            length = 5;
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
                
            }
            
        }
        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
            
        }
        int get_element(int index){
            if(index > 0 && index < length){
                return A[index];
            }
        }
        void set_element(int index, int num){
            if(index > 0 && index < length){
                A[index] = num;
            }
            
        }

        int get_max(){
            int max = 0;
            for (int i = 0; i < length; i++)
            {
                if(A[i] > max){
                    max = A[i];
                }
            }
            return max;   
        }


};

int main(){
    Array arr(10);
    arr.initialization();
    cout << arr.get_element(3);
    arr.set_element(3, 45);
    arr.show();
    return 0;
}
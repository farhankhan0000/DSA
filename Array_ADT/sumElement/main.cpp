#include <iostream>
using namespace std;

class Array{
    private:
        int* A;
        int size;
        int length;

    public:
        Array(int size, bool zeroInitialize){
            this->size = size;
            if(zeroInitialize){
                A = new int[size]();
            }
            else{
                A = new int[size];
            }
            length = 0;
        }

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in the array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }   
        }

        void show(){
        for(int i = 0; i < length; i++){
            cout<<A[i]<<"  ";
            }
        }

        void find_two_element_sum(int k){
            for (int i = 0; i < length-1; i++)
            {
                for (int j = i+1; j < length; j++)
                {
                    if(A[i] + A[j] == k){
                        cout<<A[i]<<" "<<A[j]<<" = "<<k<<endl;
                    }
                }
                
            }
            
        }

        void hash_find_two_element_sum(Array &arr, int k){
            for (int i = 0; i < length; i++)
            {
                int completment = k - A[i];
                if(k - A[i] >= 0){
                    if(arr.A[k - A[i]] != 0){
                    cout<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
                }
                arr.A[A[i]]++;
                }
            }
            
        }



};

int main(){
    Array arr(10, false);
    Array arr1(17, true);
    arr.initialize(10);
    arr.hash_find_two_element_sum(arr1, 10);
    return 0;
}
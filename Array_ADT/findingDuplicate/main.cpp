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
            cout<<"Enter the elements in Array";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }
            
        }

        void finding_duplicate_sorted(){
            int duplicate = 0;
            for (int i = 0; i < length; i++)
            {
                if(A[i] == A[i+1] && A[i] != duplicate){
                    cout<<A[i]<<" ";
                    duplicate = A[i];
                }
            }
            
        }

        void finding_duplicate_with_count_sorted(){
            for (int i = 0; i < length-1; i++)
            {
                if(A[i] == A[i+1]){
                    int j = i + 1;
                    while(A[i] == A[j]){
                        j++;
                    }
                    cout<<A[i]<<"appeared "<<j-i<<" times in the array \n";
                    i = j - 1;
                }
            }
            
        }

        void hash_finding_duplicate_sorted(Array &arr){
            for (int i = 0; i < length; i++)
            {
                arr.A[A[i]]++;
            }
            int max = A[length-1];
            for (int i = 0; i <= max; i++)
            {
                if(arr.A[i] > 1){
                    cout<<i<<" appeared "<<arr.A[i]<<" times \n";
                }
            }
            
        }

        void finding_duplicate_unsorted(){
            for (int i = 0; i < length; i++)
            {
                int count = 1;
                if(A[i] != -1){
                    for (int j = i+1; j < length; j++)
                {
                        if(A[i] == A[j]){
                        count++;
                        A[j] = -1;
                    }
                    
                }
                }

                if(count > 1){
                        cout<<A[i]<<" appeared "<<count<<" times.\n";
                    }
                
            }
            
        }
        
        void hash_finding_duplicate_unsorted(Array &arr){
            int max = 0;
            for (int i = 0; i < length; i++){
                if(A[i] > max){
                    max = A[i];
                }
            }

            for (int i = 0; i < length; i++)
            {
                arr.A[A[i]]++;
            }

            for (int i = 0; i <= max; i++)
            {
                if(arr.A[i] > 1){
                    cout<<i<<" appeared "<<arr.A[i]<<" times \n";
                }
            }
            
        }
};

int main(){
    Array arr1(10, false);
    Array arr2(21, true);
    arr1.initialize(10);
    // arr1.finding_duplicate_sorted();
    // arr1.finding_duplicate_with_count_sorted();
    // arr1.hash_finding_duplicate_sorted(arr2);
    arr1.hash_finding_duplicate_unsorted(arr2);
    return 0;
}
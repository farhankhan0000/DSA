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
            for (int i = 0; i < length-1; i++)
            {
                if(A[i] > A[i+1]){
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

        void insertSorted(int num){
            int i = length - 1;
            while (A[i] > num)
            {
                A[i+1] = A[i];
                i--;
            }
            A[i+1] = num;
            length++;
        }

        void insertInSortedAsc(int number){
            for (int i = 0; i < length; i++)
            {
                if(number < A[i]){
                    for (int j = length; j > i; j--)
                    {
                        A[j] = A[j-1];
                    }
                    A[i] = number;
                    length++;
                    return;
                }
                
            }
            A[length] = number;
            length++;
        }

        void insertInSortedDesc(int number){
            for (int i = 0; i < length; i++)
            {
                if(number > A[i]){
                    for (int j = length; j > i; j--)
                    {
                        A[j] = A[j-1];
                    }
                    A[i] = number;
                    length++;
                    return;
                }
                
            }
            A[0] = number;
            length++;
        }

        void swap(int a, int b){
            int temp = A[a];
            A[a] = A[b];
            A[b] = temp;
        }

        void negativeLeftPositiveRight(){
            int i = 0;
            int j = length-1;
            while(i < j){
                while(A[i] < 0 && i < j){
                    i++;
                }
                while(A[j] > 0 && i < j){
                    j--;
                }
                if(i < j){
                    swap(i,j);
                }
            }
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"    ";
            }
            
        }
};

int main(){
    Array arr(10);
    arr.setArray(5);
    // arr.checkSort();
    // arr.insertInSortedDesc(10);
    arr.negativeLeftPositiveRight();
    arr.show();
    return 0;
}
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

        void reverse(){
            int temp = 0;
            for (int i = 0; i < length/2; i++)
            {
                temp = A[i];
                A[i] = A[length-i-1];
                A[length-i-1] = temp;
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

        void mergeArray(Array &arr2, Array &arr3){
            int arr3_lenght = 0;
            int i = 0;
            int j = 0;
            int k = 0;
            while(i < length && j < arr2.length){
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    k++;
                    i++;
                    arr3_lenght++;
                }
                else if(arr2.A[j] < A[i]){
                    arr3.A[k] = arr2.A[j];
                    k++;
                    j++;
                    arr3_lenght++;
                }
                else{
                    arr3.A[k] = A[i];
                    i++;
                    j++;
                    k++;
                }
            }

            while(i < length){
                arr3.A[k] = A[i];
                k++;
                i++;
                arr3_lenght++;
            }

            while(j < length){
                arr3.A[k] = arr2.A[j];
                j++;
                k++;
                arr3_lenght++;
            }
            arr3.length = arr3_lenght;
        }


        void insertUnsorted(int num, int index){
            if(index >= 0 && length < size && index <= length){
                if(length == 0 || index == length){
                    A[index] = num;
                    length++;
                }
                else{
                    for (int i = length; i > index; i--)
                    {
                        A[i] = A[i-1];
                    }
                    A[index] = num;
                    length++;
                }
            }
        }

        void insertSorted(int num){
            int index = 0;
            int i = 0;
            while(i < length){
                if(num < A[i]){
                    break;
                }
                i++;
            }
            index = i;
            if(length < size && index <= length){
                if(length == 0 || index == length){
                    A[index] = num;
                    length++;
                }
                else{
                    for (int i = length; i > index; i--)
                    {
                        A[i] = A[i-1];
                    }
                    A[index] = num;
                    length++;
                }
            }
        }

        void delete_element(int index){
            if(index >= 0 && index < length){
                for (int i = index; i < length; i++)
                {
                    A[i] = A[i+1];
                }
                length--;
                
            }
        }

        void linear_search(int num){
            int index = 0;
            for (int i = 0; i < length; i++)
            {
                if(num == A[i]){
                    index = i;
                    break;
                }
            }
            cout<<index<<"\n";
            
        }

        void binary_search(int num){
            int min = 0;
            int max = length-1;
            int middle = (min+max)/2;
            while(min <= max){
                if(A[middle] == num){
                    cout<<middle<<"\n";
                    break;
                }
                else if(A[middle] < num){
                    min = middle+1;
                    middle = (min+max)/2;
                }
                else{
                    max = middle-1;
                    middle = (min+max)/2;
                }
            }
        }

        void initialize(int length){
            this->length = length;
            cout<<"Enter the elements in Array\n ";
            for (int i = 0; i < length; i++)
            {
                cin>>A[i];
            }  
        }

        void unionUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                arr3.A[k] = A[i];
                k++;
            }
            for (int j = 0; j < length; j++)
            {
                bool isPresent = false;
                for (int i = 0; i < length; i++)
                {
                    if(arr2.A[j] == A[i]){
                        isPresent = true;
                        break;
                    }
                }
                if(!isPresent){
                    arr3.A[k] = arr2.A[j];
                    k++;
                }
                
            }
            arr3.length = k;
        }

        void unionSorted(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < length && j < length)
            {
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    i++;
                    k++;
                }
                else if(arr2.A[j] < A[i]){
                    arr3.A[k] = arr2.A[j];
                    j++;
                    k++;
                }
                else{
                    arr3.A[k] = A[i];
                    i++;
                    k++;
                    j++;
                }
            }

            while(i < length){
                arr3.A[k] = A[i];
                i++;
                k++;
            }

            while(j < length){
                arr3.A[k] = arr2.A[j];
                j++;
                k++;
            }
            arr3.length = k;
        }

        void intersectionUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < arr2.length; j++)
                {
                    if(A[i] == arr2.A[j]){
                        arr3.A[k] = A[i];
                        k++;
                        break;
                    }
                }
                
            }
            arr3.length = k;
            
        }

        void intersectionSorted(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;

            while(i < length && j < length){
                if(A[i] < arr2.A[j]){
                    i++;
                }
                else if(arr2.A[j] < A[i]){
                    j++;
                }
                else{
                    arr3.A[k] = A[i];
                    i++;
                    j++;
                    k++;
                }
            }
            arr3.length = k;
        }

        void differenceUnsorted(Array &arr2, Array &arr3){
            int k = 0;
            for (int i = 0; i < length; i++)
            {
                bool isPresent = false;
                for (int j = 0; j < arr2.length; j++)
                {
                    if(A[i] == arr2.A[j]){
                        isPresent = true;
                        break;
                    }
                    
                }

                if (!isPresent){
                    arr3.A[k] = A[i];
                    k++;
                }
                
            }
            arr3.length = k;
        }

        void differenceSorted(Array &arr2, Array &arr3){
            int i = 0;
            int j = 0;
            int k = 0;

            while(i < length && j < length){
                if(A[i] < arr2.A[j]){
                    arr3.A[k] = A[i];
                    i++;
                    k++;
                }

                else if(arr2.A[j] < A[i]){
                    j++;
                }
                else{
                    i++;
                    j++;
                    k++;
                }
            }
            arr3.length = k;
        }

        void show(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<"  ";
            }
        }
};


int main(){
    Array arr1(5);
    Array arr2(5);
    Array arr3(10);

    return 0;
}
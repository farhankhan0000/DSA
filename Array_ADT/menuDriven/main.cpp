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

        ~Array(){
            delete []A;
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

    int i;
    while(i < 20){
        cout<<"Choose the number according to taks: \n1.Insert\n2.Delete\n3.Reverse\n4.Search\n5.Merge\n6.Difference\n7.Initialize.\n8.Show\nGreater than 20 if you want to exit";
        cin>>i;
        if(i == 1){
            int n;
            cout<<"Enter the number you want to insert ";
            cin>>n;
            arr1.insertSorted(n);
        }
        else if(i == 2){
            int index;
            cout<<"Enter the index you want to delete ";
            cin>>index;
            arr1.delete_element(index);
        }
        else if(i == 3){
            arr1.reverse();
        }
        else if(i == 4){
            int num;
            cout<<"Enter the number you want to search ";
            cin>>num;
            arr1.linear_search(num);
        }
        else if(i == 5){
            arr1.mergeArray(arr2, arr3);
        }
        else if(i == 6){
            arr1.differenceSorted(arr2, arr3);
        }
        else if(i == 7){
            int num;
            cout<<"Enter 1 for arr1\nEnter 2 for arr2\nEnter 3 for arr3";
            cin>>num;
            if(num == 1){
                arr1.initialize(5);
            }
            else if(num == 2){
                arr2.initialize(5);
            }
            else if(num == 3){
                arr3.initialize(10);
            }
        }
        else if(i == 8){
            int num;
            cout<<"Enter 1 for arr1\nEnter 2 for arr2\nEnter 3 for arr3";
            cin>>num;
            if(num == 1){
                arr1.show();
            }
            else if(num == 2){
                arr2.show();
            }
            else if(num == 3){
                arr3.show();
            }
        }
        else if(i > 20){
            break;
        }
    }
    return 0;
}
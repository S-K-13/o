#include <iostream>
using namespace std;

template<class T>
void search_sort(T A[], int n) {
    T temp; 

    
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i; 

        for (int j = i + 1; j < n; j++) 
        {
            if (A[j] < A[min]) 
            {
                min = j;  
            }
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";  
    }
    cout << endl;
}

int main() {
    int n;  
    int choice; 

    
    while (true) {
        
        cout << "Select the array type:" << endl;
        cout << "1. Integer" << endl;
        cout << "2. Float" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;  
        cout << "Selected Option no: " << choice << endl;

       
        if (choice == 3)
            break;

       
        cout << "Enter the size of the array:" << endl;
        cin >> n; 

        
        if (choice == 1) {
            int* A = new int[n];  

            cout << "Enter the array elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> A[i];  
            }

            cout << "Entered array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << A[i] << " ";  
            }
            cout << endl;

           
            search_sort(A, n);

            delete[] A;

        }
       
        else if (choice == 2) {
            float* B = new float[n];  

            cout << "Enter the array elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> B[i];  
            }

            cout << "Entered array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << B[i] << " ";  
            }
            cout << endl;

            search_sort(B, n);

           
            delete[] B;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;  
}

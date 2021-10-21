//В данном ДЗ приведены два варианта решения. Первое через интовые функции. Второе через функции войд с двойными указателями.


#include <iostream>
#include <time.h>
using namespace std;

void RandArray(int* array, int size, int begin, int end)
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % (end - begin + 1) - begin;
    }
}
void PrintArray(const int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*   Задание 1. Даны два массива : А[M] и B[N] (M и N вводятся с клавиатуры).
                Необходимо создать третий массив минимально возможного размера, в котором нужно собрать
                элементы массива A, которые не включаются в массив B, без повторений.*/

int* Task1(int* A, int* B, int size_A, int size_B, int& size_C)
{
    int* temp = new int[size_A];

    int flag;

    for (int i = 0; i < size_A; i++)
    {
        flag = 0;
        for (int j = 0; j < size_B; j++)
        {
            if (A[i] == B[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            temp[size_C] = A[i];
            size_C++;
        }
    }

    return temp;
    delete[] temp;
}


/*  Задание 2. Даны два массива : А[M] и B[N] (M и N вводятся с клавиатуры).
                Необходимо создать третий массив минимально возможного размера, в котором нужно собрать
                элементы массивов A и B, которые не являются общими для них, без повторений. */

int* Task2(int* A, int* B, int size_A, int size_B, int& size_C)
{
    int* temp = new int[size_A];
    int flag;
    for (int i = 0; i < size_A; i++)
    {
        flag = 0;
        for (int j = 0; j < size_B; j++)
        {
            if (A[i] == B[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            temp[size_C] = A[i];
            size_C++;
        }
    }
    for (int i = 0; i < size_B; i++)
    {
        flag = 0;

        for (int j = 0; j < size_A; j++)
        {
            if (B[i] == A[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            temp[size_C] = B[i];
            size_C++;
        }
    }

    return temp;

    delete[] temp;
}

int main()
{
    srand(time(NULL));

    size_t size_A;
    size_t size_B;

    cout << "Input size of arr A" << endl;
    cin >> size_A;

    cout << "Input size of arr B" << endl;
    cin >> size_B;

    int* A = new int[size_A];
    int* B = new int[size_B];
    RandArray(A, size_A, 2, 10);
    cout << "Your first array A is: " << endl;
    PrintArray(A, size_A);
    cout << endl;
    RandArray(B, size_B, 2, 10);
    cout << "Your second array B is: " << endl;
    PrintArray(B, size_B);
    cout << endl;

    cout << "Modified array C is: " << endl;
    int size_C = 0;
    int* C = Task1(A, B, size_A, size_B, size_C);
    PrintArray(C, size_C);

    cout << "Modified array D is: " << endl;
    int size_D = 0;
    int* D = Task2(A, B, size_A, size_B, size_D);
    PrintArray(D, size_D);
    cout << endl;


    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}

//  Решение через двойные указатели.++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <time.h>
using namespace std;

void RandArray(int* array, int size, int begin, int end)
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % (end - begin + 1) - begin;
    }
}
void PrintArray(const int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*   Задание 1. Даны два массива : А[M] и B[N] (M и N вводятся с клавиатуры).
                Необходимо создать третий массив минимально возможного размера, в котором нужно собрать
                элементы массива A, которые не включаются в массив B, без повторений.*/

void Task1(int** A, int** B, int** C, int size_A, int size_B, int* pC)
{    
    int flag;
    for (int i = 0; i < size_A; i++)
    {
        flag = 0;
        for (int j = 0; j < size_B; j++)
        {
            if ((*A)[i] == (*B)[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            (*C)[*pC] = (*A)[i];
            (*pC)++;
        }
    }         
    
}


/*  Задание 2. Даны два массива : А[M] и B[N] (M и N вводятся с клавиатуры).
                Необходимо создать третий массив минимально возможного размера, в котором нужно собрать
                элементы массивов A и B, которые не являются общими для них, без повторений. */

void Task2(int** A, int** B, int** D, int size_A, int size_B, int& size_D)
{
    int flag;
    for (int i = 0; i < size_A; i++)
    {
        flag = 0;
        for (int j = 0; j < size_B; j++)
        {
            if ((*A)[i] == (*B)[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            (*D)[size_D] = (*A)[i];
            size_D++;
        }
    }
    for (int i = 0; i < size_B; i++)
    {
        flag = 0;

        for (int j = 0; j < size_A; j++)
        {
            if ((*B)[i] == (*A)[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            (*D)[size_D] = (*B)[i];
            size_D++;
        }
    }
}

int main()
{
    srand(time(NULL));

    int size_A;
    int size_B;
       
    cout << "Input size of arr A" << endl;
    cin >> size_A;

    cout << "Input size of arr B" << endl;
    cin >> size_B;

    int* A = new int[size_A];
    int* B = new int[size_B];
    

    RandArray(A, size_A, 2, 10);
    cout << "Your first array A is: " << endl;
    PrintArray(A, size_A);
    cout << endl;
    RandArray(B, size_B, 2, 10);
    cout << "Your second array B is: " << endl;
    PrintArray(B, size_B);
    cout << endl;

    int size_C = 0;
    int* pC = &size_C;
    int* C = new int[size_C];
    cout << "Modified array C is: " << endl;    
    Task1(&A, &B, &C, size_A, size_B, pC);
    PrintArray(C, size_C);
    
    int size_D = 0;
    int* D = new int[size_D];
    cout << "Modified array D is: " << endl;
    Task2(&A, &B, &D, size_A, size_B, size_D);
    PrintArray(D, size_D);
    cout << endl;


    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    return 0;
}


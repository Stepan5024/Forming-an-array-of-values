// Лабораторная работа №1 
// Выполнили студенты группы м3о-219Бк-50000 Бокарев С.М. Катвалян А.А.

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <math.h>
#include <chrono> 

#define PI 3.14159265

using namespace std;

void FillSaw(double* arr, int n, double min, double max, double period);
void FillSaw(int* arr, int length, int min, int max, int period);
void FillSin(double* arr, int n, double min, double max, double period);
void FillSin(int* arr, int length, int min, int max, int period);
void FillStep(double* arr, int n, double min, double max, double period);
void FillStep(int* arr, int n, int min, int max, int period);
void FillRand(double* arr, int n, double min, double max);
void FillRand(int* arr, int n, int min, int max);
void FillGrow(double* arr, int length, double min, double max);
void FillGrow(int* arr, int length, int min, int max);
void FillFall(double* arr, int length, double min, double max);
void FillFall(int* arr, int length, int min, int max);
void Writer(int* A, int length);
void Writer(double* A, int length);

ofstream File("C:\\Users\\bokar\\Documents\\operation.txt");


void FillSaw(double* arr, int n, double min, double max, double period) {
    period = max;
    for (int i = 0; i < n; i++) {
        arr[i] = fmod(i * period / 10.1, max - min) + min;
    }
    File << "Пилообразная последовательность дробных чисел" << endl;
    Writer(arr, n);
}
void FillSin(double* arr, int n, double min, double max, double period) {
    float k = period / (2 * PI);

    for (int i = 0; i < n; i++) {
        double res =  min + max / 2 * sin(4 * 3.14159265 * ((float)i / (float)n) + 2 * PI * k);
        arr[i] = res;
    }
    File << "Синусообразная последовательность дробных чисел" << endl;
    Writer(arr, n);
}


void FillStep(double* arr, int n, double min, double max, double period) {
    period = 3;
    double u = 0.0;
    for (int i = 0; i < n; i++) {

        arr[i] = min + double((double)(i) / period) - 0.3 * (fmod(i, period));
        u += 1.0;
        if (u == 2.0) u = 0.0;

    }
    File << "Ступенчатая последовательность дробных чисел" << endl;
    Writer(arr, n);
}

void FillRand(double* arr, int n, double min, double max) {
    for (int i = 0; i < n; i++) {

        arr[i] = 10 + ((double)rand() / RAND_MAX) * (max - min);
    }
    File << "Рандомная последовательность дробных чисел" << endl;
    Writer(arr, n);
}

void FillRand(int* arr, int n, int min, int max) {

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (int)max + min;
    }
    File << "Рандомная последовательность целых чисел" << endl;
    Writer(arr, n);
}

void FillGrow(double* arr, int length, double min, double max) {
    double step = (double)((max - min) / (double)length);
    
    for (int i = length; i > 0; i--) {
        arr[length - i] = (double)((double)max - (double)step * i);
    }
    File << "Возрастающая последовательность дробных чисел" << endl;
    Writer(arr, length);
}

void FillFall(double* arr, int length, double min, double max) {
    
    double step = (double)((max - min) / (double)length);
    
    for (int i = 0; i < length; i++) {
        arr[i] = (double)((double)max - (double)step * i);
    }
    File << "Убывающая последовательность дробных чисел" << endl;
    Writer(arr, length);
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;
    
    for (int i = 0; i < length; i++) {

        arr[i] = min + step * i;
    
    }
    File << "Возрастающая последовательность целых чисел" << endl;
    Writer(arr, length);
}

void FillFall(int* arr, int length, int min, int max) {

    int step = 1 + (max - min) / length;;
    for (int i = 0; i < length; i++) {

        arr[i] = max - step * i;
        
    }
    File << "Убывающая последовательность целых чисел" << endl;
    Writer(arr, length);
}
void FillSaw(int* arr, int length, int min, int max, int period) {
    
    int temp = min;
    for (int i = 0; i < length; i++) {
        //A[i] = (((length / 50000) * i) % (max - min)) + min;
        if (temp == max)  temp = min;
        arr[i] = temp;
        temp++;
    }
    File << "Пилообразная последовательность целых чисел" << endl;
    Writer(arr, length);
}

void FillSin(int* arr, int length, int min, int max, int period) {

    float k = period / (2 * PI);

    for (int i = 0; i < length; i++) {
        int res = min + max * sin(4 * 3.14159265 * ((float)i / (float)length) + 2 * PI * k);

        arr[i] = res;
    }
    File << "Синусообразная последовательность целых чисел" << endl;
    Writer(arr, length);

}

void FillStep(int* arr, int length, int min, int max, int period) {

    for (int i = 0; i < length; i++) {
        arr[i] = min + i / period;
        
    }
    File << "Ступечтая последовательность целых чисел" << endl;
    Writer(arr, length);
}
void Writer(int* A, int length) {
    /*for (int i = 0; i < length; i++) {
        printf("%3.3i\n", A[i]);
        //cout << "arr[" << i << "] = \t" << A[i] << endl;
        File << "arr[" << i << "] = \t" << A[i] << endl;
    }*/
}
void Writer(double* A, int length) {
    /*for (int i = 0; i < length; i++) {

        printf("%3.3f\n", A[i]);
        //cout << "arr[" << i << "] = \t" << A[i] << endl;
        File << "ar r[" << i << "] = \t" << A[i] << endl;
    }*/
}
int main()
{
    

    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: ";
    cin >> n;
    double* arrFill = new double[n];

    void (*LineralOperations[3])(double*, int, double, double) = { FillRand, FillGrow, FillFall};
    void (*OrderDoubleOperations[3])(double*, int, double, double, double) = { FillSaw, FillSin, FillStep };
    void (*LineralIntegerOperations[3])(int*, int, int, int) = { FillRand, FillGrow, FillFall };
    void (*OrderIntegerOperations[3])(int*, int, int, int, int) = {  FillSaw, FillSin, FillStep };

    
    
    // получаем длину массива
    int lengthLin = sizeof(LineralOperations) / sizeof(LineralOperations[0]);

    for (int i = 0; i < lengthLin; i++)
    {
        auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

        LineralOperations[i](arrFill, n, 10, 20);    // вызов функции по указателю
        auto end = chrono::steady_clock::now();
        // получаем время по окончанию формирования последовательности
        auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
        // получаем время работы в микросекундах
        cout <<  elapsed_ms.count() << endl;

    }
    for (int i = 0; i < lengthLin; i++)
    {
        auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

        OrderDoubleOperations[i](arrFill, n, 10, 15, 10);    // вызов функции по указателю
        auto end = chrono::steady_clock::now();
        // получаем время по окончанию формирования последовательности
        auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
        // получаем время работы в микросекундах
        cout << elapsed_ms.count() <<  endl;

    }

    int* Arr = new int[n];

    for (int i = 0; i < lengthLin; i++)
    {
        auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

        LineralIntegerOperations[i](Arr, n, 10, 20);    // вызов функции по указателю
        auto end = chrono::steady_clock::now();
        // получаем время по окончанию формирования последовательности
        auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
        // получаем время работы в микросекундах
        cout <<  elapsed_ms.count() <<  endl;

    }
    for (int i = 0; i < lengthLin; i++)
    {
        auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

        OrderIntegerOperations[i](Arr, n, 10, 20, 10);    // вызов функции по указателю
        auto end = chrono::steady_clock::now();
        // получаем время по окончанию формирования последовательности
        auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
        // получаем время работы в микросекундах
        cout <<  elapsed_ms.count() << endl;

    }
    
    //delete [] Arr; почему-то не работает надо сделать
    //delete [] ArrFill; почему-то не работает надо подправить
    
    File.close();

    return 0;
}

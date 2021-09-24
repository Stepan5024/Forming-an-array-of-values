// Лабораторная работа №1 
// Выполнили студенты группы м3о-219Бк-20 Бокарев С.М. Катвалян А.А.

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <math.h>
#include <chrono> 

#define PI 3.14159265

using namespace std;

void FillSaw(double* arr, int n, int min, int max);
void FillSaw(int* arr, int length, int min, int max);
void FillSin(double* arr, int n, int min, int max);
void FillSin(int* arr, int length, int min, int max);
void FillStep(double* arr, int n, double min, double max);
void FillQuasi(double* arr, int n, int min, int max);
void FillRand(double* arr, int n, int min, int max);
void FillGrow(double* arr, int length, int min, int max);
void FillGrow(int* arr, int length, int min, int max);
void FillFall(double* arr, int length, int min, int max);
void FillFall(int* arr, int length, int min, int max);
void Writer(int* A, int length);
void Writer(double* A, int length);

ofstream File("C:\\Users\\bokar\\Documents\\operation.txt");



void FillSaw(double* arr, int n, double min, double max) {

    for (int i = 0; i < n; i++) {
        arr[i] = fmod( i * max / 10.1, max - min) + min;
        
        
    }


}
void FillSin(double* arr, int n, int min, int max) {
    /*for (int i = 0; i < n; i++) {
        double res = sin(4 * PI * ((float)i / (float) n));
        res += 1.0;
        res /= 2.0;
        res += (max - min);
        arr[i] = res;

    }*/
    
    for (int i = 0; i < n; i++) {
        double res = 20 * sin(4 * 3.14159265 * ((float)i / (float)n));

        arr[i] = res;
    }
}

void FillStep(double* arr, int n, double min, double max) {
    

    double u = 0.0;
    for (int i = 0; i < n; i++) {

        arr[i] = min + double((double)(i ) / 3.0) - 0.3 * (double)(i % 3);
        u += 1.0;
        if (u == 2.0) u = 0.0;
        
    }

}



void FillRand(double* arr, int n, int min, int max) {

    
    for (int i = 0; i < n; i++) {

        double ret = 10 + ((double)rand() / RAND_MAX) * (max - min);

        arr[i] = ret;
       
    }

}

void FillRand(int* arr, int n, int min, int max) {

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max + min;
    }

}
void FillGrow(double* arr, int length, int min, int max) {
    double step = (double)((max - min) / (double)length);
    
    for (int i = length; i > 0; i--) {

        arr[length - i] = (double)((double)max - (double)step * i);
       
    }

}

void FillFall(double* arr, int length, int min, int max) {
    
    double step = (double)((max - min) / (double)length);
    
    for (int i = 0; i < length; i++) {

        arr[i] = (double)((double)max - (double)step * i);
        
    }
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;
    
    for (int i = 0; i < length; i++) {

        arr[i] = min + step * i;
    
    }

}

void FillFall(int* arr, int length, int min, int max) {

    int step = 1 + (max - min) / length;;
    for (int i = 0; i < length; i++) {

        arr[i] = max - step * i;
        
    }
}
void FillSaw(int* arr, int length, int min, int max) {
    int temp = min;
    for (int i = 0; i < length; i++) {
        //A[i] = (((length / 20) * i) % (max - min)) + min;
        if (temp == max)  temp = min;
        arr[i] = temp;
        temp++;
    }
}

void FillSin(int* arr, int length, int min, int max) {
    for (int i = 0; i < length; i++) {
        int res = 20 * sin(4 * 3.14159265 * ((float)i / (float)length));
        
        arr[i] = int(res);
    }
}

void FillStep(int* arr, int length, int min, int max) {
    for (int i = 0; i < length; i++) {
        arr[i] = min + i / 3;
        //arr[i] = i - (i % (length / 10));
    }
}
void Writer(int* A, int length) {
    for (int i = 0; i < length; i++) {
        printf("%3.3i\n", A[i]);
        //cout << "arr[" << i << "] = \t" << A[i] << endl;
        File << "arr[" << i << "] = \t" << A[i] << endl;
    }
}
void Writer(double* A, int length) {
    for (int i = 0; i < length; i++) {

        printf("%3.3f\n", A[i]);
        //cout << "arr[" << i << "] = \t" << A[i] << endl;
        File << "arr[" << i << "] = \t" << A[i] << endl;
    }
}
int main()
{
    

    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: ";
    cin >> n;
    double* arrFill = new double[n];

    auto begin = chrono::steady_clock::now();
    // получаем время перед началом формирования последовательности
    
    FillRand(arrFill, n, 10, 20);
    cout << "Рандомная последовательность дробных чисел" << endl;
    File << "Рандомная последовательность дробных чисел" << endl;
    Writer(arrFill, n);

    FillGrow(arrFill, n, 10, 20);
    cout << "Возрастающая последовательность дробных чисел" << endl;
    File << "Возрастающая последовательность дробных чисел" << endl;
    Writer(arrFill, n);


    FillFall(arrFill, n, 10, 20);
    cout << "Убывающая последовательность дробных чисел" << endl;
    File << "Убывающая последовательность дробных чисел" << endl;
    Writer(arrFill, n);


    FillSaw(arrFill, n, 10.0, 20.0);
    cout << "Пилообразная последовательность дробных чисел" << endl;
    File << "Пилообразная последовательность дробных чисел" << endl;
    Writer(arrFill, n);

    FillSin(arrFill, n, 10.0, 20.0);
    cout << "Синусообразная последовательность дробных чисел" << endl;
    File << "Синусообразная последовательность дробных чисел" << endl;
    Writer(arrFill, n);

    FillStep(arrFill, n, 10.0, 20.0);
    cout << "Ступенчатая последовательность дробных чисел" << endl;
    File << "Ступенчатая последовательность дробных чисел" << endl;
    Writer(arrFill, n);

    //delete[] arrFill;

    int* Arr = new int[n];

    FillRand(Arr, n, 10, 20);
    cout << "Рандомная последовательность целых чисел" << endl;
    File << "Рандомная последовательность целых чисел" << endl;
    Writer(Arr, n);


    FillGrow(Arr, n, 10, 120);
    cout << "Возрастающая последовательность целых чисел" << endl;
    File << "Возрастающая последовательность целых чисел" << endl;
    Writer(&Arr[0], n);

    FillFall(Arr, n, 10, 120);
    cout << "Убывающая последовательность целых чисел" << endl;
    File << "Убывающая последовательность целых чисел" << endl;
    Writer(&Arr[0], n);

    FillSaw(Arr, n, 10, 20);
    cout << "Пилообразная последовательность целых чисел" << endl;
    File << "Пилообразная последовательность целых чисел" << endl;
    Writer(&Arr[0], n);


    FillSin(&Arr[0], n, 10, 20);
    cout << "Синусообразная последовательность целых чисел" << endl;
    Writer(&Arr[0], n);


    FillStep(&Arr[0], n, 10, 20);
    cout << "Ступенчатая последовательность целых чисел" << endl;
    Writer(&Arr[0], n);


    //delete [] Arr; почему-то не работает надо сделать
    //delete [] ArrFill; почему-то не работает надо подправить
    
    auto end = chrono::steady_clock::now();
    // получаем время по окончанию формирования последовательности
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
    // получаем время работы в микросекундах
    cout << "Время работы алгоритма по формированию последовательности: " << elapsed_ms.count() << " (мкС)" << endl;
    // вывод времени работы 


    File.close();

    return 0;
}

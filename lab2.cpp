#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;
using time_mngr = time_point<steady_clock, duration<__int64_t, ratio<1, 1000000000>>>;

int findPivot(int arr[], int min, int max) {
    int pivot = min -1;
    for (int i = min; i < max; ++i){
        if(arr[i] < arr[max]) {
            pivot++;
            swap(arr[i], arr[pivot]);
        }
    }
    pivot++;
    swap(arr[pivot], arr[max]);
    return pivot;
}

void quickSort(int arr[], int min, int max) {
    if (min >= max) {
        return;
    }
    int pivot = findPivot(arr, min, max);
    quickSort(arr, min, pivot - 1);
    quickSort(arr, pivot + 1, max);
}

int rightBorder(int arr[], int value, int low, int mid, int high) {
    while ((high - low) > 1) {
        mid = (low + high) / 2;
        if (value >= arr[mid]) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}


int leftBorder(int arr[], int value, int low, int mid, int high) {
    while ((high - low) > 1) {
        mid = (low + high) / 2;
        if (value <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return high;
}

int findElement(int arr[], int n, int value) {
    for (int i = 0; i < n; ++i) {
        if (value == arr[i]) {
            return 1;
        }
    }
    return 0;

}
int binSearch(int arr[], int value, const int len) {
    int low = 0;
    int high = len - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (value == arr[mid]) {
            return mid;
        }
        else if (value > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
//Уменьшите каждый четный элемент на значение, введенное пользовате-лем. Каждый четный элемент умножьте на случайную величину в диапазоне от 1 до 9.
// Выведите на экран сколько четных элементов, которые имеют четные значения, сколько нечетных элементов имеют нечетные значения.
// Выведите количество элементов, которые нацело делятся на 1, 2, 3, 4, 5, 6, 7, 8, 9
void idz5(int arr[], int len, int num) {
    for (int i = 1; i < len; i += 2) {
        if (i % 2) {
            arr[i] -= num;
            arr[i] *= rand() % 9 + 1;
        }
    }
    for (int i = 0; i < len; ++i) {
        cout << " " << arr[i];
    }
    for (int j = 1; j < 10; ++j) {
        cout << "Элементы, кратные " << j << ": ";
        for (int i = 0; i < len; ++i) {
            if (!(arr[i] % j)) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }
}
//-----------------------------------------------------------------------

void randomMassive(int arr[], const int n)
{
    setlocale(LC_ALL, "ru");
    cin.sync();
    cin.clear();
    time_mngr start, end;
    nanoseconds result;
    //1 TASK
    for(int i = 0; i < n; ++i){
        arr[i]=rand()%200-99;
    }
    cout << "НЕОТСОРТИРОВАННЫЙ массив :" << arr[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << arr[i];
    }
    cout << "\n";
    //3 TASK
    start = steady_clock::now();
    int mx = arr[0];
    int mn = arr[0];

    for (int i = 1; i < n; ++i) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    end = steady_clock::now();
    cout << "min: " << mn << ", max: " << mx;
    cout << "\n";
    result = end - start;
    cout << "Поиск max и min в неотсортированном массиве заняла " << result.count() << " наносекунд\n";
    quickSort(arr, 0, n - 1);
}


// ----------------------------------------------------------------------
void sortedMassive(int arr[], const int n){
    int a,b;
    int avg;
    int index;
    int idz;
    int low, mid = 0, high, l_border, r_border;
    int index1, index2;
    time_mngr start, end;
    nanoseconds result;
    cout<<"-------------------------------------------------------------------------------------------\n";
    //2 TASK
    start = steady_clock::now();
    quickSort(arr, 0, n - 1);
    end = steady_clock::now();
    result = end - start;
    cout << "ОТСОРТИРОВАННЫЙ массив :" << arr[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << arr[i];
    }
    cout << "\n";
    cout << "Сортировка заняла " << result.count() << " наносекунд";
    cout << "\n";
    //3 TASK
    start = steady_clock::now();
    int mx =arr[n - 1];
    int mn =arr[0];
    end = steady_clock::now();
    result = end - start;
    cout << "min: " << mn << ", max: " << mx;
    cout << "\n";
    cout << "Поиск max и min значений отсортированного массива занял " << result.count() << " наносекунд\n";
    //4 TASK
    avg = round((mx + mn) / 2.0);
    cout << "\nCреднее значение максимального и минимального значения : " << avg<< "\n";
    if (binSearch(arr, avg, n) == -1) {
        cout << "Такого элемента нет в массиве";
    }
    else {
        high = n - 1;
        l_border = leftBorder(arr, avg, low, mid, high);
        r_border = rightBorder(arr, avg, low, mid, high);
        cout << "В массиве " << r_border - l_border + 1 << " элементов равных среднему значению" << "\n";
        cout << "Индексы элементов: ";
        for (int i = l_border; i <= r_border; ++i) {
            cout << i << " ";
        }
    }
    cout << "\n";
    //5 TASK
    cout<< "\nВведите значение а, чтобы посмотреть количество элементов\n";
    cout<< "в отсортированном массиве, которые МЕНЬШЕ этого числа :\n";
    cin >> a;
    low = 0;
    high = n - 1;
    l_border = leftBorder(arr, a, low, mid, high);
    cout << l_border << " элементов, меньших " << a << "\n";
    //6 TASK
    cout<< "\nВведите значение b, чтобы посмотреть количество элементов\n";
    cout<< "в отсортированном массиве, которые БОЛЬШЕ этого числа :\n";
    cin >> b;
    low = 0;
    high = n - 1;
    r_border = rightBorder(arr, b, low, mid, high);
    cout << n - 1 - r_border << " элементов, больших " << b << "\n";
    //7 TASK
    start = steady_clock::now();
    findElement(arr, n, a);
    end = steady_clock::now();
    result = end - start;
    cout << "Обычный перебор прошел за " << result.count() << " наносекунд\n";
    start = steady_clock::now();
    index = binSearch(arr, b, n);
    end = steady_clock::now();
    result = end - start;
    if (index == -1) {
        cout << "Числа " << b << " нет в массиве\n";
    }
    else {
        cout << "Число " << arr[index] << " находится под индексом " << index << "\n";
    }
    cout << "Бинарный поиск прошел за " << result.count() << " наносекунд\n";
    //8 TASK
    cout << "\nВводите индексы элементов(от 0 до 99), которые хотите поменять местами (Вводить попарно и через пробел):\n";
    cin >> index1 >> index2;
    start = steady_clock::now();
    swap(arr[index1], arr[index2]);
    end = steady_clock::now();
    cout << "Замена прошла за " << (end - start).count() << " наносекунд\n";

    cout << "МАССИВ С ИЗМЕНЕННЫМИ ИНДЕКСАМИ:";
    for (int i = 0; i < n; ++i) {
        cout << " " << arr[i];
    }
    cout << "\n";
    cout << "\nВведите число, на которое хотитете уменьшить каждый нечетный элемент: ";
    cin >> idz;
    idz5(arr, n, idz);
}


//---------------------------------------------------------------------------
int main2(){
    const int n = 100;
    int arr[n];
    randomMassive(arr, n);
    sortedMassive(arr, n);
}


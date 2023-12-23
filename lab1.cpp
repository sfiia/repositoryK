#include <iostream>
using namespace std;


void firstTask() {
    cout << "Size of Data Types: \n"
         << "\tint: " << sizeof(int) << "\n"
         << "\tshort int: " << sizeof(short int) << "\n"
         << "\tlong int: " << sizeof(long int) << "\n"
         << "\tfloat: " << sizeof(float) << "\n"
         << "\tdouble: " << sizeof(double) << "\n"
         << "\tlong double: " << sizeof(long double) << "\n"
         << "\tchar: " << sizeof(char) << "\n"
         << "\tbool: " << sizeof(bool) << "\n";
}


void secondTask() {
    int n, order;
    int long unsigned mask;

    cout << "Enter an integer: ";
    cin >> n;

    order = sizeof(n) * 8 - 1;
    mask =  1ULL << order;
    for (int i = 0; i <= order; i++) {
        putchar((n & mask) ? '1' : '0');
        if ((i + 1) % 8 == 0 || i == 0) {
            putchar(32);
        }
        mask >>= 1;
    }

    char command[1000];
    cout << "\n" << "Do you want to transfer bits?(y / n): ";
    cin >> command;

    switch (command[0]) {
        case 'y':
            int perenos;
            cout << "Enter the number of transfer: ";
            cin >> perenos;
            order = sizeof(int) * 8 - 1;
            mask = 1ULL << (order - perenos);
            for (int i = 0; i <= order; i++) {
                cout << ((n & mask) ? "1" : "0");
                mask = mask >> 1;
                if (!i) {
                    cout << " ";
                }
                if ((i + 1) % 8 == 0) {
                    cout << " ";
                }
            }

            cout << "\n";

            break;

        case 'n':
            break;
    }

}


void thirdTask() {
    union {
        int tool;
        float n;
    };

    cout << "Enter a single precision real number: ";
    cin >> n;

    int order = sizeof(int) * 8 - 1;
    int unsigned mask = 1 << order;

    for (int i = 0; i <= order; i++) {
        putchar((tool & mask) ? '1' : '0');
        if (i == 0 || i == 8) {
            putchar(32);
        }
        mask >>= 1;
    }
    char command[1000];
    cout << "\n" << "Do you want to transfer bits?(y / n): ";
    cin >> command;

    switch (command[0]) {
        case 'y':
            int perenos;
            cout << "Enter the number of transfer: ";
            cin >> perenos;
            order = sizeof(int) * 8 - 1;
            mask = 1ULL << (order - perenos);
            for (int i = 0; i <= order; i++) {
                cout << ((tool & mask) ? "1" : "0");
                mask = mask >> 1;
                if (!i) {
                    cout << " ";
                }
                if ((i + 1) % 8 == 0) {
                    cout << " ";
                }
            }

            cout << "\n";

            break;

        case 'n':
            break;
    }

}


void fourthTask() {
    union {
        double n;
        int arr[2];
    };

    cout << "Enter a double precision real number: ";
    cin >> n;

    int order = sizeof(double) * 8 - 1;
    long long int unsigned mask = 1ULL << order - 32;

    for (int i = 0; i <= order / 2; i++) {
        putchar((arr[1] & mask) ? '1' : '0');
        mask >>= 1;
        if (i == 0 || i == 11) {
            putchar(32);
        }
    }

    mask = 1ULL << order;

    for (int i = order / 2 + 1; i <= order; i++) {
        putchar((arr[0] & mask) ? '1' : '0');
        mask >>= 1;
    }

    char command[1000];
    cout << "\n" << "Do you want to transfer bits?(y / n): ";
    cin >> command;

    switch (command[0]) {
        case 'y':
            int perenos;
            cout << "Enter the number of transfer: ";
            cin >> perenos;
            order = sizeof(int) * 8 - 1;
            mask = 1ULL << (order - perenos);
            for (int i = 0; i <= order; i++) {
                cout << ((arr[2] & mask) ? "1" : "0");
                mask = mask >> 1;
                if (!i) {
                    cout << " ";
                }
                if ((i + 1) % 8 == 0) {
                    cout << " ";
                }
            }

            cout << "\n";

            break;

        case 'n':
            break;
    }

}



int main1() {
    setlocale(LC_ALL, "Russian");

    firstTask();

    do {
        char dataType[1000];
        cout << "\nEnter the data type(i / f / d) or 'e' to exit: ";
        cin >> dataType;

        if (dataType[1] == NULL) {
            switch (dataType[0]) {
                case 'i':
                    secondTask();
                    break;
                case 'f':
                    thirdTask();
                    break;
                case 'd':
                    fourthTask();
                    break;
            }

            if (dataType[0] == 'e') {
                break;
            }
        }


    } while (true);

    return 0;
}

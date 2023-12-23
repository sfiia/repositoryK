#include <iostream>
#include "main.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    bool task = true;
    int choose = 0;

    while (choose != -1){
        cout << "\n\n\nВВедите номер лабораторной работы, котороую хотите выполнить: \n"
                "1 лабораторная работа.\n"
                "2 лабораторная работа.\n"
                "3 лабораторная работа.\n"
                "4 лабораторая работа.\n\n\n";

        cout << "Номер задания: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 )
            cout << "Такого варианта ответа нет \n";

        else
            switch (choose){

                case 1:
                    main1();
                    break;

                case 2:
                    main2();
                    break;

                case 3:
                    main3();
                    break;

                case 4:{
                    main4();
                    break;
                }
            }
    }
    return 0;
}

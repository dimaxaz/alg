#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

void saveToFile(const std::string& filename, int* array, int size) {
    std::ofstream file(filename);
    for (int i = 0; i < size; ++i) {
        file << array[i] << " ";
    }
    file.close();
}

void selectionSort(int* array, int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        int minMaxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (ascending ? array[j] < array[minMaxIndex] : array[j] > array[minMaxIndex]) {
                minMaxIndex = j;
            }
        }
        int temp = array[minMaxIndex];
        array[minMaxIndex] = array[i];
        array[i] = temp;
    }
}

void randomFillArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() - rand(); 
    }
}

void manualFillArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> array[i];
    }
}

void printMenu() {
    std::cout << "\t    +Меню программы+\n" << std::endl;
    std::cout << "______________***********______________\n\n\n";
    std::cout << "1 - Сортировка по возрастанию" << std::endl;
    std::cout << "2 - Сортировка по убыванию" << std::endl;
    std::cout << "3 - Ввести количество элементов массива" << std::endl;
    std::cout << "4 - Заполнить массив вручную" << std::endl;
    std::cout << "5 - Заполнить массив случайными числами" << std::endl;
    std::cout << "6 - Выйти\n\n" << std::endl;
    std::cout << "______________***********______________\n\n\n";
    std::cout << "Выберите желаемую опцию : ";
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    int size = 0;
    int* array = nullptr;

    bool running = true;
    while (running) {
        printMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
        case 2: {
            bool ascending = (choice == 1);
            if (array == nullptr) {
                std::cout << "Сначала создайте массив и заполните его значениями.\n" << std::endl;
                std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
                _getch();
                system("cls");
                break;
            }
            saveToFile("original_array.txt", array, size);
            std::cout << "Исходный массив сохранен в original_array.txt\n";
            selectionSort(array, size, ascending);
            saveToFile("sorted_array.txt", array, size);
            std::cout << "Массив отсортирован и сохранен в sorted_array.txt\n" << std::endl;
            std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
            _getch();
            system("cls");
            break;
        }
        case 3: {
            std::cout << "Введите количество элементов массива: ";
            std::cin >> size;

            delete[] array;
            array = new int[size];
            std::cout << "Создан массив из " << size << " элементов.\n" << std::endl;
            std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
            _getch();
            system("cls");
            break;
        }
        case 4: {
            if (array == nullptr) {
                std::cout << "Сначала создайте массив, задав количество элементов.\n" << std::endl;
                std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
                _getch();
                system("cls");
                break;
            }
            manualFillArray(array, size);
            std::cout << "Массив заполнен вручную.\n" << std::endl;
            std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
            _getch();
            system("cls");
            break;
        }
        case 5: {
            if (array == nullptr) {
                std::cout << "Сначала создайте массив, задав количество элементов.\n" << std::endl;
                std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
                _getch();
                system("cls");
                break;
            }
            randomFillArray(array, size);
            std::cout << "Массив заполнен случайными значениями.\n" << std::endl;
            std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
            _getch();
            system("cls");
            break;
        }
        case 6:
            running = false;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n" << std::endl;
            std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
            _getch();
            system("cls");
        }
    }

    delete[] array; // Освобождение выделенной памяти
    return 0;
}

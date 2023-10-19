//
// Created by radom on 18.10.2023.
//

#include <fstream>
#include "Test.h"
#include "algoritgms/BruteForce.h"

Test::Test() {
    bool running = true;
    do {
        cout << "Co chcesz zrobić?\n" <<
             "1.Wczytanie danych z pliku\n" <<
             "2.Wygenerowanie danych losowych\n" <<
             "3.Wyświetlenie ostatnio wczytanych lub wygenerowanych danych\n" <<
             "4.Uruchomienie danego algorytmu dla ostatnio wczytanych lub wygenerowanych danych i wyświetlenie wyników\n"
             <<
             "0.Wyjście" << endl;
//
        int choice;
        cin >> choice;

        string path;
        switch (choice) {
            case 1:
                deleteMatrix();
                cout << "Podaj ścieżkę absolutną do pliku txt"<<endl;
                cin >> path;
                readFromFile(path);
                break;
            case 2:
                deleteMatrix();

                cout << "Podaj liczbe wierzchołków" << endl;
                cin >> matrixSize;
                cout << "Podaj maksymalną długość ścieżek" << endl;
                int maxLen;
                cin >> maxLen;
                generateData(maxLen);
                break;
            case 3:
                printMatrix();
                break;
            case 4:
                cout << "Wybierz algorytm:\n" <<
                     "1.Przegląd zupełny\n" <<
                     "0.Wyjście" << endl;

                int alg;
                cin >> alg;
                runAlgorithm(alg);
                break;
            default:
                running = false;


        }
    } while (running);
}


Test::~Test() {
    deleteMatrix();
}


void Test::readFromFile(std::string path) {
    // Otwórz plik
    ifstream file(path);

    // Sprawdź, czy udało się otworzyć plik
    if (!file.is_open()) {
        cout << "Nie można otworzyc." << endl;
    }

    // Zmienna przechowująca wartość wczytaną z pliku
    int wartoscZPliku;

    // Wyczyść flagi błędów i pozycję odczytu pliku
    file.clear();
    file.seekg(0, ios::beg);

    int i = 0;
    int j = 0;
    while (file >> wartoscZPliku) {
//        cout << wartoscZPliku<< endl;

        if (i == 0) {
            //tworzenie tabeli ścieżek
            matrixSize = wartoscZPliku;
            matrix = new int *[matrixSize]; // Deklaracja tablicy wskaźników na wskaźniki do int

            for (int i = 0; i < matrixSize; ++i) {
                matrix[i] = new int[matrixSize]; // Alokacja pamięci dla każdego wiersza
            }

        } else {
            if (i > matrixSize) {
                j += 1;
                i = 1;
            }


            matrix[j][i - 1] = wartoscZPliku;

        }

        i++;
    }

    file.close();

}


void Test::generateData(int maxLen) {
    matrix = new int *[matrixSize]; // Deklaracja tablicy wskaźników na wskaźniki do int

    for (int i = 0; i < matrixSize; ++i) {
        matrix[i] = new int[matrixSize]; // Alokacja pamięci dla każdego wiersza
    }


    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i == j) {
                matrix[i][j] = -1;
                continue;
            }
            int newEdge = rand() % maxLen;
            if (newEdge == 0) {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = newEdge;
            }

        }

    }

}


void Test::runAlgorithm(int alg) {

    if (alg == 1) {
        BruteForce* bruteForce = new BruteForce(matrix, matrixSize);

        time.start();
        bruteForce->start();
        time.stop();

        cout << "\nNajkrótsza ścieżka: ";
        int* minPath = bruteForce->getMinPath();
        for (int i=0; i<matrixSize; i++) {
            cout << minPath[i] << ", ";
        }
        cout << " ma długość: " << bruteForce->getMinLenght() << endl;
        cout << "Czas wykonania algorytmu to: " << time.getTime() << "ms\n" << endl;

        delete bruteForce;
    }
}


void Test::printMatrix() {
    if(matrixSize==0){
        cout<<"Tablica jest pusta"<<endl;
        return;
    }
    cout << "Tabela sąsiedstwa z wagami:" << endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Rozmiar grafu: " << matrixSize << endl;
}


void  Test::deleteMatrix() {
    if(matrixSize!=0 ) {
        for (int i = 0; i < matrixSize; i++) {
            delete[] matrix[i];
        }

        matrixSize = 0;

    }
}
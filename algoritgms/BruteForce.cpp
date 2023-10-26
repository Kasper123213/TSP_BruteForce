//
// Created by radom on 18.10.2023.
//

#include<iostream>
#include "BruteForce.h"

using namespace std;
//Konstruktor klasy jako argumenty przyjmuje wskaznik na macierz i jej rozmiar. tworzy też zmienne w których przechowywał
//będzie najkrótszą znalezioną ścieżkę oraz jej długość. Wartość -1 długości oznacza, że graf nie posiada cyklu hamiltona
BruteForce::BruteForce(int **matrix, int matrixSize) {
    this->matrix = matrix;
    this->matrixSize = matrixSize;
    minPath = new int[matrixSize + 1];
    minLenght = -1;

}

//Destruktor klasy zwalnie pamięć zmiennych klasy BruteForce
BruteForce::~BruteForce() {
    delete[] minPath;
}

// metoda start uruchamia algorytm brute force
void BruteForce::start() {
    //zabezpieczenie na wypadek gdyby graf miał tylko jeden wierzchołek
    if(matrixSize==1){
        minLenght = 0;
        minPath[0] = 0;
        minPath[matrixSize] = 0;
        return;
    }
    int *arr = new int[matrixSize];

    //Wypełnienie tablicy roboczej kolejnymi indeksami wierzchołków grafu
    for (int i = 0; i < matrixSize; i++) {
        arr[i] = i;
    }

    //Wyliczamy wszystkie permutacje ułożenia wierzchołków tak aby pierwszy i ostatni wierzchołek zawsze były "0"
    perm(arr);
    //ustawiamy ostatni wierzchołek na ten sam co pierwszy czyli na 0;
    minPath[matrixSize] = minPath[0];
    //zwalniamy pamięć tablicy roboczej
    delete[] arr;
}


void BruteForce::perm(int *numbers) {
    perm(numbers, 0);
}

//liczenie kolejnych permutacji
void BruteForce::perm(int *numbers, int index) {
    int n = matrixSize;
    //
    if (index == n) {
        checkPath(numbers);
        return;
    }

    //funkcja rekurencyjnie zmienia kolejność odpowiednich elementów tablicy tak aby otrzymać wszystkie możliwe permutacje
    for (int i = index; i < n; i++) {
        //jeśli zmienil sie pierwszy element konczymy poszukiwania permutacji. Ten zabieg przyspiesza algorytm o n wierzchołkach około n-krotnie
        if(numbers[0] >0) return;
        swap(numbers, index, i);
        perm(numbers, index + 1);
        swap(numbers, index, i);
    }
}

//metoda zamienie miejscami dwa elementy tablicy
void BruteForce::swap(int *numbers, int i, int j) {
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}

//sprawdzanie czy ścieżka jest krótsza, jeśli tak to zapisujemy ją oraz jej długość
void BruteForce::checkPath(int *arr) {
    int pathLenght = 0;
    int currentCity;
    int nextCity;

    //sprawdzanie czy sciezką da sie przejść
    for (int index = 0; index < matrixSize - 1; index++) {
        currentCity = arr[index];
        nextCity = arr[index + 1];

        //liczenie długości tej ścieżki
        if (matrix[currentCity][nextCity] != -1) {
            pathLenght += matrix[currentCity][nextCity];
        } else {
            return;
        }
    }

    currentCity = arr[matrixSize - 1];
    nextCity = arr[0];
    //dodawanieostatniej krwędzi (do wierzchołka 0)
    if (matrix[currentCity][nextCity] != -1) {
        pathLenght += matrix[currentCity][nextCity];
    } else {
        return;
    }

    //jeśli ścieżka krótsza od poprzedniej zapisanej to zapamiętujemy ją
    if (pathLenght < minLenght or minLenght < 0) {
        minLenght = pathLenght;

        for(int i=0; i<matrixSize; i++){
            minPath[i] = arr[i];
        }

    }
}

//zwracanie minimalnej długości
int BruteForce::getMinLenght() {
    return minLenght;
}

//zwracanie minimalnej scieki
int *BruteForce::getMinPath() {
    return minPath;
}
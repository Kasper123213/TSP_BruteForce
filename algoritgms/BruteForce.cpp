//
// Created by radom on 18.10.2023.
//

#include<iostream>
#include "BruteForce.h"

using namespace std;

BruteForce::BruteForce(int **matrix, int matrixSize) {
    this->matrix = matrix;
    this->matrixSize = matrixSize;
    minPath = new int[matrixSize];

}


BruteForce::~BruteForce() {
    delete[] minPath;
}


void BruteForce::start() {
    if(matrixSize==1){
        minLenght = 0;
        minPath[0] = 0;
        return;
    }
    int *arr = new int[matrixSize];

    for (int i = 0; i < matrixSize; i++) {
        arr[i] = i;
    }

    perm(arr);
    delete[] arr;
}


void BruteForce::perm(int *numbers) {
    perm(numbers, 0);
}


void BruteForce::perm(int *numbers, int index) {
    int n = matrixSize;
    if (index == n) {
        checkPath(numbers);
        return;
    }

    for (int i = index; i < n; i++) {
        if(numbers[0] >0) return;
        swap(numbers, index, i);
        perm(numbers, index + 1);
        swap(numbers, index, i);
    }
}


void BruteForce::swap(int *numbers, int i, int j) {
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}


void BruteForce::checkPath(int *arr) {//todo jesli niema cyklu hamiltona to napisac to
    int pathLenght = 0;
    int currentCity;
    int nextCity;

    for (int index = 0; index < matrixSize - 1; index++) {
        currentCity = arr[index];
        nextCity = arr[index + 1];

        if (matrix[currentCity][nextCity] != -1) {
            pathLenght += matrix[currentCity][nextCity];
//            minPath[index] = arr[index];
        } else {
            return;
        }
    }

    currentCity = arr[matrixSize - 1];
    nextCity = arr[0];
    if (matrix[currentCity][nextCity] != -1) {
        pathLenght += matrix[currentCity][nextCity];
//        minPath[matrixSize-1] = currentCity;
    } else {
        return;
    }


    if (pathLenght < minLenght or minLenght < 0) {
        minLenght = pathLenght;

        for(int i=0; i<matrixSize; i++){
            minPath[i] = arr[i];
        }

    }
}


int BruteForce::getMinLenght() {
    return minLenght;
}


int *BruteForce::getMinPath() {
    return minPath;
}

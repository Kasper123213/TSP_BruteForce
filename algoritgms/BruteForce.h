//
// Created by radom on 18.10.2023.
//

#ifndef PEA1_BRUTEFORCE_H
#define PEA1_BRUTEFORCE_H


class BruteForce {
private:
    int** matrix;
    int matrixSize;
    int minLenght;
    int* minPath;
    void perm(int* numbers);
    void perm(int* numbers, int index);
    void swap(int* numbers, int i, int j);
    void checkPath(int* arr);


public:
    BruteForce(int** matrix, int matrixSize);
    ~BruteForce();
    void start();
    int getMinLenght();
    int* getMinPath();


};


#endif //PEA1_BRUTEFORCE_H

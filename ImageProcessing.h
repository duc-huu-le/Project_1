//
// Created by rmb35 on 2/21/2021.
//

#ifndef PROJECT_1_IMAGEPROCESSING_H
#define PROJECT_1_IMAGEPROCESSING_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
int **flipHorizontal(int **original, int width, int height);
int **flipVertical(int **original, int width, int height);
int **copyImage(int **original, int width, int height);
#endif //PROJECT_1_IMAGEPROCESSING_H

//
// Created by rmb35 on 2/21/2021.
//

#include "ImageProcessing.h"

int **copyImage(int **original, int width, int height)
{
    int **newimg;
    newimg = new int*[ height];
    for(int i = 0; i < height; i++){
        newimg[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(newimg+j)+i) = *(*(original+j)+i);
        }
    }
    return newimg;
}


int **flipVertical(int **original, int width, int height)
{
    int **newimg;
    newimg = new int*[ height];
    for(int i = 0; i < height; i++){
        newimg[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(newimg+j)+i) = *(*(original+width-j-1)+i);
        }
    }
    return newimg;
}

int **flipHorizontal(int **original, int width, int height)
{
    int **newimg;
    newimg = new int*[ height];
    for(int i = 0; i < height; i++){
        newimg[i] = new int[width];
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(newimg+j)+i) = *(*(original+j)+height-i-1);
        }
    }
    return newimg;
}
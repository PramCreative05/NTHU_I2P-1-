/******************************************************************************
If you are here, you probably know what convolution is already.
So I'm going to make a summary of the program I need you to make.

I'm going to create a pair of glasses that takes in a grayscale image of width w and height h.
I want you to create an algorithm that turns it into a convoluted image of width w-2 and height h-2
using a 3-by-3 kernel that contains a single-precision floating value in each pixel.
Remember to round the numbers down to integers.

Input
In the first line, there are two positive integers, w and h,
representing the width and height of the image. (3 ≤ w,h ≤ 300).

Following are 9 single-precision floating point numbers distributed into a 3 x 3 grid,
representing the numbers in the kernel.

The remaining h lines consist of w integers each,
representing the brightness value in a w x h grayscale picture.
The brightness value in each pixel is a non-negative number b (0 ≤ b ≤ 255).

Output
The resulting convolved (w-2) x (h-2) image,
consisting of numbers rounded to an integer with field width 4 (the format specifier is %4d),
all followed by a space. At the end of each line, print an end-line character '\n'.

Input:
6 6             => w, h (3 ≤ w,h ≤ 300)
-1.0 0.0 1.0    => kernel (3x3)
-2.0 0.0 2.0
-1.0 0.0 1.0
7 6 5 5 6 7     => h line, with w int each; brightness
6 4 3 3 4 6
5 3 2 2 3 5
5 3 2 2 3 5
6 4 3 3 4 6
7 6 5 5 6 7

Output:                 => convolved (w-2) x (h-2)
 -11   -4    4   11     => rounded to int; 4d followed by space
 -12   -4    4   12     => \n
 -12   -4    4   12
 -11   -4    4   11

Matrix multiplication: h, w: l x m dot m x n = l x n
row exhausted, col exhausted

Matrix convolution is different from multiplication
Convolution = masking; first multiply each member, then sum all

6 6
-1.0 0.0 1.0
-2.0 0.0 2.0
-1.0 0.0 1.0
7 6 5 5 6 7
6 4 3 3 4 6
5 3 2 2 3 5
5 3 2 2 3 5
6 4 3 3 4 6
7 6 5 5 6 7
*******************************************************************************/

#include <stdio.h>
int w, h;
int convo(int y, int x, float kernel[3][3], int img[h][w], int h, int w);

int main()
{
    scanf("%d %d", &w, &h);

    //verified with printf .1f || Please use address of location to save
    float kernel[3][3];
    for(int i = 0; i<3; i++){
        scanf("%f %f %f", &kernel[i][0], &kernel[i][1], &kernel[i][2]);
    }

    //Verified with printf %4d
    //Array: [row][column] => h line w int
    int img[h][w];
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
          scanf("%d", &img[i][j]);
        }
    }

    //Moving convolution
    for(int i=0; i<h-2; i++){
        for(int j = 0; j<w-2; j++){
            printf("%4d ", convo(i, j, kernel, img, h, w));
        }
        printf("\n");
    }
    return 0;
}

int convo(int y, int x, float kernel[3][3], int img[h][w], int h, int w){
    float result = 0;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            result += img[i+y][j+x] * kernel[i][j];
        }
    }
    return (int) result;
}



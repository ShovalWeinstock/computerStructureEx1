//
// Created by shoval on 10/24/21.
//

#include "ex1.h"
#include <stdio.h>

/**
 * The function returns 1 if it was compiled on a system that is big endian, and
 * @return 1 if it was compiled on a system that is big endian,
 * and 0 if it was compiled on a system that is little endian.
 */
int is_big_endian() {
    unsigned long word = 1;
    // a is the first byte of "word".
    char* a = (char*) &word;
    // if the first byte (least significant byte) is 1, the system is little endian.
    if (*a == 1) {
        return 0; // little endian
    }
    // otherwise- the system is big endian.
    return 1; // big endian
}

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
//    if (is_big_endian()) {
//        return merger(x, y);
//    } else {
//        return merger(y, x);
//    }
//
    //works:
    // pX is the first byte of "x".
    char* pX = (char*) &x;
    // pY is the first byte of "y".
    char* pY = (char*) &y;
    unsigned long merged;
    char* pMerged = (char*) &merged;
    int sizeOfLong = sizeof(long);
    int halfSizeOfLong = sizeOfLong / 2;
    char* a;
    char* b;
    // read the bytes from a and then from b. set a and b according to big / little endian
    if (is_big_endian()) {
        a = pX;
        b = pY;
    } else {
        a = pY;
        b = pX;
    }
    for (int i = 0; i < sizeOfLong; i++) {
        if (i < halfSizeOfLong) {
            *(pMerged+i) = *(a+i);
        } else {
            *(pMerged+i) = *(b+i);
        }
    }
    return merged;
}

unsigned long merger(unsigned long a, unsigned long int b) {
    unsigned long merged;
    char* pMerged = (char*) &merged;
    int sizeOfLong = sizeof(long);
    int halfSizeOfLong = sizeOfLong / 2;
    char* pA = (char*) &a;
    char* pB = (char*) &b;
    // read the bytes from a and then from b. set a and b according to big / little endian
    for (int i = 0; i < sizeOfLong; i++) {
        if (i < halfSizeOfLong) {
            *(pMerged+i) = *(pA + i);
        } else {
            *(pMerged+i) = *(pB + i);
        }
    }
    return merged;
}

unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    char* xP = (char *) &x;
    if (is_big_endian()) {
        xP[i] = b;
    } else {
        xP[(sizeof(long)) - 1 - i] = b;
    }
    return x;
}
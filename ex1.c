//
// Created by shoval on 10/24/21.
//

#include "ex1.h"

/**
 * The function returns whether it was compiled on a system that is big endian or little endian.
 *
 * @return 1 if it was compiled on a system that is big endian,
 * and 0 if it was compiled on a system that is little endian.
 */
int is_big_endian() {
    unsigned long word = 1;
    // a is the least significant byte of "word".
    char* a = (char*) &word;
    // if the least significant byte is 1, the system is little endian.
    if (*a == 1) {
        return 0;
    }
    // otherwise- the system is big endian.
    return 1;
}

/**
 * An instrumental function, for "merge_bytes(unsigned long x, unsigned long int y)".
 * Performing the merge of two "long" variables into one word, iterating from the first
 * half of a to the second half is b.
 *
 * @param a unsigned long
 * @param b unsigned long
 * @return Long, that is a merge of a and b.
 */
unsigned long merger(unsigned long a, unsigned long b) {
    // pA is the first byte of "a".
    char* pA = (char*) &a;
    // pB is the first byte of "b".
    char* pB = (char*) &b;
    unsigned long merged;
    char* pMerged = (char*) &merged;
    int sizeOfLong = sizeof(long);
    int halfSizeOfLong = sizeOfLong / 2;
    // read the bytes from a and then from b
    for (int i = 0; i < sizeOfLong; i++) {
        if (i < halfSizeOfLong) {
            *(pMerged+i) = *(pA + i);
        } else {
            *(pMerged+i) = *(pB + i);
        }
    }
    return merged;
}

/**
 * The function returns a word that is a merge of x and y:
 * The word is built from half of the bytes of y (from the least significant byte)
 * and the other half from the bytes of x.
 *
 * @param x unsigned long
 * @param y unsigned long
 * @return The word that is a merge of x and y.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    if (is_big_endian()) {
        return merger(x, y);
    } else {
        return merger(y, x);
    }
}

/**
 * The function returns x, a given word, after replacing its |x|/8-1-i byte to the char b.
 * @param x The given word (unsigned long)
 * @param b The char
 * @param i An index
 * @return x, after replacing its |x|/8-1-i byte to the char b.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    // xP is the least significant byte of x.
    char* xP = (char*) &x;
    if (is_big_endian()) {
        xP[i] = b;
    } else {
        xP[(sizeof(long)) - 1 - i] = b;
    }
    return x;
}
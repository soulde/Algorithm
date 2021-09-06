//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H


template<typename T>
void merge(T *arrFirst, size_t lenFirst, T *arrSecond, size_t lenSecond) {
    T temp[lenFirst + lenSecond];
    int i = 0, j = 0, k = 0;
    for (; (i < lenFirst) && (j < lenSecond);) {
        if (arrFirst[i] > arrSecond[j]) {
            temp[k++] = arrFirst[i++];
        } else {
            temp[k++] = arrSecond[j++];
        }
    }
    while (i < lenFirst) {
        temp[k++] = arrFirst[i++];
    }
    while (j < lenSecond) {
        temp[k++] = arrSecond[j++];
    }

    for (int iter = 0; iter < lenSecond + lenFirst; iter++) {
        arrFirst[iter] = temp[iter];
    }

}

template<typename T>
void mergeSort(T *array, size_t len) {
    for (int subLen = 1; subLen < len; subLen *= 2) {
        for (int offSet = 0; offSet + subLen < len; offSet += 2 * subLen) {
            merge(array + offSet, subLen, array + offSet + subLen,
                  ((offSet + 2 * subLen) >= len ? (len - offSet + subLen) : subLen));
        }
    }
}

#endif //ALGORITHM_MERGESORT_H

#include <globaldefs.h>

struct Candidate { int id; float weight; };

// USA: func_020749ac
extern "C" ARM void func_020749ac(Candidate* arr, int lo, int hi, int mode) {
    int i = (int)(unsigned int)lo;
    int j = hi;
    float pivot = arr[i].weight;

    if (mode != 0) {
        for (;;) {
            while (arr[i].weight > pivot) {
                i++;
            }
            while (arr[j].weight < pivot) {
                j--;
            }
            if (i >= j) {
                break;
            }
            float wi = arr[i].weight;
            int ii = arr[i].id;
            arr[i].weight = arr[j].weight;
            arr[i].id = arr[j].id;
            arr[j].weight = wi;
            arr[j].id = ii;
            i++;
            j--;
        }
    } else {
        for (;;) {
            while (arr[i].weight < pivot) {
                i++;
            }
            while (arr[j].weight > pivot) {
                j--;
            }
            if (i >= j) {
                break;
            }
            float wi = arr[i].weight;
            int ii = arr[i].id;
            arr[i].weight = arr[j].weight;
            arr[i].id = arr[j].id;
            arr[j].weight = wi;
            arr[j].id = ii;
            i++;
            j--;
        }
    }

    if (lo < i - 1) {
        func_020749ac(arr, lo, i - 1, mode);
    }
    if (j + 1 < hi) {
        func_020749ac(arr, j + 1, hi, mode);
    }
}

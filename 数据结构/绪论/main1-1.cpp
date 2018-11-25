 #include "c1.h"

typedef int ElemType;
#include "c1-1.h"
#include "bo1-1.cpp"

int main() {
    Triplet T;
    ElemType m;
    Status i;
    i = InitTriplet(T, 5, 7, 9);
    printf("InitTriplet Success, i = %d (1: Success), three elements are:", i);
    cout << T[0] << " " << T[1] << " " << T[2] << endl;
    i = Get(T, 2, m);
    if (i == OK) {
        cout << "T[2] = " << m << endl;
    }
    i = Put(T, 2, 6);
    if (i == OK) {
        cout << "Three elements are " << T[0] << " " << T[1] << " "<< T[2] << endl;
    }
    i = IsAscending(T);
    cout << "Is T ascending ? i = " << i << " (0: No, 1: Yes) " << endl;
    i = IsDescending(T);
    cout << "Is T descending ? i = " << i << " (0: No, 1: Yes) " << endl;
    if ((i = Max(T, m)) == OK) {
        cout << "Max element in T is " << m << endl;
    }
    if ((i = Min(T, m)) == OK) {
        cout << "Min element in T is " << m << endl;
    }
    DestroyTriplet(T);
    cout << "After destroy, T = " << T << " (NULL) " << endl;
    return 0;
}

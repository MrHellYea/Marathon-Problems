#include <iostream>

using namespace std;

typedef long long int lli;

typedef struct {
    lli storedValue;
    lli lazyStoredValue;
} Node;

const int MAXN = 100010;
int sizeOfArray, numberOfOperations;
Node segmentArray[4 * MAXN];

void refresh(int position, int begin, int end);
void update(int position, int leftInterval, int rightInterval, lli value, int begin = 1, int end = sizeOfArray);
lli query(int position, int leftInterval, int rightInterval, int begin = 1, int end = sizeOfArray);


int main() {
    int left, right, operationCode;
    lli value;

    cin >> sizeOfArray >> numberOfOperations;

    for (int i = 0; i < numberOfOperations; i++) {
        cin >> operationCode;

        if (operationCode == 1) {
            cin >> left >> right >> value;
            update(1, left+1, right, value);
        } else {
            cin >> left >> right;
            cout << query(1, left+1, right) << endl;
        }
    }

    return 0;
}


void refresh(int position, int begin, int end) {
    if (segmentArray[position].lazyStoredValue == 0) {
        return;
    }

    lli oldStoredValue = segmentArray[position].lazyStoredValue;
    
    segmentArray[position].lazyStoredValue = 0;

    if (oldStoredValue == -1) {
        oldStoredValue = 0;
    }
    segmentArray[position].storedValue = (end - begin + 1) * oldStoredValue;

    if (begin == end) {
        return;
    }

    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    segmentArray[leftChildPosition].lazyStoredValue = oldStoredValue;
    segmentArray[rightChildPosition].lazyStoredValue = oldStoredValue;
}

void update(int position, int leftInterval, int rightInterval, lli value, int begin, int end) {
    refresh(position, begin, end);

    if (rightInterval < begin || leftInterval > end) {
        return;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        if (value == 0) {
            segmentArray[position].lazyStoredValue = -1;
        } else {
            segmentArray[position].lazyStoredValue = value;
        }
        refresh(position, begin, end);
        return;
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    update(leftChildPosition, leftInterval, rightInterval, value, begin, middle);
    update(rightChildPosition, leftInterval, rightInterval, value, middle+1, end);

    segmentArray[position].storedValue = segmentArray[leftChildPosition].storedValue + segmentArray[rightChildPosition].storedValue;
}

lli query(int position, int leftInterval, int rightInterval, int begin, int end) {
    refresh(position, begin, end);

    if (rightInterval < begin || leftInterval > end) {
        return 0;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        return segmentArray[position].storedValue;
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    return query(leftChildPosition, leftInterval, rightInterval, begin, middle) + query(rightChildPosition, leftInterval, rightInterval, middle+1, end);
}
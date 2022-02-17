#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

typedef struct {
    lli storedValueForSum = 0;
    lli lazyStoredValue = 1;
} Node;

const int MAXN = 100010;
const int modulo = 1000000007;
int sizeOfArray, numberOfOperations;
Node segmentArray[4 * MAXN];

void refresh(int position, int begin, int end);
void update(int position, int leftInterval, int rightInterval, lli value, int begin = 1, int end = sizeOfArray);
void initialBuild(int position, int index, lli value = 1, int begin = 1, int end = sizeOfArray);
lli query(int position, int leftInterval, int rightInterval, int begin = 1, int end = sizeOfArray);
lli modularSum(lli a, lli b);
lli modularMultiplication(lli a, lli b);

int main() {
    int left, right, operationCode;
    lli value;

    cin >> sizeOfArray >> numberOfOperations;

    for (int i = 1; i <= sizeOfArray; i++) {
        initialBuild(1, i);
    }

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
    if (segmentArray[position].lazyStoredValue == 1) {
        return;
    }

    lli oldStoredValue = segmentArray[position].lazyStoredValue;
    
    segmentArray[position].lazyStoredValue = 1;
    segmentArray[position].storedValueForSum = modularMultiplication(segmentArray[position].storedValueForSum, oldStoredValue);

    if (begin == end) {
        return;
    }

    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    segmentArray[leftChildPosition].lazyStoredValue = modularMultiplication(segmentArray[leftChildPosition].lazyStoredValue, oldStoredValue);
    segmentArray[rightChildPosition].lazyStoredValue = modularMultiplication(segmentArray[rightChildPosition].lazyStoredValue, oldStoredValue);  
}

void update(int position, int leftInterval, int rightInterval, lli value, int begin, int end) {
    refresh(position, begin, end);
    
    if (rightInterval < begin || leftInterval > end) {
        return;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        segmentArray[position].lazyStoredValue = modularMultiplication(segmentArray[position].lazyStoredValue, value);
        refresh(position, begin, end);
        return;
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    update(leftChildPosition, leftInterval, rightInterval, value, begin, middle);
    update(rightChildPosition, leftInterval, rightInterval, value, middle+1, end);

    segmentArray[position].storedValueForSum = modularSum(segmentArray[leftChildPosition].storedValueForSum, segmentArray[rightChildPosition].storedValueForSum);
}

void initialBuild(int position, int index, lli value, int begin, int end) {
    if (index < begin || index > end) {
        return;
    }

    if (begin == end) {
        segmentArray[position].storedValueForSum = value;
        return; 
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    initialBuild(leftChildPosition, index, value, begin, middle);
    initialBuild(rightChildPosition, index, value, middle+1, end);

    segmentArray[position].storedValueForSum = (segmentArray[leftChildPosition].storedValueForSum + segmentArray[rightChildPosition].storedValueForSum);
}

lli query(int position, int leftInterval, int rightInterval, int begin, int end) {
    refresh(position, begin, end);
    
    if (rightInterval < begin || leftInterval > end) {
        return 0;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        return segmentArray[position].storedValueForSum;
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;

    lli x = query(leftChildPosition, leftInterval, rightInterval, begin, middle);
    lli y = query(rightChildPosition, leftInterval, rightInterval, middle+1, end);
    
    return modularSum(x, y);
}

lli modularSum(lli a, lli b) {
    return (a%modulo + b%modulo)%modulo;
}

lli modularMultiplication(lli a, lli b) {
    return (a%modulo * b%modulo)%modulo;
}
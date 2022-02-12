#include <iostream>

using namespace std;

const int MAXN = 100010;
int segmentArray[4 * MAXN];
int entryArray[MAXN];

void update(int position, int begin, int end, int index, int value);
int query(int position, int begin, int end, int leftInterval, int rightInterval); 
int min(int a, int b);
void build(int position, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sizeOfArray;
    int numberOfOperations;
    int element;
    int operation, x, y;

    cin >> sizeOfArray >> numberOfOperations;

    for (int i = 0; i < sizeOfArray; i++) {
        cin >> element;
        update(0, 0, sizeOfArray-1, i, element);
    }

    for (int i = 0; i < numberOfOperations; i++) {
        cin >> operation >> x >> y;

        if (operation == 1) {
            update(0, 0, sizeOfArray-1, x, y);
        } else {
            cout << query(0, 0, sizeOfArray-1, x, y-1) << endl;
        }
    }

    return 0;
}


void update(int position, int begin, int end, int index, int value) {
    if (index < begin || index > end) {
        return;
    }

    if (begin == end) {
        segmentArray[position] = value;
        return; 
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position + 1;
    int rightChildPosition = 2 * position + 2;

    update(leftChildPosition, begin, middle, index, value);
    update(rightChildPosition, middle+1, end, index, value);

    segmentArray[position] = min(segmentArray[leftChildPosition], segmentArray[rightChildPosition]);
}

int query(int position, int begin, int end, int leftInterval, int rightInterval) {
    if (rightInterval < begin || leftInterval > end) {
        return INT32_MAX;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        return segmentArray[position];
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position + 1;
    int rightChildPosition = 2 * position + 2;

    return min(query(leftChildPosition, begin, middle, leftInterval, rightInterval), query(rightChildPosition, middle+1, end, leftInterval, rightInterval));
}

void build(int position, int begin, int end) {
    if (begin == end) {
        segmentArray[position] = entryArray[begin];
        return;
    }

    int middle = (begin + end)/2;
    int leftChildPosition = 2 * position + 1;
    int rightChildPosition = 2 * position + 2;
    
    build(leftChildPosition, begin, middle);
    build(rightChildPosition, middle+1, end);

    segmentArray[position] = min(segmentArray[leftChildPosition], segmentArray[rightChildPosition]);
}

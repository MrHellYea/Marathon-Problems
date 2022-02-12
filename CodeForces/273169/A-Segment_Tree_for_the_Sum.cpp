#include <iostream>

using namespace std;

typedef long long int lli;

const int MAXN = 100010;
lli segmentArray[4 * MAXN];
lli entryArray[MAXN];

void update(lli position, lli begin, lli end, lli index, lli value);
lli query(lli position, lli begin, lli end, lli leftInterval, lli rightInterval); 
lli min(lli a, lli b);
void build(lli position, lli begin, lli end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli sizeOfArray;
    lli numberOfOperations;
    lli element;
    lli operation, x, y;

    cin >> sizeOfArray >> numberOfOperations;

    for (lli i = 0; i < sizeOfArray; i++) {
        cin >> element;
        update(0, 0, sizeOfArray-1, i, element);
    }

    for (lli i = 0; i < numberOfOperations; i++) {
        cin >> operation >> x >> y;

        if (operation == 1) {
            update(0, 0, sizeOfArray-1, x, y);
        } else {
            cout << query(0, 0, sizeOfArray-1, x, y-1) << endl;
        }
    }

    return 0;
}


void update(lli position, lli begin, lli end, lli index, lli value) {
    if (index < begin || index > end) {
        return;
    }

    if (begin == end) {
        segmentArray[position] = value;
        return; 
    }

    lli middle = (begin + end)/2;
    lli leftChildPosition = 2 * position + 1;
    lli rightChildPosition = 2 * position + 2;

    update(leftChildPosition, begin, middle, index, value);
    update(rightChildPosition, middle+1, end, index, value);

    segmentArray[position] = (segmentArray[leftChildPosition] + segmentArray[rightChildPosition]);
}

lli query(lli position, lli begin, lli end, lli leftInterval, lli rightInterval) {
    if (rightInterval < begin || leftInterval > end) {
        return 0;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        return segmentArray[position];
    }

    lli middle = (begin + end)/2;
    lli leftChildPosition = 2 * position + 1;
    lli rightChildPosition = 2 * position + 2;

    return (query(leftChildPosition, begin, middle, leftInterval, rightInterval) + query(rightChildPosition, middle+1, end, leftInterval, rightInterval));
}

void build(lli position, lli begin, lli end) {
    if (begin == end) {
        segmentArray[position] = entryArray[begin];
        return;
    }

    lli middle = (begin + end)/2;
    lli leftChildPosition = 2 * position + 1;
    lli rightChildPosition = 2 * position + 2;
    
    build(leftChildPosition, begin, middle);
    build(rightChildPosition, middle+1, end);

    segmentArray[position] = (segmentArray[leftChildPosition] + segmentArray[rightChildPosition]);
}

#include <bits/stdc++.h>

#define lli long long int

using namespace std;

typedef struct {
    lli sum; 
    lli maxPrefix;
    lli maxSuffix;
    lli maxSum;
} Node;

vector<Node> segmentArray;

void update(int pos, int begin, int end, int index, lli value);

int main() {
    lli value;
    int arraySize, numberOfOperations, index;

    scanf("%d %d", &arraySize, &numberOfOperations);
    segmentArray.resize(4 * arraySize);

    for (int i = 1; i <= arraySize; i++) {
        scanf("%lli", &value);
        update(1, 1, arraySize, i, value);
    }

    printf("%lli\n", segmentArray[1].maxSum);

    for (int i = 0; i < numberOfOperations; i++) {
        scanf("%d %lli", &index, &value);
        update(1, 1, arraySize, index + 1, value);
        printf("%lli\n", segmentArray[1].maxSum);
    }

    return 0;
}


void update(int pos, int begin, int end, int index, lli value) {
    if (index < begin || index > end) return;

    if (begin == end) {
        segmentArray[pos].sum = value;

        if (value > 0) {
            segmentArray[pos].maxPrefix = value;
            segmentArray[pos].maxSuffix = value;
            segmentArray[pos].maxSum = value;
        } else {
            segmentArray[pos].maxPrefix = 0;
            segmentArray[pos].maxSuffix = 0;
            segmentArray[pos].maxSum = 0;
        }

        return;
    }

    int middle = (begin + end) >> 1;
    int leftChildPosition = 2 * pos;
    int rightChildPosition = 2 * pos + 1;

    update(leftChildPosition, begin, middle, index, value);
    update(rightChildPosition, middle + 1, end, index, value);

    segmentArray[pos].sum = segmentArray[leftChildPosition].sum + segmentArray[rightChildPosition].sum;
    segmentArray[pos].maxPrefix = max(segmentArray[leftChildPosition].maxPrefix, segmentArray[leftChildPosition].sum + segmentArray[rightChildPosition].maxPrefix);
    segmentArray[pos].maxSuffix = max(segmentArray[rightChildPosition].maxSuffix, segmentArray[rightChildPosition].sum + segmentArray[leftChildPosition].maxSuffix);
    segmentArray[pos].maxSum = max(
        max(segmentArray[leftChildPosition].maxSum, segmentArray[rightChildPosition].maxSum),
        segmentArray[leftChildPosition].maxSuffix + segmentArray[rightChildPosition].maxPrefix
    );
}

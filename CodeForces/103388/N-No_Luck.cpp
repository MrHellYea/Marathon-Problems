#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

struct Node {
    vector<int> tops;
    int frustration = 0;
};

vector<Node> segmentArray;
int sizeOfArray, operations;

void build(vector<int> &tops, int position, int begin = 0, int end = sizeOfArray-1);
int query(int position, int positionOnLastMarathon, int leftInterval, int rightInterval, int begin = 0, int end = sizeOfArray-1);
Node merge(Node leftChild, Node rightChild);
void clear_segment_array();
void print_int_vector_elements(vector<int> intVector);


int main() {
    ibs; cti;

    int leftInterval, rightInterval;

    cin >> sizeOfArray >> operations;

    vector<int> tops(sizeOfArray);

    segmentArray.resize(4 * sizeOfArray);

    for (int i = 0; i < sizeOfArray; i++) {
        cin >> tops[i];
    }

    build(tops, 0);

    for (int i = 0; i < operations; i++) {
        int lastYear, positionOnLastMarathon, numberOfYearsFollowing;

        cin >> lastYear >> positionOnLastMarathon >> numberOfYearsFollowing;

        leftInterval = lastYear;
        rightInterval = lastYear+numberOfYearsFollowing-1;

        if (positionOnLastMarathon <= tops[lastYear-1] || numberOfYearsFollowing == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << query(0, positionOnLastMarathon, leftInterval, rightInterval) << endl;
    }

    return 0;
}


void build(vector<int> &tops, int position, int begin, int end) {
    if (begin == end) {
        if (begin < (int) tops.size()) {
            segmentArray[position].tops.push_back(tops[begin]);
        }
    } else {
        int middle = (begin+end)/2;
        int leftChildPosition = 2 * position + 1;
        int rightChildPosition = 2 * position + 2;

        build(tops, leftChildPosition, begin, middle);
        build(tops, rightChildPosition, middle+1, end);

        segmentArray[position] = merge(segmentArray[leftChildPosition], segmentArray[rightChildPosition]);
    }
}

int query(int position, int positionOnLastMarathon, int leftInterval, int rightInterval, int begin, int end) {
    if (rightInterval < begin || leftInterval > end) {
        return 0;
    }

    if (leftInterval <= begin && end <= rightInterval) {
        int value = segmentArray[position].tops.size() - (lower_bound(segmentArray[position].tops.begin(), segmentArray[position].tops.end(), positionOnLastMarathon) - segmentArray[position].tops.begin());
        return value;
    }

    int middle = (begin+end)/2;
    int leftChildPosition = 2 * position + 1;
    int rightChildPosition = 2 * position + 2;

    int leftQuery = query(leftChildPosition, positionOnLastMarathon, leftInterval, rightInterval, begin, middle);
    int rightQuery = query(rightChildPosition, positionOnLastMarathon, leftInterval, rightInterval, middle+1, end);

    return leftQuery + rightQuery;
}

Node merge(Node leftChild, Node rightChild) {
    vector<int> v1 = leftChild.tops;
    vector<int> v2 = rightChild.tops;
    vector<int> mergedVector(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), mergedVector.begin());
    return { mergedVector };
}

void clear_segment_array() {
    for (int i = 0; i < 2*sizeOfArray-1; i++) {
        segmentArray[i].frustration = 0;
    }
}

void print_int_vector_elements(vector<int> intVector) {
    for (int element: intVector) {
        cout << element << " ";
    }
    cout << endl;
}

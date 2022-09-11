#include <bits/stdc++.h>

using namespace std;
 
typedef long long int lli;

const lli MAX_SIZE = 500;

class Solution {
  public:
   
    lli cost[MAX_SIZE][MAX_SIZE]; //cost matrix
    int n, max_match; //n workers and n jobs
    lli lx[MAX_SIZE], ly[MAX_SIZE]; //labels of X and Y parts
    lli xy[MAX_SIZE]; //xy[x] - vertex that is matched with x,
    lli yx[MAX_SIZE]; //yx[y] - vertex that is matched with y
    bool S[MAX_SIZE], T[MAX_SIZE]; //sets S and T in algorithm
    lli slack[MAX_SIZE]; //as in the algorithm description
    lli slackx[MAX_SIZE]; //slackx[y] such a vertex, that
    lli prev_ious[MAX_SIZE]; //array for memorizing alternating p
   
    void init_labels()
    {
        memset(lx, 0, sizeof(lx));
        memset(ly, 0, sizeof(ly));
        for (lli x = 0; x < n; x++)
        for (lli y = 0; y < n; y++)
        lx[x] = max(lx[x], cost[x][y]);
    }
     
      
    void update_labels()
    {
        lli x, y;
        lli delta = 99999999; //init delta as infinity
        for (y = 0; y < n; y++) //calculate delta using slack
            if (!T[y])
                delta = min(delta, slack[y]);
        for (x = 0; x < n; x++) //update X labels
            if (S[x])
                lx[x] -= delta;
        for (y = 0; y < n; y++) //update Y labels
            if (T[y])
                ly[y] += delta;
        for (y = 0; y < n; y++) //update slack array
            if (!T[y])
                slack[y] -= delta;
    }
     
     
    void add_to_tree(lli x, lli prev_iousx)
    //x - current vertex,prev_iousx - vertex from X before x in the alternating path,
    //so we add edges (prev_iousx, xy[x]), (xy[x], x)
    {
        S[x] = true; //add x to S
        prev_ious[x] = prev_iousx; //we need this when augmenting
        for (lli y = 0; y < n; y++) //update slacks, because we add new vertex to S
            if (lx[x] + ly[y] - cost[x][y] < slack[y])
            {
                slack[y] = lx[x] + ly[y] - cost[x][y];
                slackx[y] = x;
            }
    }
     
     
     
    void augment() //main function of the algorithm
    {
        if (max_match == n) return; //check whether matching is already perfect
        lli x, y, root; //just counters and root vertex
        lli q[MAX_SIZE], wr = 0, rd = 0; //q - queue for bfs, wr,rd - write and read
        //pos in queue
        memset(S, false, sizeof(S)); //init set S
        memset(T, false, sizeof(T)); //init set T
        memset(prev_ious, -1, sizeof(prev_ious)); //init set prev_ious - for the alternating tree
         
        for (x = 0; x < n; x++) //finding root of the tree
        {
            if (xy[x] == -1)
            {
                q[wr++] = root = x;
                prev_ious[x] = -2;
                S[x] = true;
                break;
            }
        }
         
        for (y = 0; y < n; y++) //initializing slack array
        {
            slack[y] = lx[root] + ly[y] - cost[root][y];
            slackx[y] = root;
        }
         
        //second part of augment() function
        while (true) //main cycle
        {
            while (rd < wr) //building tree with bfs cycle
            {
                x = q[rd++]; //current vertex from X part
                for (y = 0; y < n; y++) //iterate through all edges in equality graph
                    if (cost[x][y] == lx[x] + ly[y] && !T[y])
                    {
                        if (yx[y] == -1) break; //an exposed vertex in Y found, so
                                                //augmenting path exists!
                            T[y] = true; //else just add y to T,
                        q[wr++] = yx[y]; //add vertex yx[y], which is matched
                        //with y, to the queue
                        add_to_tree(yx[y], x); //add edges (x,y) and (y,yx[y]) to the tree
                    }
                if (y < n)
                    break; //augmenting path found!
            }
            if (y < n)
                break; //augmenting path found!
             
            update_labels(); //augmenting path not found, so improve labeling
             
            wr = rd = 0;
            for (y = 0; y < n; y++)
            //in this cycle we add edges that were added to the equality graph as a
            //result of improving the labeling, we add edge (slackx[y], y) to the tree if
            //and only if !T[y] && slack[y] == 0, also with this edge we add another one
            //(y, yx[y]) or augment the matching, if y was exposed
            if (!T[y] && slack[y] == 0)
            {
                if (yx[y] == -1) //exposed vertex in Y found - augmenting path exists!
                {
                    x = slackx[y];
                    break;
                }
                else
                {
                    T[y] = true; //else just add y to T,
                    if (!S[yx[y]])
                    {
                        q[wr++] = yx[y]; //add vertex yx[y], which is matched with
                        //y, to the queue
                        add_to_tree(yx[y], slackx[y]); //and add edges (x,y) and (y,
                        //yx[y]) to the tree
                    }
                }
            }
            if (y < n) break; //augmenting path found!
        }
         
        if (y < n) //we found augmenting path!
        {
            max_match++; //increment matching
            //in this cycle we inverse edges along augmenting path
            for (lli cx = x, cy = y, ty; cx != -2; cx = prev_ious[cx], cy = ty)
            {
                ty = xy[cx];
                yx[cy] = cx;
                xy[cx] = cy;
            }
            augment(); //recall function, go to step 1 of the algorithm
        }
    }//end of augment() function
      
    lli hungarian()
    {
        lli ret = 0; //weight of the optimal matching
        max_match = 0; //number of vertices in current matching
        memset(xy, -1, sizeof(xy));
        memset(yx, -1, sizeof(yx));
        init_labels(); //step 0
        augment(); //steps 1-3
         
        for (lli x = 0; x < n; x++) //forming answer there
            ret += cost[x][xy[x]];
     
        return ret;
    }
     
    lli assignmentProblem(vector<lli> Arr, lli N) {
        n = N;

        for (lli i=0; i<n; i++) {
            for (lli j=0; j<n; j++) {
                cost[i][j] = -1*Arr[i*n+j];
            }
        }
        
        return -1 * hungarian();
    }
};

int main() {
    int n;
    lli distanceMatrixSize;

    cin >> n;

    vector<lli> length(n*n, 0);

    if (n % 2 == 0) {
        distanceMatrixSize = n/2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> length[i*n+j];
            }
        }
    } else {
        distanceMatrixSize = (n+1)/2;

        length.resize(n*(n + 1));

        for (int i = 0; i < n*(n+1); i++) {
            length[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n+1; j++) {
                if (j == n) {
                    length[i*(n+1)+j] = 0;
                } else {
                    cin >> length[i*(n+1)+j];
                }
            }
        }
    }

    vector<lli> Arr(distanceMatrixSize*distanceMatrixSize, 0);

    for (int i = 0; i < distanceMatrixSize; i++) {
        for (int j = 0; j < distanceMatrixSize; j++) {
            if (j == 0) {
                Arr[i*distanceMatrixSize+j] = length[i*2*2*distanceMatrixSize+j*2+1];
            } else {
                Arr[i*distanceMatrixSize+j] = length[i*2*2*distanceMatrixSize+j*2+1] + length[i*2*2*distanceMatrixSize+j*2+1-2];
            }
        } 
    }

    Solution ob;
    cout << ob.assignmentProblem(Arr, distanceMatrixSize) << endl;

    return 0;
}
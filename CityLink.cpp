#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class CityLink {
    public:
        int timeTaken(vector<int> x, vector<int> y);
};
int floydWarshall (vector<vector<int> > graph)
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int V = graph.at(0).size();
    int dist[V][V], i, j, k;
 
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (max(dist[i][k] , dist[k][j]) < dist[i][j])
                    dist[i][j] = max( dist[i][k] , dist[k][j]);
            }
        }
    }
 
    int max = 0;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            if( i == j ) { continue; }
            if(dist[i][j] > max) { max = dist[i][j]; }
        }
    cout << "FLOYD" << endl;
     for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            cout << dist[i][j]  << ' ';
        }
        cout << endl;
    }
    // Print the shortest distance matrix
    return max;
}
 
int parse_cities(vector<int> x, vector<int> y)
{
    vector<vector<int> > ret;

    for(int i = 0; i < x.size(); i++) {
        vector<int> row;
        for(int j = 0; j < x.size(); j++) {
            int dist;
            int x_fixed = x.at(i);
            int y_fixed = y.at(i);
            int x_target = x.at(j);
            int y_target = y.at(j);
            cout << "y_target " << y_target << endl;
            cout << "x_target " << x_target << endl;
            cout << "y_fixed " << y_fixed << endl;
            cout << "x_fixed " << x_fixed << endl;
            if(x_fixed == x_target) {
                dist = (int) ceil((float) (abs(y_fixed - y_target)) / 2);
                cout << "dist = " << dist << endl;
            } else if(y_fixed == y_target) {
                dist = (int) ceil((float) (abs(x_fixed - x_target)) / 2);
                cout << "dist = " << dist << endl;
            } else {
                dist = max(abs(x_target - x_fixed), abs(y_target - y_fixed));
            }
            row.push_back(dist);
       }
        ret.push_back(row);
    }

    for(vector<int> r : ret) {
        for(int i : r) {
            cout << i  << ' ';
        }
        cout << endl;
    }
    int min = floydWarshall(ret);
    return min;
}

int CityLink::timeTaken(vector<int> x, vector<int> y) {
    int min = parse_cities(x, y);
    return min;
}

int main()
{
    vector<int> x;
    vector<int> y;
    x = {1593,-88517,14301,3200,6,-15099,3200,5881,-2593,11,57361,-92990};
    y = {99531,-17742,-36499,1582,46,34001,-19234,1883,36001,0,233,485};
    CityLink c;
    int min = c.timeTaken(x, y);
    cout << min << endl;
    return 0;
}

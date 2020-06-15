/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int>distance(n,1e8);
        distance[src] = 0;
        
        for (int i = 0; i<=K;i++)
            
        {    vector<int>temp(distance);
            for (auto e : flights)
            {
                int a,b,w;
                a = e[0];
                b = e[1];
                w = e[2];
                temp[b] = min(temp[b],distance[a]+w);
            }
            
            distance = temp;
            
        }
        
        if (distance[dst] == 1e8)
            return -1;
        return distance[dst];
    }
};

#include <bits/stdc++.h>
using namespace std;
 
// Function to find number of possible rectangles
int countRectangles(vector<pair<int, int> >& ob)
{
 
    // Creating TreeSet containing elements
    set<pair<int, int> > it;
 
    // Inserting the pairs in the set
    for (auto & i : ob) {
        it.insert(i);
    }
 
    int ans = 0;
    for (int i = 0; i < ob.size(); ++i)
    {
        for (int j = 0; j < ob.size(); ++j)
        {
            if (ob[i].first != ob[j].first
                && ob[i].second != ob[j].second)
            {
               
                // Searching the pairs in the set
                if (it.count({ ob[i].first, ob[j].second })
                    && it.count(
                        { ob[j].first, ob[i].second }))
                {
                   
                    // Increase the answer
                    ++ans;
                }
            }
        }
    }
 
    // Return the final answer
    return ans / 4;
}
 
// Driver Code
int main()
{
 
    int N = 5;
    vector<pair<int, int> > ob(N);
 
    // Inserting the pairs
    ob[0] = { 1, 1 };
    ob[1] = { 1, 3 };
    ob[2] = { 2, 1 };
    ob[3] = { 3, 1 };
    ob[4] = { 3, 3};

    cout << countRectangles(ob);
 
    return 0;
}
 
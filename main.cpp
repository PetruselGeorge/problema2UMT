#include <vector>
#include <iostream>
#include <set>
using namespace std;


///For a rectangle the diagonal end points can be (x1, y1) and (x2, y2) given that x1!=x2 and y1!=y2.
/// This is because we are given that the rectangles should be parallel to axes.
/// Also after we get two points as the diagonal end points, keeping the properties of rectangle in mind,
/// the other two end points of the rectangle will be (x1, y2) and (x2, y1)
 
///Function to find number of possible rectangles
int countRectangles(vector<pair<int, int> >& coordinates)
{
 
    /// Creating TreeSet containing elements
    set<pair<int, int> > points;
 
    /// Inserting the pairs in the set
    for (auto & i : coordinates) {
        points.insert(i);
    }
 
    int answer = 0;

    for (int i = 0; i < coordinates.size(); ++i)
    {
        for (int j = 0; j < coordinates.size(); ++j)
        {
            if (coordinates[i].first != coordinates[j].first
                && coordinates[i].second != coordinates[j].second)
            {

                /// Searching the pairs in the set
                if (points.count({ coordinates[i].first, coordinates[j].second })
                    && points.count(
                        { coordinates[j].first, coordinates[i].second }))
                {

                    /// Increase the answer
                    ++answer;
                }
            }
        }
    }
    return answer/4 ; ///because for each rectangle are 4 coordinates
}
 
int main()
{
 
    int N = 5;
    vector<pair<int, int> > coordinates(N);
 
    /// Inserting the pairs
    coordinates[0] = { 1, 1 };
    coordinates[1] = { 1, 3 };
    coordinates[2] = { 2, 1 };
    coordinates[3] = { 3, 1 };
    coordinates[4] = { 3, 3};
    cout << countRectangles(coordinates);
 
    return 0;
}
 
//@file: pair.cpp in project HULL6
//@author: Trevor Berreth & Johnny White
//@date: March 23, 2015
//@description: finds a pair of points with
//@             the smallest Euclidean distance

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef float Coordinate;
typedef vector<Coordinate> Point;
typedef vector<Point> LineSegment;

//@      reads in a text file containing a list of x and y coordinates
//@      with the size of the list noted at the first row
//@pre : file must be available to open
//@post: returns a vector<Point> listing a list of 'size' amount
//@      of points with their x and y coordinates
//@use : vector<Point> listOfPoints = CreateListOfPointsUsingFile("filename", size);
vector<Point> CreateListOfPointsUsingFile(string filename, int& size);
//
//@      Solves the closest-pair problem by divide-and-conquer
//@pre : at least 2 points
//@post: returns the Euclidean distance of two-points
//@use : float closestDistance = EfficientClosestPair( vector<Point> P, vector<Point> Q );
float EfficientClosestPair( vector<Point> P, vector<Point> Q );

//@      Solves the closest-pair problem by brute-force
//@pre : at least 2 points
//@post: returns the Euclidean distance of two-points
//@use : float closestDistance = BruteForceClosestPair( vector<Point> P );
float BruteForceClosestPair( vector<Point> P );

//@      Merges Sorts a vector in a non-decreasing order
//@      based on the x-coordinate
//@pre : vector must have at least one element
//@post: a sorted array
//@use : MergeSortByXCoordinates(vector<Point> P);
vector<Point> MergeSortByXCoordinates(vector<Point> P);

//@      Merges Sorts a vector in a non-decreasing order
//@      based on the y-coordinate
//@pre : vector must have at least one element
//@post: a sorted array
//@use : MergeSortByYCoordinates(vector<Point> P);
vector<Point> MergeSortByYCoordinates(vector<Point> P);

//@      Merges vectors in a non-decreasing order
//@      based on the y-coordinate
//@pre : vector must have at least one element
//@post: a sorted array
//@use : vector<Point> result MergeByXCoordinates( leftP, rightP );
vector<Point> MergeByXCoordinates(vector<Point> leftP, vector<Point> rightP);

//@      Merges vectors in a non-decreasing order
//@      based on the y-coordinate
//@pre : vector must have at least one element
//@post: a sorted array
//@use : vector<Point> result MergeByYCoordinates( leftP, rightP );
vector<Point> MergeByYCoordinates(vector<Point> leftP, vector<Point> rightP);

//@      Uses a given euclidean distance to find the closest points
//@pre : the euclidean distance has already been found
//@post: returns the nearest two-points
//@use : vector<Point> pair = FindPair(float distance, vector<Point> points);
vector<Point> FindPair(float distance, vector<Point> points);

int main()
{
    vector<Point> result;
    int numPoints = 0;
    vector<Point> listPoints = CreateListOfPointsUsingFile("inpoints.dat", numPoints);
    vector<Point> P = MergeSortByXCoordinates(listPoints);
    vector<Point> Q = MergeSortByYCoordinates(listPoints);

    float distance = EfficientClosestPair(P, Q);
    cout << endl << "Distance: " << distance << endl;
    result = FindPair(distance, listPoints);
    for (int i = 0; i <= result.size() - 1; i++){
        cout<<"Point: "<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    cout<<endl;
    return 0;
}
//
//@      creates a point with mem(pow(( P[i][0] - P[j][0] ), 2) + pow(( P[i][1] - P[j][1] ), 2))ory to store an x and y value per point
//@post: returns a point
//@use : Point point = CreatePoint( xcor , ycor );
Point CreatePoint(Coordinate x, Coordinate y)
{
    Point point(2);
    point[0] = x;
    point[1] = y;
    return point;
}

//@      reads in a text file containing a list of x and y coordinates
//@      with the size of the list noted at the first row
//@pre : file must be available to open
//@post: returns a vector<Point> listing a list of 'size' amount
//@      of points with their x and y coordinates
//@use : vector<Point> listOfPoints = CreateListOfPointsUsingFile("filename", size);
vector<Point> CreateListOfPointsUsingFile(string filename, int& size)
{
    vector<Point> listOfPoints;
    int xcor;
    int ycor;
    string initLine;
    string line;
    ifstream myFile;
    Point point;

    myFile.open(filename.c_str(), ios::in);
    getline(myFile, initLine);

    sscanf(initLine.c_str(), "%d", &size);

    if (myFile.is_open())
    {
        while(getline(myFile, line))
        {
            sscanf (line.c_str(), "%d %d", &xcor, &ycor);
            point = CreatePoint( xcor , ycor );
            listOfPoints.push_back(point);
        }
    }
    else
        cout << "Unable to open file";
    myFile.close();

    return listOfPoints;
}

//@      Solves the closest-pair problem by divide-and-conquer
//@pre : at least 2 points
//@post: returns the Euclidean distance of two-points
//@use : float closestDistance = EfficientClosestPair( vector<Point> P, vector<Point> Q )
float EfficientClosestPair( vector<Point> P, vector<Point> Q )
{
    float minDistance = 0;
    if(P.size() <= 3)
    {
        minDistance = BruteForceClosestPair(P);
        return minDistance;
    }
    else
    {
        vector<Point> P_left, P_right, Q_left, Q_right, S;
        int mid = ceil(P.size() / 2);
        //Create left and right P vectors
        for (int it = 0; it < mid; it++)
        {
            P_left.push_back(P[it]);
            Q_left.push_back(P[it]);
        }
        for (int it = mid; it <= P.size() - 1; it++)
        {
            P_right.push_back(P[it]);
            Q_right.push_back(P[it]);
        }

        MergeSortByYCoordinates(Q_left);
        MergeSortByYCoordinates(Q_right);

        //create left and right Q vectors
        float distLeft  = EfficientClosestPair(P_left, Q_left);
        float distRight = EfficientClosestPair(P_right, Q_right);
        minDistance = min(distLeft, distRight);
        float m = P[ceil(P.size() / 2) - 1][0];
        for (int it = 0; it <= Q.size() - 1; it++)
        {
            if ( abs(Q[it][0] - Q[m][0]) < minDistance)
            {
                S.push_back(Q[it]);
            }
        }
        float dminsq = pow(minDistance, 2.0);
        for (int i = 0; i < S.size() - 1; i++)
        {
            int k = i + 1;
            while ( (k <= S.size()) && (pow((S[k][1] - S[i][1]), 2) < dminsq))
            {
                float newDistance = pow(( S[k][0] - S[i][0] ), 2.0) + pow( ( S[k][1] - S[i][1] ), 2.0);
                dminsq = min( newDistance, dminsq );
                k += 1;
            }
        }
        return sqrt(dminsq);
    }
}

//@      Solves the closest-pair problem by brute-force
//@pre : at least 2 points
//@post: returns the Euclidean distance of two-points
//@use : float closestDistance = BruteForceClosestPair( vector<Point> P );
float BruteForceClosestPair( vector<Point> P )
{
    float distance = INFINITY;
    float temp;
    for(int i = 0; i <= P.size() - 2; i++)
    {
        for (int j = i + 1; j <= P.size() - 1; j++)
        {
            temp = (pow(( P[i][0] - P[j][0] ), 2) + pow(( P[i][1] - P[j][1] ), 2));
            if(temp < distance)
            distance = temp;
        }
    }
    return sqrt(distance);
}

vector<Point> FindPair(float distance, vector<Point> P)
{
    vector<Point> result;
    distance *= distance;
    for(int i = 0; i < P.size() - 1; i++)
    {
        for(int j = i + 1; j < P.size(); j++)
        {
            float euclideanDistance = (pow(( P[i][0] - P[j][0] ), 2) + pow(( P[i][1] - P[j][1] ), 2));
            if( (distance <= euclideanDistance + .001)&&(distance >= euclideanDistance - .001) )
            {
                result.push_back(P[i]);
                result.push_back(P[j]);
                return result;
            }
        }
    }
}

vector<Point> MergeSortByXCoordinates(vector<Point> P)
{
    if(P.size() == 1)
    {
        return P;
    }
    std::vector<Point>::iterator middle = P.begin() + (P.size() / 2);

    vector<Point> left(P.begin(), middle);
    vector<Point> right(middle, P.end());

    left = MergeSortByXCoordinates(left);
    right = MergeSortByXCoordinates(right);

    return MergeByXCoordinates(left, right);
}

vector<Point> MergeSortByYCoordinates(vector<Point> P)
{
    if(P.size() == 1)
    {
        return P;
    }
    std::vector<Point>::iterator middle = P.begin() + (P.size() / 2);

    vector<Point> left(P.begin(), middle);
    vector<Point> right(middle, P.end());

    left = MergeSortByYCoordinates(left);
    right = MergeSortByYCoordinates(right);

    return MergeByYCoordinates(left, right);
}

vector<Point> MergeByYCoordinates( vector<Point> left, vector<Point> right )
{
    vector<Point> result;
    int leftIt = 0;
    int rightIt = 0;

    while(leftIt < left.size() && rightIt < right.size())
    {
        if(left[leftIt][1] < right[rightIt][1])
        {
            result.push_back(left[leftIt]);
            leftIt++;
        }
        else
        {
            result.push_back(right[rightIt]);
            rightIt++;
        }
    }
    while(leftIt < left.size())
    {
        result.push_back(left[leftIt]);
        leftIt++;
    }

    while(rightIt < right.size())
    {
        result.push_back(right[rightIt]);
        rightIt++;
    }
return result;

}

vector<Point> MergeByXCoordinates( vector<Point> left, vector<Point> right )
{
    vector<Point> result;
    int leftIt = 0;
    int rightIt = 0;

    while(leftIt < left.size() && rightIt < right.size())
    {
        if(left[leftIt][0] < right[rightIt][0])
        {
            result.push_back(left[leftIt]);
            leftIt++;
        }
        else
        {
            result.push_back(right[rightIt]);
            rightIt++;
        }
    }
    while(leftIt < left.size())
    {
        result.push_back(left[leftIt]);
        leftIt++;
    }

    while(rightIt < right.size())
    {
        result.push_back(right[rightIt]);
        rightIt++;
    }
return result;
}

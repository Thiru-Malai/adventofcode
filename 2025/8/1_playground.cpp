#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

const long long unsigned int MAXIMUM_SIZE = 9223372036854775806;

struct Point{
    long double x;
    long double y;
    long double z;
};

struct Distance {
    struct Point p1;
    struct Point p2;
    long double distance;
};

struct Circuit {
    set<Point> point;
    int sizeOfPoint = point.size();
};

long long totalDistanceSize = 0;
size_t maxSize = 1000000;  // example large value

bool compareDistanceBtwPoints(const Distance& a, const Distance& b){
    return a.distance < b.distance;
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}

inline bool operator<(const Point& p1, const Point& p2)
{
    if (p1.x != p2.x) return p1.x < p2.x;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.z < p2.z;
}

long double calculate3DDistance(Point p1, Point p2, Distance distanceOfPoints[]){
    long double dist = 0.0;

    dist = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2) + pow((p1.z - p2.z),2)) * 1.0;

    struct Distance d;
    d.distance = dist;
    d.p1 = p1;
    d.p2 = p2;

    distanceOfPoints[totalDistanceSize] = d;
    totalDistanceSize++;
    return dist;
}

int main(){
    ifstream file("input.txt");
    ifstream file2("example_input.txt");

    string line;
    vector<Point> points;
    string point[] = {};
    struct Distance *distanceOfPoints = (struct Distance *) malloc(maxSize * sizeof(struct Distance));
    struct Circuit *circuit = (struct Circuit *) malloc(maxSize * sizeof(struct Circuit));;


    while(getline(file2, line)){
        struct Point p;
        p.x = stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1, line.size());
        p.y = stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1, line.size());
        p.z = stoi(line);
        points.push_back(p);
    }

    for (auto it1 = 0; it1 < points.size(); it1++) {
        for(auto it2 = it1+1; it2 < points.size(); it2++){
            calculate3DDistance(points[it1], points[it2], distanceOfPoints);
        }
    }

    cout<<"Total Distance "<<endl;
    cout<<totalDistanceSize<<endl;

    sort(distanceOfPoints, distanceOfPoints + totalDistanceSize, compareDistanceBtwPoints);

    int i = 0, connections = 0;
    // for (int it2 = 0; it2 < totalDistanceSize; it2++) {
    //     struct Circuit c;
    //     bool found = false;
    //     int index = -1;
    //     int num = -1; // -1 not found & 0 both & 1 first & 2 second
        // cout<<"Connections "<<connections<<endl;
        // cout<<"Distance "<<distanceOfPoints[it2].p1.x<<" "<<distanceOfPoints[it2].p1.y<<" "<<distanceOfPoints[it2].p1.z<<" & "<<distanceOfPoints[it2].p2.x<<" "<<distanceOfPoints[it2].p2.y<<" "<<distanceOfPoints[it2].p2.z<<" : "<<distanceOfPoints[it2].distance<<endl;
    //     for(int it3 = 0; it3 < i; it3++){
    //         if(find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p1) != circuit[it3].point.end() && find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p2) != circuit[it3].point.end()){
    //             cout<<"Found both already"<<endl;
    //             found = true;
    //             index = it3;
    //             num = 0;
    //             break;
    //         } else if(find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p1) != circuit[it3].point.end()){
    //             found = true;
    //             num = 1;
    //             index = it3;
    //             break;
    //         } else if(find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p2) != circuit[it3].point.end()){
    //             found = true;
    //             num = 2;
    //             index = it3;
    //             break;
    //         }
    //     }
    //     if(found){
    //         if(num == 1){
    //             cout<<"Found in 1"<<endl;
    //             connections++;
    //             c.point = circuit[index].point;
    //             c.point.push_back(distanceOfPoints[it2].p2);
    //             c.sizeOfPoint = c.point.size();
    //             circuit[index] = c;

    //         } else if (num == 2){
    //             cout<<"Found in 2"<<endl;
    //             connections++;
    //             c.point = circuit[index].point;
    //             c.point.push_back(distanceOfPoints[it2].p1);
    //             c.sizeOfPoint = c.point.size();
    //             circuit[index] = c;
    //         }
    //     } else {
    //         connections++;
    //         cout<<"New"<<endl;
    //         c.point = circuit[i].point;
    //         c.point.push_back(distanceOfPoints[it2].p1);
    //         c.point.push_back(distanceOfPoints[it2].p2);
    //         c.sizeOfPoint = c.point.size();
    //         circuit[i] = c;
    //         i++;
    //     }
    //     if(connections == 10){
    //         cout<<"No of active circuits "<<i<<endl;
    //         break;
    //     }
    // }
    for (int it2 = 0; it2 < totalDistanceSize; it2++) {
        struct Circuit c;
        bool found1 = false, found2 = false;
        int index1 = -1, index2 = -1;
        int num1 = -1, num2 = -1;
        cout<<"Distance "<<distanceOfPoints[it2].p1.x<<" "<<distanceOfPoints[it2].p1.y<<" "<<distanceOfPoints[it2].p1.z<<" & "<<distanceOfPoints[it2].p2.x<<" "<<distanceOfPoints[it2].p2.y<<" "<<distanceOfPoints[it2].p2.z<<" : "<<distanceOfPoints[it2].distance<<endl;
        for(int it3 = 0; it3 < i; it3++){
            if(find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p1) != circuit[it3].point.end()){
                found1 = true;
                index1 = it3;
                num1 = 1;
            } 
            if(find(circuit[it3].point.begin(), circuit[it3].point.end(), distanceOfPoints[it2].p2) != circuit[it3].point.end()){
                found2 = true;
                num2 = 2;
                index2 = it3;
            }
        }
        if(found1 && found2){
            if(index1 == index2){
                // pass
                // connections++;
            } else {
                cout<<"Found p1 & p2 in different circuits combining"<<endl;
                connections++;
                c.point = circuit[index1].point;
                c.point.insert(circuit[index2].point.begin(), circuit[index2].point.end());
                c.sizeOfPoint = c.point.size();
                circuit[index1] = c;
                circuit[index2] = {};
                i--;
            }
        } else if(found1){
            cout<<"Found p1"<<endl;
            connections++;
            c.point = circuit[index1].point;
            c.point.insert(distanceOfPoints[it2].p2);
            c.sizeOfPoint = c.point.size();
            circuit[index1] = c;
        } else if(found2){
            cout<<"Found p2"<<endl;
            connections++;
            c.point = circuit[index2].point;
            c.point.insert(distanceOfPoints[it2].p1);
            c.sizeOfPoint = c.point.size();
            circuit[index2] = c;
        } else {
            cout<<"New"<<endl;
            connections++;
            c.point = circuit[i].point;
            c.point.insert(distanceOfPoints[it2].p1);
            c.point.insert(distanceOfPoints[it2].p2);
            // cout<<c.point.count(distanceOfPoints[it2].p1)<<" "<<c.point.count(distanceOfPoints[it2].p2)<<endl;
            // cout<<distanceOfPoints[it2].p1.x<<" "<<distanceOfPoints[it2].p2.x<<endl;
            c.sizeOfPoint = c.point.size();
            circuit[i] = c;
            i++;
        }
        cout<<"Updated Size "<<c.point.size()<<endl;
        int s = 0, con = 0;
        for(int k = 0; k < i; k++){
            con+=(circuit[k].sizeOfPoint -1);
        }
        for(int j = 0; j < connections; j++){
            s+=circuit[j].sizeOfPoint;
        }
        
        cout<<"Sum "<<s<<endl;
        cout<<"Connections "<<connections<<endl;
        cout<<"Connections New"<<con<<endl;
        if(con >= 10){
            break;
        }
    }
    int max1 = 0,max2 = 0, max3 = 0, total = 0;
    for(int j = 0; j < connections; j++){
        if(circuit[j].sizeOfPoint > max1){
            max3 = max2;
            max2 = max1;
            max1 = circuit[j].sizeOfPoint;
        } else if(circuit[j].sizeOfPoint > max2){
            max3 = max2;
            max2 = circuit[j].sizeOfPoint;
        } else if(circuit[j].sizeOfPoint > max3){
            max3 = circuit[j].sizeOfPoint;
        }
        cout<<"Circuit "<<j+1<<endl;
        cout<<circuit[j].sizeOfPoint<<endl;
        total+=circuit[j].sizeOfPoint;
        // for(int k = 0; k < circuit[j].sizeOfPoint; k++){
        //     cout<<circuit[j].point[k].x<<" "<<circuit[j].point[k].y<<" "<<circuit[j].point[k].z<<endl;
        // }
    }
    cout<<max1<<" "<<max2<<" "<<max3<<endl;
    cout<<"Total "<<total;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n log n) -- due to sorting (dominant factor)
// Space Complexity : O(n)   -- due to vector 
bool compare( pair <int,int> p1, pair<int,int> p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1>v2;
}


int main(){
    int n;
    cout<<"enter number of objects"<<endl;
    cin>>n;
    vector < pair <int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(), compare);  // sort based on a custom function (which is the value/weight method)
    for(int i=0;i<v.size();i++){
        cout<<"The profit and their respective weight is : "<<endl;
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    int W; // capacity
    cout<<"Enter the weight"<<endl;
    cin>>W;

    int profit = 0;
    for (int i=0;i<n;i++){
        if(v[i].second <= W){
            profit += v[i].first; 
            W -= v[i].second;
            continue;
        }

        double weight_ratio = (double) v[i].first/v[i].second;
        profit += W* weight_ratio;
        W = 0; // which is W -= V[i].second which is zero in this case
    }

    cout<<"Total Profit : "<<profit<<endl;

    return 0;
}
/*Enter number of elements : 3
Enter Knapsack Capacity : 50
Enter profits of each item : 60
100
120
Enter their respetive weight : 10
20
30
220*/

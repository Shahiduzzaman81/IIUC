// Counting Sort
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v(6);
    vector<int>output(6);

    int maxi = INT_MIN , mini = INT_MAX;

    for(int i=0;i<6;i++){
        cin>>v[i];
        maxi = max(v[i],maxi);
        mini = min(v[i],mini);
    }

    int range = maxi - mini;
    vector<int>fq(range+1,0);

    for(int i=0;i<6;i++){
        fq[v[i] - mini]++;
    }

    for(int i=1;i<fq.size();i++){
        fq[i] += fq[i-1]; 
    }

    for(int i = 5; i >= 0; i--){
        output[--fq[v[i] - mini]] = v[i];
    }

    for(int i=0;i<6;i++){
        cout<<output[i]<<" ";
    }

    return 0;
}
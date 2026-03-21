#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Paket{
    int x;
    int c;
};

int main(){
    int n;
    cin >> n;

    vector<Paket> paket(n);
    for(int i = 0; i < n; i++)
        cin >> paket.at(i).x;

    for(int i = 0; i < n; i++)
        cin >> paket.at(i).c;
    
    sort(paket.begin(), paket.end(), [](Paket a, Paket b){
        return a.x < b.x;
    });

    map<int, int> collect;
    int l = 0, total = 0;

    for(int r = 0; r < n; r++){
        while(collect.count(paket.at(r).c)){
            collect.erase(paket.at(l).c);
            l++;
        }

        collect.insert({paket.at(r).c, 1});
        total = max(total, r-l+1);
    }

    cout << total << endl;


    return 0;
}
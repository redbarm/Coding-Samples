#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    vec.push_back({10,11,12});
    vec[0].push_back(9999);
    //for (int i=0;i < vec.size();i++){
    //    for (auto it=vec[i].begin();it!=vec[i].end();it++){
    //        cout << *it << "\n";
    //}
    //}

    for (int i=0;i < vec.size();i++){
        cout << vec[i][1];
    }
    return 0;
}
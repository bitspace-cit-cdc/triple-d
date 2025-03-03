
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if(x1+x2+x3+x4 || y1+y2+y3+y4){
        cout << "false";
        return 0;
    }
    vector<pair<int,int>> pts = {{x1,y1},{x2,y2},{x3,y3},{x4,y4}};
    vector<int> d;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            int dx = pts[i].first - pts[j].first, dy = pts[i].second - pts[j].second;
            d.push_back(dx*dx+dy*dy);
        }
    }
    sort(d.begin(), d.end());
    cout << ((d[0] > 0 && d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[4]==d[5] && d[4]==2*d[0]) ? "true" : "false");
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int c[100][100];
int n = 0;
int mark[100]{};
int res = 1e9;
int curr_dis = 0;
int path[100];
int cmin = 1e9;

int TRY(int k){
	for(int i = 2; i <= n; i++){
		if(mark[i] == 0){
			mark[i] = 1;
			curr_dis += c[path[k-1]][i];
			path[k] = i;

			if(curr_dis + cmin*(n-k+1) > res){
				mark[i] = 0;
				curr_dis -= c[path[k-1]][i];
				continue;
			}
			
			if(k == n){
				res = min(res, curr_dis + c[i][1]);
			}
			else{
				TRY(k+1);
			}
			
			mark[i] = 0;
			curr_dis -= c[path[k-1]][i];
			
		}
	}
	
	return 0;
}

int input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
        
    return 0;
}

int main(){
	input();
	path[1] = 1;
	TRY(2);
	cout<<res;
	return 0;
}


/*
8
0 2 1 3 7 3 2 7
4 0 9 2 8 5 13 2
2 4 0 3 6 9 1 5
3 3 2 0 2 3 7 3
2 7 3 9 0 4 1 9
2 1 4 5 6 0 5 4
1 6 7 2 4 5 0 10
12 2 3 1 4 5 6 0
*/

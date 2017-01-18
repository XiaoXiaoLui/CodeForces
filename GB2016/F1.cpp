#include <bits/stdc++.h>

#define MOD 1000000007
#define LINF (1LL<<60)
#define INF 2147483647
#define PI 3.1415926535897932384626433
#define ll long long
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))

using namespace std;

string itos(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

int t, h, cur;
vector<int> v;
vector<int> near[210];
bool vis[210], full;

bool found, st;

void answer(int k){
	found = true;
	cout << "! " << k << endl << flush;
}

bool ask(int pos){
	cout << "? " << pos << endl << flush;
	int k;
	cin >> k;
	vis[pos] = true;
	v.push_back(pos);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		near[pos].push_back(x);
	}
	if(k == 2){
		answer(pos);
		return false;
	}
	return k == 1;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> h;
		v.clear();
		for(int i = 0; i < 210; i++)
			near[i].clear();
		fill(vis, vis+210, false);
		found = full = false;
		for(int i = 0; i < 16 && not found; i++){
			if(not i)
				st = ask(1);
			else if(st){
				if(full){
					cur = (v.size() + 1) / 2;
					v.erase(v.begin() + cur, v.end());
					for(auto x: near[v.back()]){
						if(not vis[x]){
							st = ask(x);
							break;
						}
					}
				}
				else{
					reverse(v.begin(), v.end());
					cur = v.size();
					for(auto x: near[v.back()]){
						if(not vis[x]){
							st = ask(x);
							break;
						}
					} 					
				}
				full = true;
			}
			else if(v.size() == h){
				do{					
					v.pop_back();
				}while(count_if(near[v.back()].begin(), near[v.back()].end(), [](int x){
					return not vis[x];
				}) == 0);
				for(auto x: near[v.back()]){
					if(not vis[x]){
						st = ask(x);
						break;
					}
				}
			}
			else{
				for(auto x: near[v.back()]){
					if(not vis[x]){
						st = ask(x);
						break;
					}
				}
			}
			fflush(stdout);
		}
		if(not found){
			v.pop_back();
			for(auto x: near[v.back()]){
				if(not vis[x]){
					answer(x);
					fflush(stdout);
					break;
				}
			}
		}
	}
	return 0;
}
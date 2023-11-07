#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define pii pair<int, int> 
using namespace std;
const int NMAX = 1e5+5, MMAX = 1e5+5;
int n, m1, m2, s1[NMAX], s2[NMAX];
pii ch[MMAX], fo[MMAX];

priority_queue<int, vector<int>, greater<int> > id;
priority_queue<pii, vector<pii >, greater<pii > > t; // leave_time, id

bool cmp(pii a, pii b){
	return a.first < b.first;
}

int main(){
#ifndef TEST
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	cin >> n >> m1 >> m2;
	for(int i=0;i<m1;i++)
		cin >> ch[i].first >> ch[i].second;
	for(int i=0;i<m2;i++){
		cin >> fo[i].first;
		cin >> fo[i].second;
	}
	sort(ch, ch+m1, cmp); sort(fo, fo+m2, cmp);
	for(int i=0;i<m1+m2+1;i++) id.push(i);
	t.push(make_pair(ch[0].second, id.top()));
	s1[id.top()]++;	id.pop();
	for(int i=1;i<m1; i++){
		while(!t.empty()&&t.top().first<=ch[i].first){
			id.push(t.top().second);
			t.pop();
		}
		t.push(make_pair(ch[i].second, id.top()));
		s1[id.top()]++;	id.pop();
	}
	for(int i=1;i<n;i++){
		s1[i] += s1[i-1];
	}
    // printf("%d %d\n", id.size(), t.size());
	while(!id.empty()) id.pop(); while(!t.empty()) t.pop();
	for(int i=0;i<m1+m2+1;i++) id.push(i);
	t.push(make_pair(fo[0].second, id.top()));
	s2[id.top()]++;	id.pop();
	for(int i=1;i<m2; i++){
		if(!t.empty())	while(t.top().first<=fo[i].first){
			id.push(t.top().second);
			t.pop();
			if(t.empty()) break;
		}
		t.push(make_pair(fo[i].second, id.top()));
		s2[id.top()]++;	id.pop();
	}
	for(int i=1;i<n;i++){
		s2[i] += s2[i-1];
	}
	int ans = 0;
	for(int i=0;i<n-1;i++){
		ans = max(ans, s1[i]+s2[n-i-2]);
//		cout << s1[i] << ' ' << s2[n-i-2] << endl;
	}
	ans = max(ans, max(s1[n-1], s2[n-1]));
	cout << ans;
	return 0;
}
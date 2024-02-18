#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> tree[1000];  //인접리스트
vector<bool> visit(1000); //삭제한 노드 표시용
int cnt =0;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < tree[x].size(); i++) {
			int y = tree[x][i];

			if (!visit[y]) {
				visit[y] = true;
				q.push(tree[x][i]);
			}
		}
	
	}
	
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, deln, i, j;
	int num;
	vector<int> v(1000, 0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == -1) {
			continue;      //-1이면 부모노드 존재 x
		}
		tree[num].push_back(i);  //단방향 인접 리스트임
		
	}
	
	cin >> deln;
	bfs(deln);
	
	for (i = 0; i < n; i++) {
		int cnt2 = 0;  
		if (!visit[i]) {
			for (j = 0; j < tree[i].size(); j++) {
				if (tree[i][j] != deln)   //삭제노드 예외처리
					cnt2++;
			}
			if (cnt2 == 0) {  //원소의 개수가 0이면 카운트 증가
				cnt++;
			}
		}
	
	}
	cout << cnt;


}
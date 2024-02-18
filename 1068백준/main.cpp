#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> tree[1000];  //��������Ʈ
vector<bool> visit(1000); //������ ��� ǥ�ÿ�
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
			continue;      //-1�̸� �θ��� ���� x
		}
		tree[num].push_back(i);  //�ܹ��� ���� ����Ʈ��
		
	}
	
	cin >> deln;
	bfs(deln);
	
	for (i = 0; i < n; i++) {
		int cnt2 = 0;  
		if (!visit[i]) {
			for (j = 0; j < tree[i].size(); j++) {
				if (tree[i][j] != deln)   //������� ����ó��
					cnt2++;
			}
			if (cnt2 == 0) {  //������ ������ 0�̸� ī��Ʈ ����
				cnt++;
			}
		}
	
	}
	cout << cnt;


}
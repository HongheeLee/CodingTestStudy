/*
https://www.acmicpc.net/problem/12935

0�� ��带 �߽ɿ� �ΰ� 1~3���� ���� �̷���� �����Ҹ� �̾��شٰ� �����Ѵ�.
�����Ҷ� 0���� ����� 2~3�� ¥�� ���� ��� ���ڸ�ŭ �ܼ���ΰ� 3�ΰ��� �þ
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
int n, s;
int arr[555];
int id = 1;

void _print(int x) {
	cout << 0 << ' ' << id++ << '\n';

	for (int i = 1; i < arr[x]; i++) {
		cout << id - 1 << ' ' << id << '\n';
		id++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> s;

	arr[0] = 2;
	n += 3;

	for (int i = 1; i <= 500; i++) {
		if (cnt + 2 * i <= s) {
			cnt += 2 * i;
			arr[i] = 2;
			n += 2;
		}
		else if (cnt + i <= s) {
			cnt += i;
			arr[i] = 1;
			n++;
		}
		else {
			n += s - cnt;
			for (int j = 1; j <= s - cnt; j++) {
				arr[j]++;
			}
			break;
		}
	}

	cout << n << '\n';
	for (int i = 0; i <= 500; i++) {
		if (arr[i] == 0) break;

		_print(i);
	}




	return 0;
}
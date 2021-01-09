/*
https://programmers.co.kr/learn/courses/30/lessons/60060

Ǯ�� :
������ ���̿� ���� ���� ���ڿ� ������ ���ڸ� ���� �����Ѵ�.
�� �迭�� �����ؼ� ������ �����ϸ� �̺�Ž���� �̿��ؼ� ���Ѵ�.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(),(v).end()
const int mxn = 10001;

string str_cut(string& s) {
	string ret = "";
	
	for (auto c : s) {
		if (c == '?') break;
		ret.push_back(c);
	}

	return ret;
}

int solve(vector<string>& arr, string target, int sz) {
	vector<string>::iterator it1, it2;
	it1 = upper_bound(all(arr), target + "{");
	it2 = lower_bound(all(arr), target);
	return it1 - it2;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> str[mxn], rstr[mxn];

	int l;
	for (auto s : words) {
		l = s.size();
		str[l].push_back(s);
		reverse(all(s));
		rstr[l].push_back(s);
	}

	for (int i = 1; i < mxn; i++) {
		sort(all(str[i]));
		sort(all(rstr[i]));
	}

	for (string q : queries) {
		l = q.size();
		if (q.front() == '?') {
			reverse(all(q));
			q = str_cut(q);
			answer.push_back(solve(rstr[l], q, l));
		}
		else {
			q = str_cut(q);
			answer.push_back(solve(str[l], q, l));
		}
	}


	return answer;
}
#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 16937 �� ��ƼĿ 
	���� �ʵ��б�, ���б����ߴ� ���� ���� ���� ����..
	
	CASE �з� + �ܼ� ����.
	
	�´�� �ִ� ���� ū ���� ����, �´��� ���� ���� �κ��� ���� ���� ���̰� �ȴٴ� ������ �̿��ؼ�
	�� 8���� ���̽� �з����ش�. 
	
	���ǹ��� �ϳ��� ��ġ�� �ڵ�� �ܼ������� �������� �����Ƽ� �ܼ��ϰ� �����ϴ� ���·� �ڵ带 �ۼ��ߴ�. 
*/
int main(){
	int h,w;cin>>h>>w;
	
	vector<pair<int,int>> v;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int r,c;cin>>r>>c;
		v.push_back({r,c});
	}
	
	int ans=0;
	bool check=false;
	for(int i=0;i<n;i++){
		auto A=v[i];
		int AR=v[i].first,AC=v[i].second;
		for(int j=i+1;j<n;j++){
			auto B=v[j];
			int BR=v[j].first,BC=v[j].second;
			int square=AR*AC+BR*BC;
			check=false;
			//�´�� �ִ� ���� �� ū ���� ����, �´��� ���� ���� �� ���� ������.
			if(AR+BR<=h&&max(AC,BC)<=w) check=true;
			if(AR+BR<=w&&max(AC,BC)<=h) check=true;
			if(AC+BC<=h&&max(AR,BR)<=w) check=true;
			if(AC+BC<=w&&max(AR,BR)<=h) check=true;
			if(AR+BC<=h&&max(AC,BR)<=w) check=true;
			if(AR+BC<=w&&max(AC,BR)<=h) check=true;
			if(AC+BR<=h&&max(AR,BC)<=w) check=true;
			if(AC+BR<=w&&max(AR,BC)<=h) check=true;
			if(check) ans=max(square,ans);
		}
	}
	cout<<ans;
} 

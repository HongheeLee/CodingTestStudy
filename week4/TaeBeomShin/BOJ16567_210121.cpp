#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ 16567 ���̳ʸ� �ձ�
	
	- ù �õ� �ð��ʰ� : 0�� ȣ��ɶ����� ���� ���� ���ؼ� �ð��ʰ��� ��.
	- �ڵ� ����, ���� ���ϴ� �ڵ带 ������ ����, ���� ���� �߰��Ǵ� ��츦 ���̽� �з��ؼ�
	  ���� ������Ʈ�ϴ� ���·� ����.
	  
	- ���� : O(N)�� Ǯ�̰� ������ ��찡 ������. ���� ������ ���ö��� �ǽ�����..
			(���ɰ� �¾Ƶ� �������̽����� Ʋ��Ȯ�� �ſ� ����) 
*/
int main(){
	fastio;
	int n,m;cin>>n>>m;
	int road[n];
	for(int i=0;i<n;i++) cin>>road[i];
	
	int count=0;
	for(int i=0;i<n;i++){
		if(road[i]==1){
			while(road[i]==1&&i<n) i++;
			count++;
		}
	}
	
	while(m--){
		int num;cin>>num;
		if(num==0){
			cout<<count<<"\n";
		}else{
			int idx;cin>>idx;
			if(road[idx-1]!=1){
				road[idx-1]=1;
				if(idx-2<0&&road[idx]==0) count++;
				if(idx>=n&&road[idx-2]==0) count++;
				if(idx-2>=0&&idx<n&&road[idx-2]==0&&road[idx]==0) count++;
				if(idx-2>=0&&idx<n&&road[idx-2]==1&&road[idx]==1) count--;	
			}
		}
	}
} 

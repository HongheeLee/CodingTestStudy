#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int room[51][51]={0,};
int main(){
	int r,c,t;cin>>r>>c>>t;
	
	vector<P> cleaner;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			cin>>room[i][j];
			if(room[i][j]==-1) cleaner.push_back({i,j});
		}
	
	
	while(t--){
		vector<P> dust;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(room[i][j]>0) dust.push_back({i,j});
		
		/*
		1.�̼������� Ȯ��ȴ�. Ȯ���� �̼������� �ִ� ��� ĭ���� ���ÿ� �Ͼ��-> ���� Ȯ��� ĭ���ٷ� ���� �ʴ´�. 
		 -(r, c)�� �ִ� �̼������� ������ �� �������� Ȯ��ȴ�.
	 	*/		
		int size=dust.size();
		for(int i=0;i<size;i++){
			auto cur=dust[i];
			int curx=dust[i].first,cury=dust[i].second;
			int count=0;
			for(int dir=0;dir<4;dir++){
				int nx=curx+dx[dir],ny=cury+dy[dir];
				//-������ ���⿡ ����û���Ⱑ �ְų�, ĭ�� ������ �� �������δ� Ȯ���� �Ͼ�� �ʴ´�.
				if(nx<0||ny<0||nx>r||ny>c) continue;
				if(room[nx][ny]==-1) continue;
				room[nx][ny]+=room[curx][cury]/5;
				count++;
			}
			room[curx][cury]-=room[curx][cury]/5*count;
		}
		/*
			2.����û���Ⱑ �۵��Ѵ�.
			-���� ����û������ �ٶ��� �ݽð�������� ��ȯ�ϰ�, �Ʒ��� ����û������ �ٶ��� �ð�������� ��ȯ�Ѵ�.
		*/
		int x=cleaner[0].first, y=clearn[0].second;
		
	}
}

#include<bits/stdc++.h>
using namespace std;
/*
�Ϲ����� ������ �̺�Ž�� ����.
�̺�Ž���� �׻� left,right���� ����� �����ִ°� �߿��ϴ�.
�׷��� ������ testcase�� �ùٸ��� �������� hidden case�� ���� ������ ��찡 ����.

���ݱ��� Ǭ �̺�Ž�� ������ �����غ�����, left�� ���� �� �ִ�, right�� ������ ��������
�ϴ� ���� ���� ���Ҵ�. ���� STl�� lowerbound, upperbound�� �̿��ؾ��ϴ� ������ ����.

�����غ���. 
*/
int main(){
	int n,m;cin>>n>>m;
	
	int arr[n];
	int total=0;
	int maxv=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		total+=arr[i];
		maxv=max(arr[i],maxv);
	}
	
	int right=total,left=maxv,ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		int sum=0,count=0;
		
		for(int i=0;i<n;i++){
			if(sum+arr[i]>mid){
				sum=0;
				count++;
			}
			sum+=arr[i];
		}
		count++;
		(count<=m)?right=mid-1:left=mid+1;
	}
	cout<<left;
}

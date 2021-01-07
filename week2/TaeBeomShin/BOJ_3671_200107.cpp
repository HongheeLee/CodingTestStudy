#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
using namespace std;
const int MAX=1e7;
bool isPrime[MAX+1];//���� �Ҽ����� ����Ǿ� �ִ� �迭.
/*
	���α׷��ӽ� �Ҽ�ã�� ������ ����.
	 
    1. �־��� ���ҷ� ���ڸ� �����.(-> m���� 1��, ... ,m���� m�� ����)
    2. �Ҽ����� Ȯ���Ѵ�-> �迭�� ����� �Ҽ����� Ȯ���Ѵ�.
*/

int solution(string numbers) {
    // �־��� ���ڷ� ������ �����.-> next_permutation
    vector <int> v;
    for(int i=0;i<numbers.size();i++)
        v.push_back(numbers[i]-'0');
    sort(v.begin(),v.end());
    set<int> ans;
    do{
        for(int i=0;i<=v.size();i++){
            int temp=0;
            for(int j=0;j<i;j++){
                temp=(temp*10)+v[j];
                if(isPrime[temp]) ans.insert(temp);
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    return int(ans.size());
}

int main(){
	fastio;
    fill(isPrime+2, isPrime+MAX+1, true);
    for(int i=2; i<=MAX; i++){
        if(!isPrime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i)
            isPrime[j] = false;
    }
    int t;cin>>t;
    while(t--){
    	string num;cin>>num;
    	cout<<solution(num)<<"\n";
	}
}

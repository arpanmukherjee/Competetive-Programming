    #include <iostream>
    #include <set>
    using namespace std;
     
    int main() {
    	int N,c;
    	cin>>N;
    	set<int>S;
    	set<int>::iterator it;
    	for(int i=0;i<N;i++){
    	cin>>c;
    	  S.insert(c);
    	}
    	it=S.end();
    	it--;
    	cout<<*it<<" ";
    	it--;
    	cout<<*it;
    	return 0;
    } 
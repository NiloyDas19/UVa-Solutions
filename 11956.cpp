#include<bits/stdc++.h>
using namespace std;


string hexa(int val){
  string ans;
  while(val > 0){
    int rem = val%16;
    val/=16;
    if(rem>=10){
      if(rem==10) ans+="A";
      else if(rem==11) ans+="B";
      else if(rem==12) ans+="C";
      else if(rem==13) ans+="D";
      else if(rem==14) ans+="E";
      else if(rem==15) ans+="F";
    }
    else{
      ans+=to_string(rem);
    }
  }
  reverse(ans.begin(),ans.end());
  if(ans.size()<=1){
    if(ans.size()==1) ans = "0"+ans;
    else if(ans.size()==0) ans+="00";
  }
  return ans;
}

int main()
{
  int test,i,cs = 0; cin >> test;
  while(test--){
    string s; cin >> s;
    vector<int>store(105,0);
    i = 1;
    for(auto &c:s){
      if(c=='.') {}
      else if(c=='+'){
        store[i]++;
        if(store[i] > 255) store[i] = 0;
      }
      else if(c=='-'){
        store[i]--;
        if(store[i] < 0) store[i] = 255;
      }
      else if(c=='>'){
        i++;
        if(i>100) i = 1;
      }
      else if(c=='<'){
        i--;
        if(i<1) i = 100;
      }
    }

    cout << "Case " << ++cs << ": ";
    for(i=1;i<=100;i++){
      cout << hexa(store[i]) ;
      if(i==100) cout << "\n";
      else cout << " ";
    }
  }
  return 0;
}
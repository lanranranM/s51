#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	//freopen("c:\\Users\\蓝染\\Desktop\\data.in.txt","r",stdin);
	//for(int j=0;j<10;++j){
		string str;
	    cin>>str;
	    string str1=str.substr(0,1);
	    int eachLength=stoi(str1,nullptr,10);
	    str.erase(str.begin());
	    sort(str.begin(),str.end());
	    int n=str.size()/eachLength;
	    str.erase(str.begin()+eachLength*n,str.end());
	    //排序木问题 
	    string min=str;
	    for(int current=0;current<str.size();current+=eachLength){
	    	cout<<"I'm in for"<<endl; 
	    	string currentStr=str.substr(current,eachLength);
	    	cout<<"currentStr:"<<currentStr<<"第一位:"<<str[current]<<endl; 
	    	if(str[current]=='0'){
	    		cout<<"I'm zero now "<<current<<endl;
	    		int i=current;
	    		
	    		while(str[i]=='0')
	    		++i;
	    		str.insert(i+1,str.substr(current,1));
	    		str.erase(str.begin()+current);
	    		cout<<"现在的str:"<<str<<endl;
	    		current-=eachLength;
			}
			else{ 
				cout<<"I'm not zero"<<endl;
				if(currentStr.compare(min)==0){
					if(currentStr.compare(str)==0)
					cout<<"output:"<<currentStr<<" ";
					else{ //这里跳过零有问题！ 
					
					cout<<"we are same "<<endl;
					currentStr=str.substr(current,1)+str.substr(current+2,eachLength-1);
					cout<<"output："<<currentStr<<" ";
					str.insert(current+1,str.substr(current+2,eachLength-1));
					str.erase(str.begin()+current+eachLength+1);
					cout<<"跳零："<<str<<endl; 
				}
				}
				else if(current==0||currentStr.compare(min)>0){
					cout<<"aha"<<endl;
					cout<<"output"<<currentStr<<" ";
					min=currentStr;
				}
			}
			
			cout<<"min:"<<min<<endl;
		
		}
	    cout<<endl;
	 
//}
	return 0; 

}

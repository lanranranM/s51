#include<iostream>     //�ڶ���  case��ͨ�� �޴��Ĳ���ϵ�� 
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("c:\\Users\\��Ⱦ\\Desktop\\data.in.txt","r",stdin);
	for(int j=0;j<10;++j){
		string str;
	    cin>>str;
	    string str1=str.substr(0,1);
	    int eachLength=stoi(str1,nullptr,10);
	    str.erase(str.begin());
	    sort(str.begin(),str.end());
	    int n=str.size()/eachLength;
	    str.erase(str.begin()+eachLength*n,str.end());
	    //debug:cout<<str<<endl;
	    //����ľ���� 
	    string min=str;
	    for(int current=0;current<str.size();current+=eachLength){
	    	//debug:cout<<"I'm in for"<<endl; 
	    	string currentStr=str.substr(current,eachLength);
	    	//debug: cout<<"currentStr:"<<currentStr<<"��һλ:"<<str[current]<<endl; 
	    	if(str[current]=='0'){
	    		//debug:cout<<"I'm zero now "<<current<<endl;
	    		if(eachLength==1){
	    			str.erase(str.begin());
	    			current--;
				} 
	    		else{
	    		int i=current;
	    		while(str[i]=='0')
	    		++i;
	    		str.insert(i+1,str.substr(current,1));
	    		str.erase(str.begin()+current);
	    		//debug: cout<<"���ڵ�str:"<<str<<endl;
	    		current-=eachLength;
	    	}
			}
			else{ 
				//debug: cout<<"I'm not zero"<<endl;
				if(currentStr.compare(min)==0){
				    if(eachLength==1){
						//debug: cout<<"special!"<<endl;
						str.erase(str.begin()+current);
						current--;
					}
					else if(currentStr.compare(str)==0)
					cout<<currentStr<<" ";
					
					else{ //���������������⣡ 
					//debug:cout<<"we are same "<<endl;
					currentStr=str.substr(current,eachLength-1)+str.substr(current+eachLength,1);
					cout<<currentStr<<" ";
					str.insert(current+eachLength-1,str.substr(current+eachLength,1));
					str.erase(str.begin()+current+eachLength+1);
					//debug: cout<<"���㣺"<<str<<endl; 
				}
				}
				else if(current==0||currentStr.compare(min)>0){
					//debug:cout<<"aha"<<endl;
					cout<<currentStr<<" ";
					min=currentStr;
				}
			}			
			//debug: cout<<"min:"<<min<<endl;
			//debug��cout<<"�������壺"<<str<<endl;		
		}
	    cout<<endl;
	}
	return 0; 
}

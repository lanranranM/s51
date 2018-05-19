#include<iostream>    //最后一个有抛出异常orz 思路是循环将每组的component建好，然后跟前面的依次比较。 
#include<vector>      //如遇相同元素的component则合并，最后return vector<string> graph的长度为component数量 
#include<stdio.h>     //vector[0]则为包含A的component 
#include<string>      //遇到的问题：1，不知如何将char加入只声明了的string中 
#include<iomanip>     //            2，太大的数有抛出异常不知为何 
#include<stdlib.h>    //            3，循环那一块不会优化，太复杂 
#include<algorithm>
using namespace std; 
string result;
string Binary(int n){
	int a;
	a=n%2;
	n=n/2;
	if(n!=0){
	    Binary(n);	    
	}	
	result.append(to_string(a));
	return result;
		 
}
string Com(string edges,char current){    //因为不知道怎么用char add到 string后所以被迫先创建好有100个空格的string然后替换掉某个元素 
	string result="                                                                                                     ";
	result[0]=current;
	int a=0;
	for(int i=0;i<edges.size();++i){
		current++;
		if(edges.substr(i,1).compare("1")==0){
			a++;
			result[a]=current;
		}
	}
	
	result.erase(result.begin()+a+1,result.end()); 
	return result;
}
int main(){
	int vertices;
	scanf("%d,",&vertices);
	string Hex;                 //start:输入十六进制将其转换为二进制 
    cin>>Hex;
    int a=stoi(Hex,nullptr,16);
    string bin=Binary(a);
    while(bin.size()%4!=0){
    	bin.insert(0,"0");
	}                         //end 
	
	vector<string> graph;
	int binIndex=0;
	int index=0;
	char current='A';
	for(int j=vertices-1;j>=0;--j){
		
		string edges=bin.substr(binIndex,j);
		//cout<<"检查二进制循环："<<edges<<endl; 
		string currentCom=Com(edges,current);
		graph.push_back(currentCom);
		int cCSize=currentCom.size();
		//cout<<"未进入："<<currentCom<<"in graph:"<<index<<" "<<graph[index]<<endl; 
		int tmp=index;
		if(index!=0){
			while(tmp-1>=0){
			
			for(int z=0;z<graph[tmp-1].size();++z){
				//cout<<"graph上一层：" <<" "<<graph[tmp-1]<<endl;
				for(int y=0;y<currentCom.size();++y){
					 
					if(graph[tmp-1].compare(z,1,currentCom,y,1)==0){
						//cout<<"now:"<<currentCom<<endl;
						currentCom.erase(y,1); 	
						--y;	
						//cout<<"now:"<<currentCom<<endl;				
					}
				}
			}
			if(cCSize!=currentCom.size()){      //啊啊啊这里出问题了 
			
				graph[tmp-1]+=currentCom; //这里不行！ 
				graph.erase(graph.begin()+index);
				//cout<<"result:"<<graph[tmp-1]<<" "<<endl;
				--index;
				--tmp;
				break;
			}
			//else
			--tmp;
		}
		}
		
		++current;
		++index;
		binIndex+=j;
	}
	sort(graph[0].begin(),graph[0].end());
	cout<<graph.size()<<","<<graph[0];
	return 0;
	

    
}

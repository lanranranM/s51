#include<iostream>    //���һ�����׳��쳣orz ˼·��ѭ����ÿ���component���ã�Ȼ���ǰ������αȽϡ� 
#include<vector>      //������ͬԪ�ص�component��ϲ������return vector<string> graph�ĳ���Ϊcomponent���� 
#include<stdio.h>     //vector[0]��Ϊ����A��component 
#include<string>      //���������⣺1����֪��ν�char����ֻ�����˵�string�� 
#include<iomanip>     //            2��̫��������׳��쳣��֪Ϊ�� 
#include<stdlib.h>    //            3��ѭ����һ�鲻���Ż���̫���� 
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
string Com(string edges,char current){    //��Ϊ��֪����ô��char add�� string�����Ա����ȴ�������100���ո��stringȻ���滻��ĳ��Ԫ�� 
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
	string Hex;                 //start:����ʮ�����ƽ���ת��Ϊ������ 
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
		//cout<<"��������ѭ����"<<edges<<endl; 
		string currentCom=Com(edges,current);
		graph.push_back(currentCom);
		int cCSize=currentCom.size();
		//cout<<"δ���룺"<<currentCom<<"in graph:"<<index<<" "<<graph[index]<<endl; 
		int tmp=index;
		if(index!=0){
			while(tmp-1>=0){
			
			for(int z=0;z<graph[tmp-1].size();++z){
				//cout<<"graph��һ�㣺" <<" "<<graph[tmp-1]<<endl;
				for(int y=0;y<currentCom.size();++y){
					 
					if(graph[tmp-1].compare(z,1,currentCom,y,1)==0){
						//cout<<"now:"<<currentCom<<endl;
						currentCom.erase(y,1); 	
						--y;	
						//cout<<"now:"<<currentCom<<endl;				
					}
				}
			}
			if(cCSize!=currentCom.size()){      //����������������� 
			
				graph[tmp-1]+=currentCom; //���ﲻ�У� 
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

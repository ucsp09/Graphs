#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
template <typename T>
class graph_interface{
	protected:map< T, vector<T> > g;
	public:	virtual void add_edge(T node1,T node2)=0;
			void add_node(T a)//complexity O(logn) to find if node exists and then O(1) to add node
			{
				if(g.find(a)==g.end())//find() std::map function
				{
					vector<T> vec;
					g[a]=vec;
					cout<<endl<<"node"<<" "<<a<<" "<<"added successfully";
				}
				else
					throw "This node already exists(cannot add again)";
			}
			void display()//complexity O(nodes*edges)
			{
				typename map< T, vector<T> >::iterator it;
				for(it=g.begin();it!=g.end();++it)
				{
					cout<<endl<<it->first<<":";
					for(int j=0;j<it->second.size();j++)
						cout<<it->second[j];	
				}
			}
};
template <typename T>
class undirected_graph:public graph_interface<T>{
	public:	void add_edge(T node1,T node2)//complexity O(n) to find if edge exists and then O(1) to add edge
			{
				if(node1==node2)
					throw "Self edges are not allowed";
				else
				{
					if(graph_interface<T>::g.find(node1)!=graph_interface<T>::g.end())//find() std::map function
						if(find(graph_interface<T>::g[node1].begin(),graph_interface<T>::g[node1].end(),node2)!=graph_interface<T>::g[node1].end())//find() library algorithm function
							throw "This edge already exists(cannot add again)";
					graph_interface<T>::g[node1].push_back(node2);
					graph_interface<T>::g[node2].push_back(node1);
					cout<<endl<<"edge"<<" "<<node1<<","<<node2<<" "<<"added successfully";	
				}			
			}	
};
template <typename T>
class directed_graph:public graph_interface<T>{
	public:	void add_edge(T node1,T node2)//complexity O(n) to find if edge exits or is bidirectional and then O(1) to add edge
			{
				if(node1==node2)
					throw "Self directed edges are not allowed";
				else
				{
					if(graph_interface<T>::g.find(node1)!=graph_interface<T>::g.end())//find() std::map function
						if(find(graph_interface<T>::g[node1].begin(),graph_interface<T>::g[node1].end(),node2)!=graph_interface<T>::g[node1].end())//find() library algorithm function
							throw "This edge already exists(cannot add again)";
					int flag=0;				
					if(graph_interface<T>::g.find(node2)!=graph_interface<T>::g.end())//find() std::map function
					{
						flag++;
						if(find(graph_interface<T>::g[node2].begin(),graph_interface<T>::g[node2].end(),node1)!=graph_interface<T>::g[node2].end())//find() library algorithm function
							throw "Edges can't be bidirectional'";
					}
					graph_interface<T>::g[node1].push_back(node2);
					if(flag==0)
					{
						vector<T> vec;
						graph_interface<T>::g[node2]=vec;
					}
					cout<<endl<<"edge"<<" "<<node1<<"->"<<node2<<" "<<"added successfully";				
				}	
			}
};
int main()
{
	try{
		directed_graph<int> g1;
		g1.add_edge(1,2);
		g1.add_node(3);
		g1.display();
	}
	catch(const char* msg){
		cout<<endl<<msg;
	}
	return 0;
}

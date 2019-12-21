#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
template <typename T>
class graph_interface{
	public:	map< T , vector<T> > g;
			virtual void add_node(T a)=0;
			virtual void add_edge(T node1,T node2)=0;
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
	public:	void add_node(T a)//complexity O(logn) to find if node exists and then O(1) to add node
			{
				if(graph_interface<T>::g.find(a)==graph_interface<T>::g.end())//find() std::map function
				{
					vector<T> vec;
					graph_interface<T>::g[a]=vec;
					cout<<endl<<"node"<<" "<<a<<" "<<"added successfully";
				}
				else
					throw "This node already exists(cannot add again)";
			}
			void add_edge(T node1,T node2)//complexity O(n) to find if edge exists and then O(1) to add edge
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
int main()
{
	try{
		undirected_graph<int>g1;
		g1.add_node(6);
		g1.add_edge(6,7);
		g1.add_edge(5,4);
		g1.add_edge(6,9);
		g1.add_edge(9,6);
		g1.display();
	}
	catch(const char* msg){
		cout<<endl<<msg;
	}
	return 0;
}

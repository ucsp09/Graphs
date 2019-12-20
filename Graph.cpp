#include<iostream>
#include<map>
#include<vector>
using namespace std;
template <typename T>
class graph
{
	private: map< T , vector<T> > g;
	public:	
  			void add_node(T a)
			{
				if(g.find(a)==g.end())
				{
					vector<T> vec;
					g[a]=vec;
				}
				else
				{
					throw "This node already Exists";
				}
			}
			void add_edge(T node1,T node2)
			{
				if(node1==node2)
					throw "Self edges are not allowed";
				else
				{
					if(g.find(node1)!=g.end())
						if(find(g[node1].begin(),g[node1].end(),node2)!=g[node1].end())
							throw " This Edge already Exists";							
					g[node1].push_back(node2);
					g[node2].push_back(node1);			
				}
			}
}
int main()
{
  	try{
	graph<int> g1;
	g1.add_node(3);
	g1.add_node(4);
 	g1.add_node(5);
	g1.add_edge(2,3);
	g1.add_edge(5,6);
	g1.add_edge(5,6);
	g1.add_edge(2,3);
	}
	catch(const char* msg){
		cout<<endl<<msg;
	}
  return 0;
}

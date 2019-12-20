#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
template <typename T>
class graph
{
	private: map< T , vector<T> > g;
	public:	
  		void add_node(T a)//complexity O(1)
		{
		if(g.find(a)==g.end())//find std::map function
			{
				vector<T> vec;
				g[a]=vec;
       }
				else
				{
				 throw "This node already Exists";
				}
		}
		void add_edge(T node1,T node2)//complexity O(N) to find if edge already exists O(1) to add edge
		{
		if(node1==node2)
			throw "Self edges are not allowed";
		else
			{
			if(g.find(node1)!=g.end())//find std::map function
			     if(find(g[node1].begin(),g[node1].end(),node2)!=g[node1].end())//find #include<algorithm> function
				throw " This Edge already Exists";							
			g[node1].push_back(node2);
			g[node2].push_back(node1);			
			}
		}
		void display()//complexity O(nodes*edges)
		{
			typename map< T , vector<T> >::iterator it;
			for(it=g.begin();it!=g.end();++it)
			{
			cout<<endl<<it->first<<":";
			for(int j=0;j<it->second.size();j++)
				cout<<it->second[j];	
			} 
		}
};
int main()
{
  	try{
	graph<int> g1;
	g1.add_node(3);
	g1.add_node(4);
 	g1.add_node(5);
	g1.add_edge(2,3);
	g1.add_edge(5,6);
	g1.display();
	}
	catch(const char* msg){
		cout<<endl<<msg;
	}
  return 0;
}

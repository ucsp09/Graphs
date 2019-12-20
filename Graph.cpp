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
}
int main()
{
  	try{
	graph<int> g1;
	g1.add_node(3);
	g1.add_node(4);
  	g1.add_node(4);
 	g1.add_node(5);
	}
	catch(const char* msg){
		cout<<endl<<msg;
	}
  return 0;
}

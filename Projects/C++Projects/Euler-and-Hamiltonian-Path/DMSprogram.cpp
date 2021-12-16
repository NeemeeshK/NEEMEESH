#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include<stdio.h>
using namespace std;
int n;

class Euler{
  int V;    
  vector<int> *adj;    
public:
  Euler(int V)  { this->V = V;  adj = new vector<int>[V];  }//declaring no. of vertices and adjecency matrix
  ~Euler()      { delete [] adj;  }
 
  void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }   //creating and updating adjecency matrix
  void rmvEdge(int u, int v);   
  void printEulerTour();
  void printEulerUtil(int s);
  int DFSCount(int v, bool visited[]);
  bool isValidNextEdge(int u, int v);
  int iseuler(int[]);
};

void Euler::printEulerTour(){
  int u = 0;
  for (int i = 0; i < V; i++)
      if (adj[i].size() & 1 )   //taking vertex having odd degree
        {   u = i; break;  }
  printEulerUtil(u);
  cout << endl;
}
 
void Euler::printEulerUtil(int u){
  vector<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i){ //traversing through adjecency matrix
      int v = *i;
      if (v != -1 && isValidNextEdge(u, v)){    // If edge u-v is not removed and it's a a valid next edge
          cout << u << "-" << v << " ";
          rmvEdge(u, v);
          printEulerUtil(v);    //recursive function for all vertices adjacent to this vertex 'u'
        }
    }
}

bool Euler::isValidNextEdge(int u, int v){  //function to check whether u-v edge should be considered as next edge
    int count = 0;  	
    vector<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)    //1.to check whether v is the only adjacent vertex of u
        if (*i != -1)
            count++;
    if (count == 1)
        return true;
    
    //2.code for checking whether u-v is a bridge
    bool visited[V];
    memset(visited, false, V);
    int count1 = DFSCount(u, visited);  //count of vertices reachable from u
    rmvEdge(u, v);
    memset(visited, false, V);
    int count2 = DFSCount(u, visited);  //count vertices reachable from u after removing u-v edge
    addEdge(u, v);
    return (count1 > count2)? false: true;  //if count1>2 => u-v is a bridge if not then we can proceed with is u-v edge
}
 
void Euler::rmvEdge(int u, int v){
  vector<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;
 
  vector<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}
 
int Euler::DFSCount(int v, bool visited[]){     //finding count of vertices reachable using DFS algo 
  visited[v] = true;
  int count = 1;
  vector<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)  // Recur for all vertices adjacent to this vertex
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited);
  return count;
}

int Euler::iseuler(int a[]){    //function for checking whether Euler path/circuit is possible
	int count = 0;
	for(int i=0;i<n;i++){
		if(a[i] % 2 != 0)
			count++;
	}
	if(count == 0){
		cout<<"Euler's circuit exists:\n";
		return 1;
	}
	else if(count == 2){
		cout<<"Euler's path exists:\n";
		return 1;
	}
	else{
		cout<<"No euler's path or circuit exist:'\n\n";
		return -1;
	}
}
 
class Hamiltonian{
	int *path,v,x;
	public:
		Hamiltonian(int n){ v = 0; x = 0; path = new int[n]; }
		bool isSafe(bool graph[][10], int pos);
		bool hamCycleUtil(bool graph[][10], int pos, int i);
		bool hamCycle(bool graph[][10]);
		void printSolution();
};

bool Hamiltonian::isSafe(bool graph[][10], int pos){
    if (graph [ path[pos-1] ][ v ] == 0)  //check whether edege is present in between the previous vertex and new vertex to be added in the path
        return false;
 
     for (int i = 0; i < pos; i++)
        if (path[i] == v)       //check whether the new vertex to be added is already present in the path
            return false;
    return true;
}
 
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i){
    if (pos == n){      //checks whether it's last element of path/cycle(end of path/cycle)
        if ( graph[ path[pos-1] ][ path[0] ] == 1 ){    //check whether last element of path is same as 1st
        	cout<<"Hamiltonian cycle exists\n";
        	x = 1;
    	}
        else
        	cout<<"Hamiltonian path exists\n";
        return true;
    }
    // Try different vertices as a next candidate in Hamiltonian Cycle.
    for (v = 0; v < n; v++){
    	if(v == i)
    		continue;
        if (isSafe(graph, pos)){       //checks whether element to be added is valid or not
            path[pos] = v;
            if (hamCycleUtil (graph, pos+1, i) == true)     // recur to construct rest of the path
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
 
bool Hamiltonian::hamCycle(bool graph[][10]){
    for (int i = 0; i < n; i++) //setting initial path with -1
        path[i] = -1;
    for(int i=0;i < n; i++){
        path[0] = i;    //setting 0th position of path as i
        if ( hamCycleUtil(graph,1,i) == true ){ //initial call to hamCycleUtil with current position as 1 and check it whether it returns true
            printSolution();
            return true;
        }
    }
    cout<<"\nNo Hamiltonian path or cycle exist";
    return false; 

}
 
void Hamiltonian::printSolution()
{
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << "-" << path[i + 1] << " ";  //print path
        
 	if(x == 1)
    	cout << path[n - 1] << "-" << path[0];   //print cycle
    cout<<"\n";
}

int main(){
	int i,j,v1,v2,Edges;
    cout<<"\n Enter the number of vertices of graph: ";
 	cin>>n;
 	Euler g1(n);
 	Hamiltonian g2(n);
 	int a[n] = {0};        //array for degrees
 	bool graph1[10][10];   //adjacency matrix
	for(i=0;i<n;i++)       //initializing adjacency matrix with 0.
  		for(j=0;j<n;j++)
   			graph1[i][j]=0;
 	cout<<"\n Enter the total number of edges: ";
 	cin>>Edges;
	for(i=1;i<=Edges;i++) 	{
  		cout<<"\n Enter the edge: ";
  		cin>>v1>>v2;
  		graph1[v1][v2]=1;   //setting adjecency matrix (used in euler)
  		graph1[v2][v1]=1;   //setting adjecency matrix (used in euler)
  		g1.addEdge(v1, v2);     //adding edge for euler path implementation
  		a[v1]++;	//incrementing degree (used for euler)
		a[v2]++;    //incrementing degree (used for euler)
 	}
 	cout<<"\n";
 	g2.hamCycle(graph1);    //call to find hamiltonian path
 	cout<<"\n";
 	if(g1.iseuler(a) == 1)      //checking if euler path can be found or not using degrees' logic
 		g1.printEulerTour();
  return 0;
}
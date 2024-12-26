#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SolutionSeven{
public:
	void DFS(int node, unordered_map<int,vector<int>> adj, unordered_map<int,bool>& visited,
		     int& edgesCount, int& verticesCount){
		visited[node]=true;
		verticesCount++;
		for(int adjNode: adj[node]){
			edgesCount++;
			if(!visited[adjNode]){
				DFS(adjNode,adj,visited,edgesCount,verticesCount);
			}
		}
	}
	int countCompleteComponents(int n, vector<vector<int>>& edges){
		unordered_map<int,vector<int>> adj;
		unordered_map<int,bool> visited;
		for(int i=0; i<edges.size(); i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int edgesCount=0;
			int verticesCount=0;
			if(!visited[i]){
				DFS(i,adj,visited,edgesCount,verticesCount);
				if(verticesCount*(verticesCount-1)==edgesCount) ans++;
			}
		}
		return ans;
	}
};

int main(){
	return 0;
}
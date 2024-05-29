class Solution {
public:

    bool iscycle(int i,int parent,vector<vector<int>>&ans,vector<int>&visited){
        
        visited[i]=1;
        
        for(auto ele:ans[i]){
            if(!visited[ele]){
                if(iscycle(ele,i,ans,visited))return true;
            }
            
            else if(parent!=ele)return true;
        }
        
        visited[i]=0;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<vector<int>>ans(edges.size()+1);
        vector<int>visited(edges.size()+1);
            
        for(int i=0;i<edges.size();i++){
              
               ans[edges[i][0]].push_back(edges[i][1]);
               ans[edges[i][1]].push_back(edges[i][0]);

               
         if(iscycle(edges[i][0],-1,ans,visited))return edges[i];
                
        }
        
        return {};
    }
};
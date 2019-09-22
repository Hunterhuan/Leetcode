class Solution {
    map<int, set<int>> group2item; //组织架构，没有小组的项目会分配一个唯一的小组
    
    map<int, int> groupInNum;       //每个小组的入度
    map<int, set<int>> groupDir;   //小组的依赖图
    map<int, int> itemInNum;       //组内每个成员的入度
    map<int, set<int>> itemDir;    //组内的依赖图

    
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int minGroup = m;
        
        for(int i=0;i<group.size();i++){
            if(group[i] == -1){
                group[i] = minGroup++;
            }
            group2item[group[i]].insert(i);
        }
        for(int to = 0; to < beforeItems.size(); to++){
            int toGroup = group[to];
            for(auto from: beforeItems[to]){
                int fromGroup = group[from];
                
                if(toGroup == fromGroup){
                    itemDir[from].insert(to);
                    itemInNum[to]++; //入度加一
                }else{
                    if(groupDir[fromGroup].count(toGroup) == 0){
                        groupDir[fromGroup].insert(toGroup);
                        groupInNum[toGroup]++; //入度加一
                    }
                }
            }
        }
        
        //第一步检查小组间是否有冲突
        queue<int> que;
        vector<int> groupAns;
        for(int to = 0; to < minGroup; to++){
            if(groupInNum[to] == 0){
                que.push(to);
                groupAns.push_back(to);
            }
        }
        
        while(!que.empty()){
            int from = que.front();
            que.pop();
            for(auto to: groupDir[from]){
                groupInNum[to]--;
                if(groupInNum[to] == 0){
                    que.push(to);
                    groupAns.push_back(to);
                }
            }
        }
        if(groupAns.size() != minGroup){
            return {};
        }
        
        //第二部检查小组内的项目是否有冲突
        vector<int> ans;
        
        
        for(auto id: groupAns){
            auto& items = group2item[id];
            
            int num = 0;
            for(auto to: items){
                if(itemInNum[to] == 0){
                    que.push(to);
                    ans.push_back(to);
                    num++;
                }
            }
            
            while(!que.empty()){
                int from = que.front();
                que.pop();
                for(auto to: itemDir[from]){
                    itemInNum[to]--;
                    if(itemInNum[to] == 0){
                        que.push(to);
                        ans.push_back(to);
                        num++;
                    }
                }
            }
            
            if(num != items.size()){
                return {};
            } 
        }
        return ans;
        
    }
};
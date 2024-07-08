class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> genes(bank.begin(),bank.end());
        if(genes.find(endGene) == genes.end()){
            return -1;
        }
        queue<pair<string , int>> q;
        q.push({startGene,0});

        vector<char> gene({'A','C','G','T'});

        while(!q.empty()){
            auto [current,level] = q.front();
            q.pop();

            for(int i = 0;i<current.size();i++){
                string temp  = current;
                for(int j = 0;j<gene.size();j++){
                    temp[i] = gene[j];
                    if(temp == endGene){
                        return level+1;
                    }

                    if(genes.find(temp) != genes.end()){
                        q.push({temp,level+1});
                        genes.erase(temp);
                    }
                }
            }
        }

        return -1;
    }
};
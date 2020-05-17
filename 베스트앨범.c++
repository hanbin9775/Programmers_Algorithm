#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

bool compare2(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m;
    map<string, int>:: iterator it;

    int len = genres.size();

    for(int i=0; i<len; i++){
        it = m.find(genres[i]);

        if(it == m.end()){
            m.insert(make_pair(genres[i],plays[i]));    
        }
        else{
            it->second += plays[i];
        }
    }

    vector<pair<string,int>> sortV;

    for(auto iter = m.begin(); iter !=m.end(); iter++){
        sortV.push_back(make_pair(iter->first, iter->second));
    }

    sort(sortV.begin(), sortV.end(), compare);

    vector<vector<pair<int,int>>> bestAlbum;

    vector<pair<int,int>> temp_v;

    for(int i=0; i<sortV.size(); i++){

        for(int j=0; j<len; j++){
            if(genres[j]==sortV[i].first){
                temp_v.push_back(make_pair(plays[j],j));
            }
        }
        sort(temp_v.begin(), temp_v.end(), compare2);
        bestAlbum.push_back(temp_v);
        temp_v.clear();
    }    

    for(int i=0; i<bestAlbum.size(); i++){
        for(int j=0; j<bestAlbum[i].size(); j++){
            answer.push_back(bestAlbum[i][j].second);
            if(j==1){
                break;
            }
        }
    }


    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> cache;
    vector<string>:: iterator it;
    int cur=0;
    int len = cities.size();
    while(cur<len){
        string city = cities[cur];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        it = find(cache.begin(), cache.end(), city);

        //cache hit
        if(it != cache.end()) {
            answer+=1;
            cache.erase(it);
            cache.push_back(city);
        }
        //cache miss
        else{
            answer+=5;
            if(cache.size()<cacheSize) cache.push_back(city);           
            else if(cacheSize>0){
                cache.erase(cache.begin());
                cache.push_back(city);
            }
        }
        cur++;
    }

    return answer;
}
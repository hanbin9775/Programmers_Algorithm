#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convertSharp(string a){
    for(int i=0; i<a.length(); i++){
        if(a[i]=='#'){
            a[i-1]= tolower(a[i-1]);
            a.erase(a.begin()+(i--));
        }
    }
    return a;
}

int getInterval(string a, string b){
    int hour_interval = stoi(b.substr(0,2))-stoi(a.substr(0,2));
    int minute_interval = stoi(b.substr(3,2))-stoi(a.substr(3,2));
    return hour_interval*60 + minute_interval;
}

//melody_total, title, interval
pair<pair<string,string>,int> printMelody(string info){

    string start;
    string end;
    string title;
    string melody;
    string melody_total="";

    int f_c = info.find(',');
    start = info.substr(0, f_c);
    int s_c = info.find(',', f_c+1);
    end = info.substr(f_c+1, s_c-f_c-1);
    int t_c = info.find(',', s_c+1);
    title = info.substr(s_c+1, t_c-s_c-1);
    melody = convertSharp(info.substr(t_c+1));

    int interval = getInterval(start, end);

    int idx=0;
    for(int i=0; i<interval; i++){
        if(idx==melody.length()) idx=0;
        melody_total += melody[idx++];
    }
    return make_pair(make_pair(melody_total, title),interval);
}

bool comp(pair<pair<string,string>,int> a, 
          pair<pair<string,string>,int> b){
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    pair<pair<string,string>,int> temp;
    m = convertSharp(m);
    vector<pair<pair<string,string>,int>> cache;
    for(int i=0; i<musicinfos.size(); i++){
        temp = printMelody(musicinfos[i]);
        if(temp.first.first.find(m)!=string::npos){
            cache.push_back(temp);
        }
    }
    if (cache.size() ==0 )return "(None)";

    stable_sort(cache.begin(), cache.end(), comp);

    return cache[0].first.second;
}
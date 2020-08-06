#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<int,int>> info;

    for(int i=0; i<lines.size(); i++){
        //end ms time
        int h_to_ms = (10*(lines[i][11]-'0') + lines[i][12]-'0') * 3600000;
        int m_to_ms = (10*(lines[i][14]-'0') + lines[i][15]-'0') * 60000;
        int s_to_ms = (10*(lines[i][17]-'0') + lines[i][18]-'0') * 1000;
        int ms = 100*(lines[i][20]-'0')+10*(lines[i][21]-'0')+(lines[i][22]-'0');
        int end_ms_time = h_to_ms + m_to_ms + s_to_ms + ms;

        //process time
        string pt_to_str = lines[i].substr(24,lines[i].length()-25);
        float f = stof(pt_to_str);
        int process_time = 1000*f;
        int start_ms_time = end_ms_time-process_time+1;

        info.push_back(make_pair(start_ms_time, end_ms_time));
    }

    for(int i=0; i<info.size()-1; i++){

        int range_start = info[i].second;
        int range_end = range_start+999;
        int cnt = 1;

        for(int j=i+1; j<info.size(); j++){
            int start_time = info[j].first;
            int end_time = info[j].second;

            if(start_time<= range_start && range_start<=end_time) cnt++;
            else if(range_start<=start_time && end_time<=range_end) cnt++;
            else if(start_time<= range_end && range_end<=end_time) cnt++;
            else if(start_time<= range_start && range_end<=end_time) cnt++;
        }
        answer = max(answer , cnt);
    }

    return answer;
}
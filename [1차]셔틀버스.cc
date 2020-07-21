#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int answer =0;
    vector<int> time_to_min;

    for(int i=0; i<timetable.size(); i++){
        string time = timetable[i];
        time_to_min.push_back(((time[0]-'0')*10+(time[1]-'0'))*60+(time[3]-'0')*10+time[4]-'0');
    }
    sort(time_to_min.begin(), time_to_min.end());

    int idx=0;
    int last_bus = 540 + (n-1) * t;
    for(int bus_time=540; bus_time<=last_bus; bus_time+=t){
        int cnt=0;
        for(idx; idx<time_to_min.size(); idx++){
            if(cnt==m) break;
            if(time_to_min[idx]<=bus_time) cnt++;
            else break;
        }

        //막차일 떄
        if(bus_time==last_bus){
            //꽉차서 못탈 때, 전 사람보다 1분 빨리옴
            if(cnt==m){
                answer = time_to_min[idx-1]-1;
            } 
            // 자리빌때
            else{
                answer = bus_time;
            }
        }
    }
    int hour = answer/60;
    int minute = answer%60;
    return to_string(hour/10)+to_string(hour%10)+":"+to_string(minute/10)+to_string(minute%10);
}
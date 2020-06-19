#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string days[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int diff=0;
    for(int i=1; i<a; i++){
        if(i==2) diff+=29;
        else{
            if(i<=7){
                if(i%2==1) diff+=31;
                else if(i%2==0) diff+=30;
            }
            else if(i>7){
                if(i%2==0) diff+=31;
                else if(i%2==1) diff+=30;
            }
        }
    }
   return days[(diff+b-1)%7];
}
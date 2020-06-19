function solution(priorities, location) {
    var answer = 0;
    var cur_loc = location;
    
    var max = Math.max(...priorities);
    var cnt=1;
    while(true){
        if(priorities[0]=== max){
            //원하는 location의 값의 순서라면
            if(cur_loc===0){
                answer = cnt;
                break;
            }
            //원하는 순서가 아니면 빼버림
            priorities.shift();
            cnt+=1;
            if(cur_loc>0){
                cur_loc-=1;
            }
            else if(cur_loc===0){
                cur_loc = priorities.length-1;
            }
            max = Math.max(...priorities);
            console.log("poped!");
        }
        else {
            priorities.push(priorities.shift());
            if(cur_loc>0){
                cur_loc-=1;
            }
            else if(cur_loc===0){
                cur_loc = priorities.length-1;
            }
        }
            
    }
    
    return answer;
}

console.log(solution([1,1,9,1,1,1],0))
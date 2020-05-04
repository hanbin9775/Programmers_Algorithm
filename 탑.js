function solution(heights) {
    var answer = [];
    
    var len = heights.length;
    console.log(len);

    var height;
    var temp =[];
    var check;

    heights.reverse();

    for(var i=1; i<len; i++){

        check = true;

        height = heights[i-1];
        
        temp = heights.slice(i);
        var temph = temp.length;
        
        for(var j=0; j<temph; j++){
            if(height < temp[j]){
                answer.push(len-(i+j));
                check = false;
                break;
            }
        }
        if(check === true){
            answer.push(0);
        }
    }
    answer.push(0);
    answer.reverse();

    return answer;
}

console.log(solution([3, 9, 9, 3, 5, 7, 2]));
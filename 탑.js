function solution(heights) {
    
    return heights.map((v,i)=>{
        console.log(v+" "+i );
        while(i){
            i--;
            if(heights[i]>v){
                return i +1;
            }
        }
        return 0;
    });   
    
}

console.log(solution([3, 9, 9, 3, 5, 7, 2]));
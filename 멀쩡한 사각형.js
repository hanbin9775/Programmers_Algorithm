function gcd(m,n){
    if(m%n==0){
        return n;
    }
    else{
        return gcd(n,m%n);
    }
}

function solution(w,h){
	var answer = 1;
    var intersect = w+h-1;
    
    const shorterGCD = (a,b) =>{
        return b === 0 ? a : shorterGCD(b,a%b);
    }
    
    var gcdWH = gcd(w,h);
    
    if(gcdWH!=1){
        intersect -= gcdWH-1;        
    }
    
    answer = w*h - intersect;
    
	return answer;
}
function solution(n, left, right) {
  const flattedArray = [];
  for (let i = left; i <= right; i++) {
    let element = parseInt(i / n) <= i % n ? (i % n) + 1 : parseInt(i / n) + 1;
    flattedArray.push(element);
  }
  return flattedArray;
}

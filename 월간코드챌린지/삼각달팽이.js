function solution(n) {
  const answer = Array(n)
    .fill()
    .map((_, i) => Array(i + 1).fill(0));

  const length = (n * (n + 1)) / 2;
  const dirArr = ["down", "right", "up"];
  let dirIdx = 0;
  let x = 0;
  let y = 0;
  for (let i = 0; i < length; i++) {
    answer[y][x] = i + 1;
    if (dirArr[dirIdx] === "down") {
      y += 1;
      if (!answer[y] || answer[y][x] !== 0) {
        y -= 1;
        x += 1;
        dirIdx = (dirIdx + 1) % 3;
      }
    } else if (dirArr[dirIdx] === "right") {
      x += 1;
      if (!answer[y] || answer[y][x] !== 0) {
        y -= 1;
        x -= 2;
        dirIdx = (dirIdx + 1) % 3;
      }
    } else {
      x -= 1;
      y -= 1;
      if (!answer[y] || answer[y][x] !== 0) {
        y += 2;
        x += 1;
        dirIdx = (dirIdx + 1) % 3;
      }
    }
  }

  return answer.flat();
}

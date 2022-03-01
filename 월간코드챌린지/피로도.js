const traverseDungeons = (dungeons, visited, curFatigue, answerScope) => {
  visited.forEach((dungeon, idx) => {
    const newVisited = [...visited];
    const [least, consume] = dungeons[idx];

    if (!dungeon && curFatigue >= least) {
      newVisited[idx] = true;
      const visitedNum = newVisited.filter((item) => item).length;
      if (visitedNum > answerScope.answer) answerScope.answer = visitedNum;
      traverseDungeons(dungeons, newVisited, curFatigue - consume, answerScope);
    }
  });
};

function solution(k, dungeons) {
  const answerScope = { answer: 0 };
  const dungeonsLength = dungeons.length;
  const visitedDungeonsArray = Array(dungeonsLength).fill(false);
  traverseDungeons(dungeons, visitedDungeonsArray, k, answerScope);
  return answerScope.answer;
}

2;
3;
4;
5;
6;
7;
8;
9;
10;
11;
12;
13;
14;
15;
16;
const dictionary = new Set([]);
const words = ["", "A", "E", "I", "O", "U"];

const writeDictionary = (curIdx, curWord) => {
  if (curIdx === 5) {
    if (curWord) dictionary.add(curWord);
    return;
  }
  words.forEach((word) => writeDictionary(curIdx + 1, curWord + word));
};

function solution(word) {
  writeDictionary(0, "");
  return [...dictionary].sort().findIndex((dicWord) => dicWord === word) + 1;
}

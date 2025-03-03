#include <bits/stdc++.h>
using namespace std;

vector<string> wordBreak(string s, vector<string> &wordDict,
                         vector<int> &scores) {
  if (wordDict.empty()) {
    return {};
  }

  unordered_map<string, int> wordToScore;
  for (size_t i = 0; i < wordDict.size(); ++i) {
    wordToScore[wordDict[i]] = scores[i];
  }

  unordered_map<int, pair<int, vector<string>>> memo;

  function<pair<int, vector<string>>(int)> dfs =
      [&](int index) -> pair<int, vector<string>> {
    if (index == s.length()) {
      return {0, {""}};
    }

    if (memo.find(index) != memo.end()) {
      return memo[index];
    }

    int maxScore = INT_MIN;
    vector<string> bestSentences;

    for (const string &word : wordDict) {
      if (s.compare(index, word.length(), word) == 0) {
        auto [remainingScore, sentences] = dfs(index + word.length());
        int totalScore = remainingScore + wordToScore[word];

        if (totalScore > maxScore) {
          maxScore = totalScore;
          bestSentences.clear();
          for (const string &sentence : sentences) {
            bestSentences.push_back(sentence.empty() ? word
                                                     : sentence + " " + word);
          }
        } else if (totalScore == maxScore) {
          for (const string &sentence : sentences) {
            bestSentences.push_back(sentence.empty() ? word
                                                     : sentence + " " + word);
          }
        }
      }
    }

    return memo[index] = {maxScore, bestSentences};
  };

  auto [maxScore, sentences] = dfs(0);
  return sentences.size() ? sentences : vector<string>{"No Result"};
}

void solve() {
  string s;
  cin >> s;

  int n;
  cin >> n;

  vector<string> wordDict(n);
  vector<int> scores(n);

  for (int i = 0; i < n; ++i) {
    cin >> wordDict[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> scores[i];
  }

  vector<string> result = wordBreak(s, wordDict, scores);
  for (const string &sentence : result) {
    cout << sentence << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
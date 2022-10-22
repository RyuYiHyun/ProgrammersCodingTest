//https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


bool playcomp(pair<string, pair<int, int>>& a, pair<string, pair<int, int>>& b)
{
    return a.second.second > b.second.second;
}

bool comp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<pair<string, pair<int, int>>> playlist; // <장르 : < index : 재생수>>
    unordered_map<string, int> playCount;
    int i = 0;
    for (auto e : genres)
    {
        playlist.push_back(make_pair(e, make_pair(i, plays[i])));
        playCount[e] += plays[i]; // 장르별 재생수 세기
        i++;
    }

    vector<pair<string, int>> rank(playCount.begin(), playCount.end());
    sort(rank.begin(), rank.end(), comp); // 장르 랭킹 순 정렬
    sort(playlist.begin(), playlist.end(), playcomp); // 재생 많은 순으로 정렬

    vector<int> index;
    for (auto r : rank)
    {
        string check_genres = r.first;
        int count = 0;
        for (auto k : playlist)
        {
            if (check_genres == k.first && count < 2)
            {
                index.push_back(k.second.first);
                ++count;
            }
        }
    }
    return index;
}
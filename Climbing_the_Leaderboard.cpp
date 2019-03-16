/*
Alice is playing an arcade game and wants to climb to the top of the leaderboard and wants to track her ranking. 
The game uses Dense Ranking, so its leaderboard works like this:

The player with the highest score is ranked number  on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately 
following ranking number.
For example, the four players on the leaderboard have high scores of 100, 90 , 90 , and 80 . Those players will have ranks
1 , 2 , 2 , and 3 , respectively. If Alice's scores are 70, 80 and 105, her rankings after each game are 4th, 3rd and 1st.
Function Description

Complete the climbingLeaderboard function in the editor below. It should return an integer array where each element
represents Alice's rank after the jth game.

climbingLeaderboard has the following parameter(s):

scores: an array of integers that represent leaderboard scores
alice: an array of integers that represent Alice's scores

Sample Input 1:
7
100 100 50 40 40 20 10
4
5 25 50 120

Sample Output 1:
6 4 2 1

Sample Input 2:
6
100 90 90 80 75 60
5
50 65 77 90 102

Sample Output 2:
6 5 4 2 1
*/
vector<int> climbingLeaderboard(vector<int> s, vector<int> a) 
{
    vector<int> v(a.size());
    
    int i,j=0,pos=1,k=a.size()-1;
    for(i=k;i>=0;i--)
    {
        for(;j<s.size();j++)
        {
            if(a[i]>=s[j])
            {
                v[k--]=pos;
                break;
            }
            if(s[j]!=s[j-1])
            {
                pos++;
            }
        }
    }
    while(k>=0)
    {
        v[k--]=pos;
    }
    return v;
}
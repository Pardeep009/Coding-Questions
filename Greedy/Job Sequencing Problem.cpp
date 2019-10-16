/*

  Given a set of N jobs where each job i has a deadline and profit associated to it.
  Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
  We earn the profit if and only if the job is completed by its deadline. 
  The task is to find the maximum profit and the number of jobs done.
   
  Example:
  Input:
  2
  4
  1 4 20 2 1 10 3 1 40 4 1 30
  5
  1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

  Output:
  2 60
  2 127

  Explanation:
  Testcase 1: 2 jobs can be done with maximum profit of 60.
  
*/
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id,deadline,profit;
};

typedef Job Job;

bool comparator(Job j1,Job j2)
{
    return j1.profit>j2.profit;
}

int main() {
	//code
	int t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Job jobs[n];
        int max_deadline = 0;
        for(i=0;i<n;i++)
        {
            cin>>jobs[i].id;
            cin>>jobs[i].deadline;
            cin>>jobs[i].profit;
            max_deadline = max(max_deadline,jobs[i].deadline);    
        }
        int intervals[max_deadline];
        for(i=0;i<max_deadline;i++)
        {
            intervals[i] = 0;
        }
        sort(jobs,jobs+n,comparator);
        int sel_jobs = 0;
        int profit = 0;
        i=0;
        int j;
        while(i<n)
        {
            for(j = jobs[i].deadline-1;j>=0;j--)
            {
                if(intervals[j] == 0)
                {
                    sel_jobs++;
                    profit += jobs[i].profit;
                    intervals[j] = 1;
                    break;
                }
            }
            i++;
        }
        cout<<sel_jobs<<" "<<profit<<endl;
    }
	return 0;
}

/*
Hackerland is a one-dimensional city with houses aligned at integral locations along a road. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a fixed range meaning it can transmit a signal to all houses within that number of units distance away.

Given a map of Hackerland and the transmission range, determine the minimum number of transmitters so that every house is within range of at least one transmitter. Each transmitter must be installed on top of an existing house.

For example, assume houses are located at x=[1,2,3,5,9]  and the transmission range k=1 .Antennae at houses 2 and 5 and 9 would provide complete coverage. There is no house at location 7 to cover both 5 and 9. Ranges of coverage, are [1,2,3],[5] , and [9].

Complete the hackerlandRadioTransmitters function in the editor below. It must return an integer that denotes the minimum number of transmitters to install.

hackerlandRadioTransmitters has the following parameter(s):

v: integer array that denotes the locations of houses
k: an integer that denotes the effective range of a transmitter

Sample Input 0
5 1
1 2 3 4 5

Sample Output 0
2

Explanation 0
We can cover the entire city by installing 2 transmitters on houses at locations 2 and 4.
*/

int hackerlandRadioTransmitters(vector<int> v, int k)
{
    int c=0;
        int i=1,j=0;
        int l=v.size();
        sort(v.begin(),v.end());
        vector<int>::iterator ub=v.begin();
        while(i<l)
        {
            if(v[i]-v[j]<=k)
            i++;
        else
        {
            c++;
            ub=upper_bound(v.begin(),v.end(),v[i-1]+k);
            if(ub==v.end())
            return c;
            j=ub-v.begin();
            i=j+1;
        }
    }
    return c+1;
}

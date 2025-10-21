class Solution
{
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps)
    {
        /*
        dp1[k] = the min time to take some tire k laps (num_lap * len(tires))

        -> Observations:
            worst case is to take the min tire num_laps times
            Then the total time will be 10^5 * 10^3 = 10^8
            dp1[k] should always be <= 10^8
            k <= log2(10^8) log min_r(10^8)
            so the time complexity will be log2(10^8) * len(tires)

        dp2[l] = min time to finish l laps, (dp1[i]+dp2[l-i]) for all i: 1->num_laps (num_laps^2)
        */
    }
};
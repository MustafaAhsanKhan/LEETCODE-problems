class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        double ans = abs((11.0 / 2.0) * minutes - 30 * hour);
        if(ans > 180)
            return 360.0 - ans;
        return ans;
    }
};
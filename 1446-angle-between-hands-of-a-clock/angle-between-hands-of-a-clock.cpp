class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteangle=6.0*minutes;
        double hrangle = 30.0*(hour%12) + 0.5*minutes;
        double ans=abs(hrangle-minuteangle);
        return min(ans,360.0-ans);
    }
};
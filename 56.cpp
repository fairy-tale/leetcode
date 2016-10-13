/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
private:
	static bool cmp(Interval v1, Interval v2) {
		return v1.start < v2.start;
	}
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		int n = intervals.size();
		if (!n) return res;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval tmp = intervals[0];
		for (int i = 1; i < n; ++i) {
			if (intervals[i].start <= tmp.end) {
				tmp.end = max(tmp.end, intervals[i].end);
			}
			else {
				res.push_back(tmp);
				tmp = intervals[i];
			}
		}
		res.push_back(tmp);
		return res;
	}
};
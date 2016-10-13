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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int n = intervals.size();
		vector<Interval> res;
		if (!n) {
			res.push_back(newInterval);
		}
		else {
			sort(intervals.begin(), intervals.end(), cmp);
			Interval tmp = newInterval;
			bool flag = false;
			for (int i = 0; i < n; ++i) {
				if (intervals[i].end < newInterval.start) {
					res.push_back(intervals[i]);
				}
				else if (intervals[i].start > newInterval.end) {
					if (!flag) {
						flag = true;
						res.push_back(tmp);
					}
					res.push_back(intervals[i]);
				}
				else {
					tmp.start = min(tmp.start, intervals[i].start);
					tmp.end = max(tmp.end, intervals[i].end);
				}
			}
			if (!flag) res.push_back(tmp);
		}
		return res;
	}
};
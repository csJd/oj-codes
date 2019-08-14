"""
154. Day of the Year https://leetcode.com/problems/day-of-the-year/
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61


Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
"""

from datetime import datetime


class Solution:
    def dayOfYear(self, date: str) -> int:
        start_date = date[:5] + "01-01"
        start = datetime.strptime(start_date, "%Y-%m-%d")
        end = datetime.strptime(date, "%Y-%m-%d")
        delta = end-start
        return delta.days + 1


def main():
    solu = Solution()
    print(solu.dayOfYear("2019-01-09"))


if __name__ == "__main__":
    main()

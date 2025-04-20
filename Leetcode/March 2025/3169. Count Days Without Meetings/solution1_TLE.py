"""
    Time Limit Exceeded
"""
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        md = set()
        for st,nd in meetings:
            
            for i in range(st, nd+1):
                md.add(i)
            
        # print(len(md))
        return days - len(md)
        
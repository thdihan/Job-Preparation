### 595. Big Countries

[Link](https://leetcode.com/problems/big-countries/description/?envType=study-plan-v2&envId=top-sql-50)

```sql
-- Write your PostgreSQL query statement below
SELECT name, population, area
FROM world
WHERE area >= 3000000 OR population >= 25000000;
```

### 1148. Article Views I

[Link](https://leetcode.com/problems/article-views-i/description/?envType=study-plan-v2&envId=top-sql-50)

```sql
-- Write your PostgreSQL query statement below
SELECT DISTINCT author_id as id
FROM views
WHERE author_id = viewer_id
ORDER BY id ASC;
```

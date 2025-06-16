### 1683. Invalid Tweets

[Link](https://leetcode.com/problems/invalid-tweets/?envType=study-plan-v2&envId=top-sql-50)

```sql
-- Write your PostgreSQL query statement below
SELECT tweet_id
FROM tweets
WHERE LENGTH(content) > 15;
```

```sql
-- Write your PostgreSQL query statement below
SELECT tweet_id
FROM (
    SELECT length(content) as no_of_char, tweet_id
    FROM tweets
)
WHERE no_of_char > 15;

```

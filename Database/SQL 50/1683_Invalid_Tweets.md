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

#### Q:

1. What is the diff btwn length() in select and LENGTH() in where clause?
2. What are the functions can be used in where clause like LENGTH()?

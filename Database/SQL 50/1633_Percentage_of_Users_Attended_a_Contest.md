### 1633. Percentage of Users Attended a Contest

[Link]()

```sql
-- Write your PostgreSQL query statement below
SELECT
    C.contest_id as contest_id,
    ROUND((COUNT(C.user_id) * 1.0 / MAX(U.total_user) * 1.0) * 100, 2) as percentage
FROM
    Register AS C,
    (
        SELECT COUNT(*) AS total_user
        FROM Users
    ) AS U
GROUP BY
    C.contest_id
ORDER BY
    percentage DESC, contest_id ASC
```

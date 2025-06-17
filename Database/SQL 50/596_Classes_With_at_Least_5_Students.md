### 596. Classes With at Least 5 Students

[Link]()

```sql
-- Write your PostgreSQL query statement below
SELECT
    class
FROM
    Courses
GROUP BY
    class
HAVING
    COUNT(student) >= 5

```

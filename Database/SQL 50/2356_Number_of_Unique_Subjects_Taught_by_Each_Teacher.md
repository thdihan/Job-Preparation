### 2356. Number of Unique Subjects Taught by Each Teacher

[Link]()

```sql
# Write your MySQL query statement below
SELECT
    teacher_id,
    count(DISTINCT subject_id) AS cnt
FROM
    Teacher
GROUP BY
    teacher_id;

```

### 1280. Students and Examinations

[Link]()

---

A `CROSS JOIN` in SQL returns the Cartesian product of two tables. That means it combines every row of the first table with every row of the second table, regardless of any condition.

```sql
-- Write your PostgreSQL query statement below
SELECT ST.student_id AS student_id, student_name, SU.subject_name AS subject_name, COUNT(E.student_id) attended_exams
FROM Students AS ST
CROSS JOIN Subjects AS SU
LEFT JOIN Examinations AS E
    ON ST.student_id = E.student_id AND SU.subject_name = E.subject_name
GROUP BY ST.student_id, student_name, SU.subject_name
ORDER BY ST.student_id, student_name, SU.subject_name;
```

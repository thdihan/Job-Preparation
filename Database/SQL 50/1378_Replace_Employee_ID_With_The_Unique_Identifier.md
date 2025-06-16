### 1378. Replace Employee ID With The Unique Identifier

[Link](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=top-sql-50)

---

-   `LEFT JOIN` is used to get all the data from left table even if there is no match of id with right table.
-   `LEFT JOIN` is basically `LEFT (OUTER) JOIN`.

---

```sql
-- Write your PostgreSQL query statement below
SELECT unique_id, name
FROM Employees
LEFT JOIN EmployeeUNI
    ON Employees.id = EmployeeUNI.id;
```

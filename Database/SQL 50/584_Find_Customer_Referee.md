### 584. Find Customer Referee

[Link](https://leetcode.com/problems/find-customer-referee/?envType=study-plan-v2&envId=top-sql-50)

---

Tips \
The key is to always use `IS NULL` or `IS NOT NULL` operators to specifically check for NULL value. Using `referee_id != NULL` will give wrong answer.

---

```sql
-- Write your PostgreSQL query statement below

SELECT name
FROM customer
WHERE referee_id <> 2 OR referee_id IS NULL;
```

```sql
-- Write your PostgreSQL query statement below

SELECT name
FROM customer
WHERE id NOT IN (
    SELECT id FROM customer
    WHERE referee_id = 2
);
```

```
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+

Output:
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```

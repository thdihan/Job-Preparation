### 1211. Queries Quality and Percentage

[Link]()

---

IMP: NEED TO RECHECK \

1. ROUND(AVG(CASE WHEN Q.rating < 3 THEN 1.0 ELSE 0 END) \* 100.0, 2) AS poor_query_percentage

---

```sql
-- PostgreSQL
SELECT
    Q.query_name,
    ROUND(AVG(Q.rating * 1.0 / Q.position), 2) AS quality,
    ROUND(AVG(CASE WHEN Q.rating < 3 THEN 1.0 ELSE 0 END) * 100.0, 2) AS poor_query_percentage
FROM
    Queries AS Q
GROUP BY
    Q.query_name;
```

```sql
-- Write your MySQL query statement below
SELECT
    Q.query_name,
    ROUND(AVG(Q.rating * 1.0/Q.position), 2) AS quality,
    ROUND(AVG(rating < 3) * 100.00, 2) AS poor_query_percentage
FROM
    Queries AS Q
GROUP BY
    Q.query_name
```

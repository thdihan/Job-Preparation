### 1757. Recyclable and Low Fat Products

[Link](https://leetcode.com/problems/recyclable-and-low-fat-products/description/?envType=study-plan-v2&envId=top-sql-50)

```sql
// mysql
SELECT product_id
FROM products
WHERE
    low_fats = 'Y'
    AND recyclable = 'Y';
```

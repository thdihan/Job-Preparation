### 1251. Average Selling Price

[Link]()

```sql

-- Write your PostgreSQL query statement below
SELECT
    P.product_id, COALESCE( ROUND( SUM(price * units) / SUM(units * 1.0) ,2) , 0) average_price
FROM
    Prices P
LEFT JOIN
    UnitsSold US
    ON
        P.product_id = US.product_id
        AND US.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY P.product_id
```

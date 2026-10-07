# Write your MySQL query statement below
SELECT p1.product_name,SUM(o.unit) AS unit 
FROM Products p1 
INNER JOIN Orders o ON p1.product_id = o.product_id
WHERE o.order_date BETWEEN "2020-02-01" AND "2020-02-29"
GROUP BY p1.product_name
HAVING SUM(o.unit) >= 100;
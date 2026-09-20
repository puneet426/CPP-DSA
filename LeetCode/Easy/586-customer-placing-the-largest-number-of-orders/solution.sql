# Write your MySQL query statement below
WITH order_counts AS (
    SELECT customer_number, 
        COUNT(*) AS order_count,
        DENSE_RANK() OVER (ORDER BY COUNT(*) DESC) AS rnk
    FROM Orders
    GROUP BY customer_number
)
SELECT customer_number
FROM order_counts
WHERE rnk = 1;
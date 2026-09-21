# Write your MySQL query statement below
WITH ranked AS (
    SELECT *,
        ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rn
    FROM Delivery
)
SELECT ROUND(COUNT(CASE WHEN order_date = customer_pref_delivery_date THEN 1 END)*100 / COUNT(customer_id), 2) AS immediate_percentage
FROM ranked
WHERE rn = 1

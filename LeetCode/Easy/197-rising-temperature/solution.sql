# Write your MySQL query statement below
SELECT w.id AS id
FROM Weather w
INNER JOIN Weather we ON w.recordDate = DATE_ADD(we.recordDate, INTERVAL 1 DAY)
WHERE w.temperature>we.temperature;



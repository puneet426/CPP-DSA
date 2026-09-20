# Write your MySQL query statement below
SELECT r.contest_id, ROUND(COUNT(u.user_id)*100/(SELECT COUNT(*) FROM Users),2) AS percentage 
FROM Register r
INNER JOIN Users u ON u.user_id = r.user_id
GROUP BY r.contest_id ORDER BY percentage DESC, contest_id ASC
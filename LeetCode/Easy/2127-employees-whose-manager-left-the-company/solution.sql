SELECT employee_id
FROM Employees e1
WHERE salary < 30000
AND manager_id IS NOT NULL
AND NOT EXISTS (
    SELECT 1 FROM Employees e2 WHERE e2.employee_id = e1.manager_id
)
ORDER BY employee_id;
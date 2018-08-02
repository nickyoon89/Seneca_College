CREATE VIEW DepartmentEmployeeCount_View AS 
    SELECT 
        department_name AS "DEPARTMENT",
        COUNT(employee_id) AS "# of Employees"
    FROM 
        employees JOIN departments
        ON employees.department_id = departments.department_id
    GROUP BY department_name
    ORDER BY department_name;

SELECT * FROM DepartmentEmployeeCount_View;

CREATE OR REPLACE VIEW DepartmentEmployeeCount_View AS 
    SELECT 
        NVL(department_name,'Not Yet Assigned') AS "DEPARTMENT",
        COUNT(employee_id) AS "# of Employees"
    FROM 
        employees LEFT JOIN departments
        ON employees.department_id = departments.department_id
    GROUP BY department_name
    ORDER BY department_name;
    
SELECT * FROM DepartmentEmployeeCount_View;

CREATE VIEW DepartmentEmployees_View AS
    SELECT
         NVL(department_name,'Not Yet Assigned') AS "Department",
        TRIM(first_name)||' '||last_name AS "EMPLOYEE"
    FROM
        employees LEFT JOIN departments
        ON employees.department_id = departments.department_id
    ORDER BY department_name;
    
SELECT * FROM DepartmentEmployees_View;
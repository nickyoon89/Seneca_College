-- ***********************
-- Name: Jihyun Yoon
-- ID: 124558172
-- Date: Jun 14, 2018
-- Purpose: Lab 6 DBS301
-- ***********************

--Q1. Set Autocommit on
SET AUTOCOMMIT ON;

--Q2. insert myself in employee
INSERT INTO employees VALUES (999, 'Jihyun', 'Yoon', 'JYOON31', '647.894.9719', sysdate, 'AD_VP', NULL, 0.2, 100, 90);
--DELETE FROM employees WHERE employee_id=999;

--Q3. Change salary to 2500 when the last name is Matos and Whalen
UPDATE employees
SET salary=2500
WHERE UPPER(last_name)='MATOS' OR UPPER(last_name)='WHALEN';

--Q4. Display employees working in same department with Abel
SELECT last_name "Last Name"
FROM employees
WHERE department_id IN (
    SELECT department_id
    FROM employees
    WHERE UPPER(last_name) = 'ABEL'
    );
    
--Q5. display the last name of the lowest paid employee(s)
SELECT last_name "Last Name"
FROM employees
WHERE salary = (
    SELECT MIN(salary)
    FROM employees
    );
    
--Q6. display the city that the lowest paid employee(s) are located in
SELECT DISTINCT city "City"
FROM locations
WHERE location_id IN (
    SELECT location_id
    FROM departments
    WHERE department_id IN (
        SELECT department_id
        FROM employees
        WHERE salary = (
            SELECT MIN(salary)
            FROM employees
            )
        )
    );
    
--Q7. display info of the lowest paid employee(s) in each department
SELECT last_name "Last Name",
    department_id "Department ID", 
    salary "Salary"
FROM employees
WHERE department_id||salary IN (
    SELECT department_id || MIN(salary)
    FROM employees
    GROUP BY department_id
    )
ORDER BY department_id;

--Q8. display the last name of the lowest paid employee(s) in each city
SELECT last_name "Last Name",
    city "City"
FROM (
    SELECT city, last_name, salary
    FROM (employees e JOIN departments d 
         ON e.department_id=d.department_id) JOIN locations l
         ON d.location_id=l.location_id
    )
WHERE city||salary IN (
    SELECT city || MIN(salary) "Chk"
    FROM (employees e JOIN departments d 
         ON e.department_id=d.department_id) JOIN locations l
         ON d.location_id=l.location_id
    GROUP BY city
    );
    
--Q9. display info for all employees who earn less than any department's lowest salary
SELECT last_name "Last Name",
    salary "Salary"
FROM employees
WHERE salary < ANY(
    SELECT MIN(salary)
    FROM employees
    GROUP BY department_id
    )
ORDER BY salary DESC, last_name;

--Q10. display info for all employees whose salary matches any salaries from the IT department.
SELECT last_name "Last Name",
    job_id "Job Title",
    salary "Salary"
FROM employees
WHERE salary = ANY(
    SELECT salary
    FROM employees
    WHERE department_id = (
        SELECT department_id
        FROM departments
        WHERE UPPER(department_name)='IT'
        )
    )
ORDER BY salary, last_name;
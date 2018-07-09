-- ***********************
-- Name: Jihyun Yoon
-- ID: 124558172
-- Date: Jun 07, 2018
-- Purpose: Lab 5 DBS301
-- ***********************

-- Q1. Display dept name, city, adress, postal code for dept. sort by city and dept name
SELECT department_name "Dept Name", 
    city "City", 
    street_address "Street Address", 
    postal_code "Postal Code"
FROM departments d JOIN locations l
ON d.location_id=l.location_id
ORDER BY city, department_name;

--Q2. display full name as a "last, first", hire date, salary, dept name and city with dept name starting with A or S.

SELECT TRIM(last_name)||', '||first_name "Full Name",
    hire_date "Hire Date",
    TO_CHAR(salary,'$9,999,999.00') "Salary",
    department_name "Department Name",
    city "City"
FROM employees e JOIN departments d ON e.department_id=d.department_id
    JOIN locations l ON d.location_id=l.location_id
WHERE UPPER(department_name) LIKE 'S%' OR
    UPPER(department_name) LIKE 'A%'
ORDER BY department_name,"Full Name";

--Q3. display full name of manager of department in specific provinces along with more info and sort by city and dept name

SELECT TRIM(last_name)||', '||first_name "Full Name",
    department_name "Dept Name",
    city "City",
    postal_code "Postal Code",
    state_province "State/Province"
FROM departments d JOIN employees e ON d.manager_id=e.employee_id
    JOIN locations l ON d.location_id=l.location_id
WHERE state_province IN ('Ontario','California','Washington')
ORDER BY city, department_name;

--Q4. Display employee's last name, number along with manager's last name, number and label the columns.

SELECT e.last_name "Employee",
    e.employee_id "Emp#",
    m.last_name "Manager",
    m.employee_id "Mgr#"
FROM employees e JOIN employees m ON e.manager_id=m.employee_id;

--Q5. display department name, city, street address, postal code and country name. sort by department name desc.

SELECT department_name "Department Name",
    city "City",
    street_address "Street Address",
    country_name "Country Name"
FROM departments d LEFT JOIN locations l USING(location_id)
    LEFT JOIN countries USING(country_id)
ORDER BY department_name DESC;

--Q6. display full name of employees, hired date, salary, department name with names start with A or S.

SELECT TRIM(first_name)||' / '||last_name "Full Name",
    hire_date "Hire Date",
    TO_CHAR(salary,'$9,999,999.99') "Salary",
    department_name "Dept Name"
FROM employees e LEFT JOIN departments d ON e.department_id=d.department_id
WHERE UPPER(department_name) LIKE 'A%' OR
    UPPER(department_name) LIKE 'S%' 
ORDER BY department_name, last_name;

--Q7. rewrite Q6 with USING

SELECT TRIM(first_name)||' / '||last_name "Full Name",
    hire_date "Hire Date",
    TO_CHAR(salary,'$9,999,999.00') "Salary",
    department_name "Dept Name"
FROM employees e LEFT JOIN departments d USING (department_id)
WHERE UPPER(department_name) LIKE 'A%' OR
    UPPER(department_name) LIKE 'S%' 
ORDER BY department_name, last_name;

--Q8. display full name of manager in specific province plus dept name, city, postal code and province name.
SELECT 
    CASE 
        WHEN d.manager_id IS NULL THEN '-'
        ELSE TRIM(last_name)||', '||first_name 
    END "Manager Name", 
    department_name "Dept Name",
    city "City",
    postal_code "Postal Code",
    state_province "State/Province"
FROM departments d LEFT JOIN employees e ON d.manager_id=e.employee_id
    LEFT JOIN locations l ON d.location_id=l.location_id
WHERE state_province IN ('Ontario','California','Washington')
ORDER BY city, department_name;

--Q9. Rewrite Q8 with USING
SELECT 
    CASE 
        WHEN d.manager_id IS NULL THEN '-'
        ELSE TRIM(last_name)||', '||first_name 
    END "Manager Name", 
    department_name "Dept Name",
    city "City",
    postal_code "Postal Code",
    state_province "State/Province"
FROM departments d LEFT JOIN employees e USING(department_id)
    LEFT JOIN locations l USING(location_id)
WHERE state_province IN ('Ontario','California','Washington') AND
    (d.manager_id IS NULL OR d.manager_id=e.employee_id)
ORDER BY city, department_name;

--Q10. display dept name, highest, lowest and avg pay per each department. sory it by highest avg shows first
SELECT department_name "Dept Name",
    LPAD(NVL(TO_CHAR(MAX(salary),'$9,999,999.99'),'-'),14) "High",
    LPAD(NVL(TO_CHAR(MIN(salary),'$9,999,999.99'),'-'),14) "Low",
    LPAD(NVL(TO_CHAR(AVG(salary),'$9,999,999.99'),'-'),14) "Avg"
FROM departments d LEFT JOIN employees e
    ON d.department_id=e.department_id
GROUP BY department_name
--HAVING AVG(Salary) IS NOT NULL
ORDER BY AVG(NVL(salary,0)) DESC;

--Q11. Display employee last name, number, manager's last name and number.
SELECT NVL(e.last_name,'-') "Employee",
    NVL(TO_CHAR(e.employee_id),'-') "Emp#",
    NVL(m.last_name,'-') "Manager",
    NVL(TO_CHAR(m.employee_id),'-') "Mgr#"
FROM employees e FULL OUTER JOIN employees m ON e.manager_id=m.employee_id;
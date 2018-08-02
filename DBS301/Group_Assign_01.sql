-- ***********************
-- Name: Jihyun Yoon, Paul Repasi, Supreet Saini
-- ID: 124558172, 029808086, 118694173
-- Date: Jun 15, 2018
-- Purpose: Assignment 1 - DBS301
-- ***********************

--Q1. Display info of all employees hired in May or Nov with the most recently hired employee first
SELECT RPAD(employee_id,5) AS "Employee Number" ,
  CAST (last_name || ', ' || first_name AS VARCHAR(25)) AS "Full Name" , 
  job_id AS "Job", 
  '['||TRIM(TO_CHAR(LAST_DAY(hire_date),'Month')) || ' ' || TO_CHAR(LAST_DAY(hire_date),'ddth "of" YYYY')||']' AS "Hire date"  
FROM employees
WHERE  EXTRACT(MONTH FROM hire_date) IN (5,11)
  AND EXTRACT(YEAR FROM hire_date) NOT IN (1994, 1995)
ORDER BY hire_date DESC;

--Q2. Display info of all employees as Vice President or Manager whose monthly earning is out of 6000~11000 range
SELECT 'Emp# ' || employee_id ||' named ' || TRIM(first_name) || ' ' || last_name
  || ' who is ' || ' ' || job_id || ' will have a new salary of ' || ' $' || 
  (CASE WHEN job_id LIKE '%VP%' THEN 1.3 ELSE 1.2 END * salary)
FROM employees 
WHERE (job_id LIKE '%VP%' 
   OR employee_id != ANY(
      SELECT DISTINCT manager_id
      FROM employees
      WHERE manager_id IS NOT NULL
      ))
  AND (salary < 6000 OR salary > 11000);

--Q3. Display info of all employees not earning a commision or if they work in the SALES. with their salary after bonus is over 15000
SELECT last_name as "Last Name",
  salary as "Salary",
  job_id as "Job ID",
  NVL(to_char(manager_id), 'None') as "Manager#",
  TO_CHAR(((salary * NVL(commission_pct, 0) + salary) + 1000) * 12, '$999,999.99') as "Total Income"
FROM employees
WHERE commission_pct IS NULL
    OR department_id = (
        SELECT department_id
        FROM departments
        WHERE UPPER(department_name) LIKE 'SALES'
        )
    AND (salary * NVL(commission_pct, 0) + salary) + 1000 >= 15000
ORDER BY "Total Income" DESC;

--Q4. Display info only when the lowest pay of dept/job is in the range of 6000~18000. Exclude some department and specific job
SELECT e.department_id ||'/ '
  ||job_id||': '
  ||TO_CHAR(MIN(salary),'$999,999.99') AS "Lowest Dept/Job Pay"
FROM employees e JOIN departments d 
  ON e.department_id=d.department_id
WHERE UPPER(d.department_name) != 'SALES' 
  AND UPPER(d.department_name) != 'IT'
  AND UPPER(job_id) NOT LIKE '%REP%'
GROUP BY e.department_id, job_id
HAVING MIN(salary) BETWEEN 6000 AND 18000
ORDER BY e.department_id, job_id;

--Q5. Display info of all employees who earn more than all lowest paid employees per department outside of the US locations
SELECT last_name AS "Last Name",
  TO_CHAR(salary,'$999,999.99') AS "Salary",
  job_id AS "Job"
FROM employees
WHERE salary > ALL(SELECT MIN(salary)
    FROM (employees e JOIN departments d ON e.department_id=d.department_id)
      JOIN locations l ON d.location_id=l.location_id
    WHERE l.country_id != 'US'
    GROUP BY d.department_id)
  AND UPPER(job_id) NOT LIKE '%PRES%'
  AND UPPER(job_id) NOT LIKE '%VP%'
ORDER BY job_id;

--Q6. Display info of employees in IT or MARKETING who earn more than the worst paid person in ACCOUNTING
SELECT last_name AS "Last Name",
  salary AS "Salary",
  job_id AS "Job"
FROM employees
WHERE department_id = ANY(
    SELECT department_id
    FROM departments
    WHERE UPPER(department_name) IN ('IT','MARKETING'))
  AND salary > (SELECT MIN(salary)
    FROM employees
    WHERE department_id=(
      SELECT department_id
      FROM departments
      WHERE UPPER(department_name) = 'ACCOUNTING'))
ORDER BY last_name;

--Q7. Display info of employee in SALES or MARKETING who earns less than the best paid unionized employee
SELECT CAST(TRIM(first_name)||' '||last_name AS VARCHAR(25))AS "Employee",
  job_id AS "Job",
  LPAD(TO_CHAR(salary,'$999,999'),12,'=') AS "Salary",
  department_id AS "Dept#"
FROM employees
WHERE salary < (
  SELECT MAX(salary)
  FROM employees
  WHERE job_id NOT LIKE '%PRES%'
    AND job_id NOT LIKE '%VP%'
    AND employee_id != ANY(
      SELECT DISTINCT manager_id
      FROM employees
      WHERE manager_id IS NOT NULL
      ))
  AND department_id = ANY(
    SELECT department_id
    FROM departments
    WHERE UPPER(department_name) = 'SALES'
      OR UPPER(department_name) = 'MARKETING'
  );

--Q8. Display info in each department, if City is null, it should be displayed as 'Not Assigned Yet' with detailed options
--EMPLOYEE: including employees who work for NO departments, exclduing emplty departments
SELECT NVL(d.department_name,'No Department') AS "Dept Name",
  CAST(NVL(l.city,'Not Assigned Yet') AS VARCHAR(25)) AS "City",
  COUNT(DISTINCT e.job_id) AS "# of Jobs"
FROM employees e LEFT JOIN departments d ON d.department_id=e.department_id
  LEFT JOIN locations l ON l.location_id = d.location_id
GROUP BY NVL(d.department_name,'No Department'), 
    CAST(NVL(l.city,'Not Assigned Yet') AS VARCHAR(25))
HAVING COUNT(DISTINCT e.job_id)>0;
  
--CITY: displaying all the cities even there is no department
SELECT NVL(d.department_name,'No Department') AS "Dept Name",
  CAST(NVL(l.city,'Not Assigned Yet') AS VARCHAR(25)) AS "City",
  COUNT(DISTINCT e.job_id) AS "# of Jobs"
FROM locations l LEFT JOIN departments d ON l.location_id = d.location_id
  LEFT JOIN employees e  ON d.department_id=e.department_id
GROUP BY NVL(d.department_name,'No Department'), 
    CAST(NVL(l.city,'Not Assigned Yet') AS VARCHAR(25));

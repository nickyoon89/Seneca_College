-- ***********************
-- Name: Jihyun Yoon
-- ID: 124558172
-- Date: May 31 2018
-- Purpose: Lab 3 DBS301
-- ***********************

SET PAGESIZE 200;
SET LINESIZE 200;

-- Question 1 – Display the column named "Real Amount" to show difference between the Ava pay and Lowest pay.
SELECT 
    to_char((AVG(NVL(SALARY,0))-MIN(SALARY)), '$999,999.99') AS "Real Amount"
    FROM employees;

-- Question 2 – Display the department number and Highest(High), Lowest(Low) and Average(Avg) pay per each department.  Sort and have make sure it matched to specific format
SELECT 
    department_id AS "Department No.",
    to_char(MAX(salary),'$999,999.99') AS "High",
    to_char(MIN(salary),'$999,999.99') AS "Low",
    to_char(AVG(salary),'$999,999.99') AS "Avg"
FROM employees
GROUP BY department_id
ORDER BY "Avg" DESC;

-- Question 3 – Display how many workers are in each department as "Dept#", "Job" and "How Many" except departments without a worker. sort by number of workers
SELECT 
    department_id AS "Dept#",
    job_id AS "Job",
    COUNT(employee_id)||' workers' AS "How Many"
FROM employees 
GROUP BY department_id, job_id
HAVING COUNT(employee_id)>1
ORDER BY "How Many" DESC;

-- Question 4 – display job title and total paid motnly for each job. Exclude AD_PRES, AD_VP and include jobs require more than 12,000. Sort out put by paid desc
SELECT 
    job_id AS "Job",
    to_char(SUM(SALARY),'$999,999.99') AS "Total Monthly Pay"
FROM employees
WHERE job_id NOT IN ('AD_PRES', 'AD_VP')
GROUP BY job_id
HAVING (SUM(SALARY)) > 12000
ORDER BY (SUM(SALARY)) DESC;

-- Question 5 – Display how many people each manager supervises when it's more than 2 people and excluding manager number 100, 101 and 102. Sort by number of supervised people
SELECT
    manager_id AS "Manager#",
    TO_CHAR(COUNT(employee_id),'9,999')||' people' AS "Supervised People"
FROM employees
WHERE manager_id NOT IN (100,101,102)
GROUP BY manager_id
HAVING COUNT(employee_id) > 2
ORDER BY COUNT(employee_id) DESC;

-- Question 6 – Display the latest and earliest hire date of each department excluding dept# 10 and 20. Then sort by most recent latest hire date to show first.
SELECT 
    department_id AS "Dept #",
    TO_CHAR(MAX(hire_date),'Mon fmddth, YYYY') AS "Lastest",
    TO_CHAR(MIN(hire_date),'Mon fmddth, YYYY') AS "Earliest"
FROM employees
WHERE department_id NOT IN (10, 20)
GROUP BY department_id
HAVING TO_CHAR(MAX(hire_date),'SCC') != TO_CHAR(sysdate, 'SCC')
ORDER BY MAX(hire_date) DESC;

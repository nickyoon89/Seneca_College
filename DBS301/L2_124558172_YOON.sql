-- ***********************
-- Name: Jihyun Yoon
-- ID: 124558172
-- Date: 2018/05/17
-- Purpose: Lab 2 DBS301
-- ***********************

SET PAGESIZE 200;
SET LINESIZE 200;

-- Question 1 – display empoyee id, last name and salary(8000~15000) and sort by salary then last name

SELECT 
    employee_id, 
    last_name, 
    salary
FROM employees 
WHERE salary BETWEEN 8000 AND 15000
ORDER BY salary DESC, last_name;

-- Question 2 – Modify Q1 to show only Programmer and Sales Representatives

SELECT 
    employee_id, 
    last_name, 
    salary
FROM employees 
WHERE 
    job_id IN ('IT_PROG', 'SA_REP') AND
    (salary BETWEEN 8000 AND 15000 )
ORDER BY salary DESC, last_name;

-- Question 3 – Same job title as Q2 but out range of salary of Q1

SELECT 
    employee_id, 
    last_name, 
    salary
FROM employees 
WHERE 
    job_id IN ('IT_PROG', 'SA_REP') AND
    (salary < 8000 OR salary > 15000)
ORDER BY salary DESC, last_name;

-- Question 4 – Show employees hired before 1998 and sort by hire date showing recent first

SELECT 
    last_name, 
    job_id,
    salary
FROM employees 
WHERE 
    hire_date < TO_DATE('19980101','yyyymmdd')
ORDER BY hire_date DESC;

-- Question 5 – Modify Q4 to show who has more than 10,000 salary. Sort by job title first then highest paid first.

SELECT 
    last_name, 
    job_id,
    salary
FROM employees 
WHERE 
    hire_date < TO_DATE('19980101','yyyymmdd') AND
    salary > 10000
ORDER BY job_id, salary DESC;

-- Question 6 – Display job title and full name who has 'e' or 'E' in their first name

SELECT 
    job_id AS "Job Title",
    trim(first_name) || ' ' || last_name AS "Full name"
FROM employees 
WHERE 
    first_name LIKE '%e%' OR
    first_name LIKE '%E%';
-- WHERE REGEXP_LIKE(first_name,'[eE]');


-- Question 7 – Display last name, salary, and commission percent for who has commission

SELECT 
    last_name,
    salary,
    commission_pct
FROM employees 
WHERE 
    commission_pct>0;
    
-- Question 8 – Same as Q7, but order of descending salaries

SELECT 
    last_name,
    salary,
    commission_pct
FROM employees 
WHERE 
    commission_pct>0
ORDER BY salary DESC;

-- Question 9 – Same as Q8, but sorting with numeric value

SELECT 
    last_name,
    salary,
    commission_pct
FROM employees 
WHERE 
    commission_pct>0
ORDER BY 2 DESC;
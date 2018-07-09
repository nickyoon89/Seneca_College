-- ***********************
-- Name: Jihyun Yoon
-- ID: 124558172
-- Date: May 24, 2018
-- Purpose: Lab 3 DBS301
-- ***********************

SET PAGESIZE 200;
SET LINESIZE 200;

-- Question 1 – Display tomorrow's date in the specific format

SELECT TRIM(to_char(sysdate+1,'Month'))||' '||TO_CHAR(sysdate+1,'fmddth" of year "YYYY')
AS "Date of Tomorrow" 
from dual;

-- Question 2 – Display employees in departsment 20, 50, 60 with increased salary and annual increasement added.
SELECT 
    last_name AS "Last Name",
    first_name AS "First Name",
    salary AS "Salary",
    FLOOR(salary*1.05) AS "Good Salary",
    (FLOOR(salary*1.05)-salary)*12 AS "Annual Pay Increase"
FROM employees 
WHERE department_id in (20,50,60);

-- Question 3 – Display employees' full name and job title in specific format
SELECT 
    trim(last_name)||', '||first_name||' is '||job_id
    AS "Person and Job"
FROM employees 
WHERE 
    UPPER(last_name) LIKE '%S'AND
    (UPPER(first_name) LIKE 'C%' OR UPPER(first_name) LIKE 'K%')    
ORDER BY last_name;
    
-- Question 4 – Display employees hired before 1992 and calculate number of years between today
SELECT 
    last_name AS "Last Name",
    hire_date AS "Hire Date",
    ROUND((MONTHS_BETWEEN(sysdate,hire_date))/12) AS "Years Worked"
FROM employees 
WHERE 
    hire_date < TO_DATE('19920101','yyyymmdd')
ORDER BY "Years Worked";

-- Question 5 – Display city, country, province when cities starts with S and has minimum 8 characters.

SELECT 
    city AS "City Name",
    country_id AS "Country Code",
    NVL(state_province,'Unknown Province') AS "Province"
FROM locations
WHERE 
    UPPER(city) LIKE 'S%' AND
    LENGTH(city) >= 8;

-- Question 6 – 
--Display last name, hire date, and salary review date which is the first Thursday after a year of service who hired after 1997.
--Column name = REVIEW DATE, sort by review date and it has specific format
SELECT 
    last_name AS "Last Name",
    hire_date AS "Hire Date",
    TRIM(TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date,12), 'Thursday'),'DAY'))||
    TRIM(TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date,12), 'Thursday'),'", "Month'))||
    TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date,12), 'Thursday'),'" the "Ddsp" of year "YYYY') 
    AS "REVIEW DAY"
FROM employees 
WHERE 
    hire_date > TO_DATE('19971231','yyyymmdd')
ORDER BY NEXT_DAY(ADD_MONTHS(hire_date,12), 'Thursday');
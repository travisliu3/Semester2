-- ***********************
-- Name: Travis Liu
-- ID: 156740201
-- Date: 1 June, 2022
-- Purpose: Lab 03 DBS211 – Part 2
-- ***********************
SET AUTOCOMMIT ON;

CREATE TABLE employees AS
SELECT *
FROM dbs211_employees;

ALTER TABLE employees
ADD CONSTRAINT employees_pk
PRIMARY KEY (employeenumber);

ALTER TABLE employees
ADD CONSTRAINT employees_fk
FOREIGN KEY (REPORTSTO)
REFERENCES employees (employeenumber);

-- Q1
INSERT INTO EMPLOYEES VALUES(1703, 'Liu', 'Travis', 'x32325', 'tliu84@myseneca.ca', 4, 1088, 'Accountant');


-- Q2
SELECT *
FROM employees
WHERE UPPER(email) = 'TLIU84@MYSENECA.CA';


-- Q3
UPDATE employees SET jobtitle = 'Head Cashier'
WHERE UPPER(email) = 'TLIU84@MYSENECA.CA';


-- Q4
INSERT INTO EMPLOYEES VALUES(1704, 'Musk', 'Elon', 'x32327', 'elon.musk@gmail.com', 3, 1703, 'Cashier');


-- Q5
DELETE FROM employees
WHERE employeenumber = 1703;


-- Q6
DELETE FROM employees
WHERE employeenumber = 1704;


-- Q7
INSERT ALL
    INTO employees VALUES ( 1703, 'Liu', 'Travis', 'x32325', 'tliu84@myseneca.ca', 4, 1088, 'Accountant' )
    INTO employees VALUES ( 1704, 'Musk', 'Elon', 'x32327', 'elon.musk@gmail.com', 3, 1088, 'Cashier' )
    SELECT * FROM dual;
    

-- Q8
DELETE FROM employees
WHERE reportsto = 1088 AND UPPER(email) = 'TLIU84@MYSENECA.CA' OR UPPER(email) = 'ELON.MUSK@GMAIL.COM';


DROP TABLE employees; 
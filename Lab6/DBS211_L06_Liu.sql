-- ***********************
-- Name: Travis Liu
-- ID: 156740201
-- Date: 19 June, 2022
-- Purpose: Lab 06 DBS211
-- ***********************

-- Q1 SOLUTION --
-- Making a new connection to the server.
-- The use of BEGIN keyword.
-- The use of COMMIT keyword which will commit the current transaction and begin a new one.
-- The use of DDL statements which auto-commit the current transaction and begin a new one.


-- Q2 Solution –
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;
CREATE TABLE staffs(
EMPLOYEENUMBER	NUMBER(38,0)    PRIMARY KEY,
LASTNAME	VARCHAR2(50 BYTE)   NOT NULL,
FIRSTNAME	VARCHAR2(50 BYTE)   NOT NULL,
EXTENSION	VARCHAR2(10 BYTE)   NOT NULL,
EMAIL	VARCHAR2(100 BYTE)      NOT NULL,
OFFICECODE	VARCHAR2(10 BYTE)   NOT NULL,
REPORTSTO	NUMBER(38,0)        DEFAULT NULL,
JOBTITLE	VARCHAR2(50 BYTE)   NOT NULL,
CONSTRAINT staffs_report_fk FOREIGN KEY (REPORTSTO) REFERENCES staffs(EMPLOYEENUMBER),
CONSTRAINT staffs_office_fk FOREIGN KEY (OFFICECODE) REFERENCES DBS211_OFFICES(OFFICECODE)
);


-- Q3 Solution –
INSERT ALL
  INTO STAFFS VALUES (1001, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1002, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1003, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1004, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1005, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
    SELECT * FROM DUAL;


-- Q4 Solution –
SELECT * FROM STAFFS;
-- 5 rows were selected.


-- Q5 Solution -
ROLLBACK;
SELECT * FROM STAFFS;
-- No rows were selected.


-- Q6 Solution -
INSERT ALL
  INTO STAFFS VALUES (1001, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1002, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1003, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1004, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
  INTO STAFFS VALUES (1005, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
    SELECT * FROM DUAL;
COMMIT;
ROLLBACK;
SELECT * FROM STAFFS;
-- 5 rows were selected.


-- Q7 Solution -
-- a)
UPDATE STAFFS
        SET REPORTSTO = 1004
    WHERE EMPLOYEENUMBER != 1004;
-- b)
UPDATE STAFFS
        SET JOBTITLE = 'Sales Manager'
    WHERE EMPLOYEENUMBER = 1004;
COMMIT;


-- Q8 Solution -
SELECT * FROM STAFFS;


-- Q9 Solution - 
ROLLBACK;
-- a)
SELECT *
FROM STAFFS
WHERE REPORTSTO = 1004;
-- b) No, the rollback command was not effective.
-- c) In task 6, rollback tried to remove the inserted values and in this task, the rollback tried to remove the the updated values in task 7.
-- Both the rollbacks in task 6 and 9 failed because the changes were commited before the rollback.


-- Q10 Solution -
DROP TABLE STAFFS;
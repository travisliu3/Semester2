SELECT
   customernumber AS "customer number",
   customername AS "customer name",
   creditlimit AS "credit limit",
   CASE
      WHEN
         salesrepemployeenumber IS NULL 
      THEN
         'Travis Liu' 
   END
   AS "sales person" 
FROM
   dbs211_customers 
WHERE
   salesrepemployeenumber IS NULL 
ORDER BY
   customernumber;


SELECT
   customernumber,
   paymentdate,
   amount 
FROM
   dbs211_payments 
WHERE
   amount < 1000 
   OR amount > 100000 
ORDER BY
   customernumber,
   paymentdate;


INSERT INTO
   TRAINER 
VALUES
   (
      156740201, 'Travis Liu', '23 York Road blvd', 'Vancover', 'Canada', 'tmlik@gmail.com', '7390239304', 3, 1223
   )
;


SELECT
   customernumber AS "customer number",
   customername AS "customer name",
   paymentdate AS "payment date",
   amount 
FROM
   DBS211_CUSTOMERS 
   JOIN
      DBS211_PAYMENTS USING (CUSTOMERNUMBER) 
WHERE
   EXTRACT(year 
FROM
   paymentdate) > 2003 
ORDER BY
   paymentdate,
   amount;
   
   

CREATE TABLE employees(
employeenumber      INT             PRIMARY KEY,    
firstname           VARCHAR(50)     NOT NULL,    
lastname            VARCHAR(50),
email               VARCHAR(60)     UNIQUE,
salary              NUMERIC(10, 2)  CHECK (salary <= 100000), 
department          INT             
);

CREATE TABLE dependents(
ID                INT             PRIMARY KEY,    
firstname         VARCHAR(50)     NOT NULL,    
lastname          VARCHAR(50)     NOT NULL,
insurancenumber   INT             NOT NULL,
SSN               VARCHAR(60)     UNIQUE, 
employee          INT,
CONSTRAINT foreign_key FOREIGN KEY (employee) REFERENCES employees(employeenumber)
);

DELETE FROM DBS211_CUSTOMER WHERE customernumber IS NULL;



CREATE TABLE product (

              product_id NUMBER(3) PRIMARY KEY,

              product_name VARCHAR(30) NOT NULL,

              price NUMBER (3,2) CHECK (price > 0),

              quantity NUMBER(3) 

);

SELECT *

FROM product

WHERE product_id = 1023;


SELECT productcode, productline, quantityinstock

FROM DBS211_PRODUCTS

WHERE UPPER(substr(productvendor,1, 1)) = UPPER('c') AND quantityinstock < 6000

ORDER BY quantityinstock, productcode;



SELECT e.employeenumber, concat(e.firstname, concat(' ', e.lastname)) AS "full name", e.reportsto AS "manager ID"

FROM DBS211_EMPLOYEES e JOIN DBS211_CUSTOMERS c ON e.employeenumber = c.salesrepemployeenumber

WHERE e.reportsto = 1002 

ORDER BY e.employeenumber;


SELECT e.employeenumber, concat(e.firstname, concat(' ', e.lastname)) AS "full name", e.reportsto AS "manager ID"

FROM DBS211_EMPLOYEES e JOIN DBS211_CUSTOMERS c ON e.employeenumber = c.salesrepemployeenumber

WHERE e.reportsto = 1002 

ORDER BY e.employeenumber;



SELECT employeenumber, concat(firstname, concat(' ', lastname)) AS "full name", email, 'Travis Liu' AS "Manager"

FROM DBS211_EMPLOYEES 

WHERE reportsto NOT IN (1088, 1102, 1143)

ORDER BY employeenumber;
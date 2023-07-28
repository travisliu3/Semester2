-- ***********************
-- Name: Travis Liu
-- ID: 156740201
-- Date: 2 June, 2022
-- Purpose: Lab 04 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT
   customernumber AS "Customer Number",
   customername AS "Customer Name",
   city AS "City",
   creditlimit AS "Credit Limit",
   salesrepemployeenumber AS "Sales Advisor ID",
   firstname || ' ' || lastname AS "Sales Advisor Name" 
FROM
   DBS211_CUSTOMERS 
   INNER JOIN
      DBS211_EMPLOYEES 
      ON DBS211_CUSTOMERS.salesrepemployeenumber = dbs211_employees.employeenumber 
WHERE
   UPPER(dbs211_customers.city) = 'NYC' 
   OR UPPER(dbs211_customers.city) = 'PARIS' 
   OR UPPER(dbs211_customers.city) = 'VANCOUVER' 
ORDER BY
   dbs211_customers.city,
   dbs211_customers.customernumber;


-- Q2 Solution –
SELECT
   employeenumber AS "Employee Number",
   concat(concat(lastname, ', '), firstname) AS "Employee Name",
   phone AS "Phone",
   extension AS "Extension",
   country AS "Country" 
FROM
   DBS211_OFFICES 
   INNER JOIN
      DBS211_EMPLOYEES 
      ON dbs211_offices.officecode = dbs211_employees.officecode 
WHERE
   UPPER(dbs211_offices.country) = 'JAPAN' 
   OR UPPER(dbs211_offices.country) = 'UK' 
ORDER BY
   employeenumber;


-- Q3 Solution –
SELECT
   customernumber AS "Customer Number",
   customername AS "Customer Name",
   firstname || ' ' || lastname AS "Salesperson Name",
   email AS "Salesperson Email" 
FROM
   DBS211_CUSTOMERS 
   INNER JOIN
      DBS211_EMPLOYEES 
      ON DBS211_CUSTOMERS.salesrepemployeenumber = dbs211_employees.employeenumber 
WHERE
   dbs211_customers.customernumber = 114 
   OR dbs211_customers.customernumber = 119 
   OR dbs211_customers.customernumber = 121 
ORDER BY
   customernumber;


-- Q4 Solution –
SELECT
   p.productcode AS "product code",
   productname AS "product name",
   quantityinstock AS "quantity",
   buyprice AS "price" 
FROM
   DBS211_products p 
   LEFT OUTER JOIN
      dbs211_orderdetails o 
      ON p.productcode = o.productcode 
WHERE
   quantityordered IS NULL 
ORDER BY
   p.productcode;


-- Q5 Solution –
CREATE VIEW customer_report AS 
SELECT
   c.customernumber,
   customername,
   phone,
   city,
   ordernumber,
   orderdate,
   status 
FROM
   DBS211_CUSTOMERS c 
   INNER JOIN
      DBS211_ORDERS o 
      ON c.customernumber = o.customernumber 
WHERE
   UPPER(status) = 'CANCELLED';


-- Q6 Solution –
SELECT
   * 
FROM
   customer_report 
ORDER BY
   customernumber;


-- Q7 Solution –
CREATE 
OR REPLACE VIEW customer_report AS 
SELECT
   c.customernumber,
   customername,
   phone,
   city,
   ordernumber,
   orderdate,
   status 
FROM
   DBS211_CUSTOMERS c 
   LEFT OUTER JOIN
      DBS211_ORDERS o 
      ON c.customernumber = o.customernumber 
WHERE
   UPPER(status) = 'CANCELLED' 
   OR status IS NULL 
   AND UPPER(city) = 'MADRID' 
   OR UPPER(city) = 'BERLIN';


-- Q8 Solution –
SELECT
   * 
FROM
   customer_report 
ORDER BY
   city,
   customernumber;


-- Q9 Solution –
SELECT
   c.customernumber,
   customername,
   city 
FROM
   customer_report c 
   LEFT OUTER JOIN
      DBS211_ORDERS o 
      ON c.customernumber = o.customernumber 
WHERE
   UPPER(city) = 'MADRID' 
   AND c.status IS NULL 
ORDER BY
   c.customernumber;


-- Q10 Solution –
DROP VIEW customer_report;
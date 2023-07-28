-- ***********************
-- Group number: 7
-- ID: 156740201(Travis Liu), 159872217(Viraj Chauhan), 162098214(Supreety Datta)
-- Date: 17 June, 2022
-- Purpose: Assignment 01 DBS211
-- ***********************


-- Q1 SOLUTION --
SELECT
   e.employeenumber AS "Employee Number",
   concat(concat(e.lastname, ', '), e.firstname) AS "Employee Name",
   phone AS "Phone",
   e.extension AS "Extension",
   city AS "City",
   'Unknown' AS "Manager ID",
   'Unknown' AS "Manager Name" 
FROM
   DBS211_EMPLOYEES e 
   JOIN
      DBS211_OFFICES USING (OFFICECODE) 
   JOIN
      DBS211_EMPLOYEES e2 
      ON e.employeenumber = e2.employeenumber 
WHERE
   e.reportsto IS NULL 
ORDER BY
   city,
   e.employeenumber;


-- Q2 SOLUTION --
SELECT
   e.EMPLOYEENUMBER,
   concat(concat(e.firstname, ' '), e.lastname) AS "Employee Name",
   phone AS "Phone",
   e.extension AS "Extension",
   city AS "City"
FROM
   DBS211_EMPLOYEES e 
   JOIN
      DBS211_OFFICES o 
      ON e.officecode = o.officecode  
WHERE
   city = 'NYC' 
   OR city = 'Paris' 
   OR city = 'Tokyo' 
ORDER BY
   city,
   e.employeenumber;


-- Q3 SOLUTION --
SELECT
   e.EMPLOYEENUMBER AS "Employee Number",
   concat(concat(e.lastname, ', '), e.firstname) AS "Employee Name",
   phone AS "Phone",
   e.extension AS "Extension",
   city AS "City",
   e.reportsto AS "Manager ID",
   concat(concat(e2.firstname, ' '), e2.lastname) AS "Manager Name" 
FROM
   DBS211_EMPLOYEES e 
   JOIN
      DBS211_OFFICES o 
      ON e.officecode = o.officecode 
   JOIN
      DBS211_EMPLOYEES e2 
      ON e.reportsto = e2.employeenumber 
WHERE
   city = 'NYC' 
   OR city = 'Paris' 
   OR city = 'Tokyo' 
ORDER BY
   city,
   e.employeenumber;


-- Q4 SOLUTION --
SELECT
   e.employeenumber AS "Manager Id",
   concat(concat(e.firstname, ' '), e.lastname) AS "Manager Name",
   country,
   CASE
      WHEN
         e.reportsto IS NULL 
      THEN
         'Does not report to anyone' 
      ELSE
         'Reports to ' || ( 
         SELECT
            e2.firstname || ' ' || e2.lastname || '(' || e2.jobtitle || ')' 
         FROM
            dbs211_employees e2 
         WHERE
            e.reportsto = e2.employeenumber ) 
   END
   AS "Reports to" 
         FROM
            dbs211_employees e 
            INNER JOIN
               dbs211_offices o 
               ON e.officecode = o.officecode 
         WHERE
            (
               e.reportsto = 1002 
               OR e.reportsto = 1056 
               OR e.reportsto IS NULL 
            )
            AND e.employeenumber != 1076 
         ORDER BY
            e. employeenumber;



-- Q5 SOLUTION --
SELECT
   customernumber,
   customername,
   productcode,
   msrp AS "OLD price",
   round((msrp - (msrp*0.1)), 2) AS "New Price" 
FROM
   dbs211_orderdetails o 
   JOIN
      dbs211_products p USING (productcode) 
   JOIN
      dbs211_orders USING (ordernumber) 
   JOIN
      dbs211_customers USING (customernumber) 
WHERE
   quantityordered > 55 
   AND productvendor = 'Exoto Designs' 
ORDER BY
   customernumber,
   "OLD price" DESC;


-- Q6 SOLUTION --
-- a) --
SELECT distinct
   o.customernumber,
   customername 
FROM
   dbs211_orders op 
   JOIN
      dbs211_orders o 
      ON o.customernumber = op.customernumber 
   JOIN
      dbs211_customers c 
      ON o.customernumber = c.customernumber 
WHERE
   o.ordernumber != op.ordernumber 
ORDER BY
   o.customernumber;

-- b) --
SELECT distinct
   o.customernumber,
   customername 
FROM
   dbs211_orders op 
   JOIN
      dbs211_orders o 
      ON o.customernumber = op.customernumber 
   JOIN
      dbs211_customers c 
      ON o.customernumber = c.customernumber 
WHERE
   o.ordernumber NOT IN 
   (
      SELECT distinct
         o.ordernumber 
      FROM
         dbs211_orders op 
         JOIN
            dbs211_orders o 
            ON o.customernumber = op.customernumber 
         JOIN
            dbs211_customers c 
            ON o.customernumber = c.customernumber 
      WHERE
         o.ordernumber != op.ordernumber 
   )
ORDER BY
   o.customernumber,
   customername;
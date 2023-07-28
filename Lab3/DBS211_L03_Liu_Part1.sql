-- ***********************
-- Name: Travis Liu
-- ID: 156740201
-- Date: 1 June, 2022
-- Purpose: Lab 03 DBS211 – Part 1
-- ***********************
SET AUTOCOMMIT ON;


-- Q1
SELECT
   customernumber AS "Customer Number",
   customername AS "Customer Name",
   concat(concat(contactfirstname, ' '), contactlastname) AS "Contact Name",
   phone AS "Phone Number" 
FROM
   DBS211_CUSTOMERS 
WHERE
   UPPER(city) = 'MADRID' 
ORDER BY
   customernumber DESC;


-- Q2
SELECT distinct
   customernumber 
FROM
   DBS211_PAYMENTS 
ORDER BY
   customernumber FETCH NEXT 10 ROWS ONLY;


-- Q3
SELECT
   * 
FROM
   DBS211_PAYMENTS 
WHERE
   amount > 100000 
   AND EXTRACT(year 
FROM
   paymentdate) != 2003 
ORDER BY
   customernumber DESC;


-- Q4
SELECT
   ordernumber,
   orderdate,
   status,
   customernumber 
FROM
   DBS211_ORDERS 
WHERE
   UPPER(status) = 'ON HOLD' 
   OR UPPER(status) = 'IN PROCESS' 
ORDER BY
   orderdate;


-- Q5
SELECT
   ProductCode,
   ProductName,
   BuyPrice,
   MSRP,
   (
      MSRP - BuyPrice
   )
   AS markup,
   round(100 * (MSRP - BuyPrice) / BuyPrice, 1) AS percmarkup 
FROM
   DBS211_PRODUCTS 
WHERE
   round(100 * (MSRP - BuyPrice) / BuyPrice, 1) > 140 
ORDER BY
   percmarkup;


-- Q6
SELECT
   customernumber,
   customername,
   phone 
FROM
   DBS211_CUSTOMERS 
WHERE
   UPPER(customername) LIKE 'C%CO.' 
ORDER BY
   customernumber;
--Name - Travis Liu, Supreety Datta, Viraj Chauhan
--Student ID - 156740201, 162098214, 159872217

CREATE OR REPLACE VIEW rating AS
    SELECT DISTINCT Hotelname, CustomerID, RatingStar, ReviewDec
    FROM BOOKING JOIN HOTEL USING (HOTELID) JOIN CUSTOMER USING (CustomerID);
--The above view shows the rating to each hotel by each customer which can be used to
--fix any issues the customer faced during the stay in the hotel 
    
CREATE OR REPLACE VIEW totalearnings AS
    SELECT SUM(Commission) AS "Total Earnings", HotelID
    FROM BOOKING
    GROUP BY HotelID;
--The above view returns the total earnings from comission from all the hotels
--which can be used as a benchmark to improve the customer experience
    
CREATE OR REPLACE VIEW highestearning AS
    SELECT Commission AS "Max Earnings from a Hotel", HotelID
    FROM BOOKING
    WHERE Commission = (SELECT MAX(Commission) FROM BOOKING);
--The above view shows only those hotel from which the earnings are highest
--this data can be used to promote those hotels more from fhich the earnings are highest

CREATE OR REPLACE VIEW bookings AS
    SELECT COUNT(HotelID) AS "No. of bookings in Feb"
    FROM BOOKING
    WHERE EXTRACT(MONTH FROM checkin) = 2;
--The above view returns the number of bookings in a perticular month which can be used to
--identify the busy seasons and run ads and offers to attract maximum number of customers
--Name - Travis Liu, Supreety Datta, Viraj Chauhan
--Student ID - 156740201, 162098214, 159872217

CREATE TABLE CUSTOMER (
    CustomerID INT PRIMARY KEY,
    fname   VARCHAR(20)     NOT NULL,
    lname    VARCHAR(20)     NOT NULL,
    phone   INT,
    email    VARCHAR(20)     NOT NULL,
    Passwrd   VARCHAR(20)     NOT NULL,
    CONSTRAINT phn_chk CHECK (phone BETWEEN 1000000000 AND 9999999999) 
);

CREATE TABLE HOTEL (
    HotelID INT   PRIMARY KEY,
    Addressline1 VARCHAR(80)   NOT NULL,
    Prov VARCHAR(80),
    Hotelname    VARCHAR(80)  NOT NULL
);

CREATE TABLE BOOKING (
    HotelID INT   NOT NULL,
    CustomerID INT   NOT NULL,
    Guests   INT     NOT NULL,
    CheckOut    DATE     NOT NULL,
    CheckIn   DATE,
    ReviewDec    VARCHAR(80),
    RatingStar   INT,
    Commission   INT     NOT NULL,
    Payment   INT     NOT NULL,
    PRIMARY KEY(HotelID, CustomerID),
    CONSTRAINT rat_chk CHECK (RatingStar BETWEEN 1 AND 5),
    CONSTRAINT fk1_fk FOREIGN KEY (HotelID) REFERENCES HOTEL(HotelID),
    CONSTRAINT fk2_fk FOREIGN KEY (CustomerID) REFERENCES CUSTOMER(CustomerID)
);

CREATE TABLE PAYMENT (
    PaymentID INT   PRIMARY KEY,
    CustomerID INT   NOT NULL,
    CardNumber    INT  NOT NULL,
    AmountPaid    INT  NOT NULL,
    PaymentDtae    DATE  NOT NULL,
    CONSTRAINT card_chk CHECK (CardNumber BETWEEN 1000000000000000 AND 9999999999999999),
    CONSTRAINT customer_fk FOREIGN KEY (CustomerID) REFERENCES CUSTOMER(CustomerID)
);

--DROP TABLE BOOKING;
--DROP TABLE PAYMENT;
--DROP TABLE HOTEL;
--DROP TABLE CUSTOMER;
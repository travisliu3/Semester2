-- ***********************
-- Name: Travis Liu
-- ID: 1567640201
-- Date: 10 June, 2022
-- Purpose: Lab 05 DBS211
-- ***********************
SET AUTOCOMMIT ON; 

-- Q1 SOLUTION --
CREATE TABLE L5_ACTORS (
a_id         INT            PRIMARY KEY,
first_name   VARCHAR(20)    NOT NULL,
last_name    VARCHAR(30)    NOT NULL
);

CREATE TABLE L5_CASTINGS (
movie_id   INT,
actor_id   INT,
PRIMARY KEY(movie_id, actor_id)
);

CREATE TABLE L5_DIRECTORS (
director_id   INT          PRIMARY KEY,
first_name    VARCHAR(20)  NOT NULL,
last_name     VARCHAR(30)  NOT NULL
);

CREATE TABLE L5_MOVIES (
m_id            INT             PRIMARY KEY,
title           VARCHAR(35)     NOT NULL,
release_year    INT             NOT NULL,
director        INT             NOT NULL,
score           DECIMAL(3,2),
CONSTRAINT director_fk FOREIGN KEY (director) REFERENCES L5_DIRECTORS(director_id),
CONSTRAINT score_chk CHECK (score BETWEEN 0 AND 5)
);


-- Q2 SOLUTION –-
ALTER TABLE L5_CASTINGS
    ADD CONSTRAINT movie_id_fk FOREIGN KEY (movie_id) REFERENCES L5_MOVIES(m_id);
    
ALTER TABLE L5_CASTINGS
    ADD CONSTRAINT actor_id_fk FOREIGN KEY (actor_id) REFERENCES L5_ACTORS(a_id);
    

-- Q3 SOLUTION –-
ALTER TABLE L5_DIRECTORS
    ADD username VARCHAR(60);


-- Q4 SOLUTION –-
ALTER TABLE L5_DIRECTORS
    ADD CONSTRAINT username_uni UNIQUE (username);


-- Q5 SOLUTION –-
INSERT ALL
    INTO L5_DIRECTORS (director_id, first_name, last_name) VALUES (1010, 'Rob', 'Minkoff')
    INTO L5_DIRECTORS (director_id, first_name, last_name) VALUES (1020, 'Bill', 'Condon')
    INTO L5_DIRECTORS (director_id, first_name, last_name) VALUES (1050, 'Josh', 'Cooley')
    INTO L5_DIRECTORS (director_id, first_name, last_name) VALUES (2010, 'Brad', 'Bird')
    INTO L5_DIRECTORS (director_id, first_name, last_name) VALUES (3020, 'Lake', 'Bell')
    SELECT * FROM dual;


-- Q6 SOLUTION –-
UPDATE L5_DIRECTORS
    SET username = concat(LOWER(SUBSTR(first_name, 1, 1)), LOWER(last_name))
    WHERE username IS NULL;


-- Q7 SOLUTION –-INCOMPLETE
DROP TABLE L5_CASTINGS;
DROP TABLE L5_ACTORS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_DIRECTORS;
-- The order of deletion of tables is important because table with unique or
-- primary keys is referenced by foreign keys in another table which prevents the user to break the table structure.
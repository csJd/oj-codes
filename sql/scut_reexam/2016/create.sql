CREATE TABLE students
(
    sno VARCHAR(5),
    sname VARCHAR(20),
    sdate DATE,
    cno VARCHAR(5),
    PRIMARY KEY (sno),
    FOREIGN KEY (cno) REFERENCES classes(cno)
);

CREATE TABLE classes
(
    cno VARCHAR(5),
    cspec VARCHAR(20),
    dno VARCHAR(5),
    cyear INT,
    cnum INT CHECK (cnum < 31),
    PRIMARY KEY (cno),
    FOREIGN KEY (don) REFERENCES departments(cno)
);

CREATE TABLE departments
(
    dno VARCHAR(5),
    dname VARCHAR(20),
    PRIMARY KEY (dno)
);

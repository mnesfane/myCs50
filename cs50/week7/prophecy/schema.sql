CREATE TABLE new_student (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE house (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE relat (
    id INTEGER,
    house TEXT,
    student_name TEXT,
    PRIMARY KEY(id)
);
create table stucourse(
     sid int primary key auto_increment,
     sname varchar(20) NOT NULL,
     semail varchar(20) NOT NULL UNIQUE,
     snumber bigint NOT NULL,
     sgender varchar(20) NOT NULL,
     scourse varchar(20) NOT NULL,
     stime varchar(20) NOT NULL,
     scounsellor varchar(20) NOT NULL);




     insert into stucourse(sname,semail,snumber,sgender,scourse,stime,scounsellor) values
    ("naveenkumar","naveen@gmail.com",6383146128,"Male","Java Full Stack","10 to 12","Vidya mam"),
    ("manojkumar","manoj@gmial.com",6547896325,"Male","Python Full stack","10 to 12","Divya Mam"),
    ("chakara","chakara@gmail.com",9687459632,"Male","Dot net","10 to 12","Nithya mam"),
 ("priya","priya@gmail.com",9632145963,"Female","Java Full Stack","3 to 5", "Vidya mam"),
    ("pooja","pooja@gmail.com",9632145885,"Female","Java backend","1 to 3", "Nithya mam");



    SELECT 
    studentcourse.name, 
    studentcourse.phonenum, 
    studentcourse.gmail, 
    batchtime.time
FROM studentcourse
LEFT JOIN batchtime 
    ON studentcourse.batchtime = batchtime.timeid;


      SELECT 
    studentcourse.name, 
    studentcourse.phonenum, 
    studentcourse.gmail, 
    batchtime.time
FROM studentcourse
RIGHT JOIN batchtime 
    ON studentcourse.batchtime = batchtime.timeid;



    create table student_details(
   sno int primary key,
    sname varchar(20),
    sgender varchar(20),
    scourse varchar(20),
    stime varchar(20));



    java 2
    pyton 3
    dot net 1


    3 to 5 3
    10 to 12 1
    2 to 3 2  




    insert into student_details (SNO,SNAME,Sgender,scourse,stime) values
     (1,"naveen",1,2,3),
     (2,"manoj",1,3,1),
     (3,"priya",2,1,2);



     select student_details.sno,student_details.sname,student_details.sgender,gender.gender
    from student_details
    inner join gender on 
   student_details.sgender = gender.sno;





   select
    student_details.sno, student_details.sname,
    gender.gender,
    course.coursename,
    time.course_time
    from student_details
    inner join gender on
    student_details.sgender = gender.sno 
    on student_details.scourse = course.sno 
    on student_details.stime = time.sno 
    ;



    SELECT 
    student_details.sno, 
    student_details.sname,
    gender.student_gender,
    course.coursename,
    time.course_time
FROM student_details
INNER JOIN gender 
    ON student_details.sgender = gender.sno
INNER JOIN course 
    ON student_details.scourse = course.sno
INNER JOIN time 
    ON student_details.stime = time.sno;




       SELECT 
    student_details.sno, 
    student_details.sname,
    gender.student_gender,
    course.coursename,
    time.course_time
FROM student_details
right JOIN gender 
    ON student_details.sgender = gender.sno
right JOIN course 
    ON student_details.scourse = course.sno
right JOIN time 
    ON student_details.stime = time.sno;




       SELECT 
    student_details.sno, 
    student_details.sname,
    gender.student_gender,
    course.coursename,
    time.course_time
FROM student_details
left JOIN gender 
    ON student_details.sgender = gender.sno
left JOIN course 
    ON student_details.scourse = course.sno
left JOIN time 
    ON student_details.stime = time.sno;




select
     student_details.sno,
     student_details.sname,
     student_details.sgender,
     gender.student_gender
     from student_details
     inner join gender on
     student_details.sgender = gender.sno;



     select
     student_details.sno,
     student_details.sname,
     student_details.sgender,
     gender.student_gender
     from student_details
     left join gender on
     student_details.sgender = gender.sno;


        select
     student_details.sno,
     student_details.sname,
     student_details.sgender,
     gender.student_gender
     from student_details
     right join gender on
     student_details.sgender = gender.sno;




     select
     student_details.sno,
     student_details.sname,
     student_details.sgender,
     gender.student_gender
     from student_details
     full outer join gender on
     student_details.sgender = gender.sno;



insert into right_table (id,right_value)
    values
     (1,"R1"),
     (2,"R2"),
     (3,"R3"),
     (4,"R4"),
     (5,"R5");



     select left_table.id,
     left_table.left_value
     from left_table
     right join right_table
     on
     left_table.id = right_table.id;





     select left_table.id,
     left_table.left_value,
     right_table.right_value
     from left_table
     self join right_table on
     left_table.id = right_table.id;



       select LL.id,
     LL.left_value,
     RR.right_value
     from left_table as LL
     inner join right_table as RR on
     LL.id = RR.id;


     
     select left_table.id,
     left_table.left_value,
     right_table.right_value
     from left_table
     cross join right_table ;



     create procedure salary_details()
     begin
     select eid from empbatch03 where eid>65;
     select esalary from empbatch03 where esalary>50000;
     select dept from empbatch03 where dept like '%HR%';
     end &&



    -- =========================
-- 0) Create / select DB
-- =========================
CREATE DATABASE IF NOT EXISTS joinpractise;
USE joinpractise;

-- Start fresh (drop if exists, in dependency order)
DROP TABLE IF EXISTS `time`;
DROP TABLE IF EXISTS course;
DROP TABLE IF EXISTS gender;
DROP TABLE IF EXISTS student_details;
DROP TABLE IF EXISTS parent;

-- =========================
-- 1) parent table (text fields)
-- =========================
CREATE TABLE parent (
  SNO     INT PRIMARY KEY AUTO_INCREMENT,
  SNAME   VARCHAR(20),
  sgender VARCHAR(20),
  scourse VARCHAR(20),
  stime   VARCHAR(20)
);

-- Tip: since SNO is AUTO_INCREMENT, don't include it in INSERT unless you need a specific id
INSERT INTO parent (SNAME, sgender, scourse, stime) VALUES
('naveen','male','java full stack','3 to 5'),
('manoj','male','python','10 to 12'),
('priya','female','dot net','2 to 3');

SELECT * FROM parent;

-- =========================
-- 2) student_details (uses code ids for gender, course, time)
-- (keeping your original VARCHAR types to match your session)
-- =========================
CREATE TABLE student_details (
  sno     INT PRIMARY KEY,
  sname   VARCHAR(20),
  sgender VARCHAR(20),  -- stores 1/2 etc.
  scourse VARCHAR(20),  -- stores 1/2/3 etc.
  stime   VARCHAR(20)   -- stores 1/2/3 etc.
);

INSERT INTO student_details (sno, sname, sgender, scourse, stime) VALUES
(1,'naveen',1,2,3),
(2,'manoj',1,3,1),
(3,'priya',2,1,2);

SELECT * FROM student_details;

-- =========================
-- 3) Lookup tables: gender, course, time
-- =========================

-- 3a) gender
CREATE TABLE gender (
  sno INT PRIMARY KEY,
  gender VARCHAR(20)
);

INSERT INTO gender VALUES (1,'male'), (2,'female');
SELECT * FROM gender;

-- Rename column 'gender' -> 'student_gender' (exactly like you did)
ALTER TABLE gender CHANGE gender student_gender VARCHAR(50);

-- (Optional demo) rename to double underscore and back, like your trial
ALTER TABLE gender RENAME COLUMN student_gender TO student__gender;
ALTER TABLE gender RENAME COLUMN student__gender TO student_gender;

SELECT * FROM gender;

-- 3b) course
CREATE TABLE course (
  sno INT PRIMARY KEY,
  coursename VARCHAR(20)
);

INSERT INTO course VALUES
(1,'dot net'),
(2,'java'),
(3,'python');

SELECT * FROM course;

-- 3c) time  (quoted with backticks because TIME is a data type name)
CREATE TABLE `time` (
  sno INT PRIMARY KEY,
  course_time VARCHAR(20)
);

INSERT INTO `time` VALUES
(1,'10 to 12'),
(2,'2 to 3'),
(3,'3 to 5');  -- you added this later

SELECT * FROM `time`;

-- =========================
-- 4) Joins
-- =========================

-- 4a) Map just gender
SELECT
  sd.sno,
  sd.sname,
  sd.sgender,
  g.student_gender
FROM student_details AS sd
INNER JOIN gender AS g
  ON sd.sgender = g.sno;

-- 4b) Full mapping: gender + course + time (INNER JOIN)
SELECT
  sd.sno,
  sd.sname,
  g.student_gender AS gender,
  c.coursename,
  t.course_time
FROM student_details AS sd
INNER JOIN gender AS g
  ON sd.sgender = g.sno
INNER JOIN course AS c
  ON sd.scourse = c.sno
INNER JOIN `time` AS t
  ON sd.stime = t.sno;

-- 4c) LEFT JOIN version (keeps all rows from student_details)
SELECT
  sd.sno,
  sd.sname,
  g.student_gender AS gender,
  c.coursename,
  t.course_time
FROM student_details AS sd
LEFT JOIN gender AS g
  ON sd.sgender = g.sno
LEFT JOIN course AS c
  ON sd.scourse = c.sno
LEFT JOIN `time` AS t
  ON sd.stime = t.sno;

-- 4d) RIGHT JOIN version (keeps all rows from the lookup tables side)
SELECT
  sd.sno,
  sd.sname,
  g.student_gender AS gender,
  c.coursename,
  t.course_time
FROM student_details AS sd
RIGHT JOIN gender AS g
  ON sd.sgender = g.sno
RIGHT JOIN course AS c
  ON sd.scourse = c.sno
RIGHT JOIN `time` AS t
  ON sd.stime = t.sno
ORDER BY sd.sno;

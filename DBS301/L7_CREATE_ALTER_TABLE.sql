set wrap off
set linesize 500
set pagesize 30
COLUMN CONSTRAINT_NAME FORMAT a35;
COLUMN COLUMN_NAME FORMAT a25;
COLUM TABLE_NAME FORMAT a20;
COLUMN constraint_type FORMAT a10;
COLUMN search_condition FORMAT a45; 

DROP TABLE tblCourse CASCADE CONSTRAINTS;
DROP TABLE tblStudent CASCADE CONSTRAINTS;
DROP TABLE tblInstructor CASCADE CONSTRAINTS;
DROP TABLE tblSemester CASCADE CONSTRAINTS;
DROP TABLE tblCourseDetail CASCADE CONSTRAINTS;

CREATE TABLE tblCourse(
    CourseID NUMBER(38),
    CourseCode VARCHAR(6)
        CONSTRAINT c_code_nn NOT NULL,
    CONSTRAINT c_id_min CHECK(CourseID>0),
    CONSTRAINT c_code_uk UNIQUE(CourseCode),
    CONSTRAINT c_id_pk PRIMARY KEY(CourseID)
);

CREATE TABLE tblStudent(
    StudentID NUMBER(38),
    StudentNumber VARCHAR(11)
        CONSTRAINT s_sno_nn NOT NULL,
    StudentFname VARCHAR(20),
    StudentLname VARCHAR(20)
        CONSTRAINT s_lname_nn NOT NULL,
    CONSTRAINT s_id_min CHECK(StudentID>0),
    CONSTRAINT s_sno_uk UNIQUE(StudentNumber),
    CONSTRAINT s_id_pk PRIMARY KEY(StudentID)
);

CREATE TABLE tblInstructor(
    InstructorID NUMBER(38),
    InstructorNumber VARCHAR(15)
        CONSTRAINT i_ino_nn NOT NULL,
    InstructorFname VARCHAR(25),
    InstructorLname VARCHAR(25)
        CONSTRAINT i_lname_nn NOT NULL,
    CONSTRAINT i_id_min CHECK(InstructorID>0),
    CONSTRAINT i_ino_uk UNIQUE(InstructorNumber),
    CONSTRAINT i_id_pk PRIMARY KEY(InstructorID)
);

CREATE TABLE tblSemester(
    SemesterID NUMBER(38),
    SemesterCode VARCHAR(11)
        CONSTRAINT se_code_nn NOT NULL,
    SemesterYear NUMBER(4)
        CONSTRAINT se_year_nn NOT NULL,
    SemesterSeason VARCHAR(6)
        CONSTRAINT se_seasone_nn NOT NULL,
    CONSTRAINT se_id_min CHECK(SemesterID>0),
    CONSTRAINT se_code_uk UNIQUE(SemesterCode),
    CONSTRAINT se_year_min CHECK(SemesterYear>2000),
    CONSTRAINT se_year_uk UNIQUE(SemesterYear),
    CONSTRAINT se_season_chk CHECK(SemesterSeason IN ('Fall','Winter','Summer')),
    CONSTRAINT se_id_pk PRIMARY KEY(SemesterID)
);

CREATE TABLE tblCourseDetail(
    CourseID NUMBER(38),
    StudentID NUMBER(38),
    SemesterID NUMBER(38),
    InstructorID NUMBER(38),
    CourseGrade VARCHAR(2)
        CONSTRAINT cd_grade_nn NOT NULL,
    CourseFinalGrade NUMBER(5,2)
        CONSTRAINT cd_fgrade_nn NOT NULL,
    CONSTRAINT cd_grade_chk CHECK(CourseGrade IN ('F', 'D', 'D+', 'C', 'C+', 'B', 'B+', 'A', 'A+')),
    CONSTRAINT cd_fgrade_chk CHECK(CourseFinalGrade BETWEEN 0 AND 100),
    CONSTRAINT cd_dtl_pk PRIMARY KEY(CourseID, StudentID, SemesterID)
);

ALTER TABLE tblCourseDetail ADD(
    CONSTRAINT cd_course_fk
        FOREIGN KEY(CourseID) REFERENCES tblCourse(CourseID),
    CONSTRAINT cd_student_fk
        FOREIGN KEY(StudentID) REFERENCES tblStudent(StudentID),
    CONSTRAINT cd_semester_fk
        FOREIGN KEY(SemesterID) REFERENCES tblSemester(SemesterID),
    CONSTRAINT cd_inst_fk
        FOREIGN KEY(InstructorID) REFERENCES tblInstructor(InstructorID)
);

ALTER TABLE tblCourse
    ADD CourseDesc VARCHAR(35)
        CONSTRAINT c_desc_nn NOT NULL;

ALTER TABLE tblSemester DROP CONSTRAINT se_year_uk;

ALTER TABLE tblCourseDetail
    RENAME COLUMN CourseGrade
    TO CourseLetterGrade;

ALTER TABLE tblStudent
    MODIFY (
        studentFname VARCHAR(25),
        studentLname VARCHAR(25)
    );
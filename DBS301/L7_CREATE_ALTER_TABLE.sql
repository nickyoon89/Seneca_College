CREATE TABLE tblCourse(
    CourseID NUMBER(38),
    CourseCode TEXT(6)
        CONSTRAINT c_code_nn NOT NULL,
    CONSTRAINT c_id_min CHECK(CourseID>0),
    CONSTRAINT c_code_uk UNIQUE(CourseID),
    CONSTRAINT c_id_pk PRIMARY KEY(CourseID)
    );

CREATE TABLE tblInstructor(
    InstructorID NUMBER(38),
    InstructorNumber TEXT(15)
        CONSTRAINT i_ino_nn NOT NULL,
    InstructorFname TEXT(25),
    InstructorLname TEXT(25)
        CONSTRAINT i_lname_nn NOT NULL,
    CONSTRAINT i_id_min CHECK(InstructorID>0),
    CONSTRAINT i_ino_uk UNIQUE(InstructorNumber),
    CONSTRAINT i_id_pk PRIMARY KEY(InstructorID)
);

CREATE TABLE tblStudent(
    StudentID NUMBER(38),
    StudentNumber TEXT(11)
        CONSTRAINT s_sno_nn NOT NULL,
    StudentFname TEXT(20),
    StudentLname TEXT(20)
        CONSTRAINT s_lname_nn NOT NULL,
    CONSTRAINT s_id_min CHECK(StudentID>0),
    CONSTRAINT s_sno_uk UNIQUE(StudentNumber),
    CONSTRAINT s_id_pk PRIMARY KEY(StudentID)
);

CREATE TABLE tblSemester(
    SemesterID NUMBER(38),
    SemesterCode TEXT(11)
        CONSTRAINT se_code_nn NOT NULL,
    SemesterYear NUMBER(4)
        CONSTRAINT se_year_nn NOT NULL,
    SemesterSeason TEXT(6)
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
    CourseGrade TEXT(2)
        CONSTRAINT cd_grade_nn NOT NULL,
    CourseFinalGrade NUMBER(5,2)
        CONSTRAINT cd_fgrade_nn NOT NULL,
    CONSTRAINT cd_grade_chk CHECK(CourseGrade IN ('F', 'D', 'D+', 'C', 'C+', 'B', 'B+', 'A', 'A+')),
    CONSTRAINT cd_fgrade_chk CHECK(CourseFinalGrade BETWEEN 0 AND 100),
    CONSTRAINT PRIMARY KEY(CourseID, StudentID, SemesterID)
)

ALTER TABLE tblCourseDetail ADD(
    CONSTRAINT cd_course_fk
        FOREIGN KEY(CourseID) REFERENCES tblCourse,
    CONSTRAINT cd_student_fk
        FOREIGN KEY(StudentID) REFERENCES tblStudent,
    CONSTRAINT cd_semester_fk
        FOREIGN KEY(SemesterID) REFERENCES tblSemester,
    CONSTRAINT cd_inst_fk
        FOREIGN KEY(InstructorID) REFERENCES tblInstructor
)
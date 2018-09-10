// View models for School of ICT web service

export class Program {
    Id:             number;
    Code:           string;
    Name:           string;
}

export class Course {
    Id:             number;
    ProgramId:      number;
    CourseId:       number;
    ProgramCode:    string;
    CourseCode:     string;
    CourseName:     string;
    Status:         string;
    DateCreated:    Date;
    DateRetired:    Date;
    Semester:       number;
}

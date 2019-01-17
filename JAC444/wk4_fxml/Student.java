package jac444.wk4;

import java.io.Serializable;
/**
 * Student object
 * @author Jihyun Yoon
 * @version 1.0
 */
public class Student implements Serializable {
	/**
	 * Serial identifier for Student objects
	 */
	private static final long serialVersionUID = 1L;
	String name;
	String course;
	Integer grade;
	
	/**
	 * Empty Student constructor
	 */
	Student() { };
	
	/**
	 * Student constructor
	 * @param name the name of the Student
	 * @param course the course the Student is in
	 * @param grade the grade the Student has in the course
	 */
	Student(String name, String course, Integer grade) {
		if (grade >= 0 && grade <=100) {
			this.name = name;
			this.course = course;
			this.grade = grade;
		} else {
		System.out.println("Please enter a grade between 0 and 100!");
		}
	}
}

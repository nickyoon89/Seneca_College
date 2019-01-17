package jac444.wk5;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Date;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
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
	private SimpleIntegerProperty StudID = new SimpleIntegerProperty(0);
	private SimpleStringProperty name = new SimpleStringProperty("");
	private SimpleStringProperty course = new SimpleStringProperty("");
	private SimpleIntegerProperty grade = new SimpleIntegerProperty(0);

	// default constructor
	public Student() {
		this("","",0);
	};

	/**
	 * To specify way to do "writeObject" with "Student"
	 * @param ObjectOutputStream
	 * @throws IOException
	 */
	private void writeObject(ObjectOutputStream out)
            throws IOException {
		out.writeObject(getStudID());
        out.writeObject(getName());
        out.writeObject(getCourse());
        out.writeObject(getGrade());
    }

	/**
	 * To specify way to do "readObject" with "Student"
	 * @param ObjectInputStream
	 * @throws IOException
	 * @throws ClassNotFoundException
	 */
	private void readObject(ObjectInputStream in)
            throws IOException, ClassNotFoundException {
		StudID = new SimpleIntegerProperty(0);
		name = new SimpleStringProperty("");
		course = new SimpleStringProperty("");
		grade = new SimpleIntegerProperty(0);
		setStudID((int) in.readObject());
        setName((String) in.readObject());
        setCourse((String) in.readObject());
        setGrade((int) in.readObject());
    }
	/**
	 * 3 parameter constructor
	 * @param Student Name
	 * @param Course Name
	 * @param Grade
	 */
	public Student(String name, String course, Integer grade) {
		if (grade >= 0 && grade <=100) {
			setStudID((int) new Date().getTime());
			setName(name);
			setCourse(course);
			setGrade(grade);
		} else {
		System.out.println("Please enter a grade between 0 and 100!");
		}
	}

	//Getters
	public int getStudID(){
		return StudID.get();
	}

	public String getName(){
		return name.get();
	}

	public String getCourse(){
		return course.get();
	}


	public int getGrade(){
		return grade.get();
	}

	//Setters
	private void setStudID(int newId){
		StudID.set(newId);
	}

	public void setName(String newName){
		name.set(newName);
	}

	public void setCourse(String newCourse){
		course.set(newCourse);
	}

	public void setGrade(int newGeade){
		grade.set(newGeade);
	}
}

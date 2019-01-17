package jac444.wk4;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

/**
 * Student Application controller
 * @author Jihyun Yoon
 * @version 1.0
 */
public class StudentController {
    @FXML private Text msg;
    @FXML private TextField filename_box;
    @FXML private TextField name_box;
    @FXML private TextField course_box;
    @FXML private TextField grade_box;

    /**
     * Sets Student object to 'not editable'
     */
    void editableFalse() {
        name_box.setEditable(false);
        course_box.setEditable(false);
        grade_box.setEditable(false);
    }

    /**
     * Sets Student object fields to 'editable'
     */
    void editableTrue() {
        name_box.setEditable(true);
        course_box.setEditable(true);
        grade_box.setEditable(true);
    }

    /**
     * Clears all fields in the application
     */
    void clearBoxes() {
        filename_box.setText("");
        name_box.setText("");
        course_box.setText("");
        grade_box.setText("");
    }

    /**
     * Initializes the application
     */
    @FXML void initialize() {
        filename_box.setEditable(true);
        editableFalse();
    }

    /**
     * Loads the Student object file
     * @param event used for event handler
     * @throws IOException
     * @throws ClassNotFoundException
     */
    @FXML protected void loadStudent(ActionEvent event) throws IOException, ClassNotFoundException {
        filename_box.setEditable(true);
        editableFalse();

        try {
        	File f = new File(filename_box.getText());
    		FileInputStream fis = new FileInputStream(f);
    		ObjectInputStream ois = new ObjectInputStream(fis);
    		Student tmp = (Student)ois.readObject();
    		ois.close();
    		name_box.setText(tmp.name);
    		course_box.setText(tmp.course);
    		grade_box.setText(tmp.grade.toString());
    		msg.setText("Loaded file '" + filename_box.getText() + "'");
        } catch (Exception FileNotFoundException) {
        	msg.setText("File '" + filename_box.getText() + "' not found");
        }

    }

    /**
     * Save the Student object file
     * @param event used for event handler
     * @throws IOException
     */
    @FXML protected void saveStudent(ActionEvent event) throws IOException {
    	try {
	    	Integer grade = Integer.parseInt(grade_box.getText());
	    	filename_box.setEditable(true);
	        editableFalse();
	        if(grade >= 0 && grade <=100) {
		        Student tmp = new Student(name_box.getText(), course_box.getText(), Integer.parseInt(grade_box.getText()));
				File f = new File(filename_box.getText());
				FileOutputStream fos = new FileOutputStream(f);
				ObjectOutputStream oos = new ObjectOutputStream(fos);
				oos.writeObject(tmp);
				oos.close();
				msg.setText("Saved '" + name_box.getText() + "' to '" + filename_box.getText() + "'");
	        } else {
	        	msg.setText("Save failed! Grade must be between 0-100");
	        }
    	} catch (Exception NumberFormatException) {
    		msg.setText("Please enter all fields");
    	}
    }

    /**
     * Allows for the creation of a new Student object
     * @param event used for event handler
     */
    @FXML protected void newStudent(ActionEvent event) {
        msg.setText("Enter student information");
        filename_box.setEditable(true);
        editableTrue();
        clearBoxes();
    }

    /**
     * Allows file in Filename field to be edited
     * @param event used for event handler
     */
    @FXML protected void editStudent(ActionEvent event) {
        msg.setText("Edit '" + filename_box.getText() + "'");
        filename_box.setEditable(true);
        editableTrue();
    }

    /**
     * Allows file in Filename field to be deleted
     * @param event used for event handler
     */
    @FXML protected void deleteStudent(ActionEvent event) {
        msg.setText("Deleted '" + filename_box.getText() + "'");
        filename_box.setEditable(true);
        editableFalse();
        name_box.setText("");
        course_box.setText("");
        grade_box.setText("");
        File f = new File(filename_box.getText());
        f.delete();
    }

    /**
     * default constructor for StudentController
     */
    public StudentController() {}
}

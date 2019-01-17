package jac444.wk6;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;

import java.sql.*;

/**
 * Student Application controller
 * @author Jihyun Yoon
 * @version 1.0
 */
public class StudentController {
    @FXML private Text msg;
    @FXML private TextField filename_box;
    @FXML private TextField db_box;
    @FXML private TextField name_box;
    @FXML private TextField course_box;
    @FXML private TextField grade_box;
    @FXML private TableView<Student> tableView;
    @FXML private Button addRec;
    @FXML private Button delRec;
    @FXML private Button conRec;
    @FXML private Button btn_edit;
    @FXML private Button btn_save;
    @FXML private Button btn_del;

    // To forbid editing
    void editableFalse() {
    	addRec.setDisable(true);
    	delRec.setDisable(true);
    	conRec.setDisable(true);
    	name_box.setEditable(false);
        course_box.setEditable(false);
        grade_box.setEditable(false);
        btn_edit.setDisable(true);
        btn_save.setDisable(true);
        btn_del.setDisable(true);

    }

    // To allow editing
    void editableTrue() {
    	addRec.setDisable(false);
    	delRec.setDisable(false);
    	conRec.setDisable(false);
    	name_box.setEditable(true);
        course_box.setEditable(true);
        grade_box.setEditable(true);
        btn_edit.setDisable(false);
        btn_save.setDisable(false);
        btn_del.setDisable(false);
    }

    // Clear editable spaces except file name
    void clearBoxes() {
        name_box.setText("");
        course_box.setText("");
        grade_box.setText("0");
    }

    /**
     * Initialize the status when the app open including setting "click event" on the table view
     */
    @FXML void initialize() {
    	try {
			Class.forName ("com.mysql.jdbc.Driver").newInstance();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        filename_box.setEditable(true);
        db_box.setEditable(true);
        editableFalse();
        db_box.textProperty().addListener((observable, oldValue, newValue) -> {
            if(!newValue.isEmpty()){
            	filename_box.setText("");
            }
        });
        filename_box.textProperty().addListener((observable, oldValue, newValue) -> {
            if(!newValue.isEmpty()){
            	db_box.setText("");
            }
        });
        tableView.setOnMouseClicked((MouseEvent event)->{
        	if (event.getButton().equals(MouseButton.PRIMARY)){
        		try{
	                Student selectedStudent = tableView.getSelectionModel().getSelectedItem();
	                name_box.setText(selectedStudent.getName());
	                course_box.setText(selectedStudent.getCourse());
	                grade_box.setText(Integer.toString(selectedStudent.getGrade()));
        		}catch(NullPointerException e){

        		}
            }
        });
        clearBoxes();
    }

    /**
     * To confirm changed record on the table view
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void confirmRecord(ActionEvent event){
    	try{
    	Student selectedStudent = tableView.getSelectionModel().getSelectedItem();
    	String name = name_box.getText();
    	String course = course_box.getText();
    	int grade = Integer.parseInt(grade_box.getText());
    	if(grade>=0&&grade<=100){
	        selectedStudent.setName(name);
	        selectedStudent.setCourse(course);
	        selectedStudent.setGrade(grade);
	        msg.setText("Record Changed");
    	}
    	else msg.setText("Grade must be between 0-100");
    	}catch (NullPointerException e){
    		msg.setText("No data yet");
    	}
        tableView.getColumns().get(0).setVisible(false);
        tableView.getColumns().get(0).setVisible(true);
        clearBoxes();
    }

    /**
     * Add record on the table view with data
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void addRecord(ActionEvent event){
    	ObservableList<Student> data = tableView.getItems();
    	Integer grade = Integer.parseInt(grade_box.getText());
    	if(grade>=0 && grade<=100){
    		data.add(new Student(name_box.getText(), course_box.getText(), grade));
    		clearBoxes();
    	}
    	else
    		msg.setText("Grade must be between 0-100");
    }

    /**
     * Delete one record from table view
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void deleteRecord(ActionEvent event){
    	try{
	    	tableView.getItems().removeAll(
	                tableView.getSelectionModel().getSelectedItems()
	        );
    	}catch(NullPointerException e){
    		msg.setText("Nothing's selected");
    	}
    }

    /**
     * File load function
     * @param ActionEvent, which is button clicked
     * @throws IOException
     * @throws ClassNotFoundException
     */
    @SuppressWarnings("unchecked")
	@FXML protected void load(ActionEvent event) throws IOException, ClassNotFoundException {
    	tableView.getItems().removeAll(
    			tableView.getItems()
    	);
    	if(!filename_box.getText().isEmpty()){
	        filename_box.setEditable(true);
	        editableFalse();
	        try {
	        	File f = new File(filename_box.getText());
	    		FileInputStream fis = new FileInputStream(f);
	    		ObjectInputStream ois = new ObjectInputStream(fis);
	    		ObservableList<Student> data = tableView.getItems();
	    		ArrayList<Student> students =  (ArrayList<Student>) ois.readObject();
	    		for(Student s : students){
	    			data.add(s);
	    		}
	    		tableView.setItems(data);
	    		ois.close();
	    		msg.setText("File loaded");
	    		btn_edit.setDisable(false);
	        } catch (Exception FileNotFoundException) {
	        	msg.setText("File load failed");
	        }
    	}else if(!db_box.getText().isEmpty()){
    		db_box.setEditable(true);
	        editableFalse();
    		Connection conn = null;
    		Statement command;
    		ResultSet data;
    		ObservableList<Student> students = tableView.getItems();
    		Student s;
    		try {
				conn = DriverManager.getConnection(db_box.getText());
				command = conn.createStatement();
				data = command.executeQuery("SELECT * FROM Students");
				while(data.next()){
					s = new Student();
					s.setCourse(data.getString("COURSE"));
					s.setGrade(data.getInt("GRADE"));
					s.setName(data.getString("NAME"));
					s.setStudID(data.getInt("ID"));
					students.add(s);
				}
				tableView.setItems(students);
				msg.setText("MySQL Loaded");
				data.close();
				command.close();
				conn.close();

			} catch (SQLException ex) {
				System.out.println("SQLException: " + ex.getMessage());
			    System.out.println("SQLState: " + ex.getSQLState());
			    System.out.println("VendorError: " + ex.getErrorCode());			}

    	}else{
    		msg.setText("Please insert file name or db connection string");
    	}
    }

    /**
     * Save data to the file
     * @param ActionEvent, which is button clicked
     * @throws IOException
     */
    @FXML protected void save(ActionEvent event) throws IOException {
    	ObservableList<Student> students=  tableView.getItems();
    	filename_box.setEditable(true);
    	if(filename_box.getText().isEmpty()){
    		msg.setText("Please input file name");
    	}else{
	    	try{
		    	File f = new File((String) filename_box.getText());
		    	FileOutputStream fos = new FileOutputStream(f);
		    	ObjectOutputStream oos = new ObjectOutputStream(fos);
		    	ArrayList<Student> data = new ArrayList<Student>();
		    	for(Student s : students){
		    		data.add(s);
		    	}
		    	oos.writeObject(data);
		    	oos.close();
		    	msg.setText("Saved the file");
		    	editableFalse();
	    	}catch(Exception e){
	    		msg.setText("Error! Couldn't save the file");
	    	}
    	}
    }

    /**
     * Ready to input new student information
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void newF(ActionEvent event) {
    	db_box.setText("");
        msg.setText("");
        tableView.getItems().removeAll(
    			tableView.getItems()
    	);
        filename_box.setEditable(true);
        editableTrue();
        clearBoxes();
    }

    /**
     * Ready to edit loaded file data
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void edit(ActionEvent event) {
        msg.setText("Edit mode on");
        filename_box.setEditable(true);
        editableTrue();
    }

    /**
     * Delete the file
     * @param ActionEvent, which is button clicked
     */
    @FXML protected void delete(ActionEvent event) {
        msg.setText("File Deleted");
        filename_box.setEditable(true);
        editableFalse();
        File f = new File(filename_box.getText());
        f.delete();
    }

    public StudentController() {}
}

package jac444.wk5;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
/**
 * Student Application starter
 * @author Jihyun Yoon
 * @version 1.0
 */
public class StudentApp extends Application {

	/**
	 * start the FX application
	 * @param The window information we will excute
	 */
	public void start(Stage stage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("Student.fxml"));

		Scene scene = new Scene(root, 400, 500);

		stage.setTitle("Student Application");
        stage.setScene(scene);
        stage.show();
	}

	/**
	 * main function
	 * @param arguements in command line
	 */
	public static void main(String[] args) {
		launch(args);
	}
}

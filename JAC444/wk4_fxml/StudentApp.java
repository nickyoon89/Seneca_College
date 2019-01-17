package jac444.wk4;

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
	 * Function that starts the setup for the application
	 * @param stage sets the stage for the application
	 */
	public void start(Stage stage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("Student.fxml"));

		Scene scene = new Scene(root, 400, 220);

		stage.setTitle("Student Application");
        stage.setScene(scene);
        stage.show();
	}

	/**
	 * Launches the application
	 * @param args the arguments used to start the application
	 */
	public static void main(String[] args) {
		launch(args);
	}
}

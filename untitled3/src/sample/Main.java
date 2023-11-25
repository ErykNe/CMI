package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import java.util.Objects;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }
    public Stage game;
    {
        game = new Stage();
    }
    @Override
    public void start(Stage stage) throws Exception {
        game = stage;
        Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("sample.fxml")));
        Scene scene = new Scene(root, Color.WHITE);
        Image ico = new Image(Objects.requireNonNull(getClass().getResourceAsStream("icon.png")));
        game.getIcons().add(ico);
        game.setTitle("Tic Tac Toe 4x3                                                                                                                                                                                                                                 made by ErykNe");
        game.setWidth(1040);
        game.setHeight(820);
        game.setResizable(false);

        root.getStylesheets().add(Objects.requireNonNull(getClass().getResource("style.css")).toExternalForm());

        game.setScene(scene);
        game.show();

    }
}

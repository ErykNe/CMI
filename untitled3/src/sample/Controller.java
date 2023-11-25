package sample;

import javafx.fxml.FXMLLoader;
import javafx.event.ActionEvent;
import java.util.Objects;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.effect.GaussianBlur;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.stage.Stage;
public class Controller {
    public Button button1;
    public Button button2;
    public Button button3;
    public Button button4;
    public Button button5;
    public Button button6;
    public Button button7;
    public Button button8;
    public Button button9;
    public Button button10;
    public Button button11;
    public Button button12;
    public Text text;
    {
        this.text = new Text();
        text.applyCss();
        text.setCache(true);
    }
    public boolean player1 = true;
    public boolean player2 = false;
    public int[] table = new int[13];
    {
        table[0] = 69;
        table[1] = 69;
        table[2] = 69;
        table[3] = 69;
        table[4] = 69;
        table[5] = 69;
        table[6] = 69;
        table[7] = 69;
        table[8] = 69;
        table[9] = 69;
        table[10] = 69;
        table[11] = 69;
        table[12] = 69;


    }
    public void press00(ActionEvent e) throws Exception {
        if (player1 == true){

           ImageView circle0 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
           button1.setGraphic(circle0);
           player1 = false;
           player2 = true;
           table[0] = 0;
        }
        else{

            ImageView cross0 = new ImageView(Controller.class.getResource("cross.png").toExternalForm());
            button1.setGraphic(cross0);
            player1 = true;
            player2 = false;
            table[0] = 1;
        }
        button1.setDisable(true);
        button1.setVisible(true);
        button1.setUnderline(true);
        button1.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press01(ActionEvent r) throws Exception {
        if (player1 == true){

            ImageView circle1 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button2.setGraphic(circle1);
            player1 = false;
            player2 = true;
            table[1] = 0;
        }
        else{

            ImageView cross1 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button2.setGraphic(cross1);
            player1 = true;
            player2 = false;
            table[1] = 1;
        }
        button2.setDisable(true);
        button2.setUnderline(true);
        button2.setVisible(true);
        button2.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press02(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle2 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button3.setGraphic(circle2);
            player1 = false;
            player2 = true;
            table[2] = 0;
        }
        else{

            ImageView cross2 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button3.setGraphic(cross2);
            player1 = true;
            player2 = false;
            table[2] = 1;
        }
        button3.setDisable(true);
        button3.setUnderline(true);
        button3.setVisible(true);
        button3.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press03(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle3 = new ImageView(Controller.class.getResource("circle.png").toExternalForm());
            button4.setGraphic(circle3);
            player1 = false;
            player2 = true;
            table[3] = 0;
        }
        else{

            ImageView cross3 = new ImageView(Controller.class.getResource("cross.png").toExternalForm());
            button4.setGraphic(cross3);
            player1 = true;
            player2 = false;
            table[3] = 1;
        }
        button4.setDisable(true);
        button4.setUnderline(true);
        button4.setVisible(true);
        button4.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press04(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle4 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button5.setGraphic(circle4);
            player1 = false;
            player2 = true;
            table[4] = 0;
        }
        else{

            ImageView cross4 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button5.setGraphic(cross4);
            player1 = true;
            player2 = false;
            table[4] = 1;
        }
        button5.setDisable(true);
        button5.setUnderline(true);
        button5.setVisible(true);
        button5.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press05(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle5 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button6.setGraphic(circle5);
            player1 = false;
            player2 = true;
            table[5] = 0;
        }
        else{

            ImageView cross5 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button6.setGraphic(cross5);
            player1 = true;
            player2 = false;
            table[5] = 1;
        }
        button6.setDisable(true);
        button6.setUnderline(true);
        button6.setVisible(true);
        button6.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press06(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle6 = new ImageView(Controller.class.getResource("circle.png").toExternalForm());
            button7.setGraphic(circle6);
            player1 = false;
            player2 = true;
            table[6] = 0;
        }
        else{

            ImageView cross6 = new ImageView(Controller.class.getResource("cross.png").toExternalForm());
            button7.setGraphic(cross6);
            player1 = true;
            player2 = false;
            table[6] = 1;
        }
        button7.setDisable(true);
        button7.setUnderline(true);
        button7.setVisible(true);
        button7.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press07(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle7 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button8.setGraphic(circle7);
            player1 = false;
            player2 = true;
            table[7] = 0;
        }
        else{

            ImageView cross7 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button8.setGraphic(cross7);
            player1 = true;
            player2 = false;
            table[7] = 1;
        }
        button8.setDisable(true);
        button8.setUnderline(true);
        button8.setVisible(true);
        button8.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press08(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle8 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button9.setGraphic(circle8);
            player1 = false;
            player2 = true;
            table[8] = 0;
        }
        else{

            ImageView cross8 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button9.setGraphic(cross8);
            player1 = true;
            player2 = false;
            table[8] = 1;
        }
        button9.setDisable(true);
        button9.setUnderline(true);
        button9.setVisible(true);
        button9.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press09(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle9 = new ImageView(Controller.class.getResource("circle.png").toExternalForm());
            button10.setGraphic(circle9);
            player1 = false;
            player2 = true;
            table[9] = 0;
        }
        else{

            ImageView cross9 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button10.setGraphic(cross9);
            player1 = true;
            player2 = false;
            table[9] = 1;
        }
        button10.setDisable(true);
        button10.setUnderline(true);
        button10.setVisible(true);
        button10.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press10(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle10 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button11.setGraphic(circle10);
            player1 = false;
            player2 = true;
            table[10] = 0;
        }
        else{

            ImageView cross10 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button11.setGraphic(cross10);
            player1 = true;
            player2 = false;
            table[10] = 1;
        }
        button11.setDisable(true);
        button11.setUnderline(true);
        button11.setVisible(true);
        button11.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void press11(ActionEvent t) throws Exception {
        if (player1 == true){

            ImageView circle11 = new ImageView(Objects.requireNonNull(Controller.class.getResource("circle.png")).toExternalForm());
            button12.setGraphic(circle11);
            player1 = false;
            player2 = true;
            table[11] = 0;
        }
        else{

            ImageView cross11 = new ImageView(Objects.requireNonNull(Controller.class.getResource("cross.png")).toExternalForm());
            button12.setGraphic(cross11);
            player1 = true;
            player2 = false;
            table[11] = 1;
        }
        button12.setDisable(true);
        button12.setUnderline(true);
        button12.setVisible(true);
        button12.setOpacity(100);
        if (player1 == true){

            text.setText("O turn");
            text.setVisible(true);
        }
        if (player2 == true){

            text.setText("X turn");
            text.setVisible(true);
        }
        this.conditions();
    }
    public void conditions() throws Exception {

        if (table[0] == 0 && table[1] == 0 && table[2] == 0) {
            this.owonmethod();
        } else if (table[0] == 1 && table[1] == 1 && table[2] == 1){
            this.xwonmethod();
        }

        if (table[3] == 0 && table[4] == 0 && table[5] == 0) {
            this.owonmethod();
        } else if (table[3] == 1 && table[4] == 1 && table[5] == 1){
            this.xwonmethod();
        }

        if (table[6] == 0 && table[7] == 0 && table[8] == 0) {
            this.owonmethod();
        } else if (table[6] == 1 && table[7] == 1 && table[8] == 1){
            this.xwonmethod();
        }

        if (table[9] == 0 && table[10] == 0 && table[11] == 0) {
            this.owonmethod();
        } else if (table[9] == 1 && table[10] == 1 && table[11] == 1){
            this.xwonmethod();
        }




        if (table[0] == 0 && table[3] == 0 && table[6] == 0){
            this.owonmethod();
        } else if (table[0] == 1 && table[3] == 1 && table[6] == 1){
            this.xwonmethod();
        }
        if (table[3] == 0 && table[6] == 0 && table[9] == 0){
            this.owonmethod();
        } else if (table[3] == 1 && table[6] == 1 && table[9] == 1){
            this.xwonmethod();
        }
        if (table[1] == 0 && table[4] == 0 && table[7] == 0){
            this.owonmethod();
        } else if (table[1] == 1 && table[4] == 1 && table[7] == 1){
            this.xwonmethod();
        }
        if (table[4] == 0 && table[7] == 0 && table[10] == 0){
            this.owonmethod();
        } else if (table[4] == 1 && table[7] == 1 && table[10] == 1){
            this.xwonmethod();
        }
        if (table[2] == 0 && table[5] == 0 && table[8] == 0){
            this.owonmethod();
        } else if (table[2] == 1 && table[5] == 1 && table[8] == 1){
            this.xwonmethod();
        }
        if (table[5] == 0 && table[8] == 0 && table[11] == 0){
            this.owonmethod();
        } else if (table[5] == 1 && table[8] == 1 && table[11] == 1){
            this.xwonmethod();
        }



        if (table[0] == 0 && table[4] == 0 && table[8] == 0){
            this.owonmethod();
        } else if (table[0] == 1 && table[4] == 1 && table[8] == 1){
            this.xwonmethod();
        }
        if (table[6] == 0 && table[4] == 0 && table[2] == 0){
            this.owonmethod();
        } else if (table[6] == 1 && table[4] == 1 && table[2] == 1){
            this.xwonmethod();
        }
        if (table[3] == 0 && table[7] == 0 && table[11] == 0){
            this.owonmethod();
        } else if (table[3] == 1 && table[7] == 1 && table[11] == 1){
            this.xwonmethod();
        }
        if (table[5] == 0 && table[7] == 0 && table[9] == 0){
            this.owonmethod();
        } else if (table[5] == 1 && table[7] == 1 && table[9] == 1){
            this.xwonmethod();
        }

        if     (button1.isUnderline() &&
                button2.isUnderline() &&
                button3.isUnderline() &&
                button4.isUnderline() &&
                button5.isUnderline() &&
                button6.isUnderline() &&
                button7.isUnderline() &&
                button8.isUnderline() &&
                button9.isUnderline() &&
                button10.isUnderline() &&
                button11.isUnderline() &&
                button12.isUnderline()
        ){
            this.drawmethod();
        }
    }
    public Rectangle Xbox;
    public Text xText;
    public Text oText;
    public Text drawText;
    public Button restartbutton = new Button();
    public void xwonmethod() throws Exception {

        Main main = new Main();
        button1.setEffect(new GaussianBlur(50));
        button2.setEffect(new GaussianBlur(50));
        button3.setEffect(new GaussianBlur(50));
        button4.setEffect(new GaussianBlur(50));
        button5.setEffect(new GaussianBlur(50));
        button6.setEffect(new GaussianBlur(50));
        button7.setEffect(new GaussianBlur(50));
        button8.setEffect(new GaussianBlur(50));
        button9.setEffect(new GaussianBlur(50));
        button10.setEffect(new GaussianBlur(50));
        button11.setEffect(new GaussianBlur(50));
        button12.setEffect(new GaussianBlur(50));
        button1.setDisable(true);
        button2.setDisable(true);
        button3.setDisable(true);
        button4.setDisable(true);
        button5.setDisable(true);
        button6.setDisable(true);
        button7.setDisable(true);
        button8.setDisable(true);
        button9.setDisable(true);
        button10.setDisable(true);
        button11.setDisable(true);
        button12.setDisable(true);
        text.setVisible(false);
        Xbox.setVisible(true);
        xText.setVisible(true);
        restartbutton.setVisible(true);
    }
    public void owonmethod() throws Exception{
        Main main = new Main();
        button1.setEffect(new GaussianBlur(50));
        button2.setEffect(new GaussianBlur(50));
        button3.setEffect(new GaussianBlur(50));
        button4.setEffect(new GaussianBlur(50));
        button5.setEffect(new GaussianBlur(50));
        button6.setEffect(new GaussianBlur(50));
        button7.setEffect(new GaussianBlur(50));
        button8.setEffect(new GaussianBlur(50));
        button9.setEffect(new GaussianBlur(50));
        button10.setEffect(new GaussianBlur(50));
        button11.setEffect(new GaussianBlur(50));
        button12.setEffect(new GaussianBlur(50));
        button1.setDisable(true);
        button2.setDisable(true);
        button3.setDisable(true);
        button4.setDisable(true);
        button5.setDisable(true);
        button6.setDisable(true);
        button7.setDisable(true);
        button8.setDisable(true);
        button9.setDisable(true);
        button10.setDisable(true);
        button11.setDisable(true);
        button12.setDisable(true);
        text.setVisible(false);
        Xbox.setVisible(true);
        oText.setVisible(true);
        restartbutton.setVisible(true);
    }
    public void drawmethod() throws Exception{
        Main main = new Main();
        button1.setEffect(new GaussianBlur(50));
        button2.setEffect(new GaussianBlur(50));
        button3.setEffect(new GaussianBlur(50));
        button4.setEffect(new GaussianBlur(50));
        button5.setEffect(new GaussianBlur(50));
        button6.setEffect(new GaussianBlur(50));
        button7.setEffect(new GaussianBlur(50));
        button8.setEffect(new GaussianBlur(50));
        button9.setEffect(new GaussianBlur(50));
        button10.setEffect(new GaussianBlur(50));
        button11.setEffect(new GaussianBlur(50));
        button12.setEffect(new GaussianBlur(50));
        button1.setDisable(true);
        button2.setDisable(true);
        button3.setDisable(true);
        button4.setDisable(true);
        button5.setDisable(true);
        button6.setDisable(true);
        button7.setDisable(true);
        button8.setDisable(true);
        button9.setDisable(true);
        button10.setDisable(true);
        button11.setDisable(true);
        button12.setDisable(true);
        text.setVisible(false);
        Xbox.setVisible(true);
        if (!xText.isVisible()){
            if (!oText.isVisible()){
                drawText.setVisible(true);
            }
        }

        restartbutton.setVisible(true);
    }
    public void restartbutton(ActionEvent e) throws Exception{
       Controller controller = new Controller();
        Stage game = (Stage) restartbutton.getScene().getWindow();
        game.close();
        Stage stage = new Stage();
        Main main = new Main();
        Parent root2 = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("sample.fxml")));
        Scene scene = new Scene(root2, Color.WHITE);
        Image ico = new Image(Objects.requireNonNull(getClass().getResourceAsStream("icon.png")));
        stage.getIcons().add(ico);
        stage.setTitle("Tic Tac Toe 4x3                                                                                                                                                                                                                                 made by ErykNe");
        stage.setWidth(1040);
        stage.setHeight(820);
        stage.setResizable(false);
        root2.getStylesheets().add(Objects.requireNonNull(getClass().getResource("style.css")).toExternalForm());
        stage.setScene(scene);
        stage.show();

    }

}
